//Write a program to Find first repeating character

#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cout<<"Enter string: ";
    cin>>s;

    int freq[26] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i] - 'a']++;
    }
    
    for (int i = 0; i < s.length(); i++)
    {
        if (freq[s[i] - 'a'] > 1)
        {
            cout<<"First repeating character: "<<s[i]<<endl;
            return 0;
        }
    }

    cout<<"No repeating character found"<<endl;

    return 0;
}

