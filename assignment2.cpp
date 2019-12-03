#include<iostream>
using namespace std ;

int main ()
{
    int m,n;
    cout<<"enter the no of rows and column\n";
    cin>>m>>n;

    int a[m][n],k=0,i,j;

    cout<<"enter the elements\n";
        for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>a[i][j];
            if(a[i][j]!=0)
            {k++;}
        }

    }
     for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<a[i][j]<<"  ";
        }
           cout<<endl;
    }
     int s[k+1][3],x=0;
     s[0][0]=m;
     s[0][1]=n;
     s[0][2]=k;
     for(i=0;i<m;i++)
     {
         for(j=0;j<n;j++)
         {
             if(a[i][j]!=0)
             {
                 s[++x][0]=i;
                 s[x][1]=j;
                 s[x][2]=a[i][j];
             }
         }
     }
     cout<<"\nRows   Column    value\n";
     for(i=0;i<k+1;i++)
     {
         for(j=0;j<3;j++)
         {
             cout<<s[i][j]<<"       "<<"  ";
         }
         cout<<endl;
     }
     cout<<"\n";

// transpose of sparse matrix
 int f[k+1][3];
 f[0][0]=s[0][0];
 f[0][1]=s[0][1];
 f[0][2]=s[0][2];
x=0;
for(i=0;i<n;i++)
{
    for(j=1;j<k+1;j++)
    {
        if(i==s[j][1])
        f[++x][0]=s[j][1];
        f[x][1]=s[j][0];
        f[x][2]=s[j][2];
    }
}

cout<<"\nThe simple transpose of sparse matrix is\n\n";
cout<<"\nRows   Column    value\n";
     for(i=0;i<k+1;i++)
     {
         for(j=0;j<3;j++)
         {
             cout<<f[i][j]<<"       "<<"  ";
         }
         cout<<endl;
     }
     cout<<"\n";


//fast transpose

int row_terms[20],starting_pos[20];
for (i=0;i<n;i++)
{
    row_terms[i]=0;

}
for(i=1;i<k+1;i++)
{
    row_terms[s[i][1]] ++ ;

}
 starting_pos[0]=1;
cout<<" \n Row terms : ";
for(i=0;i<n;i++)
{
    cout<<row_terms[i]<<"  ";
}
cout<<"\n starting pos : ";
for(i=0;i<n;i++)
{
    starting_pos[i+1]=starting_pos[i]+row_terms[i];
}
for(i=0;i<n;i++)
{
    cout<<starting_pos[i]<<"  ";
}
int ftrans[k+1][3];
x=0;
for(j=0;j<n;j++)
{
 for(i=1;i<=row_terms[j];i++)
    {

        ftrans[++x][0]=j;
    }
}
cout<<endl;
ftrans[0][1]=s[0][0];
ftrans[0][0]=s[0][1];
ftrans[0][2]=s[0][2];
for(i=1;i<k+1;i++)
{
    j=starting_pos[s[i][1]];
    ftrans[j][0]=s[i][1];
    ftrans[j][1]=s[i][0];
    ftrans[j][2]=s[i][2];
    starting_pos[s[i][1]]++;
}
cout<<endl<<"Fast transpose of sparse matrix"<<endl;
cout<<"\nRows   Column    value\n";
     for(i=0;i<k+1;i++)
     {
         for(j=0;j<3;j++)
         {
             cout<<ftrans[i][j]<<"       "<<"  ";
         }
         cout<<endl;
     }
     cout<<"\n";
     
     return 0;
}
