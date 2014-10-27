#include "Company.h"

#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <stdexcept>

using namespace std;
using namespace Bus_ticket;

class Company_Test {

	private:
		static void print_test(int number, bool result){
			if (result){
				clog << "Ok!" << endl;
			}else {
				clog << "Test " << number << " failed" << endl;
			}
		}

	public:
		// test 1
		static void test1 () {
			try{
				Company c("COMPANY NAME");
				print_test(1, c.get_name() == "COMPANY NAME");
			}	
			catch (...) {
				print_test(1, false);
			}		
		}

		// test 2
		static void test2 () {
			Company c("COMPANY");
			stringstream ss;
			string str1(c.to_string());
			try {
				ss << c;
				ss >> c;
				string str2(c.to_string());
				print_test(2, str1.compare(str2) == 0);
			}
			catch (...) {
				print_test(2, false);
			}
		}
};

int main () {
	//get stream buffers
	streambuf *clog_backup = clog.rdbuf();
	streambuf *cerr_backup = cerr.rdbuf();
	
	//log file
	fstream log_file;
	streampos init_pos;
	log_file.open("log.txt", fstream::out | fstream::app);

		if (log_file.is_open()){
		//redirect stream to file
		clog.rdbuf(log_file.rdbuf());
		cerr.rdbuf(log_file.rdbuf());
		
		//perform tests
		log_file << "class Company testing started" << endl;
		log_file << "Test 1:" << endl;
		Company_Test::test1();
		log_file << "Test 2:" << endl;
		Company_Test::test2();
		log_file << "class Company testing finished" << endl;
		
		//close
		log_file.close();
	}
	else{
		cout << "Could not open file 'log.txt' for writing" << endl;
	}
	
	log_file.open("log.txt", fstream::in);
	
	if (log_file.is_open()){
		char line[80];
		while (log_file.good()){
			log_file.getline(line, 80);
			cout << line << endl;
		}
	}
	else{
		cout << "Could not open file 'log.txt' for reading" << endl;
	}

	//restore initial stream buffers
	clog.rdbuf(clog_backup);
	cerr.rdbuf(cerr_backup);
	
	return 0;
}