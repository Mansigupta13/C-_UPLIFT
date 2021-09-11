#include<iostream>
#include<string>
using namespace std;

class atm									
{
private:										
	long int account;
	string name;
	int pin;
	double balance;
	string mobileno;

public:										


	void data(long int acc, string n, int p , double bal, string mobno)
	{
		account = acc;	
		name = n;
	    pin = p;
		balance = bal;
		mobileno = mobno;
	}
	long int get_account()
	{
		return account;
	}

	int get_pin()
	{
		return pin ;
	}

	double get_balance()
	{
		return balance;
	}
	
	string get_name()
	{
		return name;
	}

	string get_mobileno()
	{
		return mobileno;
	}

	void changemobile(string oldmob, string newmob)		
	{
		if (oldmob == mobileno)					
		{
			mobileno = newmob;						
			cout << endl << "Sucessfully Updated Mobile no.";
		}

		else
		{
			cout << endl << "Incorrect Old Mobile no";
		}
	}

	void cash(int amount)
	{
		if (amount > 0 && amount < balance)		
		{
			balance -= amount;	
			cout << endl << "Please Collect Your Cash";
			cout << endl << "Available Balance :" << balance<<endl;
		}

		else
		{
			cout << endl << "Invalid Input or Insufficient Balance";
		
		}
	}

};

int main()
{
	int ch = 0,enpin;
	long int enaccno;
	
	atm client1;
	client1.data(11002233456, "Manish kumar", 1453, 45000.90, "90873344321");


	do
	{

		cout << endl << "----------------Welcome to ATM-----------" << endl;
		cout << endl << "Enter Account Number:";	 
		cin >> enaccno;
		cout << endl << "Enter PIN :";				 
		cin >> enpin;
		if ((enaccno == client1.get_account()) && (enpin == client1.get_pin()))
		{
			do
			{
				int amount = 0;
				string oldmobno, newmobno;

				cout << endl << "**** Welcome to ATM *****" << endl;
				cout << endl << "Press 1:Check Balance";
				cout << endl << "Press 2:Cash withdraw";
				cout << endl << "Press 3:Show User Details";
				cout << endl << "Press 4:Update Mobile no.";
				cout << endl << "Press 5:Exit" << endl;
				cin >> ch;						
				switch (ch)					
				{
				case 1:								
					cout << endl << "Your Bank balance is :" << client1.get_balance()<<endl;
					break;


				case 2:								
					cout << endl << "Enter the amount to be withdrawn :";		
					cin >> amount;
					client1.cash(amount);		
					break;


				case 3:								
					cout << endl << "*** User Details ***";
					cout << endl << "Account no:" << client1.get_account();
					cout << endl << "Name:" <<client1.get_name();
					cout << endl << "Balance:" << client1.get_balance();
					cout << endl << "Mobile No.:" << client1.get_mobileno();
					break;


				case 4:								   
					cout << endl << "Enter Old Mobile No. ";
					cin >> oldmobno;							

					cout << endl << "Enter New Mobile No. ";
					cin >> newmobno;							

					client1.changemobile(oldmobno, newmobno);
					break;

													
				case 5:
					exit(0);						

				default:						
					cout << endl << "Enter Valid Data !!!";
				} 

			} while (1);			
		}

		else
		{
			cout << endl << "User Details are Invalid !!! ";
	
		}
	} while (1);					

	return 0;
}

