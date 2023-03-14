#include <iostream>

using namespace std;
bool isPrime(int n){ //Function (Prime Number)
    for(int i=2;i<n;i++){
        if(n%i==0){
         return false;
        }}
    return true;
}
int main()
{
    //Code to check the Prime number
    int n;
  cout<<"Enter the number to check : ";
  cin>>n;
  if(n==0||n==1){
      cout<<"Worng input";
  }

  if(isPrime(n)){
    cout<<"The number "<<n<<" is Prime"<<endl;
  }else
    cout<<"The number "<<n<<" is not a Prime"<<endl;

     //code to cout PRIME NUMBERs in an interval

//    int count=0,firstNum,lastNum;
//    cout<<"Enter the first number :";
//    cin>>firstNum;
//    cout<<"Enter the last number :";
//    cin>>lastNum;
//    for(int i=firstNum;i<=lastNum;i++){
//        if(isPrime(i)){
//           count++;
//        }
//    }
//    cout<<"The count of prime numbers are in between is : "<<count<<endl;
    return 0;
}
