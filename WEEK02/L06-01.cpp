#include<iostream>
using namespace std;

// FUNCTION
void  predefine_func(){}  //declaration function to use it in main and defining it after main function

void printName(string a){
    cout<<a<<endl;
}

void printLine(){
    for (int i = 0; i < 10; i++)
    {
        cout<<"Sundar ko sundari pasand hai"<<endl;
    }
    
}
int sumofThree(int a,int b,int c){
    int sum=a+b+c;
    return sum;
}

int main(){
    string name="AHMAR";
printName(name);
printLine();
predefine_func();
cout<<"THE SUM OF A,B,C = "<<sumofThree(34,76,51);
return 0;
}

void predifine_func(){
    cout<<"Function decleared after main function"<<endl;
}
