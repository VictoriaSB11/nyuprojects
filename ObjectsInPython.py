
#Short intro to using objects in Python

class BankAccount(object):
    def __init__(self,accountnum,balance):
        self.account_number = accountnum
        self.account_balance = balance

    def withdraw(self,x):
        if (float(self.account_balance) - x) < 0:
            print("Insufficient funds")
        else:
            self.account_balance = float(self.account_balance) - x
    
    def deposit(self,x):
        self.account_balance = float(self.account_balance) + x

    def get_balance(self):
        return float(self.account_balance)

def main():
    my_account = BankAccount("B0A123",1000)
    
    print("Current balnce is: ", my_account.get_balance())
    my_account.deposit(100)
    print("Current balance is: ", my_account.get_balance())
    my_account.withdraw(500)
    print("Current balance is:", my_account.get_balance())
    my_account.withdraw(1000)
    
main()
