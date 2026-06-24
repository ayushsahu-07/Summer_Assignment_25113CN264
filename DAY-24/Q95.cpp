#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char s[1000], longest[100], current[100];

    cout<<"Enter string: ";
    cin.getline(s, 1000);

    int n = strlen(s);
    int i = 0, j = 0;
    longest[0] = '\0';

    while(i <= n){
        if(s[i] != ' ' && s[i] != '\0'){
            current[j++] = s[i];
        }
        else{
            current[j] = '\0';
            if(strlen(current) > strlen(longest)){
                strcpy(longest, current);
            }
            j = 0;
        }
        i++;
    }

    cout<<"Longest word: "<<longest;

    return 0;
}