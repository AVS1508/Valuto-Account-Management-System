/*
Project Title : Account Management System
Version       : 1.1
Developed By  : Aditya Vikram Singh
*/
    
// Header Files
#include <fstream.h>  // For file handling operations, i/o operations
#include <conio.h>    // For clrscr() and getch() functions
#include <stdio.h>    // For gets() function to input strings
#include <iomanip.h>  // For setw() function to format outputs
#include <string.h>   // For strings operations

// Structures

// Structure to hold Username and Password of a User Account
struct ACCOUNT
{
    char Username[20], Password[20];
};

// Structure to hold the details of items used in Transaction
struct ITEM
{
    int ItmNo, ItmQty;
    char ItmName[40];
    float ItmCost;
};

// Classes

// Class to represent and perform operations on Transaction
class TRANSACTION
{
    long int TransNo;
    char TransName[40], TransDate[15];
    float TransValue;
    ITEM ItmTrans[20];
    int TransType;

public:

    void InputTrans(int &Opt, int &ItmList);

    void CommitTrans(float &Budget, float &Income, float &Expenditure);

    void DisplayTrans(int Opt, int ItmList);

    void InputItem(ITEM I);

    void DisplayItem(ITEM I);

    int RnTransType() //To return Transaction Type
    {
        return TransType;
    }

    long int RnTransNo() //To return Transaction Number
    {
        return TransNo;
    }

    void CgTransNo(long int TNo) //To change Transaction Number
    {
        TransNo=TNo;
    }

    void CgTransName(char* TName) //To change Transaction Name
    {
        strcpy(TName,TransName);
    }

    void CgTransDate(char* TDate) //To change Transaction Date
    {
        strcpy(TDate,TransDate);
    }

};

// TRANSACTION member function to input the details of a transaction
void TRANSACTION::InputTrans(int &Opt, int &ItmList)
{
    cout<<"1. Sources or Funds received "<<endl;
    cout<<"2. Terminals or Funds spent "<<endl;
    cout<<"Enter the transaction type(1/2): ";cin>>TransType;

    cout<<"Enter the transaction details."<<endl;
    cout<<"Enter the transaction number: "; cin>>TransNo;
    cout<<"Enter the transaction name/purpose: "; gets(TransName);
    cout<<"Enter the transaction date: "; gets(TransDate);

    cout<<"1. Input Transaction Worth "<<endl;
    cout<<"2. Input Items with respective Worths "<<endl;
    cout<<"Choose from the above(1/2): ";cin>>Opt;

    switch(Opt)
    {
    case 1:
            cout<<"Enter the transaction value: "; cin>>TransValue;
            break;
    case 2:
            cout<<"Enter the transaction items:- "<<endl;
            int I=0; char Ch='Y'; TransValue=0;
            do
            {
                InputItem(ItmTrans[I]);
                TransValue+=((ItmTrans[I].ItmQty)*(ItmTrans[I].ItmCost));
                I++;
                cout<<"Another item(Y/N)?";cin>>Ch;
            }while(Ch!='N' && I<20);
            ItmList=I;
            break;
    }
    cout<<"Transaction details saved."<<endl;
}

// TRANSACTION member function to commit the transaction to the budget
void TRANSACTION::CommitTrans(float &Budget, float &Income, float &Expenditure)
{
    switch(TransType)
    {
    case 1:
            Budget+=TransValue;
            Income+=TransValue;
            break;
    case 2:
            Budget-=TransValue;
            Expenditure+=TransValue;
            break;
    }
}

// TRANSACTION member function to display the details of a transaction
void TRANSACTION::DisplayTrans(int Opt, int ItmList)
{
    if(TransType==1)
        cout<<"Transaction type: Sources or Funds received"<<endl;
    else if(TransType==2)
        cout<<"Transaction type: Terminals or Funds spent"<<endl;
    else
        cout<<"Transaction type: Error-Unknown Type"<<endl;

    cout<<"Transaction number: "<<TransNo<<endl;
    cout<<"Transaction name/purpose: "<<TransName<<endl;
    cout<<"Transaction date: "<<TransDate<<endl;
    cout<<"Transaction value: "<<TransValue<<endl;

    if(Opt==2)
        for(int I=0; I<ItmList; I++)
            DisplayItem(ItmTrans[I]);

    cout<<"Transaction details shown."<<endl;
}

