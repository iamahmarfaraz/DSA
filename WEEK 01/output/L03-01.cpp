#include<iostream>
using namespace std;
void posOrneg(int a){
    if (a>0)
    {
        cout<<"Number is positive"<<endl;
    }
    else if (a<0)
    {
        cout<<"Number is negative"<<endl;
    }
    else{
        cout<<"zero"<<endl;
    }  
}

void oddeven(int a){
        if(a%2==0){
            cout<<"Even number"<<endl;
        }
        else{
            cout<<"Odd Number"<<endl;
        }
    }
    
int main(){
    int num=6;
    if (num>5)
    {
        cout<<"Greater than 5"<<endl;
    }
    else{
        cout<<"not greater than 5"<<endl;
    }

    int side;
    cout<<"Number of side="<<endl;
    cin>>side;
    if (side==3)
    {
        cout<<"Triangle"<<endl;
    }
    else if (side==4)
    {
     
        cout<<"Rectangle"<<endl;
    }
    else if (side==5)
    {
        cout<<"Pentagon"<<endl;
    }
    else{
        cout<<"Not a valid figure"<<endl;
    }
    int num1;
    cout<<"Enter the number to check whether the number is postive,Negative or zero"<<endl;
    cin>>num1;
    posOrneg(num1);

    int num2;
    cout<<"Enter the number to check whether the number is Even or Odd"<<endl;
    cin>>num2;
    oddeven(num2);
}