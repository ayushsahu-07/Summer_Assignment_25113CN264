//Write a program to Remove spaces from string.


#include<iostream>
#include<cstring>
using namespace std;

int main(){
    string str, result;
    cout<<"ENter a string: ";
    getline(cin, str);

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
        {
            result +=str[i];
        }
        
    }
    
    cout<<"After removing spaces: "<<result<<endl;

    return 0;
}