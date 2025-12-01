This is a Simple Bank Management System project written in C. It allows users to create an account, deposit money, withdraw money, check balance, and store data using file handling. This project is made for our Programming in C subject and helps understand basic concepts like functions, structures, and file operations.
algorithm 
Start
2. Display menu with options:
Create Account
Deposit Amount
Withdraw Amount
Check Balance
Exit
3. Ask the user to enter a choice
4. If choice = Create Account
Take name, account number, initial balance Store the details in file
5. If choice = Deposit Amount
Enter account number and amount
Search account in file
Add amount to balance and update file
6. If choice = Withdraw Amount
Enter account number and amount
Check if sufficient balance
Deduct amount and update file
7. If choice = Check Balance Enter account number Display the balance from file
8. If choice = Exit
Stop the program
9. If invalid choice
Show error message and repeat menu
10. End
Flowchart 
┌──────────┐
            │   Start   │
            └─────┬────┘
                  ↓
        ┌────────────────────┐
        │ Display Main Menu  │
        └─────┬──────────────┘
              ↓
      ┌────────────────┐
      │ Get User Choice│
      └───┬────────────┘
          ↓
   ┌──────────────┐
   │ Create Acc?  │── Yes ──► Enter Details → Save to File → Back to Menu
   └──────┬───────┘
          │ No
          ↓
   ┌──────────────┐
   │ Deposit?     │── Yes ──► Enter Acc No → Add Amount → Update File → Back to Menu
   └──────┬───────┘
          │ No
          ↓
   ┌──────────────┐
   │ Withdraw?    │── Yes ──► Enter Acc No → Check Balance → Deduct → Update File → Back to Menu
   └──────┬───────┘
          │ No
          ↓
   ┌──────────────┐
   │ Check Bal?   │── Yes ──► Enter Acc No → Show Balance → Back to Menu
   └──────┬───────┘
          │ No
          ↓
   ┌──────────────┐
   │ Exit?        │── Yes ──► End
   └──────┬───────┘
          │ No
          ↓
       Invalid Choice → Back to Menu
---------------------------------------
 sample output 
        BANK MANAGEMENT SYSTEM         
---------------------------------------

1. Create Account
2. Deposit Amount
3. Withdraw Amount
4. Check Balance
5. Exit

Enter your choice: 1
Enter Name: Ishani
Enter Account Number: 12345
Enter Initial Balance: 5000
Account Created Successfully!

Enter your choice: 2
Enter Account Number: 12345
Enter Amount to Deposit: 2000
Amount Deposited Successfully!

Enter your choice: 4
Enter Account Number: 12345
Current Balance: 7000

Enter your choice: 3
Enter Amount to Withdraw: 1000
Withdrawal Successful!

Enter your choice: 5
Thank you for using the Bank Management System!
