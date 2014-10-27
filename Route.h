#ifndef ROUTE_H
#define ROUTE_H

#include <string>
#define string std::string
#define ostream std::ostream
#define istream std::istream

namespace Bus_ticket {

    class Route {
        private:
            class Implementation;
            Implementation *impl;
        public:
            Route(const int &hour_departure, const int &minute_departure, const int &hour_arrival, const int &minute_arrival, const string &city_departure,
                  const string &city_arrival, const double &price);
            ~Route();
            void set_deptime(const int &hour, const int &minute);
            void set_arrtime(const int &hour, const int &minute);
            void set_route(const string &start, const string &finish);
            void set_price(const double &price);
            string get_deptime();
            string get_arrtime();
            string get_depcity();
            string get_arrcity();
            int get_tickets();
            double get_price();
            string to_string();
            friend ostream& operator<<(ostream &o, Route &route);
            friend istream& operator>>(istream &i, Route &route);
    };

    /**
    *
    * \class Route
    * 
    * \brief Describes route (departure/arrival time, cities, price and sold tickets)
    *
    */

    ostream& operator<<(ostream &o, Route &route);
    istream& operator>>(istream &i, Route &route);
}

#undef string
#undef ostream
#undef istream

#endif