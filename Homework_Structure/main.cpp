#include <iostream>
#include "athlete.h"
#include <vector>

int main(){
    std::vector<Athlete> athletes;
    Athlete first_athlete = {"Franek","Atleta",100,120};
    Athlete second_athlete = {"Marek","Kotleta",60,70};
    Athlete third_athlete = {"Arek","Pelesze",40,40};
    Athlete fourth_athlete = initialise_athlete();
    //Athlete fourth_athlete;
    //initialise_athlete(fourth_athlete);
    athletes.emplace_back(first_athlete);
    athletes.emplace_back(second_athlete);
    athletes.emplace_back(third_athlete);
    athletes.emplace_back(fourth_athlete);
    for(auto& athlete : athletes){
        print_athlete(athlete);
    }
    std::cout << "Maximal bench press: " << bench_press_record(athletes) << " kg." << std::endl;

    std::cout << "Average deadlift: " << average_deadlift_record(athletes) << " kg." << std::endl;
    sort_by_potential(athletes);
    std::cout << "Athletes sorted by potentials: " << std::endl;
    for(auto& athlete : athletes){
        print_athlete(athlete);
    }
    return 0;
}
