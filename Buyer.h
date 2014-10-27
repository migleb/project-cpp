#ifndef BUYER_H
#define BUYER_H

#include <string>
#define string std::string
#define ostream std::ostream
#define istream std::istream

namespace Bus_ticket {

    class Buyer {
        private:
            class Implementation;
            Implementation *impl;
        public:
            /**
            *
            * Name : Buyer
            *
            * Public constructor for creating new buyer with one argument:
            * name
            *
            * @param name - reference to passed name (string)
            *
            */
            Buyer (const string &name);
            /**
            *
            * Name : Buyer
            *
            * Public constructor for creating new buyer with two arguments:
            * name and surname
            *
            * @param name - reference to passed name (string)
            * @param surname - reference to passed surname (string)
            *
            */
            Buyer (const string &name, const string &surname);
            /**
            *
            * Name : ~Buyer
            *
            * Public destructor for destroying buyer
            *
            */
            ~Buyer();
            /**
            *
            * Name : set_name
            *
            * Public setting buyer name
            *
            * @param name - reference to passed name (string)
            *
            */
            void set_name (const string &_name);
            /**
            *
            * Name : set_surname
            *
            * Public setter buyer surname
            *
            * @param surname - reference to passed surname (string) 
            *
            */
            void set_surname (const string &_surname);
            /**
            *
            * Name : get_name
            *
            * Getting buyer name
            *
            * \return name
            *
            */
            string get_name();
            /**
            *
            * Name : get_surname
            *
            * Getting buyer surname
            *
            * \return surname
            *
            */
            string get_surname();
            /**
            *
            * Name : to_string
            *
            * Forming buyer object as string
            *
            * \return string - buyer object
            *
            */
            string to_string();

            /**
            *
            * Name : operator<<
            *
            * Stream to print buyer as string
            *
            * @param o - reference to output stream
            * @param buyer - reference to buyer object
            *
            * \return ostream - reference to output stream
            *
            */
            friend ostream& operator<<(ostream &o, Buyer &buyer);
            /**
            *
            * Name : operator>>
            *
            * Stream to read buyer as string
            *
            * @param i - reference to input stream
            * @param buyer - reference to buyer object
            *
            * \return istream - reference to input stream
            *
            */
            friend istream& operator>>(istream &i, Buyer &buyer);
    };

    /**
    *
    * \class Buyer
    * 
    * \brief Indicates buyer (name, surname)
    *
    */

    ostream& operator<<(ostream &o, Buyer &buyer);
    istream& operator>>(istream &i, Buyer &buyer);
}

#undef string
#undef ostream
#undef istream

#endif