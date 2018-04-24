#!/usr/bin/perl
use strict;

MAIN:
{
   my @grid;
   my $max_row;
   my $max_column;

#######################################    MAIN FUNCTION #####################################
   {
      initial_state(); 
      print "@$_\n" for @grid;
      for($row = 0; $row < $max_row; $row++)
      {
         for($column = 0; $column < $max_column; $column++)
         {
            $grid2[$row][$column] = $grid[$row][$column];
         }
      }

      $iteration = 0;
      print "Please Enter the duration of delay for each iteration :  ";
      $d = <>;
      $delay = shift || $d;
      print "To stop the iteration, press '0' \n";

      fork();
      chomp(<STDIN>);
      $update = $_[0];
OUTER:
      while($update ne 'q')
      {
#  for(;;)
#  {
   print `clear`;
   sleep $delay;

   for($row = 0; $row < $max_row; $row++)
   {
      for($column = 0; $column < $max_column; $column++)
      {
         $grid[$row][$column] = $grid2[$row][$column];
      }
   }
   next_phase();
   print ++$iteration,"cycle","\t population: ",$population, "\n";
   print "@$_\n" for @grid2;

#}
   chomp(<STDIN>);
   $update = $_[0];

      }
#######################################    SUB-FUNCTION  #####################################
      sub initial_state
      {
         print "What initial state would you like? (choose the number)\n1 random\n2 custom\n3 special\n";
         $choice = <STDIN>;
         if($choice == 1)
         {
            print "The initial state will be generated randomly.\n";
            $max_row = 10 + int(rand(16));
            $max_column = 10 + int(rand(16));
            initial_condition('N');
         }
         if ($choice == 2)
         {              
            grid_size();
            print "Do you want to enter your own starting pattern? (Y/N) ";
            $ans = <STDIN>;
            chomp($ans);
            if($ans eq 'N' || $ans eq 'n')
            {
               print "The starting pattern will be randomly generated.\n";
            }
            initial_condition($ans);
         }
         if ($choice == 3)
         {  
            print " 1.block and Longhook
               2.qq
               3.
               4.   
               ","\n";

            print "Key in the number of the initial pattern choosen : ";
            $pattern = int(<STDIN>);
            if($pattern == 1)
            {
               open(FILE, "block_and_longhook.txt") || die "Can't open file! \n";
               $read_special_file();
               close(FILE);
            }
            if($pattern == 2)
            {
               open(FILE, ".txt") || die "Can't open file! \n";
            }
            if($pattern == 3)
            {
               open(FILE, "qq.txt") || die "Can't open file! \n";
            }
            if($pattern == 4)
            {
               open(FILE, ".txt") || die "Can't open file! \n";
            }
            if($pattern == 5)

         }

         sub initial_condition
         {
            if($_[0] eq 'N' || $_[0] eq 'n')
            {
               for($row = 0; $row < $max_row; $row++)
               {
                  for($column = 0 ; $column < $max_column ; $column++)
                  {
                     $grid[$row][$column] = int(rand(2));
                     if($grid[$row][$column] == 1)
                     {
                        $grid[$row][$column] = 'x';
                     }  
                     else
                     {
                        $grid[$row][$column] = ' ';
                     }
                     $grid2[$row][$column] = ' ';
                  }
               }                   
            }
            elsif($_[0] eq 'Y' || $_[0] eq 'y')
            {
               do           
               {
                  print `clear`;                       
                  printf("%-3s\tCOLUMN\n",'ROW');
                  printf("%-6s",' '); 
                  for($header=0; $header<$max_column; $header++)
                  {
                     printf("%-3d",$header); 
                  }           
                  print "\n";
                  for($row=0; $row<$max_row; $row++)
                  {
                     printf("%-3s",' '); 
                     printf("%-3d",$row);                                      
                     for($col=0; $col<$max_column; $col++)
                     {
                        if($grid[$row][$col] ne 'x')
                        {   printf("%-3s",'_');    }
                        else
                        {   printf("%-3s",'x');    }
                     }
                     print"\n";
                  }
                  print "Specified the row and column for alive cell (separated by a <ENTER> key):\n";
                  print "(Press u to undo)\n";
                  print "(Press q to quit if you are done)\n";
                  $answer = <STDIN>;
                  chomp($answer);
                  if($answer ne 'q' && $answer ne 'Q')
                  {
                     if($answer eq 'u' || $answer eq 'U')
                     {
                        $grid[$custom_cell_row][$custom_cell_col] = ' ';
                     }
                     else
                     {
                        $custom_cell_row=int($answer);
                        $custom_cell_col=int(<STDIN>);
                        $grid[$custom_cell_row][$custom_cell_col] = 'x';
                     }
                  }
               }while($answer ne 'q' && $answer ne 'Q');
            }
         }

         sub grid_size
         {
            print "Enter number of rows: ";
            $max_row = <STDIN>;
            print "Enter number of columns: ";
            $max_column = <STDIN>;
            for($row=0; $row<$max_row; $row++)
            {        
               for($col=0; $col<$max_column; $col++)
               {
                  $grid[$row][$col] = '';
               }
            }
         }

         sub read_special_file
         {
            $row=0;
            $string = <FILE>;
            chomp $string;
            @array=split / /,$string;
            $length = $#array;
            while($row<$length)
            {
               foreach $col(0..$length)
               {
                  $grid[$row][$col]=$array[$col];
               }
               $row++;
               $string=<FILE>;
               chomp $string;
               @array=split / /,$string;
            }
            initial_condition('N');
         }
         sub neighbour
         {
            $alive = 0;
            if($grid[($_[0] + $max_row - 1) % $max_row ][$_[1] ] eq 'x')
            {
               $alive++;
            }
            if($grid[($_[0] + $max_row - 1) % $max_row ][($_[1] + $max_column - 1) % $max_column ] eq 'x')
            {
               $alive++;
            }
            if($grid[($_[0] + $max_row - 1) % $max_row ][($_[1] + $max_column + 1) % $max_column ] eq 'x')
            {
               $alive++;
            }
            if($grid[($_[0] + $max_row + 1) % $max_row ][$_[1] ] eq 'x')
            {
               $alive++;
            }
            if($grid[($_[0] + $max_row + 1) % $max_row ][($_[1] + $max_column + 1) % $max_column ] eq 'x')
            {
               $alive++;
            }
            if($grid[($_[0] + $max_row + 1) % $max_row ][($_[1] + $max_column - 1) % $max_column ] eq 'x')
            {
               $alive++;
            }
            if($grid[$_[0] ][($_[1] + $max_column - 1) % $max_column ] eq 'x')
            {
               $alive++;
            }
            if($grid[$_[0] ][($_[1] + $max_column + 1) % $max_column ] eq 'x')
            {
               $alive++;
            }
            return $alive;      
         }

         sub next_phase
         {              
            $population = 0;
            for($row = 0; $row < $max_row; $row ++)
            {
               for($column = 0; $column < $max_column; $column ++)
               {
                  if($grid[$row][$column]  eq ' ')
                  {
                     if(neighbour($row, $column) == 3)
                     {
                        $grid2[$row][$column] = 'x';
                     } 
                  }
                  if($grid[$row][$column] eq 'x')
                  {
                     if(neighbour($row, $column) < 2)
                     {
                        $grid2[$row][$column] = ' ';
                        if(neighbour($row, $column, $length) > 3)
                        {
                           $grid2[$row][$column] = ' ';
                        }
                        if(neighbour($row, $column) == 2 || neighbour($row,$column) == 3)
                        {
                           $grid2[$row][$column] = 'x';
                        }
                     }
                     if($grid2[$row][$column] eq 'x')
                     {
                        $population++;
                     }
                  }
               } 
            }
         }










https://stackoverflow.com/questions/14970397/while-loop-and-input-perl 
         while(my $var = <>){
            something($var);
         } 



         while (my $line = <STDIN>) {
            chomp $line;

# use the string comparison operator...
            last if $line eq "0";
# or use a match operator...
# last if $line =~ m/^0$/;
# or match on some special number
# last if $line == 3.1415926;

            push @stdin, $line;
         } 



         while(my $var = <>)
         {
            something($var);
         } 


         while (my $line = <STDIN>) {
            chomp $line;

# use the string comparison operator...
            last if $line eq "0";
# or use a match operator...
# last if $line =~ m/^0$/;
# or match on some special number
# last if $line == 3.1415926;

            push @stdin, $line;


https://stackoverflow.com/questions/14970397/while-loop-and-input-perl 
            while(my $var = <>){
               something($var);
            } 

         } 



