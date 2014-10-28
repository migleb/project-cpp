#ifndef BUS_H
#define BUS_H

#include <string>
#include "Route.h"

#define string std::string
#define ostream std::ostream
#define istream std::istream

namespace Bus_ticket {

    class Bus {
        private:
            class Implementation;
            Implementation *impl;
        public:
            Bus(const int &seats, Route *r);
            ~Bus();
            void set_seats (const int &_seats);
            int get_seats ();
            string to_string();
            friend ostream& operator<<(ostream &o, Bus &Bus);
            friend istream& operator>>(istream &i, Bus &Bus);
    };
    /**
    *
    * \class Bus
    * 
    * \brief Describes bus (number of seats)
    *
    */

    ostream& operator<<(ostream &o, Bus &Bus);
    istream& operator>>(istream &i, Bus &Bus);
}

#undef string
#undef ostream
#undef istream

#endif