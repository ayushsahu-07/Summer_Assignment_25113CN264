//Write a program to Check string rotation

#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char s1[100], s2[100], temp[200];

    cout<<"Enter first string: ";
    cin>>s1;
    cout<<"Enter second string: ";
    cin>>s2;

    int n1 = strlen(s1), n2 = strlen(s2);

    if (n1 != n2)
    {
        cout<<"Not a rotation";
        return 0;
    }

    int i,j;
    for (i = 0; i < n1; i++)
    {
        temp[i] = s1[i];
    }

    for ( i = 0; i < n1; i++)
    temp[n1 + i] = s1[i];
    temp[2*n1] = '\0';

    int found = 0;
    for ( i = 0; i < 2*n1 - n2; i++)
    {
        int match = 1;
        for ( j = 0; j < n2; j++)
        {
            if (temp[i + j] != s2[j])
            {
                match = 0;
                break;
            }
        }
        if (match)
        {
            found = 1;
            break;
        }
    }
    
    if (found)
    {
        cout<<s2<<" is a rotation of "<<s1;
    }
    
    else
    {
        cout<<s2<<" is not a rotation of "<<s1;
    }
    
    return 0;
}