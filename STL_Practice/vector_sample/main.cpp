#include <iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> numbers;
    vector<int> numbers2;
    cout<<"Enter the iteration :"<<endl;
    int n,a;
    cin>>n;
    cout<<"Enter the elements "<<endl;
    for(int i=0;i<n;i++){
        cin>>a;
        numbers2.insert(numbers2.begin()+i,a);
    }
    cout<<"element of Numbers2 :"<<endl;
    for(int j:numbers2){
        cout<<j<<endl;
    }
    cout<<"Enter the element index which you want to erase :  ";
    int k;
    cin>>k;
    numbers2.erase(numbers2.begin()+k-1);
    cout<<"element of Numbers2 after erased :"<<endl;
    for(int j:numbers2){
        cout<<j<<endl;
    }
    numbers.push_back(0);
    for (int i=1;i<10;i++){
    numbers.push_back(i);
    }
    cout<<"Elements of numbers :"<<endl;
    for(int i:numbers){
    cout<<i<<endl;
    }
//    for(auto itr =numbers.begin();itr!=numbers.end();itr++){
//    cout<<*itr<<endl;
//    cout<<&itr<<endl;
//    cout<<&(*itr)<<endl;
//    }
    cout<<"Size : "<<numbers.size()<<endl;
    cout<<"Max size : "<<numbers.max_size()<<endl;
    cout<<"Capacity : "<<numbers.capacity()<<endl;
    numbers.resize(5);
    cout<<"Resized : "<<numbers.size()<<endl;
    if(numbers.empty()){
    cout<<"Vector is empty!"<<endl;
    }else{
        cout<<"Vector is not empty !"<<endl;}
    cout<<"Element[0] : "<<numbers[0]<<endl;
    cout<<"Element at(0) : "<<numbers.at(0)<<endl;
    cout<<"Front :"<<numbers.front()<<endl;
    cout<<"Back :"<<numbers.back()<<endl;
    numbers.clear();
    cout<<"Size after clear :"<<numbers.size()<<endl;

            return 0;
}
