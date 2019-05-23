# Account-Management-System

## About the System 

This project is based on the system of account management and financial statement maintenance. The purpose of the accounting management system is to maintain a record of the funds received, used, disseminated and donated by an organisation. Details of transactions and maintenance of a budget and tallying of current balance/inventory in cash/kind is incorporated in this system. 

The system requires the user to have the appropriate credentials i.e. Administrator or Accountant rights. Depending on the access authority, a menu of possible actions is displayed and each option leads to a function that performs the desired operations on binary files through the use of objects of relevant class. 

The features and functionality of the system are as follows:

- Login Interface (bifurcates into Administrator and Accountant access levels)
- Access level as Administrator or Superuser
- Access level as one of the 10 predefined Accountants

- Administrator Panel/Menu:
  - Enter Initial Account Details
  - Enter Transactions History 
  - Display Transactions History - Detailed Account Statement 
  - Commit Current Transactions to Budget, Expenditure and Income 
  - Display Budget, Income & Expenditure only
  - Modify Transaction details
  - Display Accountants' Details
  - Exit the Application

- Accountant Panel/Menu:
  - Display Transactions History - Detailed Account Statement 
  - Display Budget, Income & Expenditure only
  - Display Accountants
  - Exit the Application

## About the Program Implementation

The system has been implemented through the use of various programming constructs and methods. It follows the concept of Object-Oriented Programming through the use of Classes and Objects to create a class to define the properties of transactions. The concept of File Handling through the use of binary files, is incorporated to create and maintain a record of the transactions that take place. Comments are present throughout the program to indicate the functions and needs of each component of the system. The system makes full use of the concepts taught in Computer Science in class XI and XII, to ensure clarity and good organisation of the program.

The program includes two structures, ACCOUNT and ITEM, and a class TRANSACTION. ACCOUNT structure is used for representing an individual accountant’s login credentials i.e. Username and Password. ITEM structure represents the details of any commodity/item that is purchased or sold by the company. The class TRANSACTION is used for representing the details of each financial transaction for the company and for performing operations on that transaction. All the transactions are stored in a binary file, CMPNYACC.DAT, in the form of objects of the class which are appended, to maintain records of previous transactions as well. The company’s initial funds and expenditures are stored in another binary file, ACCDET.DAT, for cross-checking and maintaining a record of the account balance. 
