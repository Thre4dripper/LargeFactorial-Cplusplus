#include<iostream>
#include<conio.h>
using namespace std;

void large_factorial(int num){
int arr[500000];
int temp=num;
int carry=0;

for(int k=0;k<500000;k++)
arr[k]=-1;
int j=0;

while(temp!=0){
    arr[j]=temp%10;
    temp/=10;
    j++;
}

num--;

while(num!=0)
{

for(int i=0;i<j;i++){
    temp=arr[i];

    if(i==0)
    arr[i]=(arr[i]*num)%10;
    else 
    arr[i]=(carry+arr[i]*num)%10;

        if(carry+temp*num>=10)
       carry=(carry+temp*num)/10;
       else carry=0;

        if(i==j-1 && carry+arr[i]*num>=10)
        temp=(carry+temp*num)/10;

       //cout<<temp<<endl;
}

while(carry!=0){
    arr[j]=carry%10;
    carry/=10;
    j++;
}
num--;

delete arr;
}



for(int k=j-1;k>=0;k--)
cout<<arr[k];
cout<<endl<<j;
}

int main(){system("cls");
    int num;
    cout<<"Enter Number->";
    cin>>num;
    if(num<0)cout<<"INVALID NUMBER";
    else if(num==0)cout<<1;
    else large_factorial(num);
    getch();

    
}