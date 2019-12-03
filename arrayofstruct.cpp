#include<string.h>
#include<stdio.h>
#include<iostream>
using namespace std;

struct student
{
  int rno,marks,str;
  char name[20];
};

void create(int,struct student[]);
void add(int,struct student[]);
void display(int,struct student[]);
void search(int,int,struct student[]);
void del(int,int,struct student[]);
void modify(int,int,struct student[]);


void create(int n,struct student s[10])
{
      int i,j;
      for(i=0;i<n;i++)
      {
	 s[i].str=0;
	 cout<<"\nEnter the roll no.: ";
	 cin>>s[i].rno;
	 for(j=0;j<i;j++)
	 {
	  if(s[i].rno==s[j].rno)
	  {
	       cout<<"Roll No. already exist.";
	       j=-1;
	  }
	 }
	 cout<<"\nEnter name :";
	 cin>>s[i].name;
	 cout<<"\nMarks :";
	 cin>>s[i].marks;
      }
}

void add(int n,struct student s[10])
{
int i,j;
      for(i=n-1;i<n;i++)
      {
	 s[i].str=0;
	 cout<<"\nEnter the roll no.: ";
	 cin>>s[i].rno;
	 for(j=0;j<i;j++)
	 {
	  if(s[i].rno==s[j].rno)
	  {
	       cout<<"Roll No. already exist.";
	       j=-1;
	  }
	 }
	 cout<<"\nEnter name :";
	 cin>>s[i].name;
	 cout<<"\nMarks :";
	 cin>>s[i].marks;
      }

      cout<<"**** Display New Added Data ****";
      display(n,s);
}

void display(int n,struct student s[10])
{
 int i;
 for(i=0;i<n;i++)
 {
   if(s[i].str==0)
   {
    cout<<"\n\tRoll No :"<<s[i].rno<<"\tName :"<<s[i].name<<"\tMarks :"<<s[i].marks;
   }
 }
}

void search(int n,int val,struct student s[10])
{
 int i;
 for(i=0;i<n;i++)
 {
   if(s[i].str==0)
   {
     if(val==s[i].rno)
     {
	cout<<"\n\tRoll No :"<<s[i].rno<<"\tName  :"<<s[i].name<<"\t Marks :"<<s[i].marks;
	break;
     }
   }
 }

  if(i==n)
  {
   cout<<"No record found";
  }
}

void modify(int n,int val,struct student s[10])
{
      int i,j;
 for(i=0;i<n;i++)
 {
   if(s[i].str==0)
   {
     if(val==s[i].rno)
     {
	cout<<"\n\tRoll No :"<<s[i].rno<<"\tName  :"<<s[i].name<<"\t Marks :"<<s[i].marks;
	cout<<"\n\tRoll No :";
	cout<<"\tName  :";
	cout<<"\t Marks :";
	s[i].str=0;
      cin>>s[i].rno>>s[i].name>>s[i].marks;
      for(j=0;j<n;j++)
      {
       if(j!=i)
       {
	if(s[i].rno==s[j].rno)
	 {
	   cout<<"\n Roll No. already exist .";
	   j=-1;
	 }
       }
       }
      break;
      }
     }
   }

  if(i==n)
  {
   cout<<"No record to Update";
   display(n,s);
  }
}

int main()
{
 int n,val, ch;
 char ans;
 struct student s[10];

 do
  {
   
   cout<<"\n\t----------------<<  OPERATIONS ON ARRAY OF STRUCTURES  >>-------------------";
   cout<<"\n\t\t1. Insert";
   cout<<"\n\t\t2. Display";
   cout<<"\n\t\t3. Add";
   cout<<"\n\t\t4. Search";
   cout<<"\n\t\t5. Modify";
   cout<<"\n\t\t6. Exit";
   cout<<"\n\n---------------------------------------------------------------------------\n\n";

 cout<<"Enter your Choice: ";
 cin>>ch;

 switch(ch)
 { 
    case 1:
      cout<<"\n Enter the No.of student : ";
      cin>>n;
      create(n,s);
      n=n+1;
      break;

    case 2: 
        cout<<"\n **** Display Database ****";
        display(n,s);
        break;

    case 3: 
        cout<<"\n **** Add new Record  ****:";
        add(n,s);
        break;

    case 4: 
        cout<<"\n Enter the Roll no. for search : ";
        cin>>val;
        search(n,val,s);
        break;

	  case 5: 
        cout<<"\n Enter the Roll no. for update : ";
        cin>>val;
        modify(n,val,s);
        break;
 
    default :
        cout<<"\n\n\tInvalid choice...";
        break;

   }
 
   cout<<"\n\n\nDo you want to continue(Y/N)?==>";
   cin>>ans;
  }while(ans=='Y'||ans=='y');
	return 0;
}