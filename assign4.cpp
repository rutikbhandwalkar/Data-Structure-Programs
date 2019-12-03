#include<iostream>
using namespace std;

int a[100],n,i,j, position, temp;

void insert()
{
    cout<<"\n Enter Elements to sort: \n";
    cin>>n;
    cout<<"\n Enter Integers: "<<n<<"\n";
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
}

void display()
{
    cout<<"\n--------------------------------------------";
    cout<<"\n Entered List is: ";
    for(i=0; i<n ;i++)
    {
        cout<<" "<<a[i];
    }
    cout<<"\n--------------------------------------------";
}

void selection_sort()
{
    int small,index, count=0, pass=0;
   for(i=0; i<(n-1); i++)
    {
        small = a[i];
        cout<<"\n------------------Selection Sort----------------------\n";
        for(j=(i+1); j<n; j++)
        {
            if(small>a[j])
            {
                small = a[j];
                count++;
                index = j;
            }
        }
        if(count!=0)
        {
            temp = a[i];
            a[i] = small;
            a[index] = temp;
            pass++;

        }
        count=0;
        for (pass = 1; pass < n; ++pass)
            {
               cout<<"\n After Pass "<<pass<<endl;
                    for (i = 0; i < n; ++i)
                        cout<<" "<<a[i];
                        cout<<"\n";
            }
    }
    cout<<"\n----------------------------------------------------------------------";
    cout<<"\n Selection Sort List in Ascending Order: ";
    for(i=0; i<n ;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n----------------------------------------------------------------------";
}

void insertion_sort()
{
    int pass=0;
    cout<<"\n\n------------------Insertion Sort--------------------\n";
    for(i=1; i<n; i++)
    {
        temp=a[i];
        j=i-1;
        while(temp>a[j] && (j>=0))
        {
            a[j+1]=a[j];
            j=j-1;
            pass++;
        }
        a[j+1]=temp;

        
       
    }
    for (pass = 1; pass < n; ++pass)
            {
               cout<<"\n After Pass "<<pass<<endl;
                    for (i = 0; i < n; ++i)
                        cout<<" "<<a[i];
                        cout<<"\n";
            }
    cout<<"\n-----------------------------------------------------------------";
    cout<<"\n Insertion Sort List in Descending Order: ";
    for(i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<"\n------------------------------------------------------------------";

}

int main()
{
    insert();
    display();
    selection_sort();
    insertion_sort();

    return 0;
}