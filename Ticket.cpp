//#define DEBUG
#define DEBUG_PREFIX "--> "

#include "Ticket.h"
#include <sstream>
#include <string>
#include <iostream>
#include <cassert>
#include <stdexcept>

using namespace std;

namespace Bus_ticket {

	Ticket::Ticket (const int discount){
		#ifdef DEBUG
			clog << DEBUG_PREFIX "Constructor called!" << endl;
		#endif
		set_discount(discount);
		id = ++sold;
		alive++;
		assert(this->id >= 0);
	}
	Ticket::~Ticket (){
		#ifdef DEBUG
			clog << DEBUG_PREFIX "Destructor called!" << endl;
		#endif
		alive--;
	}

	void Ticket::set_discount (const int &d){
		#ifdef DEBUG
			clog << DEBUG_PREFIX "set_discount(" << d << ") called!" << endl;
		#endif
		if (d >= 0){
			this->discount = d;	
		} else {
			#ifdef DEBUG
				clog << DEBUG_PREFIX "invalid argument " << endl;
			#endif
			throw invalid_argument("Discount must be between 0 and 100");	
		}
		
	}


	void Ticket::set_quantity (const int &quantity){
		#ifdef DEBUG
			clog << DEBUG_PREFIX "set_quantity(" << quantity << ") called!" << endl;
		#endif
		if (quantity > 0){
			this->quantity = quantity;
		} else {
			#ifdef DEBUG
				clog << DEBUG_PREFIX "Quantity must be positive" << endl;
			#endif
			throw invalid_argument("Quantity must be positive");
		}
	}

	Ticket Ticket::operator++(){
		#ifdef DEBUG
			clog << DEBUG_PREFIX "Pre-increasing Ticket quantity" << endl;
		#endif
		
		this->set_quantity(this->get_quantity() + 1);
		alive++;
		
		#ifdef DEBUG
			clog << DEBUG_PREFIX << this->to_string() << endl;
		#endif
		
		return *this;
	}

	Ticket Ticket::operator++(int){
		#ifdef DEBUG
			clog << DEBUG_PREFIX "Post-increasing Ticket quantity" << endl;
		#endif
		
		Ticket temp = *this;
		this->set_quantity(this->get_quantity() + 1);
		alive++;
		
		#ifdef DEBUG
			clog << DEBUG_PREFIX << this->to_string() << endl;
		#endif
		
		return *this;
	}

	Ticket Ticket::operator+=(const int &number){
		#ifdef DEBUG
			clog << DEBUG_PREFIX "Increasing Ticket quantity by " << number << endl;
		#endif
		
		this->set_quantity(this->get_quantity() + number);
		alive++;
		
		#ifdef DEBUG
			clog << DEBUG_PREFIX << this->to_string() << endl;
		#endif
		
		return *this;
	}


	Ticket& operator!(Ticket &ticket){
		 #ifdef DEBUG
		 	clog << DEBUG_PREFIX "Discount equals zero" << endl;
		 #endif
		ticket.set_discount(0);
		#ifdef DEBUG
			clog << DEBUG_PREFIX << ticket.to_string() << endl;
		#endif
		return ticket;
	}


	int Ticket::total_count (){
		return sold;
	}

	int Ticket::total_alive (){
		return alive;
	}

	int Ticket::get_discount (){
		return discount;
	}

	int Ticket::get_id (){
		return id;
	}

	int Ticket::get_quantity (){
		return quantity;
	}

	string Ticket::to_string (){
		stringstream ss;
		ss << sold << " " << id << " " << discount << " " << alive;
		return ss.str();
	}

	ostream& operator<<(ostream &o, Ticket &ticket){
		o << ticket.get_discount() << endl;
		return o;
	}

	istream& operator>>(istream &i, Ticket &ticket){
		int discount;
		
		{			
			i >> discount;
			
			if (i.fail()){
				i.clear();
				i.ignore(256, '\n');
				throw ios_base::failure("Input error");
			}
		}
		
		ticket.set_discount(discount);
		
		return i;
	}


	int Ticket::alive = 0;
	int Ticket::sold = 0;

}