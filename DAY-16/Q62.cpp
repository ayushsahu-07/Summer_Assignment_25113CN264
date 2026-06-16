//Write a program to Find maximum frequency element

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
    
    int maxFreq = 0, maxElem = arr[0];

    for (int i = 0; i < n; i++)
    {
        int freq = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == arr[i])
            {
                freq++;
            }
            if (freq > maxFreq)
            {
                maxFreq = freq;
                maxElem = arr[i];
            }   
        }
    }
    
    cout<<"Maximum frequency element: "<<maxElem<<endl;
    cout<<"Frequency: "<<maxFreq<<endl;

    return 0;
}
