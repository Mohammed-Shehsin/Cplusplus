#include <iostream>

using namespace std;
int factorial(int n){
    if(n<=1){
        return 1;
    }
    else
    return n*factorial(n-1);
}
int main()
{  int n;
    cout<<"Enter the value"<<endl;
    cin>>n;
    cout<<"the factorial of "<<n<<" is : "<<factorial(n)<<endl;
    return 0;
}

                                        //CODE IN PYTHON
//def factorial(number):
//    if number<=1:
//        return 1
//    return number*factorial(number-1)

//number=int(input("Enter the the number : "))
//print(f' Factorial of {number} is {factorial(number)}')
