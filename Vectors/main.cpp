#include <iostream>
#include <vector>
using namespace std;
int max_value(vector<int> &vec){
    int max=vec[0];
    for(auto el:vec){
        if(max< el){
        max=el;
        }
    }
    return max;
}
int min_value(vector<int> &vec){
    int min=vec[0];
    for(auto el:vec){
        if(min> el){
        min=el;
        }
    }
    return min;
}
int main()
{
  vector<int> user;
  int i = 1;
  cout<<"Enter the Elemnts :" <<endl;
  while(i!=0){
      cin>>i;
    user.emplace_back(i);
  }
  cout<<"max is "<<max_value(user)<<endl;
  cout<<"min is "<<min_value(user)<<endl;
  return 0;
}
