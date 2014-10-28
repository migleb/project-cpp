#include <vector>
#include <string>

#include "Terminal.h"




namespace Bus_ticket {

	using namespace std;

	class Terminal::Implementation {
		private:
			vector<Company> companies;

			friend class Terminal;
	};

	Terminal::Terminal()
		: impl (new Implementation())
	{

	}

	Terminal::~Terminal() {
		delete impl;
	}

	void Terminal::add_company(Company &c){
		impl->companies.push_back(c);
	}

}