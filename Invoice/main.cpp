#include <iostream>

#include "invoice.h"

using namespace std;

int main()
{
    Invoice inv(7770003699, 123456789);

    // inv.add_item("M3 screw", 0.37, 'A', 100);
    // inv.add_item("2 mm drill", 2.54, 'B', 2);

    Item item1("M3 screw", 0.37, 'A', 100);
    inv.add_item(item1);
    inv.add_item(Item("2 mm drill", 2.54, 'B', 2));

    std::cout << inv << std::endl;

    return 0;
}
