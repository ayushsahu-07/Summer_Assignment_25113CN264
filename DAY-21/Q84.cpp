//Write a program to Convert lowercase to uppercase

#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char str[100];
    cout<<"Enter a string: ";
    cin.getline(str, 100);

    int length = strlen(str);

    for (int i = 0; i < length; i++)
    {
        if (str[i] >='a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32;
        }
        
    }

    cout<<"Uppercase string: "<<str<<endl;


    return 0;
}
