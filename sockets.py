import socket
import sys

#Testing a connection with sockets, receiving data, reading data and sending data/answers to conversion questions

try:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
except socket.error:
    print("Failed to create socket")
    sys.exit()
print("Sockets created")
s.connect(("128.238.66.83", 8888))
print("Socket connected")

def convert(num,base):
    ans = 0
    if(base == 2):
        ans = bin(int(num))
    elif(base == 16):
        ans = hex(int(num))
    elif(base == 10):
        ans = int(num)
    return ans

def receive():
    
    data = s.recv(2048)
    data = data.decode("utf-8")
    print(data)
    for pos in range(len(data)):
        if(data[pos:pos+7] == "Convert"):
            lst = data.split('(')
            for x in range(len(lst[1])):
                if lst[1][x] == ')':
                    num = lst[1][:x]
            base = lst[2].replace(")","")
            ans = convert(num,int(base))
            return ans
        if(data[pos:pos+3] == "How"):
            return "Salsaman"
def main():
    while True:
        ans = receive()
        print(ans)
        s.send(bytes(str(ans)+'\n','utf-8'))
        if(ans == "Yuh dunz it!!"):
            break
 

main()

    
