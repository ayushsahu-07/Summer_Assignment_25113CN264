//Write a program to Count even and odd elements

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    int arr[n];
    cout<<"Enter "<<n<<" elements"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int even = 0, odd = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]%2 == 0)
        {
            even++;
        }
        else{
            odd++;
        }
    }
    
    cout<<"Even count is: "<<even<<endl;
    cout<<"Odd count is: "<<odd<<endl;
    return 0;
}
