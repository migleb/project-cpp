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

	class Buyer::Implementation{
		private:
			string name;
			string surname;
			void init (const string &name, const string &surname = "");
			friend class Buyer;
	};

	//initializing name and surname
	void Buyer::Implementation::init (const string &name, const string &surname){
		#ifdef DEBUG
			clog << DEBUG_PREFIX "init(" << name << ", " << surname << ") called!" << endl;
		#endif
	    this->name = name;
	    this->surname = surname;
	}	

	//constructor (1 arg.)
	Buyer::Buyer (const string &name)
		: impl(new Implementation())
	{
	    #ifdef DEBUG
			clog << DEBUG_PREFIX "Constructor (1 arg) called!" << endl;
		#endif
	    impl->init(name);  
	    assert(impl->name.length());
	}

	//constructor (2 arg.)
	Buyer::Buyer (const string &name, const string &surname)
		: impl(new Implementation())
	{
		#ifdef DEBUG
			clog << DEBUG_PREFIX "Constructor (2 arg) called!" << endl;
		#endif
	    impl->init(name, surname);
	}

	//destructor
	Buyer::~Buyer () {
		#ifdef DEBUG
			clog << DEBUG_PREFIX "Destructor called!" << endl;
		#endif
		delete impl;
	}

	//setters
	void Buyer::set_name (const string &name){
		#ifdef DEBUG
			clog << DEBUG_PREFIX "set_name(" << name << ") called!" << endl;
		#endif
		impl->name = name;
	}

	void Buyer::set_surname (const string &surname){
		#ifdef DEBUG
			clog << DEBUG_PREFIX "set_surname(" << surname << ") called!" << endl;
		#endif
		impl->surname = surname;
	}

	//getters
	string Buyer::get_name (){
		return impl->name;
	}

	string Buyer::get_surname(){
		return impl->surname;
	}

	template <typename T>
	T Buyer::to_string() const{
		stringstream ss;
		ss << impl->name << " " << impl->surname;
		return ss.str();
	}

	template string Buyer::to_string() const;

	ostream& operator<<(ostream &o, Buyer &buyer){
		o << buyer.to_string<string>() << endl;
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
