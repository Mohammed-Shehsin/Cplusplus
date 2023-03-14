#ifndef VEHICLEPRODUCTION_H_
#define VEHICLEPRODUCTION_H_
#include <string>
#include<vector>
using namespace std;
struct VehicleProduction
{
   string manufacturer;
   string country;
   int vehicles;
};


void print_vehicle_production(const VehicleProduction &vehicle_production);
VehicleProduction initialise_vehicle_production();
void print_vector_vehicle_productions(const std::vector<VehicleProduction> &vp);
void print_largest_production(const std::vector<VehicleProduction>& vehicle_productions);
void print_smallest_production(const std::vector<VehicleProduction>& vehicle_productions);
void sort_productions(std::vector<VehicleProduction>& vehicle_productions);
#endif // VEHICLEPRODUCTION_H_
