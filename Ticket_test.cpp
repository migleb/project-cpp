#include "Ticket.h"

#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <fstream>

using namespace std;
using namespace Bus_ticket;

class Ticket_Test {
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
			try {
				Ticket t(0);
				t.set_discount(50);
				print_test(1,t.get_discount() == 50);
			}
			catch (invalid_argument){
				print_test(1,false);
			}
			
		}
		
		// test 2
		static void test2 (){
			Ticket t(0);
			try {
				t.set_discount(-10);
				throw 1;
			}
			catch (invalid_argument){
				print_test(2, true);
			}
			catch (...){
				print_test(2, false);
			}
		}
		
		// test 3
		static void test3 (){
			Ticket t(50);
			stringstream ss;
			string str1(t.to_string());
			try {
				ss << t;
				ss >> t;
				string str2(t.to_string());
				print_test(3, str1.compare(str2) == 0);
			}
			catch (...){
				print_test(3, false);
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
		log_file << "class Ticket testing started" << endl;
		log_file << "Test 1:" << endl;
		Ticket_Test::test1();
		log_file << "Test 2:" << endl;
		Ticket_Test::test2();
		log_file << "Test 3:" << endl;
		Ticket_Test::test3();
		log_file << "class Ticket testing finished" << endl;
		
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


	system("PAUSE");
}