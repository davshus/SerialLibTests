#include "serial/serial.h"
#include <string>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#define	EXIT pause(); return 0
using namespace std;
void pause() {
	printf("Press any key to continue.");
	_getch();
	printf("\n");
}
void printArgUsage(char* arg0) {
	printf("Incorrect argument usage!\n Correct usage: %s <port> <baud rate>\n", arg0);
}
serial::Serial* connect(char *cport, char *cbaud = "9600") {
	string port(cport);
	string sbaud(cbaud);
	//Validate baud
	int baud;
	try {
		baud = stoi(sbaud);
	}
	catch (out_of_range) {
		throw out_of_range("Baud rate is out of range.");
	}
	catch (invalid_argument) {
		throw invalid_argument("Baud rate is not a number.");
	}
	if (baud < 0) {
		throw out_of_range("Baud rate is a negative number.");
	}
	try {
		serial::Serial *thisSerial = new serial::Serial(port, baud, serial::Timeout(1000));
		return thisSerial;
	}
	catch (const exception& e) {
		printf("There was a problem creating a Serial connection.\n");
		throw exception(e.what());
	}
}
int main(int argc, char *argv[]) {
	if (argc < 2 || argc > 3) {
		printArgUsage(argv[0]);
		EXIT;
	}
	if (argc == 2) {
		try {
			serial::Serial *SP = connect(argv[1]);
			SP->write("test");
			cout << SP->read(4) << endl;
			delete SP;
		}
		catch (const exception& e) {
			cout << e.what() << endl;
			EXIT;
		}
	}
	else {
		try {
			serial::Serial *SP = connect(argv[1], argv[2]);
			SP->write("test");
			cout << SP->read(4) << endl;
			delete SP;
		}
		catch (const exception& e) {
			cout << e.what() << endl;
			EXIT;
		}
	}
	EXIT;
}