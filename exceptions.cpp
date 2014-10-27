#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

#include <exception>
#include <stdexcept>

#include "Buyer.h"
#include "Company.h"
#include "Bus.h"
#include "Route.h"
#include "Ticket.h"

using namespace std;
using namespace Bus_ticket;

int main () {

	Buyer b("vardas", "pavarde");

	while (true) {
		cout << "Enter purchaser name and surname:" << endl;
		try {
			cin >> b;
			break;
		}
		catch (ios_base::failure &f) {
			cerr << f.what() << endl;
		}
		catch (invalid_argument &f){
			cerr << f.what() << endl;
		}
	}
	cout << b;

	Company c("pavadinimas");
	while (true){
		cout << "Enter company name:" << endl;
		try {
			cin >> c;
			break;
		}
		catch (ios_base::failure &f){
			cerr << f.what() << endl;
		}
	}
	cout << c;

	Bus new_bus(40);
	while (true){
		cout << "Enter seats number:" << endl;
		try {
			cin >> new_bus;
			break;
		}
		catch (ios_base::failure &f){
			cerr << f.what() << endl;
		}
	}
	cout << new_bus;

	
	system("PAUSE");
}