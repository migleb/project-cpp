//#define NDEBUG
#define DEBUG_PREFIX "--> "

#include "Company.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

namespace Bus_ticket {

	Company::Company (const string &name){
		#ifdef DEBUG
			clog << DEBUG_PREFIX "Constructor called!" << endl;
		#endif
		set_name(name);
		assert(this->name.length());
	}

	Company::~Company (){
		#ifdef DEBUG
			clog << DEBUG_PREFIX "Destructor called!" << endl;
		#endif
	}

	void Company::set_name (const string &name){
		#ifdef DEBUG
			clog << DEBUG_PREFIX "set_name(" << name << ") called!" << endl;
		#endif
		this->name = name;
	}

	string Company::get_name (){
		return name;
	}

	string Company::to_string (){
		stringstream ss;
		ss << name << endl;
		return ss.str();
	}

	ostream& operator<<(ostream &o, Company &company){
		o << company.to_string() << endl;
		return o;
	}

	istream& operator>>(istream &i, Company &company){
		string name;

		{
			i >> name;

			if (i.fail()){
				i.clear();
				i.ignore(256, '\n');
				throw ios_base::failure("Input error");
			}
		}

		company.set_name(name);

		return i;
	}
}