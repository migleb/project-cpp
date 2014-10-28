#include <sstream>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

#include "Buyer.h"
#include "Company.h"
#include "Bus.h"
#include "Route.h"
#include "Ticket.h"

#include "Print.hpp"

using namespace std;
using namespace Bus_ticket;

int main () {

    const int d = 3;
    Buyer* p[d];
    string _name;
    Ticket t(2);

    // buyer (template demonstration)
    for (int i = 0; i < d; i++){
        cout << "Enter buyer name:" << endl;
        cin >> _name;
        p[i] = new Buyer(_name);
    //    print<Buyer>(*p[i]);
    }

    Route* r = new Route(11,20,15,30,"Vilnius","Klaipeda",60.45);
    cout << "Route:" << endl;
    cout << r->get_deptime() << " - " << r->get_arrtime() << endl;
    cout << r->get_depcity() << " - " << r->get_arrcity() << endl;
    cout << "Price: " << r->get_price() << "LT" << endl;
    //cout << "Purchaser: " << p[1]->get_name() << endl;

    cout << "Discount: " << t.get_discount() << "%" << endl;

    !t;

    cout << "Discount: " << t.get_discount() << "%" << endl;

    //free memory
    for (int i = 0; i < d; i++){
        delete p[i];
    }

    delete r;
    //delete t;

    system("PAUSE");
}
