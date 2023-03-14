#pragma once
#include<string>
#include <vector>
using namespace std;
struct Athlete
{
    string name;
    string surname;
    float bench_press_record;
    float deadlift_record;
};
double average_deadlift_record(const vector<Athlete> &athletes);
double bench_press_record(const vector<Athlete> &athletes);
void print_athlete(const Athlete &athlete);
void sort_by_potential(vector<Athlete> &athletes);
Athlete initialise_athlete();

