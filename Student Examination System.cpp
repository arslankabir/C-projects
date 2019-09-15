#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
int totalstudents=0;
class exam
{
	private:
	short roomno;
	char *subjectcode,*examdate,*examstarttime,*examinername;
	public:
	exam()
	{
		subjectcode = new char[3000];
		examdate = new char[3000];
		examstarttime = new char[3000];
		examinername = new char[3000];
	}
	void info()
	{
		system("cls");
		cout<<"Please Enter Examination Details\n";
		cout<<"Enter Room.No\n";
		cin>>roomno;
		cout<<"Enter Subject Code\n";
		cin.ignore();
		gets(subjectcode);
		cout<<"Enter Exam Date (Format dd/mm/year)\n";
		gets(examdate);
		cout<<"Enter Exam start Time (Format hh:mm)\n";
		gets(examstarttime);
		cout<<"Enter Examiner Name\n";
		gets(examinername);	
	}
	void details()
	{
		system("cls");
		cout<<"Examination Details Are given Below\n";
		cout<<"Room Number\n";
		cout<<roomno<<endl;
		cout<<"Subject Code\n";
		puts(subjectcode);
		cout<<"Exam Date\n";
		puts(examdate);
		cout<<"Exam Starting time\n";
		puts(examstarttime);
		cout<<"Examiner Name\n";
		puts(examinername);
	}
};
class student
{
	private:
	int x;
    int studentrollno[10];
	char *studentname[10];
	public:
	student()
	{
		x=0;
		for(int k=0;k<10;k++)
		{
		studentname[k]=new char[50];
		studentrollno[k]=-1;
	    }
	}
	void entry()
	{
		x++;
		system("cls");
		cout<<"Maximum You can Enter 10 student Per row\n";
		if(x<10)
		{
			cout<<"Enter roll.no of "<<x<<" student\n";
			cin>>studentrollno[x];
			cin.ignore(1);
			cout<<"Enter Name of"<<x<<" student\n";
			gets(studentname[x]);
		}
		
    }
    void insertionatlast()
    {
    	system("cls");
    	cout<<"Enter Student Toll No\n";
    	cin>>studentrollno[9];
    	cout<<"Enter Student Name\n";
    	gets(studentname[9]);
	}
	void specificposition()
	{
		system("cls");
		int pos,to;
		cout<<"Enter position at Which you want to insert record\n";
		cin>>pos;
		for(int k=0;k<10;k++)
		{
		if(studentrollno[k]==-1)
		{
			to=k;
			break;
		}
	    }
		while(to>pos)
		{
			studentrollno[to]=studentrollno[to-1];
			studentname[to]=studentname[to-1];
			to--;
		}
    	cout<<"Enter Student Toll No\n";
    	cin>>studentrollno[pos];
    	cout<<"Enter Student Name\n";
    	cin.ignore();
    	gets(studentname[pos]);
	}
	int search(short roll)
	{
		int res=0;
		for(int k=0;k<10;k++)
		{
			if(roll==studentrollno[k])
			{
				cout<<"Result Found\n";
				cout<<"Student Roll no\n";
				cout<<studentrollno[k]<<endl;
				cout<<"Student Name\n";
				puts(studentname[k]);
				res=1;
				break;
			}
		}
		if(res==1)
		return 1;
		else
		return 0;
	}
	int deletion(short roll)
	{
		system("cls");
		int res=0;
		for(int k=0;k<10;k++)
		{
			if(roll==studentrollno[k])
			{
				for(int j=k;j<10;j++)
				{
				studentrollno[j]=studentrollno[j+1];
				studentname[j]=studentname[j+1];
		    	}
		    	res=1;
		    	break;
			}
		}
		if(res==1)
		return 1;
		else
		return 0;
	}
	int update(short roll)
	{
		system("cls");
		int res=0;
		for(int k=0;k<10;k++)
		{
			if(roll==studentrollno[k])
			{
				cout<<"Enter New Rollno\n";
				cin>>studentrollno[k];
				cout<<"Enter New Name of Student\n";
				cin.ignore();
				gets(studentname[k]);
				res=1;
		    	break;
			}
		}
		if(res==1)
		return 1;
		else
		return 0;
	}
    
};
int main()
{
	exam e;
	student all[10];
	int  ch=1;
	while(1)
	{
	cout<<"Enter Your choice \n";
	cout<<" enter 1 for entry \n";
    cout<<"enter 2 for insertion at last \n";
    cout<<" enter 3 to add a student at specific position\n";
    cout<<"enter 4 search a student\n";
    cout<<"enter 5 to delete a student\n";
    cout<<"enter 6 to show total student\n";
    cout<<"enter 7 to enter Examination Information\n";
    cout<<" enter 8 to Show examination Details\n";
    cout<<"enter 9 to Update Record\n";
    cout<<" enter 10 to exit\n";
    int op;
    cin>>op;
    switch(op)
    {
    	case 1:
    		{
    			cout<<"Enter Number of Row in which you want to Add student\n";
    			int l;
    			cin>>l;
    			all[l].entry();
    			break;
			}
		case 2:
    		{
    			cout<<"Enter Number of Row in which you want to Add student at last\n";
    			int l;
    			cin>>l;
    			all[l].insertionatlast();
    			break;
			}
		case 3:
    		{
    			cout<<"Enter Number of Row in which you want to Add student at specific position\n";
    			int l;
    			cin>>l;
    			all[l].specificposition();
    			break;
			}
		case 4:
    		{
    			system("cls");
    			int res,row;
    			cout<<"Enter Roll number to search\n";
    			short rn;
    			cin>>rn;
    			cin.ignore(1);
    			for(int k=0;k<10;k++)
    			{
    				res=all[k].search(rn);
    				if(res==1)
    				{
    					row=k;
    					break;
					}
				}
				if(res==1)
				cout<<"Row number is\n"<<row<<endl;
				else
				cout<<"result not found\n";
				break;
			}
		case 5:
    		{
    			system("cls");
    			int res;
    			cout<<"Enter Roll number to Delete\n";
    			short rn;
    			cin>>rn;
    			for(int k=0;k<10;k++)
    			{
    				res=all[k].deletion(rn);
    				if(res==1)
    				{
    					break;
					}
				}
				if(res==1)
				cout<<"Record Deleted\n"<<endl;
				else
				cout<<"Record Not Found\n";
    			break;
			}
		case 6:
    		{
    			system("cls");
    			cout<<"Total Number Of students in Examination is ="<<totalstudents<<endl;
    			break;
			}
		case 7:
    		{
    			system("cls");
    			e.info();
    			break;
			}
		case 8:
    		{
    			system("cls");
    			e.details();
    			break;
			}
		case 9:
    		{
    			system("cls");
    			int res;
    			cout<<"Enter Roll number to update\n";
    			short rn;
    			cin>>rn;
    			for(int k=0;k<10;k++)
    			{
    				res=all[k].update(rn);
    				if(res==1)
    				{
    					break;
					}
				}
				if(res==1)
				cout<<"Record updated\n"<<endl;
				else
				cout<<"Record Not Found\n";
    			break;
			}
		case 10:
    		{
    			system("cls");
    			exit(0);
    			break;
			}
	}
    }
    getch();
    return 0;
}
