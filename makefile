CC = "C:\Program Files (x86)\CodeBlocks\MinGW\bin\g++"
FLAGS = -Wall 


all : build Buyer_test Company_test Bus_test Route_test Ticket_test exceptions run





rebuild: clean build

build : main.exe Buyer_test.exe Company_test.exe Bus_test.exe Route_test.exe Ticket_test.exe exceptions.exe

debug : FLAGS = -DDEBUG
debug : clean Buyer_test.exe Company_test.exe Bus_test.exe Route_test.exe Ticket_test.exe
	Buyer_test Company_test Bus_test Route_test Ticket_test

main.exe : main.cpp Buyer.cpp Company.cpp Bus.cpp Route.cpp Ticket.cpp
	$(CC) $(FLAGS) main.cpp Buyer.cpp Company.cpp Bus.cpp Route.cpp Ticket.cpp -o main.exe

Buyer_test.exe : Buyer_test.cpp Buyer.cpp
	$(CC) $(FLAGS) Buyer_test.cpp Buyer.cpp -o Buyer_test.exe

Company_test.exe : Company_test.cpp Company.cpp
	$(CC) $(FLAGS) Company_test.cpp Company.cpp -o Company_test.exe	

Bus_test.exe : Bus_test.cpp Bus.cpp
	$(CC) $(FLAGS) Bus_test.cpp Bus.cpp -o Bus_test.exe

Route_test.exe : Route_test.cpp Route.cpp
	$(CC) $(FLAGS) Route_test.cpp Route.cpp -o Route_test.exe

Ticket_test.exe : Ticket_test.cpp Ticket.cpp
	$(CC) $(FLAGS) Ticket_test.cpp Ticket.cpp -o Ticket_test.exe	

exceptions.exe : exceptions.cpp Buyer.cpp Company.cpp Bus.cpp
	$(CC) $(FLAGS) exceptions.cpp Buyer.cpp Company.cpp Bus.cpp -o exceptions.exe


Buyer_test : Buyer_test.exe
	Buyer_test

Company_test : Company_test.exe
	Company_test	

Bus_test : Bus_test.exe
	Bus_test

Route_test : Route_test.exe
	Route_test

Ticket_test : Ticket_test.exe
	Ticket_test

exceptions : exceptions.exe
	exceptions

run : main.exe
	main

clean : 
	rm -f *.exe *.o