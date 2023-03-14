#include <iostream>

using namespace std;
void input_array(char *array,int n){

    for(int i=0;i<n;i++){
        cin>>array[i];
    }
}
void small_to_cap(char *array){

   for(int i=0;array[i]!='\0';i++){
       if(array[i]>='a'&& array[i]<='z'){
       array[i]=array[i]-32;}
   }
   cout<<"Capital letter of the inputed elements are : "<<endl;
   for(int j=0;array[j]!='\0';j++){
      cout<<array[j]<<" ";
   }
}
int main()
{
    char array[50]={};
    int n;
    cout<<"enter the iteration : ";
    cin>>n;
    cout<<"Input the characters :"<<endl;
    input_array(array,n);
    small_to_cap(array);

    return 0;
}
