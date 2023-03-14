#include <iostream>
#include "vehicleproduction.h"
#include <vector>

int main(){
    std::vector<VehicleProduction> vehicle_productions;
    VehicleProduction first_production = {"First","CountryA",500};
    VehicleProduction second_production = {"Second","CountryB",200};
    VehicleProduction third_production = {"Third","CountryC",300};
    VehicleProduction fourth_production = initialise_vehicle_production();
    vehicle_productions.emplace_back(first_production);
    vehicle_productions.emplace_back(second_production);
    vehicle_productions.emplace_back(third_production);
    vehicle_productions.emplace_back(fourth_production);
    print_vehicle_production(first_production);
    print_vector_vehicle_productions(vehicle_productions);
    print_largest_production(vehicle_productions);
    print_smallest_production(vehicle_productions );
    sort_productions(vehicle_productions );
    print_vector_vehicle_productions(vehicle_productions);
    //remember to add also the comparation functions (predicates) for std::algorithm functions
    return 0;
}
