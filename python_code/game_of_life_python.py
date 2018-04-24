import time
import os

#variables declaration
file_input_ns = [] # input file without spacebar
final = [] # input file with spacebar
generation = 0
ms = 0 # delay time
size = [0,0] # size of input [rows, columns]
all_array = [] # record all of the previous iteration
population_count_array = [] # record all of the previous population count

#Function definition
def print_generation_population(generation,population_cnt):
    print("Generation {}".format(generation))
    print("Population {}".format(population_cnt))

def pause():
    raw_input("Press enter to continue")

def delay(ms):
    time.sleep(float(ms)/1000.0)
    
def population(current_array,size_row,size_col):
    cnt=0
    #local Row
    for i in range(size_row):
        for j in range(size_col):
            if(current_array[i][j]=="0"):
                cnt+=1
    population_count_array.append(cnt)
    return cnt 

def format_grid(current_array):
    num_row = 0
    for x in current_array:
        num_col = 0
        for y in x:
            current_array[num_row][num_col] = remain_same(y)
            num_col += 1
        num_row += 1
    return current_array

def remain_same(curr_state):
    if(curr_state == "" or curr_state == " "):
        return(" ")
    elif(curr_state == "0"):
        return("0")
    else:
        print("Error")
        
def get_file(name):
    try:
        with open(name) as f:
            file_input = f.readlines()  
    except IOError:
            print("Error opening file")
#Remove \n
    for x in file_input:
        x = x.replace("\n","").replace("@","").replace(" ","")
        file_input_ns.append(x)    

    for y in file_input_ns:
        k = y.split(",")
        final.append(k)
    return (final)

def remove_additional_split(current_array):
    current_array.pop(-1)
    for x in current_array:
        x.pop(-1)
    return current_array

def get_size(current_array,size):
    size[0] = len(current_array)
    size[1] = len(current_array[0])
    return(size)

def clear(size_row,size_col):
    return([[" " for x in range(size_col)]for y in range(size_row)])

def output(current_array):
    for i in current_array:
        for x in i:
	    print(x),
        print("\n")
        
def wrap_around_row(l_row):
    if(l_row == size_row-1):
        return(0)
    else:
        return (l_row+1)
    
def wrap_around_col(l_col):
    if(l_col == size_col-1):
        return(0)
    else:
        return (l_col+1)

#Check presence of life in neighbours (8 direction)
def check_neighbour(current_array,my_coordinate,grid_mode,check_array):
    count = 0
    #Local Row
    l_row = my_coordinate[0]
    #Local Column
    l_col = my_coordinate[1]
#Right
    #Check top right
    if(check_array[0]==1 and current_array[l_row-1][wrap_around_col(l_col)] == "0"):
        count += 1
    #Check right
    if(check_array[1] == 1 and current_array[l_row][wrap_around_col(l_col)] == "0"):
        count += 1
    #Check bottom right
    if(check_array[2] == 1 and current_array[wrap_around_row(l_row)][wrap_around_col(l_col)] == "0"):
        count +=1
#Up and down
    if(check_array[3] == 1 and current_array[l_row-1][l_col] == "0"):
        count +=1
    if(check_array[4] == 1 and current_array[wrap_around_row(l_row)][l_col] == "0"):
        count +=1
#Left
    #Check top left
    if(check_array[5] == 1 and current_array[l_row-1][l_col-1] == "0"):
        count += 1
    #Check left
    if(check_array[6] == 1 and current_array[l_row][l_col-1] == "0"):
        count += 1
    #Check bottom left
    if(check_array[7] == 1 and current_array[wrap_around_row(l_row)][l_col-1] == "0"):
        count +=1
    return count

#Topology = 1, wrap around
#Topology = 2, closed grid
#check_array is to select which neighbour to evaluate.
#format for check_array : [top right, right, bottom right, top, bottom, top left, left, bottom left]
def select_topology(current_array,my_coordinate,grid_mode):
    check_array = []
    count = 0
    l_row = my_coordinate[0]
    l_col = my_coordinate[1]
    
    if(grid_mode == "1"):
        check_array = [1,1,1,1,1,1,1,1]
        count = check_neighbour(current_array,my_coordinate,grid_mode,check_array)
        return count
    elif(grid_mode == "2"):
        check_array = check_closed_arr(check_array,l_row,l_col)
        count = check_neighbour(current_array,my_coordinate,grid_mode,check_array)
        return count

