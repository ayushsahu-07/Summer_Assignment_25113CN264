//Write a program to Find maximum occurring character

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

    int maxCount = 0,  maxIndex = 0;

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > maxCount)
        {
            maxCount = freq[i];
            maxIndex = i;
        }
    }

    cout<<"Maximum occuring character: "<<(char)(maxIndex= 'a')<<endl;
    cout<<"Count: "<<maxCount<<endl;

    return 0;
}
