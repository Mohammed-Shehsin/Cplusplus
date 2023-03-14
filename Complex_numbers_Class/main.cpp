#include<iostream>
#include<numeric>
#include<vector>
#include<conio.h>
#include<algorithm>
//using namespace std;
//class Student {
//private:
// std::string _name;
// std::string _surname;
// std::vector _grades;
// int _id;
//public:
// Student(string name,string surname,vector grades){
// _name=name;
// _surname=surname;
// for(auto &it: grades){
// add_grade(it);
// }
// }
// void set_id(int id=0){
// if(id >= 1000 && id <= 9999){
// _id=id;
// }
// }
// int get_id(){
// return _id;
// }


// float calculate_grade() {
// float sum = accumulate(_grades.begin(), _grades.end(), 0.0f);
// return sum / _grades.size();
// }
// void print(){
// cout<<_name<<" "<<_surname<<":";
// for(auto i:_grades ){
// cout< // }

// }
// bool add_grade(float grade) {
// if (grade >= 2.0 && grade <= 5.0) {
// // The grade is valid; let's add it and return true
// _grades.push_back(grade);
// return true;
// }
// // The grade is invalid; let's return false
// return false;
// }



// };
//int main()
//{ Student s1={"jas","hwww",{1,2,34,5}};
// s1.print();
// return 0;
//}
using namespace std;
class Complex{
private:
float _real;
float _img;


public:
Complex(float real=0,float img=0){
_real=real;
_img=img;
}
void print (){
//cout<<_real<<_img<<"i";
if(_real!=0){
cout<<_real;
if(_img!=0){
if(_img>0){
cout<<"+";}
cout<<_img<<"i"<<endl;
}
}
}
Complex add(Complex c1){
Complex c3;
c3._real=_real+c1._real;
c3._img=_img+c1._img;
return c3;
}
void set_real(float real=0){
_real=real;
}
float get_real(){
return _real;
}
void set_img(float img=0){
_img=img;
}
float get_img(){
return _img;
}
};




int main(){

Complex a(1.0, -2.0); // creates 1-2i
Complex b(3.14); // creates 3.14

b.set_img(-5);

Complex c = a.add(b);

c.print(); // prints 4.14-7i

return 0;
}
