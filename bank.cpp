#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
int k=0;
class bank
{
	char name[50];
	char balance[50];
	char account[50];
	char phone[50];
	public:
		void entry();
		void view();
		void by_name();
}s1[3];
int main()
{
	int i,choice;
	cout<<"Press 1 for enter record: "<<endl;
	cout<<"Press 2 for view record: "<<endl;
	cout<<"Press 3 for search by name: "<<endl;
	for(i=0;i<3;i++)
	{
		cout<<"Enter your choice 1,2,3"<<endl;
		cin>>choice;
		if(choice==1)
		s1[i].entry();
		else if(choice==2)
		s1[i].view();
		else if(choice==3)
		s1[i].by_name();
		else
		cout<<"Invalid choice: ";
	}
}
	void bank::entry(){
		int a,b=0;
		for(a=0;a<=2;a++)
		{
		cout<<"THE RECORD OF CUSTOMER "<<b+1<<endl;
		cout<<"enter the name of the customer: "<<endl;
		cin.ignore(1);
		gets(s1[a].name);
		cout<<"enter the blnce: "<<endl;
		gets(s1[a].balance);
		cout<<"enter the account number:"<<endl;
		gets(s1[a].account);
		cout<<"enter the phone num of the customer: "<<endl;
		gets(s1[a].phone);
		b++;	
		}
	}
	void bank::view()
	{
		int k;
		for(k=0;k<=3;k++)
		{
		cout<<s1[k].name<<endl;
		cout<<s1[k].balance<<endl;
		cout<<s1[k].account<<endl;
		cout<<s1[k].phone<<endl;
	}
	}
	void bank::by_name()
	{
		int c,y=0;
		char search[50];
		cout<<"Enter the name you want to search: "<<endl;
	    cin.ignore(1); 
		gets(search);
		for(c=0;c<=3;c++){
		if(strcmp(search,s1[c].name)==0)
		{
		cout<<s1[c].name<<endl;
		cout<<s1[c].balance<<endl;
		cout<<s1[c].account<<endl;
		cout<<s1[c].phone<<endl;
		y++;
		}
		
	}
	if(y==0)
		{
			cout<<"Sorry its invalid:"<<endl;
		}
	}
	

