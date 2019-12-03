#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;

struct stud
{
 int rn,ts,id,ph;
 char add[30],na[20],d[15],in[5];
 struct stud *next;
}*h=NULL,*p,*q,*t;

void add()
{
    int ts;
  p =(stud *)malloc(sizeof(stud));
  cout<<"\n Enter the Name of Student: ";
  cin>>p->in;
  cout<<"\n Enter the College Name of Student: ";
  cin>>p->na;
  cout<<"\n Enter ID of Student: ";
  cin>>p->id;
  cout<<"\n Enter Roll no. of Student: ";
  cin>>p->rn;
  cout<<"\n Enter Mobile No. of Student: ";
  cin>>p->ph;
  cout<<"\n Enter Address of the Student: ";
  cin>>p->add;
  cout<<"\n Enter Birth Date of Student: ";
  cin>>p->d;

  p->next=NULL;

  if(h==NULL)
  {
   h=p;
  }
  else
  {
    q=h;
    while(q->next!=NULL)
    q=q->next;
    q->next=p;
  }
  ts++;
}

void addAt(int r)
{
 q=h;
 int ts;
 while(q->rn!=r || q==NULL)
  q=q->next;
 if(q->rn==r)
 {
  p =(stud *)malloc(sizeof(stud));
   cout<<"\n Enter the Name of Student: ";
  cin>>p->in;
  cout<<"\n Enter the College Name of Student: ";
  cin>>p->na;
  cout<<"\n Enter ID of Student: ";
  cin>>p->id;
  cout<<"\n Enter Roll no. of Student: ";
  cin>>p->rn;
  cout<<"\n Enter Mobile No. of Student: ";
  cin>>p->ph;
  cout<<"\n Enter Address of the Student: ";
  cin>>p->add;
  cout<<"\n Enter Birth Date of Student: ";
  cin>>p->d;

  p->next=q->next;
  q->next=p;
  ts++;
 }
 else
 {
  cout<<"\n\n Record Not Found..";
 }
}


void delAt(int r)
{
    int ts;
 q=h;
 while((q->next)->rn!=r || q==NULL)
  q=q->next;
 if((q->next)->rn==r)
 {
  q->next=(q->next)->next;
  cout<<"\n\n Record Deleted..";
  ts--;
 }
 else
  cout<<"\n\n Record Not Found..";
}

void modAt(int id)
{
 q=h;
 int ch;
 while(q->id!=id && q!=NULL)
  q=q->next;
 if(q->id==id)
 {
  cout<<"******* MODIFY *******\n1.Student Name\n2.College Name";
  cout<<"\n3.Roll No.\n4.Mobile No.\n5.Address\n6.Date of Birth:\nEnter choice: ";
  cin>>ch;
  switch(ch)
  {
  case 1 :  cout<<"\n\nEnter the Name of Student: ";
          cin>>q->in;break;
  case 2 : cout<<"\nEnter the College Name of Student: ";
          cin>>q->na;break;
  case 3 : cout<<"\nEnter the Roll No. of Student : ";
          cin>>q->rn;break;
  case 4 :  cout<<"\nEnter the Mobile No. of Student: ";
          cin>>q->ph;break;
  case 5 :  cout<<"\nEnter the Address of Student: ";
          cin>>q->add;break;
  case 6 :  cout<<"\n Enter Birth Date of Student: ";
          cin>>p->d;break;
  }
 }
 else
  cout<<"\n Record Not Found..";
}

void search(char ni[5])
{
 int flag=0;
 q=h;
 while(q!=NULL)
 {
  if(strcmp(q->in,ni)==0)
  {
  flag=1;
  cout<<"\n\nName of Student: "<<q->in<<endl;
  cout<<"\n\nCollege Name of Student: "<<q->na<<endl;
  cout<<"\n\nID of Student: "<<q->id<<endl;
  cout<<"\n\nRoll No. of Student: "<<q->rn<<endl;
  cout<<"\n\nPh No. of Student: "<<q->ph<<endl;
  cout<<"\n\nAddress of Student: "<<q->add<<endl;
  cout<<"\n\nD.O.B. of Student: "<<q->d<<endl;
  cout<<"\n\n\n";
  }
  q=q->next;
 }
 if(flag==0)
  cout<<"\n\nNo Match Found..";
}

void display()
{
 q=h;
 while(p!=NULL)
 {
  cout<<"\n\nName of Student: "<<q->in<<endl;
  cout<<"\n\nCollege Name of Student: "<<q->na<<endl;
  cout<<"\n\nID of Student: "<<q->id<<endl;
  cout<<"\n\nRoll No. of Student: "<<q->rn<<endl;
  cout<<"\n\nPh No. of Student: "<<q->ph<<endl;
  cout<<"\n\nAddress of Student: "<<q->add<<endl;
  cout<<"\n\nD.O.B. of Student: "<<q->d<<endl;
  cout<<"\n\n";
  q=q->next;
 }
}

int main()
{
 int ch=0,r;
 char ni[5];
 while(ch!=7)
 {
   cout<<"\n\n************************ SINGLY LINKED LIST ******************************\n\n";
  cout<<"1.Add the Record.\n\n2.Add Record at Locn.\n\n3.Delete Record.";
  cout<<"\n\n4.Modify Record.\n\n5.Search Record.1";
  cout<<"\n\n6.Display\n\n7.Exit";
  cout<<"\n\n***************************************************************************";
  cout<<"\n\nEnter the Choice: ";
  cin>>ch;
  cout<<"\n***************************************************************************";
  //scanf("%d",&ch);
  
   switch(ch)
   {
    case 1:
    add();
    break;

    case 2:
    cout<<"\nEnter the Roll No.: ";
    cin>>r;
    addAt(r);
    break;

    case 3:
    cout<<"\nEnter the Roll No.: ";
    cin>>r;
    delAt(r);
    break;

    case 4:
    cout<<"\nEnter the ID: ";
    cin>>r;
    modAt(r);
    break;

    case 5:
    cout<<"\nEnter the Name: ";
    cin>>ni;
    search(ni);
    break;

    case 6:
    display();
    break;
   }
 }
 return 0;
}
