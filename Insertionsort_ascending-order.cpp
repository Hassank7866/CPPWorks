#include<iostream>
using namespace std; 

int main()
{
cout<<"Enter the amount of elements you want in your array"<<endl;
int n=0;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
cin>>arr[i];
}
//we'll comment how the insertion sort alogo is actually working
for(int i=1;i<n;i++)//This for loop basically seperates the sorted and usorted parts by reserving the zero element as sorted

{
int current= arr[i];
int j=i-1;
while(arr[j]>current&&j>=0)
{
arr[j+1]=arr[j];
j--;
}
arr[j+1]=current;
}
for(int i=0;i<n;i++)
{
cout<<arr[i]<<" ";
}
}
