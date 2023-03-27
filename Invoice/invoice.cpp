#include "invoice.h"
#include<cstring>
using namespace std;
Item::Item(string name, double price, char tax, int amount){
    name_ = name;
    price_ = price;
    tax_ = tax;
    amount_ = amount;
}
string Item::get_name() {
    return name_;
}
double Item::get_price(){
    return price_;
}

char Item::get_tax(){
    return tax_;
}

int Item::get_amount(){
    return amount_;
}
void Invoice::add_item(Item item){
item_.emplace_back(item);
}

std::ostream &operator<<(std::ostream &str, Invoice &rhs){
        str << "------------------VAT invoice------------------" << endl;
        str << "===============================================" << endl;
        str << "Seller: " << rhs.seller_;
        str << "             Buyer:0 " << rhs.buyer_ << endl;
        str << "                  c.j.       VAT   il.        Net      Total" << endl;

        // string name;
        // double price;
        // char tax;
        // int amount;
        double sum=0,net_sum=0;
        for (Item value : rhs.item_){
            //name = item_
            str << value.get_name() << "    |   " << value.get_price() << "    |   " << value.get_tax() << "    |   " << value.get_amount() << "   |   " << value.get_amount() * value.get_price() << "   |   ";

            if (value.get_tax() == 'A'){
             sum+= 0.23*value.get_price()*value.get_amount() + value.get_price()*value.get_amount();
            str << sum<< endl;
            }
            else if (value.get_tax() == 'B'){
                sum+=0.08*value.get_price()*value.get_amount() + value.get_price()*value.get_amount();
            str << sum << endl;
            }
            else if (value.get_tax() == 'C'){
                sum+= value.get_price()*value.get_amount() ;
            str <<sum<< endl;
            }

            net_sum+= value.get_price()*value.get_amount();
        }
        // for (auto value : rhs.item_){
        //     str << value.get_name();
        // }

        str << "------------------------------------ TOTAL -------------------------"<<endl;
        str << "                            " <<"NET  "<<net_sum<<"|"<<"TOTAL  "<<sum<<endl;
        return str;
    }
