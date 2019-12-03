#include<iostream>
using namespace std;

int findlength(char *str)
{   
    int i=0;
    while(str[i]!='\0')
    { 
        i++; 
    }
    return i;
}

void compare()
{ 
    char str1[30], str2[30];
    int i1=0,i2=0,i=0,flag=0;

    cout<<"\n Enter the string1: "; 
    cin>>str1;
    
    while(str1[i1]!='\0')
    { 
        i1++; 
    }
 
    cout<<"\n Enter the string2:"; 
    cin>>str2;
    
    while(str2[i2]!='\0')
    { 
        i2++; 
    }
    
    if(i2!=i1)
    { 
        cout<<"\n Strings are not Equal "; 
    }
    else
    { 
        for(i=0;i<i1;i++)
        { 
            if(str1[i]!=str2[i])
            { 
                flag=1;
                break;
            }
        }
    if(flag==1)
    { 
        cout<<"\n Strings are not Equal "; 
    }
    else
    { 
        cout<<"\n Strings are Equal "; 
    }
    }
} 

void concat()
{ 
    char str1[30], str2[30];
    int i1=0,i2=0,i=0,flag=0;
    
    cout<<"\n Enter the string1: "; 
    cin>>str1;
    
    while(str1[i1]!='\0')
    { 
        i1++; 
    }
    
    cout<<"\n Enter the string2:"; 
    cin>>str2;
    
    while(str2[i2]!='\0')
    { 
        i2++; 
    }
    for(i=0;i<i2;i++)
    { 
        str1[i1+i]=str2[i]; 
    }
    str1[i1+i2]='\0';

    cout<<"\n The concatenated String is: "; puts(str1);
}
 
 void reverse()
 {
    char str1[30], str2[30];
    int l1;
    
    cout<<"Enter String to Reverse: ";
    cin>>str1;
     
    l1=findlength(str1);
    str2[l1];
    int j=0;

    for(int i=l1-1;i>=0;i--)
    {
      str2[j]=str1[i];
       j++;
    }

    str2[l1]='\0';
    cout<<"Reversed String is: ";
    cout<<str2;
 }
 
 void copy()
 {
    char str1[30], str2[30];
    int l1;
    
    cout<<"Enter 1 string to copy: ";
    cin>>str1;
     
    l1=findlength(str1);
    cout<<"Enter 2 string to copy: ";
    cin>>str2;
    
    for(int i=0; i<l1;i++)
    {
        str1[i]=str2[i];
    }
     
    cout<<"After Copy: ";
    cout<<str1;
 }

int main()
{ 
    G:
    char str[50];

    cout<<"\n----------------------------------------------------\n";
    cout<<"Enter your choice \n \t1.Find length of string\n\t"
            "2.Compare two Strings \n\t3.Concatenate two strings\n\t4.Reverse\n\t5.Copy\n\n";
    char ch, opt;
    cout<<"\t\t My Choice is..."; cin>>ch;
    cout<<"\n__________________________________________________\n";
    
    if(ch=='1') 
    {
        int i;
            cout<<"\n Enter the string: ";
            cin>>str; i=findlength(str);
            cout<<"\n String length is: "<<i;
    }
    
    else if(ch=='2') { compare(); }
    else if(ch=='3') { concat(); }
    else if(ch=='4'){reverse();}
    else if(ch=='5'){copy();}
    
    cout<<"\n__________________________________________________\n";
    cout<<"\n\tDo you want to do again (y/n): "; 
    cin>>opt;
    if((opt=='y')||(opt=='Y'))
    goto G; else exit ;

} 
