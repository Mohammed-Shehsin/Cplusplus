#include <iostream>

using namespace std;

int main()
{
    int array[50]={},n,swap=0;
    cout<<"Enter your Array Iteration : ";
    cin>>n;
    cout<<"Enter your array element : "<<endl;
    for(int i=0;i<n;i++){
        cin>>array[i];
    }
      do{
         swap=0;
          for(int i=0;i<n-1;i++){
              if(array[i]>array[i+1]){
               int temp = array[i];
               array[i]=array[i+1];
               array[i+1]= temp;
               swap=1;
              }
          }
      }while(swap);
    cout<<"Sorted array is : "<<endl;
    for(int j=0;j<n;j++){
        cout<<array[j]<<endl;
    }
    return 0;
}
