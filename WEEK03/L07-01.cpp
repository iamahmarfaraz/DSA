#include<iostream>
using namespace std;
// ARRAYS
int main()
{
int arr[100];  //Array created succesfully
cout<<"The base address of Arr is: "<<&arr<<endl;  //"Address of" operator(&) 
cout<<"This will also give the base address of Arr: "<<arr<<endl;
cout<<endl;
cout<<"Size of array Arr: "<<sizeof(arr)<<endl;

// int brr[]={1,2,3,4};
// int crr[5]={2,4};
int num;
cin>>num;
int num1[num];
//taking input in array
for (int i = 0; i < num; i++)
{
    cin>>num1[i];
}
cout<<"Printing the Array"<<endl;
for (int i = 0; i < num; i++)
{
    cout<<num1[i]<<" ";
}
cout<<endl;
int arr1[5]={12,4,9,75,90};
for (int i = 0; i < 5; i++)
{
    cout<<arr1[i]<<" ";
}


return 0;
}