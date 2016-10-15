'''

Victoria Spann-Burton
CS 1114
N11325501

The purpose of this program is to clean out weather data, create a new file that converts that weather data to metric values, and then calculate and compare average rainfall of the cities
'''


# Part A
def clean_data(complete_weather_filename, cleaned_weather_filename):
    file1 = open(complete_weather_filename,"r")
    file2 = open(cleaned_weather_filename,"w")
    line1 = file1.readline()
    lst1 = line1.split(",")
    string1 = ''
    file2.write(string1 + lst1[0] + ',' + lst1[1] + ',' + lst1[2] + ',' + lst1[3] + "," + lst1[8] + "\n")
    index = 1
    for line in file1:
        if index%2 == 0:
            lst = line.split(",")
            string = ''
            if lst[8] == 'T':
                precip = '0'
            else:
                precip = str(lst[8])
            string = string + lst[0] + "," +lst[1] + "," + lst[2] + "," + lst[3] +"," + precip
            file2.write(string + '\n')
        index += 1
    file1.close()
    file2.close()

        
    
    # Complete this function to clean the CSV.
    # It should create a new file as specified in the assignment specs.
    

#Part B
def f_to_c(f_temperature):
    celsius = (f_temperature - 32) * (5/9)
    celsius = format(celsius,".2f")
    return str(celsius) # modify this

def in_to_cm(inches):
    cm = (inches*2.54)
    cm = format(cm,".2f")
    return str(cm) # modify this

def convert_data_to_metric(imperial_weather_filename, metric_weather_filename):
    file1 = open(imperial_weather_filename,"r")
    file2 = open(metric_weather_filename,"w")
    header = file1.readline()
    file2.write(header + "\n")
    for line in file1:
        lst = line.split(",")
        string = ''
        string = string + lst[0] + ',' + lst[1] + ',' + f_to_c(int(lst[2])) + ',' + f_to_c(int(lst[3])) + ',' + in_to_cm(float(lst[4]))
        file2.write(string + '\n')
        
    file1.close()
    file2.close()
    # Similar to clean_data() - read in the file and make a new file with metric values.

