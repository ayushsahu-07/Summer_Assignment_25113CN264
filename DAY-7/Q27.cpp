
/*using namespace std;

int sum(int n)
{
    if(n == 0)
    return 0;

    return (n % 10) + sum(n / 10);
}

int main(){

    int n;
    cout<<"Enter a number";
    cin>>n;
    
    int sum1 = sum(n);
    cout<<"Sum of digit = "<<sum;

    return 0;
}*/
#include <iostream>
using namespace std;

// Recursive function to calculate the sum of digits
int digitSum(int num)
{
    if (num == 0)
        return 0;

    return (num % 10) + digitSum(num / 10);
}

int main()
{
    int num;

    cout << "Enter a number: ";
    cin >> num;

    int sum = digitSum(num);

    cout << "The sum of digits is: " << sum << endl;

    return 0;
}