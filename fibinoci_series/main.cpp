#include <iostream>

using namespace std;
double fib(double n){
     if(n==0 ||n==1){
         return n;
     }

     return fib(n-1)+fib(n-2);
}
int main()
{   double n;
    cout<<"Enter the value :"<<endl;
    cin>>n;
    cout<<"the fibinocii series of the value "<<n<<" is :"<<fib(n)<<endl;
    return 0;
}
