//Write a program to Remove duplicate characters.


 #include<iostream>
#include<cstring>
using namespace std;

int main(){
    char s[100], result[100];

    cout<<"Enter string: ";
    cin>>s;

    int n = strlen(s);
    int freq[26] = {0};
    int j = 0;

    for(int i = 0; i < n; i++){
        int idx = s[i] - 'a';
        if(freq[idx] == 0){
            result[j++] = s[i];
            freq[idx] = 1;
        }
    }

    result[j] = '\0';

    cout<<"After removing duplicates: "<<result;

    return 0;
}