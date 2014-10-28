#include <string>

#include "Company.h"
#include "Bus.h"
#include "Buyer.h"
#include "Route.h"
#include "Ticket.h"


namespace Bus_ticket {
	class Terminal {
		private:
			class Implementation;
			Implementation *impl;
		public:
			Terminal();
			~Terminal();
			void add_company(Company &c);
	};




}