//WAP to recursive reverse number

#include<iostream>
using namespace std;

int n = 0;
void reverseNumber(int num)
{
    if (num == 0)
    {
        return;
    }
    n = n*10 + (num % 10);
    reverseNumber(num / 10);
}

int main()
{
   int num;

   cout<<"Enter a number";
   cin>>num;

   reverseNumber(num);

   cout<<"Reverse number is: " <<n;

   return 0;
}