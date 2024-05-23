#include <iostream>
using namespace std;

void solve(int arr[], int size)
{
    cout << "Size of Array inside a function : " << sizeof(arr) << endl;
    cout << "Inside solve -> arr: " << arr << endl;
    cout << "Inside solve -> &arr: " << &arr << endl;
    *arr = *arr + 1;
}

void solveP(int *&p)
{
    p = p + 1;
}

int main()
{

    // // Pointer to an array
    // int arr[5] = {1, 2, 3, 4, 5};
    // int(*ptr)[5] = &arr; // this will point "ptr" to each index of "arr"
    // cout<<(*ptr)[3]<<endl;

    // // Array of Pointer
    // int num[5] = {1, 2, 3, 4, 5};
    // int *ptr2[5]={&num[0],&num[1],&num[2],&num[3],&num[4]};
    // cout<<*ptr2[2]<<endl;

    // int arr1[] = {1, 2, 3, 4, 5};
    // cout << "Size of Array : " << sizeof(arr1) << endl;

    // cout << "Inside main -> arr: " << arr1 << endl;
    // cout << "Inside main -> &arr: " << &arr1 << endl;
    // solve(arr1, 5);

    // for (int i = 0; i < 3; i++)
    // {
    //     cout << arr1[i] << " ";
    // }

    int a = 5;
    int *p = &a;

    cout << "p: " << p << endl;
    cout << "&p : " << &p << endl;
    cout << "*p: " << *p << endl;
    solveP(p);  //BY REFRENCE CHANGE
    cout << "p: " << p << endl;
    cout << "&p : " << &p << endl;
    cout << "*p: " << *p << endl;

    return 0;
}