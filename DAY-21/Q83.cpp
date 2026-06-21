//Write a program to Count vowels and consonants.


#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char str[100];
    cout<<"Enter a string: ";
    cin.getline(str, 100);

    int vowels = 0, consonants = 0;
    int length = strlen(str);

    for (int i = 0; i < length; i++)
    {
        char ch = str[i];
    
    
      if (ch == 'a'||ch == 'e'|| ch == 'i'|| ch == 'o'||ch == 'u')
    {
        vowels++;
    }
    else if (ch >= 'a'&& ch <= 'z')
    {
        consonants++;
    }
}
    cout<<"Vowels: "<<vowels<<endl;
    cout<<"Consonants"<<consonants<<endl;


    return 0;
}