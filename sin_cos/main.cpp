#include <iostream>
#include <math.h>
#include<cmath>
using namespace std;
int factorial(int n){
    if(n==1){
        return n;
    }
    return n*factorial(n-1);
}
void calculate_trig_from_series(double x,double n ,double &sin_val,double &cos_val ){
    for(int i=0;i<n;i++){
    double sum_sin_val= (pow(-1,i)*(pow(x,(2*i)+1)))/factorial((2*i)+1);
    sin_val += sum_sin_val;

    double sum_cos_val=  (pow(-1,i)*(pow(x,(2*i))))/factorial(2*i);
    cos_val += sum_cos_val;}

}
int main()
{
    double sin_val, cos_val;
    calculate_trig_from_series(0.52, 9, sin_val, cos_val);
    cout<<sin_val<<" and "<<cos_val<<endl;// Print the results of sin_val and cos_val
    return 0;
}
