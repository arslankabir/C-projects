#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
class author
{
	public:
	char name[20];
	char email[30];
	char institute[20];
	public:
	author()
	{	strcpy(name,"");
		strcpy(email,"");
		strcpy(institute,"");
	}
	void set_Details()
	{	cout<<"\tENTER Author Name:";cin>>name;
		cout<<"\t ENTER Author Mail:";cin>>email;
		cout<<"\t  ENTER Author institute:";cin>>institute;
	}
	void Display()
	{	cout<<"\t\n Author Name:"<<name;
		cout<<"\t\n Author Mail:"<<email;
		cout<<"\t\n Author institute:"<<institute;
	}
	char* getname()
	{	return name;	}
	char* getemail()
	{	return email;	}
	char* getinstitute()
	{	return institute;	}
};
class book
{
	char Book_Name[20];
	double price;
	int Quantity;
	public:
	author n;
	void create_book()
	{	cout<<"ENTER book Name:";cin>>Book_Name;
		cout<<"ENTER book Price:";cin>>price;
		cout<<"ENTER book Quantity:";cin>>Quantity;
		n.set_Details();
	}
	char *getbookname()
	{	return Book_Name;	}
	author getauthor()
	{ 	return  n;	}
	double getprice()
	{ 	return price;       }
	int getquantity()
	{ 	return Quantity;	}
	void display()
	{	cout<<"\nbook Name:"<<Book_Name;
		cout<<"\nbook Price:"<<price;
		cout<<"\nbook Quantity:"<<Quantity;
		n.Display();
	}
	void show_books()
	{
		cout<<"\nBook Name: "<<Book_Name;
		cout<<"\nAuthor's Name: "<<n.getname();
		cout<<"\nBook Quantity: "<<Quantity;
	}
};

//**************************************************