// TRANSACTION member function to input an item's details
void TRANSACTION::InputItem(ITEM I) 
{
    cout<<"Enter the item number: "; cin>>I.ItmNo;
    cout<<"Enter the item name: "; gets(I.ItmName);
    cout<<"Enter the item quantity: "; cin>>I.ItmQty;
    cout<<"Enter the item cost: "; cin>>I.ItmCost;
}

// TRANSACTION member function to display an item's details
void TRANSACTION::DisplayItem(ITEM I) 
{
    cout<<"Item number: "<<I.ItmNo<<endl;
    cout<<"Item name: "<<I.ItmName<<endl;
    cout<<"Item quantity: "<<I.ItmQty<<endl;
    cout<<"Item cost: "<<I.ItmCost<<endl;
}


// Function Prototypes
void SubMenu(int, int, char &, float &, float &, 
             float &, int &, int &, ACCOUNT []);
void InitialiseAccount(float &, float &, float &);
void ShowAccount(float, float, float);
void CreateTransactions(int &, int &);
void DisplayTransactions(int, int);
void CarryOutTransactions(float &, float &, float &);
void ModifyTransactions();
void DisplayAccountants(ACCOUNT [], int);
void Login(ACCOUNT [], int &);
void Encrypt(char []);

// Main Function
void main()
{
    clrscr();
    
    // Variables referenced to obtain important account information.
    float Budget=0, Income=0, Expenditure=0;

    // Empty variables used as referenced parameters for Transactions.
    int Opt, ItmList;

    // Variables used for Sub-menu choices
    int Access, Process; char Toggle='Y';
    
    ACCOUNT Accountants[10]=
    {
        {"Raj","Raj01"},
        {"Shashank","Sha12"},
        {"Vibhor","Vib23"},
        {"Ajay","Aja34"},
        {"Rahul","Rah45"},
        {"Preeti","Pre56"},
        {"Sunita","Sun67"},
        {"Pramila","Pra78"},
        {"Nishika","Nis89"},
        {"Ranjani","Ran90"}
    };
    Login(Accountants,Access);
    
    switch(Access)
    {
    //Administrator Access - Can read and write data
    case 1:
        do
        {
            cout<<endl;
            cout<<"Welcome, Administrator!";
            cout<<"Please select the desired option: "<<endl;
            cout<<"1. Enter Initial Account Details"<<endl;
            cout<<"2. Enter Transactions History "<<endl;
            cout<<"3. Display Transactions History -";
            cout<<"Detailed Account Statement "<<endl;
            cout<<"4. Commit Current Transactions to Budget,";
            cout<<"Expenditure and Income "<<endl;
            cout<<"5. Display Budget, Income & Expenditure only"<<endl;
            cout<<"6. Modify Transaction details "<<endl;
            cout<<"7. Display Accountants' Details"<<endl;
            cout<<"8. Exit the Application"<<endl;
            cout<<"Choose as 1/2/3/4/5/6/7/8: ";cin>>Process;
            SubMenu(Process,Access,Toggle,Budget,Income,
                    Expenditure,Opt,ItmList,Accountants);
        }while(Toggle!='N');
        break;
    
    //Accountant Access - Can read data/cannot write
    case 2:
        do
        {
            cout<<endl;
            cout<<"Welcome, Accountant!";
            cout<<"Please select the desired option: "<<endl;
            cout<<"1. Display Transactions History";
            cout<<"Detailed Account Statement "<<endl;
            cout<<"2. Display Budget, Income & Expenditure only"<<endl;
            cout<<"3. Display Accountants"<<endl;
            cout<<"4. Exit the Application"<<endl;
            cout<<"Choose as 1/2/3/4: ";cin>>Process;
            SubMenu(Process,Access,Toggle,Budget,Income,
                    Expenditure,Opt,ItmList,Accountants);
        }while(Toggle!='N');
        break;
    }
    getch();
}

// Function Definitions

//Display the sub-menu for the different access levels
void SubMenu(int Process, int Access, char &Toggle, float &Budget, float &Income,      
             float &Expenditure, int &Opt, int &ItmList, ACCOUNT Accountants[])
{
    if(Access==1)
        switch(Process)
        {
        case 1:
                InitialiseAccount(Budget, Income, Expenditure);
                break;
        case 2:
                CreateTransactions(Opt, ItmList);
                break;
        case 3:
                DisplayTransactions(Opt, ItmList);
                break;
        case 4:
                CarryOutTransactions(Budget, Income, Expenditure);
                break;
        case 5:
                ShowAccount(Budget, Income, Expenditure);
                break;
        case 6:
                ModifyTransactions();
                break;
        case 7:
                DisplayAccountants(Accountants, 1);
                break;
        case 8:
                Toggle='N';
                cout<<"Exiting..."<<endl;
                break;
        }
   
    else if(Access==2)
        switch(Process)
        {
        case 1:
                DisplayTransactions(Opt, ItmList);
                break;
        case 2:
                ShowAccount(Budget, Income, Expenditure);
                break;
        case 3:
                DisplayAccountants(Accountants, 2);
                break;
        case 4:
                Toggle='N';
                cout<<"Exiting..."<<endl;
                break;
        }
}

