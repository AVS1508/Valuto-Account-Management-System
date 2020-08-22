# Project Title : Account Management System
# Version       : 1.1
# Developed By  : Aditya Vikram Singh
 
# Class to hold the details of items used in Transaction
class ITEM:
    ItmNo = 0
    ItmQty = 0
    ItmName = ""
    ItmCost = 0.0

# Class to represent and perform operations on Transaction
class TRANSACTION:
    TransNo = 0
    TransName = ""
    TransDate = ""
    TransValue = 0.0
    ItmTrans = []
    TransType = 0
    
    # To return Transaction Type
    def RnTransType(self):
        return self.TransType
    
    # To return Transaction Number
    def RnTransNo(self):
        return self.TransNo
    
    # To change Transaction Number
    def CgTransNo(self, TNo):
        self.TransNo = TNo
        
    # To change Transaction Name
    def CgTransName(self, TName):
        self.TransName = TName

    # To change Transaction Date
    def CgTransDate(self, TDate):
        self.TransDate = TDate
        
    # TRANSACTION member function to input the details of a transaction
    def InputTrans(self, Opt, ItmList):
        print("1. Sources or Funds received ")
        print("2. Terminals or Funds spent ")
        print("Enter the transaction type(1/2): ", end='')
        self.TransType = int(input());

        print("Enter the transaction details.")
        print("Enter the transaction number: ", end='')
        self.TransNo = int(input());
        print("Enter the transaction name/purpose: ", end='')
        self.TransName = input();
        print("Enter the transaction date: ", end='')
        self.TransDate = input();

        print("1. Input Transaction Worth ")
        print("2. Input Items with respective Worths ")
        print("Choose from the above(1/2): ", end='')
        Opt = int(input());
        
        if Opt == 1:
            print("Enter the transaction value: ", end='')
            self.TransValue = float(input())
        elif Opt == 2:
            print("Enter the transaction items:- ")
            I = 0;
            Ch = 'Y';
            self.TransValue = 0;
            while True:
                self.InputItem(self.ItmTrans[I])
                self.TransValue = self.TransValue + (self.ItmTrans[I].ItmQty) * (self.ItmTrans[I].ItmCost)
                I = I + 1
                print("Another item(Y/N)? ", end='')
                Ch = str(input())
                if not (Ch == "N" or I >= 20):
                    break
            self.ItmList = I;
            
        print("Transaction details saved.")
        return Opt, ItmList
    
    # TRANSACTION member function to commit the transaction to the budget    
    def CommitTrans(self, Budget, Income, Expenditure):
        if self.TransType == 1:
            Budget = Budget + self.TransValue
            Income = Income + self.TransValue
        else:
            Budget = Budget - self.TransValue
            Expenditure = Expenditure + self.TransValue
        return Budget, Income, Expenditure
    
    # TRANSACTION member function to display the details of a transaction
    def DisplayTrans(self, Opt, ItmList):
        if self.TransType == 1:
            print("Transaction type: Sources or Funds received")
        elif self.TransType == 2:
            print("Transaction type: Terminals or Funds spent")
        else:
            print("Transaction type: Error - Unknown Type")
        
        print("Transaction number: " + str(self.TransNo))
        print("Transaction name/purpose: " + str(self.TransName))
        print("Transaction date: " + str(self.TransDate))
        print("Transaction value: " + str(self.TransValue))
        
        if Opt == 2:
            for I in range(ItmList):
                self.DisplayItem(self.ItmTrans[I])
        
        print("Transaction details shown.")
    
    # TRANSACTION member function to input an item's details
    def InputItem(self, Itm):
        Itm = ITEM() 
        print("Enter the item number: ", end='')
        Itm.ItmNo = input()
        print("Enter the item name: ", end='')
        Itm.ItmNane = input()
        print("Enter the item quantity: ", end='')
        Itm.ItmQty = input()
        print("Enter the item cost: ", end='')
        Itm.ItmCost = input()
    
    # TRANSACTION member function to display an item's details
    def DisplayItem(self, Itm):
        print("Item number: " + str(Itm.ItmNo))
        print("Item name: " + str(Itm.ItmName))
        print("Item quantity: " + str(Itm.ItmQty))
        print("Item cost: " + str(Itm.ItmCost))

