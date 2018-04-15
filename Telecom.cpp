#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<fstream>
using namespace std;

class display
{
	public:
	void main_menu()
	{
		system("cls");
		cout<<"-----------------TeleCom Billing System-----------------"<<endl;
		cout<<"\t\t 1.Show Record"<<endl;
		cout<<"\t\t 2.Add Record"<<endl;
		cout<<"\t\t 3.Exit"<<endl;	
		cout<<"\n\n\t\t Enter your choice.. ";
	}
};

class record:public display
{
	int choice;
	public:
	void switch_menu();
	void srecord();
	void arecord();
};

void record::arecord()
{
	char name[20];
	int time ,t_bill ;
	ofstream file;
	file.open("telecom.txt",ios::in|ios::ate);
	cout<<"Enter the Name : ";
	cin>>name;
	cout<<"Enter the Call timing in minutes. CHARGES - (2 rs. per min) : ";
	cin>>time;
	t_bill= 2*time;
	file<<name<<"\t"<<time<<"\t\t"<<t_bill<<"\n";
	cout<<"Data saved successfully.."<<endl;
	file.close();
	getchar();
	getchar();
	main_menu();
}

void record::srecord()
{
	 ifstream fin;
     fin.open("telecom.txt");
     char ch;
     while(fin)
     {
          fin.get(ch);
          cout<<ch;
     }
    fin.close();
	getchar();
	getchar();
	main_menu();

}

void record::switch_menu()
{
	cin>>choice;
		switch(choice)
		{
			case 1:
				{
					srecord();
					main_menu();
					switch_menu();
					break;
				}
			case 2:
				{
					arecord();
					main_menu();
					switch_menu();
					break;
				}
			case 3:
				{
					exit(1);
					break;
				}
			default :
				{
					system("cls");
					cout<<"\n\n\n\n\t\t\t You have entered wrong choice..."<<endl;
					cout<<"Pease enter the correct choice..."<<endl;
					main_menu();
				}
		}
}

int main()
{
	record obj1;
	obj1.main_menu();
	obj1.switch_menu();
	return 0;
}
