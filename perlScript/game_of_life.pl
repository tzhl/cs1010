#!/usr/share/bin/perl

#List of variable use
$rows;
$column;
@next;
@current;
$n;
$wall;
$start;
$cell='@';
$space=' ';
use Getopt::Long;
#by default
my $wall = 'n';
my $choice = 1;
my $rows=40;
my $column=40;
GetOptions(
      "help" =>\&help,             
      "row=i" => \$rows,
      "col=i" => \$column,
      "wall=s" => \$wall,
      "choice=s" => \$choice,
      "step" =>\&step);
#**************************main*************************#
$wall_size=0;
if($wall eq 'y'||$wall eq 'Y')
{
   $rows=$rows+2;
   $column=$column+2;    
}
#Initialized the grid
grid($rows,$column);
if($wall eq 'y'||$wall eq 'Y')
{
   $wall_size = create_wall(@current);
}
#choose method of input
if($choice==1)
{
   randomize_input(@current);
}
elsif($choice==2)
{
   pattern_selection($wall_size);

}
compute();

#************************sub funtion*****************************#
sub help
{
   print "***Key word to be used***\n";
   print "-row <number of rows> \t\t\t\t\t #by default row = 40 \n";
   print "-col <number of column> \t\t\t\t #by default col = 40 \n";
   print "-wall < 'n' for NO, 'y' for YES > \t\t\t #by default wall = 'n' \n";
   print "-choice < '1' for Randomize \t '2' for Patterns > \t #by default choice = 1 \n";
   print "-step <step by step key in the input from user> \n";
   exit(1);
}
sub step
{
#user input dimension of grid
   print "Enter number of rows > ";
   $rows=<STDIN>;
   print "Enter number of column > ";
   $column=<STDIN>;
   print "Walls surround cells?(y/n) > ";
   $wall=<STDIN>;
   chomp($wall);
   $wall_size=0;
   if($wall eq 'y'||$walls eq 'Y')
   {
      $rows=$rows+2;
      $column=$column+2;
   }
#Initialized the grid with space ' '
   grid($rows,$column);

   if($wall eq 'y'||$wall eq 'Y')
   {
      $wall_size = create_wall(@current);
   }
   print "\n1. Random\n";
   print "2. Previous set pattern\n";
   print "Choose method of input > ";
   $choice=<STDIN>;
   if($choice == 1)
   {
      randomize_input(@current);
   }
   elsif($choice == 2)
   {
      pattern_selection($wall_size);

   }
   compute();
}
#compute the display and the iteration number, then press enter to proceed to next cycle
sub compute 
{
   copy_current_next();
   print `clear`,"\n";
   $iteration_count=0;
   do
   {
      display_current_next($iteration_count);

      $iteration_count++;

      print"\nStart";
      for($k=0; $k < (int($column/8)+1);$k++)
      {
         print "\t";
      }
      print "   After iteration $iteration_count\n";

      $cont=<STDIN>;

#reset to first iteration 
      if($cont eq "r\n"||$cont eq "R\n")
      {
         $iteration_count=0;
         copy_current_next();
      }
      print `clear`,"\n";
   }until(!$cont);
}              
#copy array "current" to array "next" for computing purpose
sub copy_current_next
{
   for($i=0;$i<$rows;$i++)
   {
      for($j=0;$j<$column;$j++)           
      {              
         $next[$i][$j]=$current[$i][$j];
      }
   }
}
#initialization of grid with space ' ',making a platform to store the array "current". 
sub grid
{
   my $row=$_[0];
   my $col=$_[1];
   for($i=0; $i<$rows; $i++)
   {
      for($j=0; $j<$column; $j++)
      {              
         $current[$i][$j]=$space;
      }
   }
}
#final output for the initial state and the next state 
sub display_current_next
{
   my $count=$_[0];
   my @temp;
   for($i=0;$i<$rows;$i++)
   {
      for($j=0;$j<$column;$j++)
      {              
         print "$current[$i][$j]";
      }
      print "\t|  ";
      for($j=0;$j<$column;$j++)
      {
         $n=num_neighbour(@next);
         $temp[$i][$j]=next_cycle($n,$next[$i][$j]);
         print "$temp[$i][$j]";
      }
      print "\n";
   }
#pass reference of @temp to @next
   @next=@temp;
}
#calculate number of neighbour
sub num_neighbour
{              
   my @check=@_;
   my $num=0;

   if($check[($i+$rows-1) % $rows][($j+$column-1) % $column] eq $cell)    #algorithm for top left grid
   {    
      $num++;
   } 
   if($check[($i+$rows-1) % $rows][$j] eq $cell)              #algorithm for top grid
   {
      $num++;
   }
   if($check[($i+$rows-1) % $rows][($j+1) % $column] eq $cell)         #algorithm for top right grid
   {
      $num++;
   }
   if($check[$i][($j+$column-1) % $column] eq $cell)          #algorithm for left grid
   {
      $num++;
   }              
   if($check[$i][($j+1) % $column] eq $cell)               #algorithm for right grid
   {
      $num++;
   }              
   if($check[($i+1) % $rows][($j+$column-1) % $column] eq $cell)       #algorithm for bottom left grid
   {
      $num++;              
   }                                              
   if($check[($i+1) % $rows][$j] eq $cell)                 #algorithm for bottom grid
   {
      $num++;
   }
   if($check[($i+1) % $rows][($j+1) % $column] eq $cell)            #algorithm for bottom right grid
   {
      $num++;
   }
   return $num;
}
#the algorithm of 4 basic rule of Game of life and check wall
sub next_cycle
{
   my $num=$_[0];
   my $live_die=$_[1];
   if(check_wall($live_die))
   {
      return $live_die;
   }
   elsif($num<2||$num>3)
   {
      $live_die=$space;
   }
   elsif ($num==3)
   {
      $live_die=$cell;
   }
   return $live_die;
}
#check whether there is wall surround cells
sub check_wall
{
   my $check_w=$_[0];
   if($check_w eq 'O' || $check_w eq '-' || $check_w eq '|')
   {
      return 1;
   }
   else
   {
      return 0;
   }              
}
#create the wall for the ease of computing the next cycle
sub create_wall 
{
   @array=@_;
   $array[0][0]='O';
   $array[0][$column-1]='O';
   $array[$rows-1][0]='O';
   $array[$rows-1][$column-1]='O';
   for($i=0,$j=1;$j<$column-1;$j++)
   {
      $array[$i][$j]='-';
      $array[$rows-1][$j]='-';
   }
   for($i=1;$i<$rows-1;$i++)
   {
      $array[$i][0]='|';
      $array[$i][$column-1]='|';
   }
   $wall_size=$rows * 2 + $column *2 - 4
}
#randomise the input pattern into the @current
srand;
sub randomize_input
{
   @grid=@_;
   my $num_input;
   do
   {
      print "Enter number of starting cells > ";
      $num_input=<STDIN>;
   }until($num_input<=$rows*$column - $wall_size);
   chomp($num_input);

   for($i=0;$i<$num_input;$i++)
   {
      do
      {              
         $r=int(rand($rows));
         $c=int(rand($column));
      }until($grid[$r][$c] eq $space);
      $grid[$r][$c]=$cell;          
   }
}
#Display the pattern available and select the pattern
sub pattern_selection
{
   my $Wall_size=$_[0];
   my $space_occupied;
   my $choose;
   my $print_count=0;
   my $num_pattern=3;
   my @pattern= ("R-pentomino","Pentadecathlon","Acorn");
   my @pattern_rows=(3,9,3);
   my @pattern_cols=(3,16,7);
   my @store_num;

   if($Wall_size>0)
   {
      $space_occupied=2;       
   }
   else
   {
      $space_occupied=0;
   }
   for($i=0;$i<$num_pattern;$i++)
   {
      if($rows-$space_occupied>=$pattern_rows[$i] && $column-$space_occupied>=$pattern_cols[$i])
      {
         $store_num[$print_count]=$i;
         $print_count++;
         print $print_count,'.'," $pattern[$i]\n";
      }
   }

   if($print_count>0)
   {
      print "Enter the pattern > ";
      $choose=<STDIN>;

      if($store_num[$choose-1]==0)
      {
         R_pentomino();               
      }
      elsif($store_num[$choose-1]==1)
      {
         Pentadecathlon();
      }
      elsif($store_num[$choose-1]==2)
      {
         Acorn();
      }
      else
      {
         print "Invalid selection\n";
      }
   }
   else
   {
      print "Grid too small\n";
   }
}
#initialise pattern1
sub R_pentomino            
{
   $current[int((($rows+1)/2)-2)][int((($column+1)/2)-1)] = $cell;
   $current[int((($rows+1)/2)-2)][int(($column+1)/2)] = $cell;
   $current[int((($rows+1)/2)-1)][int((($column+1)/2)-2)] = $cell;
   $current[int((($rows+1)/2)-1)][int((($column+1)/2)-1)] = $cell;
   $current[int(($rows+1)/2)][int((($column+1)/2)-1)] = $cell;
}
#initialise pattern2
sub Pentadecathlon
{
   $current[int($rows/2)-1][int(($column/2)-3)] = $cell;
   $current[int($rows/2)-1][int(($column/2)+2)] = $cell;
   $current[int($rows/2)][int(($column/2)-5)] = $cell;
   $current[int($rows/2)][int(($column/2)-4)] = $cell;
   $current[int($rows/2)][int(($column/2)-2)] = $cell;
   $current[int($rows/2)][int(($column/2)-1)] = $cell;
   $current[int($rows/2)][int($column/2)] = $cell;
   $current[int($rows/2)][int(($column/2)+1)] = $cell;
   $current[int($rows/2)][int(($column/2)+3)] = $cell;
   $current[int($rows/2)][int(($column/2)+4)] = $cell;
   $current[int($rows/2)+1][int(($column/2)-3)] = $cell;
   $current[int($rows/2)+1][int(($column/2)+2)] = $cell;
} 
#initialise pattern3
sub Acorn
{
   $current[int($rows/2)+1][int($column/2)-3] = $cell;
   $current[int($rows/2)+1][int($column/2)-2] = $cell;
   $current[int($rows/2)-1][int(($column/2)-2)] = $cell;
   $current[int($rows/2)][int($column/2)] = $cell;
   $current[int($rows/2)+1][int($column/2)+1] = $cell;
   $current[int($rows/2)+1][int($column/2)+2] = $cell;
   $current[int($rows/2)+1][int($column/2)+3] = $cell;
} 

