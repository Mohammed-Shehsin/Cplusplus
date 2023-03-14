#include"athlete.h"
#include<iostream>
#include <vector>
#include<algorithm>
#include<iterator>
using namespace std;
void print_athlete(const Athlete &athlete){
     std::cout << "Full name: " << athlete.name + " " + athlete.surname << std::endl;
    std::cout << "Bench press personal best: " << athlete.bench_press_record << " kg. " << std::endl;
    std::cout << "Deadlift personal best: " << athlete.deadlift_record << " kg. " << std::endl;
}
Athlete initialise_athlete(){
    Athlete athlete;
    cout<<"Enter athlete's first name: ";
    cin>>athlete.name;
    cout<<"Enter athlete's surname: ";
    cin>>athlete.surname;
    cout<<"Enter athlete's bench press personal best: ";
    cin>>athlete.bench_press_record;
    cout<<"Enter athlete's deadlift personal best: ";
    cin>> athlete.deadlift_record;
    return athlete;
}
double bench_press_record(const vector<Athlete> &athletes){
    vector<double>total_bench_press_record;
    for(const auto &athlete :athletes){
        total_bench_press_record.emplace_back(athlete.bench_press_record);
    }
   double max=total_bench_press_record.at(0);
   for(auto record:total_bench_press_record){
       if(max<record){
           max=record;
       }
   }
 return max;
}
double average_deadlift_record(const vector<Athlete> &athletes){
    vector<double>total_dealift;
    for(auto &athlete :athletes){
        total_dealift.emplace_back(athlete.deadlift_record);
    }
    double sum_deadlift = 0;
    for(auto deadlift:total_dealift){
        sum_deadlift=sum_deadlift+deadlift;
    }
    return sum_deadlift/total_dealift.size();
}
bool potential( Athlete &a1 ,  Athlete &a2 ) {
    return (a1.bench_press_record+a1.deadlift_record)>(a2.bench_press_record+a2.deadlift_record);
}
void sort_by_potential(vector<Athlete> &athletes){
    sort(athletes.begin(),athletes.end(),potential);
}
