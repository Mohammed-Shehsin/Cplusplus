#include "time.h"

using namespace std;
Time::Time(int sec)
{
if(sec<60){
    sec_=sec;
}else if(sec>=60.0 && sec<3600.0){
    minu_=sec/60.0;
    sec_=((sec/60.0)-minu_)*60.0+1;
}else if(sec>3600){
    hours_=sec/3600.0;
    minu_=(sec/3600.0-hours_)*60.0;
    sec_=((sec/3600.0-hours_)*60.0-minu_)*60.0;
}

}
void Time::print() const{
    if(hours_!=0){
    cout<<hours_<<"h:"<<minu_<<"m:"<<sec_<<"s"<<endl;}
    else if(hours_==0 ){
    cout<<minu_<<"m:"<<sec_<<"s"<<endl;
    }else{
    cout<<sec_<<"s"<<endl;
    }
}
Time Time::operator+(const Time &rhs)const{
    return Time(((hours_+rhs.hours_)*3600)+((minu_+rhs.minu_)*60)+sec_+rhs.sec_);
}
Time Time::operator-(const Time &rhs)const{
    return Time(((hours_-rhs.hours_)*3600)+((minu_-rhs.minu_)*60)+(sec_-rhs.sec_));
}
ostream &operator<<(ostream &str, Time &rhs){
   if(rhs.hours_==0&&rhs.minu_==0){
       str<<rhs.sec_<<"s"<<endl;
   }else if(rhs.hours_==0){
       str<<rhs.minu_<<"m:"<<rhs.sec_<<"s"<<endl;
   }else{
       str<<rhs.hours_<<"h:"<<rhs.minu_<<"m:"<<rhs.sec_<<"s"<<endl;
   }
    return str;
}
istream &operator>>(istream &str, Time &rhs){
    string temp;
    str>>temp;
    size_t h_postion = temp.find("h");
    if(h_postion!=string::npos){
        rhs.hours_=stoi(temp.substr(0,h_postion));
        size_t m_postion =temp.find("m");
        rhs.minu_=stoi(temp.substr(h_postion+2,m_postion));
        rhs.sec_=stoi(temp.substr(m_postion+2,temp.length()-2));
    }

       return str;
}

Time::operator int(){

    return hours_*3600 + minu_*60 + sec_;

}