class student_Login
{
	char ID_number[20];
	char Student_name[20];
	int books;
	public:
	void create_student()
	{
		cout<<"Enter The ID Number ";cin>>ID_number;
		cout<<"Enter The Name of The Student: ";cin>>Student_name;
		books=0;
		cout<<"\t\tStudent Record Created Successfully...\n";
	}
	void show_student()
	{
		cout<<"\nID Number: "<<ID_number;
		cout<<"\nStudent Name: ";
		cout<<"\nNo of Book issued: "<<books;
	}
	char* get_ID_number()
	{	return ID_number;	}
	char* getstname()
	{	return Student_name;	}
	int rettoken()
	{	return books;	}


};
//**************************************************
class Engineering:public book
{	int engineering_book;
	void setbooks()
	{	cout<<"Enter books:";cin>>engineering_book;	}
	int getbooks()
	{       return engineering_book;	}

};
//**************************************************
class Medical:public book
{	int m_book;
	void setbooks()
	{	cout<<"Enter books:";cin>>m_book;	}
	int getbooks()
	{       return m_book;	}

};
//**************************************************
void mmenu()
{
	clrscr();
	cout<<"\t\t\t\t*\t*";
	cout<<"\t\t\t\t**\t**";
	cout<<"\t\t\t\t***\t***";
	cout<<"\t\t\t\t****\t****";
	cout<<"\t\t\t\t*****\t*****";
	cout<<"\t\t\t\t******\t******";
	cout<<"\t\t\t\t*******\t*******";
	cout<<"\t\t\t\t*******\t*******";
	cout<<"\t\t\t\t******\t******";
	cout<<"\t\t\t\t*****\t*****";
	cout<<"\t\t\t\t****\t****";
	cout<<"\t\t\t\t***\t***";
	cout<<"\t\t\t\t**\t**";
	cout<<"\t\t\t\t*\t*";

	cout<<"\n\t\t\t*  @@@ ****** _____________ ***** @@@";
	cout<<"\n\t\t\t*  Press 1 to CREATE BOOKS";
	cout<<"\n\t\t\t*  Press 2 to DISPLAY ALL BOOKS";
	cout<<"\n\t\t\t*  Press 4 to Search SPECIFIC BOOK";
	cout<<"\n\t\t\t*  Press 5 to Create user Login";
	cout<<"\n\t\t\t*  Press 6 to Show Students Record";
	cout<<"\n\t\t\t*  Press 7 to GO BACK TO MAIN MENU";
	cout<<"\n\t\t\t*  Press 0 to Terminate MAIN MENU";
	cout<<"\n\t\t\t*  @@@ ****** _____________ ***** @@@";
}
//******************************************
void create_books()
{       clrscr();
	book b;int option;
	fstream f("Library.txt",ios::out);
	do
	{       b.create_book();
		f.write((char*)&b,sizeof(b));
		cout<<"\n\t\t\t*  @@@ ****** _____________ ***** @@@";
		cout<<"\n\t\t\t*  Press 1 to CREATE Another BOOK";
		cout<<"\n\t\t\t*  Press 0 to Enter Main menu";
		cout<<"\n\t\t\t*  @@@ ****** _____________ ***** @@@";
		cout<<"\n\t\t\t*  ENTER Option:";cin>>option;
	}while(option!=0);
}
void Display_Books()
{       clrscr();
	book b;int option;
	fstream f("Library.txt",ios::in);
	f.seekg(0);
	while(!f.eof())
	{       f.read((char*)&b,sizeof(b));
		b.display();
		cout<<"\n\t\t\t*  @@@ ****** _____________ ***** @@@";
		cout<<"\n\t\t\t*  Press 1 to get next Book";
		cout<<"\n\t\t\t*  Press 0 to Enter Main menu";
		cout<<"\n\t\t\t*  @@@ ****** _____________ ***** @@@";
		cout<<"\n\t\t\t*  ENTER Option:";cin>>option;
	}
}
void Search_Book()
{       clrscr();
	book b;int option;char bn[20];
	fstream f("Library.txt",ios::in);
	f.seekg(0);
	while(!f.eof())
	{       f.read((char*)&b,sizeof(b));
		cout<<"ENTER book name:";cin>>bn;
		if(strcmp(b.getbookname(),bn)==0)
		{	cout<<"\n\t BOOK found :)\n";
			b.display();
			cout<<"\n\t\t\t*  @@@ ****** _____________ ***** @@@";
			cout<<"\n\t\t\t*  Press 1 to get next Book";
			cout<<"\n\t\t\t*  Press 0 to Enter Main menu";
			cout<<"\n\t\t\t*  @@@ ****** _____________ ***** @@@";
			cout<<"\n\t\t\t*  ENTER Option:";cin>>option;
		}
		else
		    cout<<"\n\t Sorry BOOK not Found :( \n\nt\t You can try another one :D \n";
	}
}
void userlogin()
{       clrscr();
	student_Login s;int option;
	fstream f("studentlogin.txt",ios::out);
	do
	{       s.create_student();
		f.write((char*)&s,sizeof(s));
		cout<<"\n\t\t\t*  @@@ ****** _____________ ***** @@@";
		cout<<"\n\t\t\t*  Press 1 to CREATE another LOGin";
		cout<<"\n\t\t\t*  Press 0 to Enter Main menu";
		cout<<"\n\t\t\t*  @@@ ****** _____________ ***** @@@";
		cout<<"\n\t\t\t*  ENTER Option:";cin>>option;
	}while(option!=0);

}
void userlogindetail()
{       clrscr();
	student_Login s;int option;
	fstream f("studentlogin.txt",ios::in);
	do
	{       f.read((char*)&s,sizeof(s));
		s. show_student();
		cout<<"\n\t\t\t*  @@@ ****** _____________ ***** @@@";
		cout<<"\n\t\t\t*  Press 1 to CREATE another LOGin";
		cout<<"\n\t\t\t*  Press 0 to Enter Main menu";
		cout<<"\n\t\t\t*  @@@ ****** _____________ ***** @@@";
		cout<<"\n\t\t\t*  ENTER Option:";cin>>option;
	}while(option!=0);

}

void main()
{	clrscr();
	int option;char password,login;
	cout<<"\n\t\tLogin ID: ";cin>>login;
	cout<<"\t\tPassword: ";cin>>password;
	if(password=='*'&&login=='a')
	do
	{	mmenu();
		cout<<"\n\t\t\t*  ENTER Option:";cin>>option;
		if(option==1)
			create_books();
		if(option==2)
			Display_Books();
		if(option==4)
			Search_Book();
		if(option==5)
			userlogin();
		if(option==6)
			userlogindetail();
	}while(option!=0);
	getch();
}
