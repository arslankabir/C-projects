#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
struct td
{
	char book_id[10];
	char book_name[10];
	char auther[10];
	int book_price;
}t[50];
void entry();
void srchby_id();
void srchby_name();
void view_record();
int main()
{
	double choice,l;
	cout<<"\t\tTELEPHONE DIRECTORY\n\n";
	for(l=0;l<4;l++)
	{
	cout<<"press 1 for entry:\n";
	cout<<"press 2 for search by BOOK ID:\n";
	cout<<"press 3 for search by name:\n";
	cout<<"press 4 for view all record:\n\n";
	cout<<"ENTER YOUR CHOICE: \n";
	cin>>choice;
	if(choice==1)
	entry();
	else if(choice==2)
	srchby_id();
	else if(choice==3)
	srchby_name();
	else if(choice==4)
	view_record();
	else
	 cout<<"YOU ENTER INVALID CHOICE\n";
}
	getch();
	return 0;
}
void entry()
{
	int a,i=0;
	for(a=0;a<2;a++)
	{
		cout<<"RECORD OF BOOK "<<i+1<<endl;
	cout<<"enter the name of the book"<<endl;
	cin.ignore(1);
	gets(t[a].book_name);
	cout<<"enter the id of the book"<<endl;
	gets(t[a].book_id);
	cout<<"enter the auther name of the book"<<endl;
	gets(t[a].auther);
	cout<<"enter the price of the book"<<endl;
	cin>>t[a].book_price;
	i++;
}
}
void srchby_name()
{
	char srch[10];
	int j,b=0;
	cout<<"enter the name of the book you want to srch"<<endl;
	cin.ignore(1);
	gets(srch);
	for(j=0;j<3;j++)
	 if(strcmp(t[j].book_name,srch)==0)
	{
		cout<<"the name of the book = "<<t[j].book_name<<endl;
	cout<<"the id of the book = "<<t[j].book_id<<endl;
	cout<<"the auther name of the book = "<<t[j].auther<<endl;
	cout<<"the price of the book = "<<t[j].book_price;
	b++;
}
if(b==0)
cout<<"invalid choice";
}
void srchby_id()
{
	int d=0,k;
	char c[10];
	cout<<"enter the book id you want to search"<<endl;
	cin.ignore(1);
	gets(c);
	for(k=0;k<3;k++)
	 if(strcmp(t[k].book_id,c)==0)
	{
		cout<<"the name of the book = "<<t[k].book_name<<endl;
	cout<<"the id of the book = "<<t[k].book_id<<endl;
	cout<<"the auther name of the book = "<<t[k].auther<<endl;
	cout<<"the price of the book = "<<t[k].book_price;
	d++;
}
if(d==0)
cout<<"invalid choice";
	
}
void view_record()
{
	int n,m=0;
	for(n=0;n<3;n++)
	{
		cout<<"the name of the book = "<<t[n].book_name<<endl;
	cout<<"the id of the book = "<<t[n].book_id<<endl;
	cout<<"the auther name of the book = "<<t[n].auther<<endl;
	cout<<"the price of the book = "<<t[n].book_price<<endl;
}
}