#Part C
def print_average_per_month(city, weather_filename, unit_type):
    file = open(weather_filename,"r")
    header = file.readline()
    jan = [0,0,0]
    feb = [0,0,0]
    mar = [0,0,0]
    apr = [0,0,0]
    may = [0,0,0]
    jun = [0,0,0]
    jul = [0,0,0]
    aug = [0,0,0]
    sep = [0,0,0]
    octo = [0,0,0]
    nov = [0,0,0]
    dec = [0,0,0]
    counter = 0
    for line in file:
        #print(counter)
        if line != '\n':
            
            lists = line.split(',')
            fileCity = lists[0]
            date = lists[1]
            high = lists[2]
            low = lists[3]
            counter += 1
            monthList = date.split('/')
            if fileCity == city:
                if monthList[0] == "1":
                    jan[0] += float(high)
                    jan[1]+= float(low)
                    jan[2] +=1 
                if monthList[0] == "2":
                    feb[0] += float(high)
                    feb[1]+= float(low)
                    feb[2]+=1
                if monthList[0] == "3":
                    mar[0] += float(high)
                    mar[1]+= float(low)
                    mar[2] +=1
                if monthList[0] == "4":
                    apr[0] += float(high)
                    apr[1]+= float(low)
                    apr[2] +=1
                if monthList[0] == "5":
                    may[0] += float(high)
                    may[1]+= float(low)
                    may[2] +=1
                if monthList[0] == "6":
                    jun[0] += float(high)
                    jun[1]+= float(low)
                    jun[2] +=1
                if monthList[0] == "7":
                    jul[0] += float(high)
                    jul[1]+= float(low)
                    jul[2] +=1
                if monthList[0] == "8":
                    aug[0] += float(high)
                    aug[1]+= float(low)
                    aug[2] += 1
                if monthList[0] == "9":
                    sep[0] += float(high)
                    sep[1]+= float(low)
                    sep[2] += 1
                if monthList[0] == "10":
                    octo[0] += float(high)
                    octo[1]+= float(low)
                    octo[2] += 1
                if monthList[0] == "11":
                    nov[0] += float(high)
                    nov[1]+= float(low)
                    nov[2] += 1
                if monthList[0] == "12":
                    dec[0] += float(high)
                    dec[1]+= float(low)
                    dec[2] += 1
    months = ["January", "February", "March", "April","May", "June", "July","August","September", "October", "November", "December"] 
    #print here
    print("Average temperatures for:", city)
    if unit_type == "imperial":
        temp = "F"
    elif unit_type == "metric":
        temp = "C"
    index = 1
    for month in months:
        if index == 1:
            print(month + ": " + str(round(jan[0]/jan[2],2)) + temp + " High " + str(round(jan[1]/jan[2])) + temp + " Low")
        if index == 2:
            print(month + ": " + str(round(feb[0]/feb[2],2)) + temp + " High " + str(round(feb[1]/feb[2])) + temp + " Low")
        if index == 3:
            print(month + ": " + str(round(mar[0]/mar[2],2)) + temp + " High " + str(round(mar[1]/mar[2])) + temp + " Low")
        if index == 4:
            print(month + ": " + str(round(apr[0]/apr[2],2)) + temp + " High " + str(round(apr[1]/apr[2])) + temp + " Low")
        if index == 5:
            print(month + ": " + str(round(may[0]/may[2],2)) + temp + " High " + str(round(may[1]/may[2])) + temp + " Low")
        if index == 6:
            print(month + ": " + str(round(jun[0]/jun[2],2)) + temp + " High " + str(round(jun[1]/jun[2])) + temp + " Low")
        if index == 7:
            print(month + ": " + str(round(jul[0]/jul[2],2)) + temp + " High " + str(round(jul[1]/jul[2])) + temp + " Low")
        if index == 8:
            print(month + ": " + str(round(aug[0]/aug[2],2)) + temp + " High " + str(round(aug[1]/aug[2])) + temp + " Low")
        if index == 9:
            print(month + ": " + str(round(sep[0]/sep[2],2)) + temp + " High " + str(round(sep[1]/sep[2])) + temp + " Low")
        if index == 10:
            print(month + ": " + str(round(octo[0]/octo[2],2)) + temp + " High " + str(round(octo[1]/octo[2])) + temp + " Low")
        if index == 11:
            print(month + ": " + str(round(nov[0]/nov[2],2)) + temp + " High " + str(round(nov[1]/nov[2])) + temp + " Low")
        if index == 12:
            print(month + ": " + str(round(dec[0]/dec[2],2)) + temp + " High " + str(round(dec[1]/dec[2])) + temp + " Low")

        index += 1
    file.close()
       
    # prints average highs and lows in each month for the given city


#Part D
def avg_rainfall(city1, city2, weatherfilename):
    file = open(weatherfilename,"r")
    header = file.readline()
    total1 = 0
    total2 = 0
    days1 = 0
    days2 = 0
    for line in file:
        lst = line.split(",")
        lst_city = lst[0]
        if city1 == lst_city:
            total1 += float(lst[4])
            days1 += 1
        elif city2 == lst_city:
            total2 += float(lst[4])
            days2 += 1
    avg_city1 = round(total1/days1,2)
    avg_city2 = round(total2/days2,2)

    if avg_city1 > avg_city2:
        print("The average rainfall of",city1,avg_city1,"is greater than the average rainfall of",city2,avg_city2)
    elif avg_city2 > avg_city1:
        print("The average rainfall of",city2,avg_city2,"is greater than the average rainfall of",city1,avg_city1)
    
#Write your question (as a comment), and implement a function to answer it



def main():
    print ("Running Part A")
    clean_data("weather.csv", "weather in imperial.csv")

    print ("Running Part B")
    convert_data_to_metric("weather in imperial.csv", "weather in metric.csv")

    print ("Running Part C")
    print_average_per_month("San Francisco", "weather in imperial.csv", "imperial")
    print_average_per_month("New York", "weather in metric.csv", "metric")
    print_average_per_month("San Jose", "weather in imperial.csv", "imperial")

    print ("Running Part D")
    city1 = input("Enter the name of a city:")
    city2 = input("Enter the name of another city:")
    filename = input("Would you like the data to be imperial or metric?")
    
    if filename == "imperial" or "Imperial":
        avg_rainfall(city1,city2,"weather in imperial.csv")
        
    elif filename == "metric" or "Metric":
        avg_rainfall(city1,city2,"weather in metric.csv")
    

    
main()