// Initialise the important account details like Budget, Income and Expenditure
void InitialiseAccount(float &Budget, float &Income, float &Expenditure)
{
    fstream ACC;
    //Overwriting for Account Details.
    ACC.open("ACCDET.DAT", ios::binary|ios::out);
    
    cout<<endl;
    cout<<"Initialisation of Account"<<endl;
    
    cout<<"Enter the current budget: "; cin>>Budget;
    ACC.write((char*)&Budget, sizeof(Budget));
    
    cout<<"Enter the current income: "; cin>>Income;
    ACC.write((char*)&Income, sizeof(Income));
    
    cout<<"Enter the current expenditure: "; cin>>Expenditure;
    ACC.write((char*)&Expenditure, sizeof(Expenditure));
    
    cout<<endl;
    ACC.close();
}

// Show the important account details like Budget, Income and Expenditure
void ShowAccount(float Budget, float Income, float Expenditure)
{
    fstream ACC;
    ACC.open("ACCDET.DAT", ios::binary|ios::in);
    
    cout<<endl;
    cout<<"Statement of Account"<<endl;
    
    ACC.read((char*)&Budget, sizeof(Budget));
    cout<<"Current budget: "<<Budget<<endl;
    
    ACC.read((char*)&Income, sizeof(Income));
    cout<<"Current income: "<<Income<<endl;
    
    ACC.read((char*)&Expenditure, sizeof(Expenditure));
    cout<<"Current expenditure: "<<Expenditure<<endl;
    
    cout<<endl;
    ACC.close();
}

// Create transactions and store these on file
void CreateTransactions(int &Opt, int &ItmList)
{
    fstream F;
    //Opening in Append mode to avoid over-writing existing records.
    F.open("CMPNYACC.DAT", ios::binary|ios::app);
    
    TRANSACTION T; char Ch='Y';
    
    do
    {
        T.InputTrans(Opt, ItmList);
        F.write((char*)&T, sizeof(T));
        cout<<"More transactions(Y/N)? ";
        cin>>Ch;
    }while(Ch!='N');
    
    F.close();
}

// Display all the transactions stored on file
void DisplayTransactions(int Opt, int ItmList)
{
    fstream F;
    F.open("CMPNYACC.DAT", ios::binary|ios::in);
    
    TRANSACTION T;
    
    while(F.read((char*)&T, sizeof(T)))
    {
        T.DisplayTrans(Opt, ItmList);
        cout<<endl;
    }
    
    F.close();
}

// Commit the transaction value to Budget, Income and Expenditure
void CarryOutTransactions(float &Budget, float &Income, float &Expenditure) 
{
    fstream F,ACC;
    F.open("CMPNYACC.DAT", ios::binary|ios::out|ios::in);
    ACC.open("ACCDET.DAT", ios::binary|ios::out);
    
    TRANSACTION T;
    
    while(F.read((char*)&T, sizeof(T)))
        T.CommitTrans(Budget, Income, Expenditure);
    
    ACC.write((char*)&Budget, sizeof(Budget));
    ACC.write((char*)&Income, sizeof(Income));
    ACC.write((char*)&Expenditure, sizeof(Expenditure));
    
    F.close();
    ACC.close();
}

// Modify Transaction Number/Name/Date
void ModifyTransactions() 
{
    fstream F;
    F.open("CMPNYACC.DAT", ios::binary|ios::out|ios::in);
    
    TRANSACTION T; 
    long int TNo; char Toggle;
    long int NewTNo; char NewTName[20], NewTDate[20];
    
    cout<<"Enter the Transaction Number of the record to be modified: ";
    cin>>TNo;
    while(F.read((char*)&T, sizeof(T)))
    {
        if(TNo==T.RnTransNo())
        {
            F.seekp(F.tellg()-sizeof(T));
            
            cout<<"Enter the changes to be made:- "<<endl;
            
            cout<<"Transaction Number(Y/N)? "; cin>>Toggle;
            if (Toggle=='Y')
            {
                cout<<"Enter the new Transaction Number: "; cin>>NewTNo;
                T.CgTransNo(NewTNo);
            }
            cout<<"Transaction Name(Y/N)? "; cin>>Toggle;
            if (Toggle=='Y')
            {
                cout<<"Enter the new Transaction Name: "; gets(NewTName);
                T.CgTransName(NewTName);
            }
            cout<<"Transaction Date(Y/N)? "; cin>>Toggle;
            if (Toggle=='Y')
            {
                cout<<"Enter the new Transaction Date: "; gets(NewTDate);
                T.CgTransDate(NewTDate);
            }
            
            F.write((char*)&T, sizeof(T));
            cout<<endl;
        }
    }
    F.close();
}

