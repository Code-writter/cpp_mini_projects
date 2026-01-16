#include<bits/stdc++.h>
#include<conio.h>
#include<string>
#include<iostream>
using namespace std;

/*
Mini ATM Project
 -> Check Balance
 -> Cash withdraw
 -> User Details
 -> Update Mobile Number
*/


class ATM                                   // Class ATM
{
    private:
        long int account_No;
        string name;
        int PIN;
        double balance;
        string mobile_No;

    public:
    
    // setData is setting data in into the private member variables
    void setData(long int account_No_a, string name_a, int PIN_a, double balance_a, string mobile_No_a)
    {
        account_No = account_No_a;
        name = name_a;
        PIN = PIN_a;
        balance = balance_a;
        mobile_No = mobile_No_a;
    }

    // getAccountNo is returning the user's account no.
    long int getAccountNo(){
        return account_No;
    }

    // getName is returning the user's name
    string getName(){
        return name;
    }

    // getPIN is returning the user's PIN
    int getPIN(){
        return PIN;
    }

    // getBalance returning the user's Bank balance
    double getBalance(){
        return balance;
    }

    // getMobileNo is returning the user's mobile No
    string getMobileNo(){
        return mobile_No;
    }

    // Member Functions

    // setMobile
    void setMobile(string mob_prev, string mob_new){
        // check old mobile number 
        if (mob_prev == mobile_No){
            mobile_No = mob_new;

            cout<<endl<<"Successfully Updated Mobile Number :-) ";
            _getch();
        }else{
            cout<<endl<<"Incorrect !!! Old mobile Number :-( ";
            _getch();
        }
    }

    // CashWithdraw
    void cashWithDraw(int amount_a){
        // check amount entered is valid or not
        if(amount_a > 0 && amount_a < balance){
            balance = balance - amount_a;

            cout<<endl<<"Please collect the cash :-) ";
            cout<<endl<<"Available balance : "<<balance;
            _getch();
        }
        else{
            cout<<endl<<"Invalid Input or Insufficient Balance :-(";
            _getch();
        }
    }
    
};

int main(){

    int choice = 0;
    // For Authentication
    int enterPIN;
    long int enterAccountNo;

    system("cls");

    // create user obj
    ATM user1;
    // set user details into the object
    user1.setData(
        1234567,
        "Tim",
        1111,
        45000,
        "9087654321"
    );

    do{
        system("cls");

        cout<<endl<<"*** Welcome to ATM ***"<<endl;
        cout<<endl<<"Enter Your Account No : ";
        cin>>enterAccountNo;

        cout <<endl <<"Enter PIN : ";
        cin>>enterPIN;

        // Authenticate 
        // check wheater the given details are correct or not
        if(
            (enterAccountNo == user1.getAccountNo()) && (enterPIN == user1.getPIN())
        ){
            do{
                int amount = 0;
                string oldMobileNo, newMobileNo;

                system("cls");

                // user Interface
                cout<<endl<<"*** Welcome to ATM ***"<<endl;
                cout<<endl<<"Select Options";
                cout<<endl<<"1. Check Balance";
                cout<<endl<<"2. Cash Withdraw";
                cout<<endl<<"3. Show User Details";
                cout<<endl<<"4. Update Mobile No.";
                cout<<endl<<"5. Exit"<<endl;

                cin>>choice;

                switch(choice)
                {
                    case 1:
                        cout<<endl<<"Your Bank Balance is : "<<user1.getBalance();
                        _getch();
                        break;

                    case 2:
                        cout<<endl<<"Enter the amount : ";
                        cin>>amount;
                        user1.cashWithDraw(amount);

                        break;

                    case 3:
                        cout<<endl<<"*** User Details are ***";
                        cout<<endl <<"Account Number : "<<user1.getAccountNo();
                        cout<<endl <<"Name : "<<user1.getName();
                        cout<<endl <<"Balance : "<<user1.getBalance();
                        cout<<endl <<"Mobile Number : "<<user1.getMobileNo();

                        _getch();
                        break;
                    case 4:
                        cout<<endl<<"Enter Old Mobile Number : ";
                        cin>>oldMobileNo;

                        cout<<endl<<"Enter New Mobile Number : ";
                        cin>>newMobileNo;

                        user1.setMobile(oldMobileNo, newMobileNo);
                        break;

                    case 5:
                        exit(0);
                    
                    default:
                        cout<<endl<<"Enter Valid Data !!! ";
                }

            }while(1);
        }
        else{
            cout<<endl<<"User details are Invalid !!!";
            _getch();
        }

    }while(1);

    return 0;
}