//Write a program to Remove duplicates from array

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

    int result[n], num = 0;

    for (int i = 0; i < n; i++)
    {
        int isDuplicate = 0;
        for (int j = 0; j < num; j++)
        {
            if (arr[i] == result[j])
            {
                isDuplicate = 1;
                break;
            }
        
        }
        
        if (isDuplicate == 0)
        {
            result[num] = arr[i];
            num++;
        }
    }
    cout<<"Array after removing duplicate: ";
    for (int i = 0; i < num; i++)
    {
        cout<<result[i]<<" ";
    }
    
    return 0;
}
