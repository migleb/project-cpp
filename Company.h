#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#define string std::string
#define ostream std::ostream
#define istream std::istream

namespace Bus_ticket {

	class Company {
	    private:
	    	class Implementation;
	    	Implementation *impl;
	    public:
	        Company(const string &name);
	        ~Company();
	        void set_name (const string &_name);
	        string get_name ();
	        string to_string();
	        friend ostream& operator<<(ostream &o, Company &company);
            friend istream& operator>>(istream &i, Company &company);
	};

	/**
    *
    * \class Company
    * 
    * \brief Indicates company (company name)
    *
    */

    ostream& operator<<(ostream &o, Company &company);
    istream& operator>>(istream &i, Company &company);
}

#undef string
#undef ostream
#undef istream

#endif