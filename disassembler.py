
def disassemble(operation_code):
    
    strcode= str(operation_code)
    if strcode[:3]== "90":
        result = "INP"

    else if strcode[0]== "1" :
        result = "ADD" + strcode[0]
    else if strcode[0]== "2" :
        result = "SUB"+ strcode[0]
    else if strcode[0]== "3" :
        result = "STA" + strcode[0]
    else if strcode[0]== "5" :
        result = "LDA" + strcode[0]
    else if strcode[0]== "6" :
        result = "BRA" + strcode[0]
    else if strcode[0]== "7" :
        result = "BRZ" + strcode[0]
    else if strcode[0]== "8" :
        result = "BRP" + strcode[0]


    return result

    
def main():
    codelst= []
                
    codeinput=int(input("Please enter the operation code: " ))

   
    while codeinput!= 000 :
        result= disassemble(codeinput)
        codelst.append(result)
        codeinput=int(input("Please enter the operation code: " )

    for item in codelst:
            print item
                                
                  
                  
main()
