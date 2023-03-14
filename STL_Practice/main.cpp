#include <iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<list>
#include<map>
#include<array>
using namespace std;

//1.STL :Standard template Library
//2.It consists of three :
//    a.Container
//    b.Iterator
//    c.Algorithm
// Array   Synatx: array<Type,Size> name;
// Access Elements:
//     a. at()
//     b. []
//     c. front()
//     d. back()
//     e. data()// give access to the underlying array
//Vectors:
//syntax: vector<Type> name;
//Modifiers:
//insert(),emplace(),push_back(),emplace_back(),pop_back(),resize(),swap()
//erase(),clear()

int main()
{
   array<int,5> myarray;
   myarray={1,2,3,4,5};
   array<int,4> myarray_2={0,9,8,7};
   array<int,3> myarray_3 {5,3,6};
   cout<<myarray.front()<<endl;
   cout<<myarray_2.at(3)<<endl;
   cout<<myarray_3.back()<<endl;

    return 0;
}
