//Write a program to Second largest element

#include<iostream>
using namespace std;

int main(){
    int n, largest = -1, second = -1;
    
    cout<<"Enter the size of array: ";
    cin>>n;
    
    int arr[n];

    cout<<"Enter "<<n<<" element: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        if (arr[i]>largest)
        {
            second = largest;
            largest = arr[i];
        }
        else if (arr[i]>second && arr[i] != largest)
        {
            second = arr[i];
        }
        
    }
    if (second == -1)
    {
        cout<<"second largest element doest not exist."<<endl;
    }
    else
    {
        cout<<"second largest element is "<<second<<endl;
    }
    
    return 0;
}