#ifndef TICKET_H
#define TICKET_H

#include <string>
#define string std::string
#define ostream std::ostream
#define istream std::istream

namespace Bus_ticket {

    class Ticket {
        private:
            static int sold;
            static int alive;
            int id;
            int discount;
            int quantity;
        public:
            Ticket(const int discount = 0);
            ~Ticket();
            void set_discount(const int &d);
            void set_quantity (const int &quantity);

            Ticket operator++(); //pre-increment of quantity
            Ticket operator++(int); //post-increment of quantity
            Ticket operator+=(const int &number); //increment of quantity
            //Ticket operator!();

            static int total_count();
            static int total_alive();
            int get_discount();
            int get_id();
            int get_quantity();
            string to_string();
            friend ostream& operator<<(ostream &o, Ticket &ticket);
            friend istream& operator>>(istream &i, Ticket &ticket);
            friend Ticket& operator!(Ticket &ticket);
    };

    /**
    *
    * \class Ticket
    * 
    * \brief Describes ticket (total sold/alive tickets, ticket id, discount, quantity)
    *
    */
    Ticket& operator!(Ticket &ticket);
    ostream& operator<<(ostream &o, Ticket &ticket);
    istream& operator>>(istream &i, Ticket &ticket);
}

#undef string
#undef ostream
#undef istream

#endif