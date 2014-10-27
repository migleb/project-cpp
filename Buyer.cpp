//#define NDEBUG
#define DEBUG_PREFIX "--> "

#include "Buyer.h"
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

namespace Bus_ticket {

	//constructor (1 arg.)
	Buyer::Buyer (const string &name){
	    #ifdef DEBUG
			clog << DEBUG_PREFIX "Constructor (1 arg) called!" << endl;
		#endif
	    init(name);  
	    assert(this->name.length());
	}

	//constructor (2 arg.)
	Buyer::Buyer (const string &name, const string &surname){
		#ifdef DEBUG
			clog << DEBUG_PREFIX "Constructor (2 arg) called!" << endl;
		#endif
	    init(name, surname);
	} 

	//initializing name and surname
	void Buyer::init (const string &name, const string &surname){
		#ifdef DEBUG
			clog << DEBUG_PREFIX "init(" << name << ", " << surname << ") called!" << endl;
		#endif
	    set_name(name);
	    set_surname(surname);
	}

	//destructor
	Buyer::~Buyer () {
		#ifdef DEBUG
			clog << DEBUG_PREFIX "Destructor called!" << endl;
		#endif
	}

	//setters
	void Buyer::set_name (const string &name){
		#ifdef DEBUG
			clog << DEBUG_PREFIX "set_name(" << name << ") called!" << endl;
		#endif
		this->name = name;
	}

	void Buyer::set_surname (const string &surname){
		#ifdef DEBUG
			clog << DEBUG_PREFIX "set_surname(" << surname << ") called!" << endl;
		#endif
		this->surname = surname;
	}

	//getters
	string Buyer::get_name (){
		return name;
	}

	string Buyer::get_surname(){
		return surname;
	}

	string Buyer::to_string(){
		stringstream ss;
		ss << name << " " << surname << endl;
		return ss.str();
	}

	ostream& operator<<(ostream &o, Buyer &buyer){
		o << buyer.to_string() << endl;
		return o;
	}

	istream& operator>>(istream &i, Buyer &buyer){
		string name, surname;

		{
			i >> name;
			i >> surname;

			if (i.fail()){
				i.clear();
				i.ignore(256, '\n');
				throw ios_base::failure("Input error");
			}
		}

		buyer.set_name(name);
		buyer.set_surname(surname);

		return i;
	}

}
