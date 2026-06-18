//Write a program to Binary search.

#include<iostream>
using namespace std;

int main(){
    int n, key;

    cout<<"Enter the size of array: ";
    cin>>n;

    int arr[n];

    cout<<"Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    cout<<"Enter the element to search: ";
    cin>>key;

    int low = 0, high = n - 1, found = 0;

    while (low <= high)
    {
        int mid = (low + high)/2;

        if (arr[mid] == key)
        {
            cout<<"Element found at index: "<<mid;
            found = 1;
            break;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
        
    }
    
    if (found == 0)
    {
        cout<<"Element not found";
    }
     
    return 0;
}