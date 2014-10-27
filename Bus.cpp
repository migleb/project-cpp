//#define NDEBUG
#define DEBUG_PREFIX "--> "

#include "Bus.h"
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <fstream>

using namespace std;

namespace Bus_ticket {

	Bus::Bus (const int &seats){
		#ifdef DEBUG
			clog << DEBUG_PREFIX "Constructor called!" << endl;
		#endif
		set_seats(seats);
	}

	Bus::~Bus(){
		#ifdef DEBUG
			clog << DEBUG_PREFIX "Destructor called!" << endl;
		#endif
	}

	void Bus::set_seats (const int &seats){
		#ifdef DEBUG
			clog << DEBUG_PREFIX "set_seats(" << seats << ") called!" << endl;
		#endif
		if (seats > 0) {
			this->seats = seats;
		} else {
			#ifdef DEBUG
				clog << DEBUG_PREFIX "invalid argument: " << seats << endl;
			#endif
			throw invalid_argument("Seats' number must be positive");
		}
	}

	int Bus::get_seats (){
		return seats;
	}

	string Bus::to_string (){
		stringstream ss;
		ss << seats << endl;
		return ss.str();
	}

	ostream& operator<<(ostream &o, Bus &bus){
		o << bus.to_string() << endl;
		return o;
	}

	istream& operator>>(istream &i, Bus &bus){
		int seats;
		
		{			
			i >> seats;
			
			if (i.fail()){
				i.clear();
				i.ignore(256, '\n');
				throw ios_base::failure("Input error");
			}
		}
		
		bus.set_seats(seats);
		
		return i;
	}

}