// Display the Usernames and Passwords (only Admin access) of the Accountants
void DisplayAccountants(ACCOUNT A[], int Access)
{
    cout<<endl; int I;
    switch(Access)
    {
    case 1:
            cout<<setw(25)<<"Accountant"<<setw(25)<<"Username";
            cout<<setw(25)<<"Password"<<endl;
            for(I=0; I<10; I++)
            {
                cout<<setw(22)<<"Accountant"<<setw(3)<<I+1;
                cout<<setw(25)<<A[I].Username<<setw(25)<<A[I].Password;
                cout<<endl;
            }
            break;
    case 2:
            cout<<setw(25)<<"Accountant"<<setw(25)<<"Username"<<endl;
            for(I=0; I<10; I++)
            {
                cout<<setw(22)<<"Accountant"<<setw(3)<<I+1;
                cout<<setw(25)<<A[I].Username;
                cout<<endl;
            }
            break;
    }
    cout<<endl;
}

// Login as Administrator or Accountant as two different access levels
void Login(ACCOUNT DB[], int &Access)
{
    int acnt;
    char usrnm[20], pswrd[20];
    
    cout<<"1. Administrator Access"<<endl;
    cout<<"2. Accountant Access"<<endl;
    
    cout<<"Please select your access level(1/2):";
    do{cin>>acnt;}while(acnt!=1 && acnt!=2);
    
    switch(acnt)
    {
    case 1:
            cout<<"Administrator Access"<<endl;
            int CorrectU1=1;
            
            //Loop for Username Entry
            do
            {
                cout<<"Enter the administrator username: "; cin>>usrnm;
                if(strcmp(usrnm,"Admin"))
                {
                    cout<<"Wrong Username. Please try again!"<<endl;
                    CorrectU1=0;
                }
                else 
                    CorrectU1=1;
                
            }while(!CorrectU1);
            
            int Counter1=5, CorrectP1=1;
            
            //Loop for Password Entry
            do
            {
                cout<<"Enter the administrator password: "; Encrypt(pswrd);
                if(strcmp(pswrd,"Admin123"))
                {
                    cout<<endl<<"Wrong Password. Please try again!"<<endl;
                    CorrectP1=0;
                }
                else 
                    CorrectP1=1;
                
                Counter1--;
                
                if(!Counter1) 
                    cout<<"5 wrong tries! Access denied!";
                
                if(CorrectP1) 
                    Access=1;
                
            }while(!CorrectP1 && Counter1);
            break;

    case 2:
            cout<<"Accountant Access"<<endl;
            int CorrectU2=0;
            
            //Loop for Username Entry
            do
            {
                cout<<"Enter the accountant username: "; cin>>usrnm;
                for(int I=0; I<10; I++)
                    if(strcmp(usrnm,DB[I].Username)==0)
                    {
                        CorrectU2=1; break;
                    }
                
            }while(!CorrectU2);
            
            int Counter2=5, CorrectP2=0;
            
            //Loop for Password Entry
            do
            {
                cout<<"Enter the accountant password: "; Encrypt(pswrd);
                for(int I=0; I<10; I++)
                    if(strcmp(pswrd,DB[I].Password)==0)
                    {
                        CorrectP2=1;
                        Access=2;
                        break;
                    }
                
                if(!CorrectP2)
                {
                    Counter2--;
                    cout<<endl<<"Wrong Password. Please try again!"<<endl;
                }
                
                if(!Counter2)
                    cout<<"5 wrong tries! Access denied!";
                
            }while(!CorrectP2 && Counter2);
            break;
    }
}

// To encrypt the password entered with asterisks
void Encrypt(char Password[20]) 
{
    char CH;
    for(int I=0; I<20; I++)
    {
        Password[I]=getch();
        if (Password[I]==13||Password[I]==32)
        {
            Password[I]='\0';
            break;
        }
        else
            cout<<"*";
    }
}
