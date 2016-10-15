
# Victoria Spann-Burton
# Operation code to mnemonic dictionary
# You can use this to lookup the machine code
# and translate it to the mnemonic instruction

def disassemble(op_code,lmc_dict):
    
    for code in op_code:
        
        if(int(code) == 901):
            print(lmc_dict[901])
            
        elif(int(code) == 902):
            print(lmc_dict[902])
            
        elif(int(code) == 000):
            print(lmc_dict[0])
            break
        
        else:
            num = code[0]
            machine = int(num)
            mailbox = code[1:]
            
            for key in lmc_dict:
                if(machine != 0 and machine == key):
                    print(lmc_dict[key] + " " + mailbox)               
            
def main():
    
    lmc_dict = {
    0: "HLT",
    1: "ADD",
    2: "SUB",
    3: "STA",
    5: "LDA",
    6: "BRA",
    7: "BRZ",
    8: "BRP",
    901: "INP",
    902: "OUT"
}
    op_code = []
    keep_going = True
    
    while(keep_going == True):
        code = input("Enter a string of operation code, enter 'Done' when you have written all the code: ")
        if(code.lower() == 'done'):
            keep_going = False
        else:
            op_code.append(code)

    print("LMC Mneumonic Instructions/n")

    disassemble(op_code,lmc_dict)
        

main()
