//WAP to write function to find sum of two numbers

#include<iostream>
using namespace std;

int sum(int a, int b){
    return a + b;
}
int main(){
    int n1, n2;

    cout<<"Enter two numbers: ";
    cin>> n1 >> n2;

    cout<<"Sum= "<< sum(n1, n2);
    return 0;
}