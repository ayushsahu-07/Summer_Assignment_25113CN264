//Write a program to Compress a string. 

#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char s[100], result[100];

    cout<<"Enter string: ";
    cin>>s;

    int n = strlen(s);
    int j = 0, i = 0;

    while (i < n)
    {
        char ch = s[i];
        int count = 0;
    
    while (i < n && s[i] == ch)
    {
        count++;
        i++;
    }
    
    result[j++] = ch;


if (count > 1)
{
    if (count >= 10)
    {
        result[j++] = '0' + (count/10);
    }
    result[j++] = '0' + (count%10);
}

    }
    result[j] = '\0';

    if(j < n)
    cout<<"Compressed: "<< result;

    else
    {
        cout<<"Compression not beneficial: "<<s;
    }
    
    
    return 0;
}
