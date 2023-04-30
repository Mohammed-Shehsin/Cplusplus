#include <iostream>

using namespace std;

class Point {
private:
    int x,y;
public:


Point(int x=0,int y=0):x(x),y(y){}

friend ostream &operator<<(ostream &COUT,Point &rhs){
       if(rhs.y==0){
           COUT<<rhs.x<<endl;
       } else{
           COUT<<rhs.x<<"."<<rhs.y<<endl;
       }
                 return COUT;
    }
Point operator+(const Point &rhs)const{

    return Point(x+rhs.x,y+rhs.y);
}

Point operator-(const Point &rhs)const{
    return Point(x-rhs.x,y-rhs.y);
}
bool operator==(const Point &rhs)const{
    return (x==rhs.x&&y==rhs.y);
}
};

int main()
{
    Point point1(3,4);
    Point point2(1,2);
    cout<<"Point 1: "<<point1<<endl;
    cout<<"Point 2: "<<point2<<endl;

    Point sum =point1+point2;
    cout<<"Sum :"<<sum<<endl;

    Point difference = point1- point2;
    cout<<"Difference :"<<difference<<endl;

    bool areEqual= point1==point2;
    cout<<"Are equal? "<<(areEqual ? "Yes" :"No")<<endl;


}
