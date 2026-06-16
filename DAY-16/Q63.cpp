//Write a program to Find pair with given sum

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    int arr[n];
    cout<<"Enter "<<n<<" numbers: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int target, found = 0;
    cout<<"Enter target sum: ";
    cin>>target;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                cout<<"Pair found: "<<arr[i]<<","<<arr[j]<<endl;
                found = 1;
            }
        }
    }
    
    if (found == 0)
    {
        cout<<"no pair found wuth this sum: "<<target<<endl;
    }
    
    return 0;
}