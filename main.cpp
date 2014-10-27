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

using namespace std;
using namespace Bus_ticket;

int main () {

    //const int d = 3;
    //Buyer* p[d];
    string _name;
    Ticket t(2);


    // for (int i = 0; i < d; i++){
    //     cin >> _name;
    //     p[i] = new Buyer(_name);
    // }

    // for (int i = 0; i < d; i++){
    //     cout << p[i]->to_string();
    // }

    Route* r = new Route(11,20,15,30,"Vilnius","Klaipeda",60.45);
    cout << "Route:" << endl;
    cout << r->get_deptime() << " - " << r->get_arrtime() << endl;
    cout << r->get_depcity() << " - " << r->get_arrcity() << endl;
    cout << "Price: " << r->get_price() << "LT" << endl;
    //cout << "Purchaser: " << p[1]->get_name() << endl;

    cout << "Discount: " << t.get_discount() << "%" << endl;

    !t;

    cout << "Discount: " << t.get_discount() << "%" << endl;
    // for (int i = 0; i < d; i++){
    //     delete p[i];
    // }

    delete r;
    //delete t;

    system("PAUSE");
}
