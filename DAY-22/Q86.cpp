//Write a program to Count words in a sentence.

#include<iostream>
#include<cstring>
using namespace std;
int main(){
    string sentence;
    cout<<"Enter a sentence: ";
    getline(cin, sentence);

    int count = 0, i = 0;

    while (i < sentence.length()){
        while (i < sentence.length() && sentence[i] == ' ')
        {
            i++;
        }
        
        if (i < sentence.length())
        {
           count++;
           while (i < sentence.length() && sentence[i] != ' ')
           {
            i++;
           }
        }
    }

    cout<<"Number of words: "<<count<<endl;
     
    return 0;
} 
 