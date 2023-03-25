#include "time.h"
#include <iostream>

using namespace std;

int main()
{
    Time t1(200);
    cout << t1 << endl; // displays 03m:20s
    Time t2;
    cout<<"Enter the time in 00h:00m:00s Format :"<<endl;
    cin >> t2; // user enters 10h:12m:01s

    Time t3 = t2 - t1; // 10h:8m:41s
    cout <<t3<<endl;
    int t3s = t3; // 36521
    cout<<"in seconds :"<<t3s<<endl;
    return 0;
}
