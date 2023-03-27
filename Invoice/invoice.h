#pragma once

#include <iostream>
#include <vector>

using namespace std;


class Item{
     private:
     string name_;
     double price_;
     char tax_;
     int amount_;
    public:
    Item (string name, double price, char tax, int amount=0);

    string get_name();

    double get_price();

    char get_tax();

    int get_amount();


};

class Invoice{
    private:
    long unsigned int buyer_;
    long unsigned int seller_;
    vector<Item> item_;

    public:
    Invoice(long unsigned int seller, long unsigned int buyer){
        buyer_ = buyer;
        seller_ = seller;
    }

    void add_item(Item item);
    friend std::ostream &operator<<(std::ostream &str, Invoice &rhs);
};
