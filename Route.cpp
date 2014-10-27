//#define NDEBUG
#define DEBUG_PREFIX "--> "

#include "Route.h"
#include <sstream>
#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>

using namespace std;

namespace Bus_ticket {

	Route::Route (const int &hour_departure, const int &minute_departure, const int &hour_arrival, const int &minute_arrival, const string &city_departure,
		  const string &city_arrival, const double &price){
		#ifdef DEBUG
			clog << DEBUG_PREFIX "Constructor called!" << endl;
		#endif
		tickets = 0;
		set_deptime (hour_departure,minute_departure);
		set_arrtime (hour_arrival,minute_arrival);
		set_route(city_departure,city_arrival);
		set_price(price);
	}

	Route::~Route(){
		#ifdef DEBUG
			clog << DEBUG_PREFIX "Destructor called!" << endl;
		#endif
	}

	void Route::set_deptime (const int &hour, const int &minute){
		#ifdef DEBUG
			clog << DEBUG_PREFIX "set_deptime(" << hour << ", " << minute << ") called!" << endl;
		#endif
		if ((hour <= 24) && (hour >= 0) && (minute < 60) && (minute >= 0)){
			hour_departure = hour;
			minute_departure = minute;
		} else {
			if ((hour > 24) || (hour < 0)){
				#ifdef DEBUG
					clog << DEBUG_PREFIX "invalid argument: " << hour << endl;
				#endif
			}
			if ((minute >= 60) || (minute < 0)){
				#ifdef DEBUG
					clog << DEBUG_PREFIX "invalid argument: " << minute << endl;
				#endif
			}
			throw invalid_argument("Hour and minute must be valid");	
		}
	}

	void Route::set_arrtime (const int &hour, const int &minute){
		#ifdef DEBUG
			clog << DEBUG_PREFIX "set_arrtime(" << hour << ", " << minute << ") called!" << endl;
		#endif
		if ((hour <= 24) && (hour >= 0) && (minute < 60) && (minute >= 0)){
			hour_arrival = hour;
			minute_arrival = minute;
		}
	}

	void Route::set_route (const string &start, const string &finish){
		#ifdef DEBUG
			clog << DEBUG_PREFIX "set_route(" << start << ", " << finish << ") called!" << endl;
		#endif
		city_departure = start;
		city_arrival = finish;
	}

	void Route::set_price (const double &price){
		#ifdef DEBUG
			clog << DEBUG_PREFIX "set_price(" << price << ") called!" << endl;
		#endif
		if (price > 0){
			this->price = price;
		} else {
			#ifdef DEBUG
				clog << DEBUG_PREFIX "invalid argument: " << price << endl;
			#endif
			throw invalid_argument("price must be positive");
		}
	}

	string Route::get_deptime (){
		stringstream time;
		time << hour_departure << ":" << minute_departure;
		return time.str();
	}

	string Route::get_arrtime (){
		stringstream time;
		time << hour_arrival << ":" << minute_arrival;
		return time.str();
	}

	string Route::get_depcity (){
		return city_departure;
	}

	string Route::get_arrcity (){
		return city_arrival;
	}

	int Route::get_tickets (){
		return tickets;
	}

	double Route::get_price (){
		return price;
	}

	string Route::to_string (){
		stringstream ss;
		ss << hour_departure << " " << minute_departure << " " << hour_arrival << " " << minute_arrival << " " <<
		city_departure << " " << city_arrival << " " << price << endl;
		return ss.str();
	}

	ostream& operator<<(ostream &o, Route &route){
		o << route.to_string() << endl;
		return o;
	}

	istream& operator>>(istream &i, Route &route){
	    int hour_departure;
	    int minute_departure;
	    int hour_arrival;
	    int minute_arrival;
	    string city_departure;
	    string city_arrival;
	    double price;
		
		{			
			i >> hour_departure;
			i >> minute_departure;
			i >> hour_arrival;
			i >> minute_arrival;
			i >> city_departure;
			i >> city_arrival;
			i >> price;
			
			if (i.fail()){
				i.clear();
				i.ignore(256, '\n');
				throw ios_base::failure("Input error");
			}
		}
		
		route.set_deptime(hour_departure,minute_departure);
		route.set_arrtime(hour_arrival,minute_arrival);
		route.set_route(city_departure,city_arrival);
		route.set_price(price);

		return i;
	}
}