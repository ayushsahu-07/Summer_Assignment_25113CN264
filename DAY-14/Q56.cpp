//Write a program to Find duplicates in array

#include<iostream>
using namespace std;

int main (){
    int n, num = 0;

    cout<<"Enter the size of array";
    cin>>n;

    int arr[n];

    cout<<"Enter "<<n<<" no.: ";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    cout<<"Duplicate no. are: "<<endl;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i +1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                cout<<arr[i]<<endl;
                num = 1;
                break;
            }
        }        
    }
    if (!num)
    {
        cout<<"No duplicates are"<<endl;
    }
    
    return 0;
}