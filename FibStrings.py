#Problem1
#Fibonacci Sequence
def fib(n): #returns the n-th item of the Fibonacci sequence
    first = 0 #corner cases
    second = 1
    num = 0
    for x in range(2,n): #the fibonacci sequence
        num = first + second 
        first = second
        second = num
    return(num)
    
def fib2(): #interacts with the user to find nth number of fibonacci sequence       
    n = int(input("Please enter a number:"))
    if n == 1: #corner case
        result = '0'
        print("The 1st number in the Fibonacci sequence is:", result)
    elif n == 2: #corner case
        result = '1'
        print("The 2nd number in the Fibonacci squence is:", reuslt)
    else:
        print("The", n,"number in the Fibonacci sequence is:")
        print(fib(n)) #uses another function to return output

def fib3(): #prints entire fibonacci sequence in a range
    i = int(input("Please enter a number:")) 
    if i >= 1:
        print('0')
    if i >= 2:
        print('1')
    for x in range(3,i+1): #for loop, accessing another function to return each number in the range
        print(fib(x))
        
fib2()
fib3()

#Problem2
#Manipulating Strings
string = input("Please enter a DNA string:")
substring = input("Please enter the sequence you are trying to locate:")
start = int(input("Enter the first bound of the range:"))
end = int(input("Enter the second bound of the range:"))

def dna(string, substring, start, end): #returns the first index of the substring you are trying to locate
    newstr = string[start:end+1] #new string based on range given by the user
    n = len(substring) #assigns length to a variable
    for x in range(end + 1): #for loop in the range 
        if substring == newstr[x:x+n]:
            return(x)
    else:
        print("-1")

def multi_dna(string, substring, start, end): #returns all indices of the substring you are trying to locate
    newstr = string[start:end+1]
    n = len(substring)
    location = ''
    for x in range(end + 1):
        if substring == newstr[x:x+n]:
            location = location + str(x) + " "
    return location
    
def main():
    print(dna(string, substring, start, end))
    print(multi_dna(string, substring, start, end))
                    
main()
            
            
            
                    
            

