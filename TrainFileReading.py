'''Victoria Spann-Burton
This program prints the stops for each train line by reading data from a file'''

def main():
    filename = "train stop data-Mac.csv"
    clean_filename = "clean train stop data.csv"
    clean_file(filename, clean_filename)
    train_lines = get_trainline(clean_filename)
    dict_train_stops = dict_trainstops(clean_filename)

    keep_going = True
    while keep_going:
        train_line = input("Enter the train line to find the stops or 'Done' to stop:")
        if train_line.lower() == "done":
            keep_going = False
        else:
            print(train_line,"line:")
            string = ''
            for stop in dict_train_stops[train_line]:
                string = string + stop + " , "
            print(string)
                   

def clean_file(filename, clean_filename):
    file1 = open(filename,"r")
    file2 = open(clean_filename,"w")

    index = 1
    for line in file1:
        string = ''
        lst = line.split(",")
        if index == 1:
            string = string + "Train Line" + "," + "Stop Name"
            file2.write(string + '\n')
        else:
            string = string + lst[0][0] + "," + lst[2]
            file2.write(string + '\n')
        index += 1
    file1.close()
    file2.close()

def get_trainline(filename):
    file = open(filename,"r")
    train_lines = []
    header = file.readline()
    for line in file:
        lst = line.split(",")
        train_lines.append(lst[0])
    clean_trainlines = set(train_lines)
    lst_clean_trainlines = list(clean_trainlines)
    file.close()
    return lst_clean_trainlines

def dict_trainstops(filename):
    file = open(filename,"r")
    header = file.readline()
    train_stops = []
    train_stops_per_line = {}
    lst = file.readline().split(",")
    train_line = lst[0]
    lst_of_lsts = []
    for line in file:
        lst = line.strip().split(",")
        if lst[0] == train_line:
             train_stops.append(lst[1])
        else:
            clean_stops = set(train_stops)
            train_stops_per_line[train_line] = list(clean_stops)
            train_line = lst[0]
            train_stops = []
    file.close()
    return train_stops_per_line
            
    
main()
