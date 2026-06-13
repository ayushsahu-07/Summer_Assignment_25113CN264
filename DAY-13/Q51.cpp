
//Write a program to Find largest and smallest element. 

#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;

    int arr[n];
    cout<<"Enter "<<n<<" elements"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int largest = arr[0],smallest = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i]>largest)
        {
            largest = arr[i];
        }
        if (arr[i]<smallest)
        {
            smallest = arr[i];
        }
        
    }
    cout<<"Largest: "<<largest<<endl;
    cout<<"Smallest: "<<smallest<<endl;

    return 0;
}