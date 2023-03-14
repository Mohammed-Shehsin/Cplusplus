#include<iostream>
#include<algorithm>
#include "vehicleproduction.h"


using namespace std;
void print_vehicle_production(const VehicleProduction &vehicle_production){
  cout<<"Manufacturer: "<<vehicle_production.manufacturer<<endl;
  cout<<"Country: "<<vehicle_production.country<<endl;
  cout<<"Vehicles: "<<vehicle_production.vehicles<<endl;
}
VehicleProduction initialise_vehicle_production(){
    VehicleProduction p1;
    cout<<"Enter manufacturer:"<<endl;
    cin>>p1.manufacturer;
    cout<<"Enter country:"<<endl;
    cin>>p1.country;
    cout<<"Enter number of vehicles:"<<endl;
    cin>>p1.vehicles;
    return p1;
}
void print_vector_vehicle_productions(const std::vector<VehicleProduction> &vp){
   for(auto &i :vp){
       print_vehicle_production(i);
   }
}
bool compare_cars_produced(const VehicleProduction &a1,const VehicleProduction &a2){
    return a1.vehicles<a2.vehicles;
}

void print_largest_production(const std::vector<VehicleProduction>& vehicle_productions){
    auto max_el = std::max_element(vehicle_productions.begin(),vehicle_productions.end(),compare_cars_produced);
    std::cout << "Largest production company: " << max_el->manufacturer << " : " << max_el->vehicles << std::endl;
}
void print_smallest_production(const std::vector<VehicleProduction>& vehicle_productions){
    auto min_el =  std::min_element(vehicle_productions.begin(),vehicle_productions.end(),compare_cars_produced);//Code here...
    std::cout << "Smallest production company: " << min_el->manufacturer << " : " << min_el->vehicles << std::endl;
}

void sort_productions(std::vector<VehicleProduction>& vehicle_productions){
    std::sort(vehicle_productions.begin(),vehicle_productions.end(),compare_cars_produced);
}