#When the topology is closed grid, check neighbours inside the closed grid only.
#Ignore the neighbours outside the closed grid.
def check_closed_arr(check_array,l_row,l_col):
#Vertical
    if(l_col != 0 and l_col != size_col-1 and l_row == 0):
    #Top
        return([0,1,1,0,1,0,1,1])
    #Bottom
    elif(l_col != 0 and l_col != size_col-1 and l_row == size_row-1):
        return([1,1,0,1,0,1,1,0])

#Horizontal
    elif(l_row != 0 and l_row != size_row-1 and l_col == 0):
    #Left    
        return([1,1,1,1,1,0,0,0])
    #Right
    elif(l_row != 0 and l_row != size_row-1 and l_col == size_col-1):
        return([0,0,0,1,1,1,1,1])
    elif(l_row == 0 and l_col == 0):
        return([0,1,1,0,1,0,0,0])
    elif(l_row == 0 and l_col == size_col-1):
        return([0,0,0,0,1,0,1,1])
    elif(l_row == size_row-1 and l_col == 0):
        return([1,1,0,1,0,0,0,0])
    elif(l_row == size_row-1 and l_col == size_col-1):
        return([0,0,0,1,0,1,1,0])
    else:
        return([1,1,1,1,1,1,1,1])

def lod(count, curr_state): # determine whether the cell will live or die
    if(count <= 1):
        return (" ")
    elif(count == 2):
        return (remain_same(curr_state))
    elif(count == 3):
        return ("0")
    elif(count > 3):
        return (" ")
    else:
        print("Error in live")

#Simulation mode = 1, continuous mode
#Simulation mode = 2, Pause-stop mode
def select_simulation_mode(simu_mode,ms):
    if(simulation_mode == "1"):
       delay(ms)
    elif(simulation_mode == "2"):
       pause()

#Input
grid_mode = raw_input("Please choose a topology\n1.Wrap Around 2.Closed \n")
while(grid_mode!='1' and grid_mode!='2'):
    print("Invalid!Please enter again \n")
    grid_mode=raw_input("Please choose a topology\n1.Wrap Around 2.Closed\n") 
cycle = input("Please key in the cycle \n")
cycle = int(cycle)
name = raw_input("Please input the file name with directory\n")
simulation_mode = raw_input("Please choose a simulation mode\n1.Continuous 2.Pause Stop Mode \n")

while(simulation_mode != "1" and simulation_mode != "2"):
    simulation_mode = raw_input("Please choose a simulation mode\n1.Continuous 2.Pause Stop Mode \n Invalid! Please Enter Again\n")
if(simulation_mode == "1"):
    ms = input("Please key in the delay (ms)\n")
    ms = float(ms)
current_array = get_file(name)
current_array = remove_additional_split(current_array)
current_array = format_grid(current_array)
size = get_size(current_array,size)
size_row = size[0]
size_col = size[1]
next_arr = [[" " for x in range(size_col)]for y in range(size_row)]
num_row = 0
num_col = 0
os.system('cls' if os.name == 'nt' else 'clear' )

#Initial output
population_count=population(current_array,size_row,size_col)
all_array.append(current_array)
output(current_array)
print_generation_population(generation,population_count)
select_simulation_mode(simulation_mode,ms)
os.system('cls' if os.name == 'nt' else 'clear')

#Start Iteration
for x in range(cycle):
    num_row =0
    for row in current_array:
        num_col = 0 
        for column in row:
            my_coordinate = [num_row,num_col]
            count = select_topology(current_array,my_coordinate,grid_mode) 
            curr_state = current_array[num_row][num_col]
            #Determine live or dead on current coordinate
            live = lod(count,curr_state)
            #Write on next grid using the given result
            next_arr[num_row][num_col] = live
            num_col +=1
        num_row +=1
    generation += 1

#Output for next grid
    output(next_arr)
    if(next_arr == current_array):
        print("Life stop growing")
        break
    current_array = next_arr
    all_array.append(current_array)
    population_count = population(current_array,size_row,size_col)
    print_generation_population(generation,population_count)
    next_arr = clear(size_row,size_col)
    select_simulation_mode(simulation_mode,ms)
    os.system('cls' if os.name == 'nt' else 'clear' )

choice = raw_input("Do u want to review the result?(Y/y=yes N/n=no)\n")
while(choice!='y' and choice=='Y' and choice=='N' and choice=='n'):
     choice=raw_input("Invalid!Please enter again=)\nDo u want to loop again?(Y/y/N/n)\n")

generation = 0
if(choice=='y' or choice=='Y'):
        for x in all_array:
	    output(all_array[generation])
            print("Generation {}".format(generation))
            print("Population {}".format(population_count_array[generation]))
	    generation += 1    
            
            select_simulation_mode(simulation_mode,ms)


