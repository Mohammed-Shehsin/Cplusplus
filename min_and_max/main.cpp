#include <iostream>

using namespace std;
void getMin_Max(int array[],int n,int&min,int&max){
    min=array[0];
    max=array[0];
    for(int i=1;i<n;i++){
        if (array[i]<min){
            min=array[i];
        }
    }
    for(int i=1;i<n;i++){
        if (array[i]>max){
            max=array[i];
        }
    }
}
int main()
{
    int array[20];
    int n;
    int min;
    int max;
    cout<<"Enter the iteration : ";
    cin>>n;
    cout<<"Enter the values "<<endl;
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
    getMin_Max(array,n,min,max);
    cout<<"Minimum value in the given element is :"<<min<<endl;
    cout<<"Maximum value in the given element is :"<<max<<endl;
}

