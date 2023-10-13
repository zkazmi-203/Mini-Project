#include<iostream>
#include<vector>
using namespace std;
/* Banking System */
class Account{
	int accountNumber;
	float accountBalance;
	string accountHolderName;
	int user_cnic;
	public:
		int static totalAccounts;
		int static accountID;
	
	Account(){
		accountNumber = 0;
		accountBalance = 0;
		accountHolderName = "";
	}

	
	void openAccount(string name,int cnic){
		accountHolderName = name;
		user_cnic = cnic;
		cout<<"Your Account has been successfully created!!!!"<<endl;
		totalAccounts++;
		++accountNumber;
	}
	
	void deposit(){
		float balance;
		cout<<"Enter Your Amount"<<endl;
		cin>>balance;
		accountBalance = accountBalance + balance;
		cout<<"Your Account Balance is: "<<accountBalance<<endl;
	}
	
		void withdraw(){
		float withdraw;
		cout<<"Enter Your Amount"<<endl;
		cin>>withdraw;
		accountBalance = accountBalance - withdraw;
		cout<<"Your Remaining Account Balance is: "<<accountBalance<<endl;
	}
		
		
	void deleteAccount(){
		accountBalance = 0;
		totalAccounts--;
		cout<<"Your Account Has Been Closed!!!!";
		
	}
	
	int static getTotalAccounts(){
		return totalAccounts;
	}	
	
	friend void displayInformation(const Account& acc);
	
	
};

   int Account :: totalAccounts = 0;
   int Account :: accountID = 1000;

	void displayInformation(const Account& acc){
		cout<<"Account Number is: "<<acc.accountNumber<<endl;
		cout<<"Account Balance is: "<<acc.accountBalance<<endl;
		cout<<"Account Holder Name is: "<<acc.accountHolderName<<endl;
		cout<<"Your CNIC is: "<<acc.user_cnic<<endl;
	}



int main(){
	int operation;
Account Account1;
	while(true){
	cout<<"Choose from below:"<<endl;
	cout<<"1.Open Account"<<endl;
	cout<<"2.Deposit Money"<<endl;
	cout<<"3.Withdraw"<<endl;
	cout<<"4.Display Information"<<endl;
	cout<<"5.Close Account"<<endl;
	cout<<"6.Exit"<<endl;
	cin>>operation;
	
				
	if(operation == 6){
		break;
	}
	else if(operation == 1){
		string name;
		int id;
				cout<<"Enter Your Name"<<endl;
				cin>>name;
				cout<<"Enter CNIC"<<endl;
				cin>>id;
				Account1.openAccount(name,id);
				
	}
		else if(operation == 2){
		Account1.deposit();
	}
		else if(operation == 3){
		Account1.withdraw();
	}
		else if(operation == 4){
		displayInformation(Account1);
	}
		else if(operation == 5){
		Account1.deleteAccount();
		
	}
	
		}
}
