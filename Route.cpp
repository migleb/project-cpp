//#define NDEBUG
#define DEBUG_PREFIX "--> "

#include "Route.h"

#include <sstream>
#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <vector>

using namespace std;

namespace Bus_ticket {

	class Route::Implementation{
		private:
            int hour_departure;
            int minute_departure;
            int hour_arrival;
            int minute_arrival;
            string city_departure;
            string city_arrival;
            int tickets;
            double price;
            friend class Route;
	};

	Route::Route (const int &hour_departure, const int &minute_departure, const int &hour_arrival, const int &minute_arrival, const string &city_departure,
		  const string &city_arrival, const double &price)
		: impl(new Implementation())
	{
		#ifdef DEBUG
			clog << DEBUG_PREFIX "Constructor called!" << endl;
		#endif
		impl->tickets = 0;
		set_deptime (hour_departure,minute_departure);
		set_arrtime (hour_arrival,minute_arrival);
		set_route(city_departure,city_arrival);
		set_price(price);
	}

	Route::~Route(){
		#ifdef DEBUG
			clog << DEBUG_PREFIX "Destructor called!" << endl;
		#endif
		delete impl;
	}

	void Route::set_deptime (const int &hour, const int &minute){
		#ifdef DEBUG
			clog << DEBUG_PREFIX "set_deptime(" << hour << ", " << minute << ") called!" << endl;
		#endif
		if ((hour <= 24) && (hour >= 0) && (minute < 60) && (minute >= 0)){
			impl->hour_departure = hour;
			impl->minute_departure = minute;
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
			impl->hour_arrival = hour;
			impl->minute_arrival = minute;
		}
	}

	void Route::set_route (const string &start, const string &finish){
		#ifdef DEBUG
			clog << DEBUG_PREFIX "set_route(" << start << ", " << finish << ") called!" << endl;
		#endif
		impl->city_departure = start;
		impl->city_arrival = finish;
	}

	void Route::set_price (const double &price){
		#ifdef DEBUG
			clog << DEBUG_PREFIX "set_price(" << price << ") called!" << endl;
		#endif
		if (price > 0){
			impl->price = price;
		} else {
			#ifdef DEBUG
				clog << DEBUG_PREFIX "invalid argument: " << price << endl;
			#endif
			throw invalid_argument("price must be positive");
		}
	}

	string Route::get_deptime (){
		stringstream time;
		time << impl->hour_departure << ":" << impl->minute_departure;
		return time.str();
	}

	string Route::get_arrtime (){
		stringstream time;
		time << impl->hour_arrival << ":" << impl->minute_arrival;
		return time.str();
	}

	string Route::get_depcity (){
		return impl->city_departure;
	}

	string Route::get_arrcity (){
		return impl->city_arrival;
	}

	int Route::get_tickets (){
		return impl->tickets;
	}

	double Route::get_price (){
		return impl->price;
	}

	string Route::to_string (){
		stringstream ss;
		ss << impl->hour_departure << " " << impl->minute_departure << " " << impl->hour_arrival << " " << impl->minute_arrival << " " <<
		impl->city_departure << " " << impl->city_arrival << " " << impl->price << endl;
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