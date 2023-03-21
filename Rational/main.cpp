#include <iostream>
#include <Rational.h>

using namespace std;

int main()
{
    Rational quarter(1, 4);
    Rational one_third(1, 3);

    Rational add_result, sub_result,mul_result,div_result;
//    add_result = one_third.add(quarter);
//    sub_result = one_third.subtract(quarter);
    add_result = one_third + quarter;
    sub_result = one_third - quarter;
    mul_result = one_third * quarter;
    div_result = one_third / quarter;
    one_third.print(); std::cout << " + "; quarter.print(); std::cout << " = "; add_result.print(); std::cout << std::endl;
    one_third.print(); std::cout << " - "; quarter.print(); std::cout << " = "; sub_result.print(); std::cout << std::endl;
    one_third.print(); std::cout << " * "; quarter.print(); std::cout << " = "; mul_result.print(); std::cout << std::endl;
    one_third.print(); std::cout << " / "; quarter.print(); std::cout << " = "; div_result.print(); std::cout << std::endl;
    cout<<"---------------------------------------------------"<<endl;
    std::cout << one_third << " + " << quarter << " = " << add_result << std::endl;
    std::cout << one_third << " - " << quarter << " = " << sub_result << std::endl;
    std::cout << one_third << " * " << quarter << " = " << mul_result << std::endl;
    std::cout << one_third << " / " << quarter << " = " << div_result << std::endl;
    cout<<"---------------------------------------------------"<<endl;
    Rational r1,r2;
    cout<<"Enter Two Rational numbers : "<<endl;
    cin>>r1>>r2;
    cout<<"You Entered : "<<r1<<"  &  "<<r2<<endl;
    Rational add_result2, sub_result2,mul_result2,div_result2;
    add_result2 = r1 + r2;
    sub_result2 = r1 - r2;
    mul_result2 = r1 * r2;
    div_result2 = r1 / r2;
    std::cout << r1 << " + " << r2 << " = " << add_result2 << std::endl;
    std::cout << r1 << " - " << r2 << " = " << sub_result2 << std::endl;
    std::cout << r1 << " * " << r2 << " = " << mul_result2 << std::endl;
    std::cout << r1 << " / " << r2 << " = " << div_result2 << std::endl;
    cout<<"_______________________________"<<endl;
    Rational r3,r4;
   cout<<"Enter Two Rational numbers : "<<endl;
   cin>>r3>>r4;
   cout<<"You Entered : "<<r3<<"  &  "<<r4<<endl;
   Rational sum = r3 + r4;
   Rational diff = r3 - r4;
   Rational mult = r3 * r4;
   Rational div = r3 / r4;
   cout<<r3<<" + "<<r4<<" = "<<sum<<endl;
   cout<<r3<<" - "<<r4<<" = "<<diff<<endl;
   cout<<r3<<" * "<<r4<<" = "<<mult<<endl;
   cout<<r3<<" / "<<r4<<" = "<<div <<endl;



    return 0;
}