# Main Function
def main():
    # Variables referenced to obtain important account information.
    Budget, Income, Expenditure = 0
    # Variables used as return parameters for Transactions
    Opt, ItmList = 0
    # Variables used for Sub-menu choices
    Access, Process, Toggle = ""
    
    Accountants = {
        "Raj": "Raj01",
        "Shashank": "Sha12",
        "Vibhor": "Vib23",
        "Ajay": "Aja34",
        "Rahul": "Rah45",
        "Preeti": "Pre56",
        "Sunita": "Sun67",
        "Pramila": "Pra78",
        "Nishika": "Nis89",
        "Ranjani": "Ran90"
    }
    
    Login(Accountants, Access)
    
    if Access == 1:
        # Administrator Access - Can read and write data
        while True:
            print("Welcome, Administrator! Please select the desired option: ")
            print("1. Enter Initial Account Details ")
            print("2. Enter Transactions History ")
            print("3. Display Transactions History - Detailed Account Statement ")
            print("4. Commit Current Transactions to Budget, Expenditure and Income ")
            print("5. Display Budget, Income & Expenditure only ")
            print("6. Modify Transaction details ")
            print("7. Display Accountants' Details ")
            print("8. Exit the Application ")
            print("Choose as 1/2/3/4/5/6/7/8: ", end='')
            Process = int(input())
            SubMenu(Process, Access, Toggle, Budget, Income, Expenditure, Opt, ItmList, Accountants)
            if Toggle == 'N':
                break
    else:
        # Accountant Access - Can read data/cannot write
        while True:
            print("Welcome, Accountant! Please select the desired option: ")
            print("1. Display Transactions History - Detailed Account Statement ")
            print("2. Display Budget, Income & Expenditure only ")
            print("3. Display Accountants ")
            print("4. Exit the Application ")
            print("Choose as 1/2/3/4: ")
            Process = int(input())
            SubMenu(Process, Access, Toggle, Budget, Income, Expenditure, Opt, ItmList, Accountants)
            if Toggle == 'N':
                break

# Display the sub-menu for the different access levels
def SubMenu(Process, Access, Toggle, Budget, Income, Expenditure, Opt, ItmList, Accountants):
    if Access == 1:
        if Process == 1:
            InitialiseAccount(Budget, Income, Expenditure)
        elif Process == 2:
            CreateTransactions(Opt, ItmList)
        elif Process == 3:
            DisplayTransactions(Opt, ItmList)
        elif Process == 4:
            CarryOutTransactions(Budget, Income, Expenditure)
        elif Process == 5:
            ShowAccount(Budget, Income, Expenditure)
        elif Process == 6:
            ModifyTransactions()
        elif Process == 7:
            DisplayAccountants(Accountants, 1)
        else:
            Toggle = 'N';
            print("Exiting...")
    else:
        if Process == 1:
            DisplayTransactions(Opt, ItmList)
        elif Process == 2:
            ShowAccount(Budget, Income, Expenditure)
        elif Process == 3:
            DisplayAccountants(Accountants, 2)
        else:
            Toggle = 'N';
            print("Exiting...")

# Initialise the important account details like Budget, Income and Expenditure
def InitialiseAccount(Budget, Income, Expenditure):
    ACC = open('ACCDET.bin', 'wb')
    print("Initialisation of Account")
    print("Enter the current budget: ", end='')
    Budget = float(input())
    ACC.write(bytearray(Budget))
    print("Enter the current income: ", end='')
    Income = float(input())
    ACC.write(bytearray(Income))
    print("Enter the current expenditure: ", end='')
    Expenditure = float(input())
    ACC.write(bytearray(Expenditure))
    return Budget, Income, Expenditure

if __name__ == '__main__':
    main()