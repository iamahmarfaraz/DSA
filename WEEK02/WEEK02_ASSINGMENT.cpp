#include <iostream>
#include <cmath>
using namespace std;
int areaofcircle(double radius)
{
    double pi = M_PI;
    return pi * radius * radius;
}
int factorial(int num)
{
    int fact = 1;
    for (int i = num; i > 0; i--)
    {

        fact *= i;
    }
    return fact;
}

bool checkprime(int n)
{
    for (int j = 2; j < n; j++)
    {
        if (n % j == 0)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}

int printno_ofdigits(int num)
{
    int counter = 0;
    for (int i = num; i >= 1; i = i / 10)
    {
        counter++;
    }
    return counter;
}
void createNumberUsingDigits(int arr[], int size)
{
    cout << "ENTER THE DIGITS(ONE DIGIT AT A TIME): ";
    int num = 0;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
        num = (num * 10) + arr[i];
    }
    cout << "NUMBER CREATED USING DIGITS : " << num;
}
void decimaltobinary(int num)
{
    cout << "THE NUMBER " << num << " in decimal is : ";
    int binaryno = 0;
    for (int i = 0; num > 0; i++)
    {
        int bit = num % 2;
        binaryno = bit * pow(10, i) + binaryno;
        num = num / 2;
    }
    cout << binaryno << endl;
}
double kmtoMiles(double num)
{
    return (num * 0.621371);
}
// LEETCODE QUESTION
void celsiusToKelvin(float celsius, float arr[])
{
    float kelvin = celsius + 273.15;
    float fahreinheit = (celsius * 1.80) + 32;
    arr[0] = kelvin;
    arr[1] = fahreinheit;
}

void calculateSetbits(int num)
{
    int setbit = 0;
    for (int i = num; i > 0; i = i / 2)
    {
        int bit = i % 2;
        if (bit == 1)
        {
            setbit++;
        }
    }
    cout <<"THE SET BIT PRESENT IN NUM = "<< setbit<<endl;
}

void oddEvenBitwise(int num)
{
        int bit = num % 2;
        if ((bit & 1) == 0)
        {
            cout<<num<<" IS A EVEN NUMBER"<<endl;
        }
        else{
            cout<<num<<" IS A ODD NUMBER"<<endl;
        }
}

int main()
{
    // cout << "ENTER THE RADIUS OF CIRCLE: " << endl;
    // double radius;
    // cin >> radius;
    // cout << areaofcircle(radius) << endl;
    // ;
    // cout << "ENTER A NUMBER: " << endl;
    // int num;
    // cin >> num;
    // cout << "FACTORIAL OF " << num << "is = " << factorial(num) << endl;
    // ;
    // cout << "ENTER A NUMBER: " << endl;
    // int num1;
    // cin >> num1;
    // for (int i = 2; i <= num1; i++)
    // {
    //     if (checkprime(i))
    //     {
    //         cout << i << " IS A PRIME NUMBER " << endl;
    //     }
    //     else
    //     {
    //         cout << i << " ISN't A PRIME NUMBER " << endl;
    //     }
    // }

    // int num2;
    // cout << "ENTER A NUMBER TO CALCULATE IT'S DIGIT: " << endl;
    // cin >> num2;
    // int digit = printno_ofdigits(num2);
    // cout << "NO. OF DIGITS = " << digit << endl;
    // int size = 5;
    // int arr[size];
    // createNumberUsingDigits(arr, size);
    // cout << endl;
    // int binNum;
    // cout << "ENTER THE NUMBER TO CONVERT IT IN BINARY: ";
    // cin>>binNum;
    // decimaltobinary(binNum);

    // double km;
    // cout << "ENTER THE KILOMETER : ";
    // cin >> km;
    // double resultKm = kmtoMiles(km);
    // cout << km << " in miles = " << resultKm << endl;

    // float celsius;
    // float frr[2];
    // cout<<"ENTER TEMPERATURE IN CELSIUS : ";
    // cin>>celsius;
    // celsiusToKelvin(celsius,frr);
    // cout<<"THE TEMPERATURE IN KELVIN IS "<<frr[0]<<" AND "<<frr[1]<<" IN FAHERIENHEIT"<<endl;

    // int numset;
    // cout << "ENTER A NUMBER TO CALCULATE IT'S SET BITS: " << endl;
    // cin >> numset;
    // calculateSetbits(numset);

    int oddevenNum;
    cout<<"ENTER THE NUMBER TO FIND OUT WHETHER THE NUMBER IS EVEN OR ODD"<<endl;
    cin>>oddevenNum;
    oddEvenBitwise(oddevenNum);

    return 0;
}