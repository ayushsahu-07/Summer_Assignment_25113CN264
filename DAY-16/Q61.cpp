//Write a program to Find missing number in array

#include<iostream>
using namespace std;

int main(){
    int n, num, expected, actual = 0;
    cout<<"Enter the size of array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter "<<n<<" numbers: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    num = n + 1;
    expected = num*(num + 1)/2;
    for (int i = 0; i < n; i++)
    {
        actual += arr[i];
    }
    cout<<"Missing number: "<<expected - actual<<endl;

    return 0;
}
