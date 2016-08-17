#include "serial/serial.h"
#include <string>
#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;
void pause() {
	printf("Press any key to continue.");
	_getch();
	printf("\n");
}
void printArgUsage(char* arg0) {
	printf("Incorrect argument usage!\n Correct usage: %s <port> <baud rate>\n", arg0);
	pause();
}
serial::Serial connect(	char *cport, char *cbaud = "9600") {
	string port(cport);
	string sbaud(cbaud);
	//Validate baud
	int baud;
	try {
		baud = stoi(sbaud);
	}
	catch (out_of_range) {
		printf("Baud rate was out of range!\nDefaulting to 9600.\n");
		baud = 9600;
	}
	catch (invalid_argument) {
		printf("No valid number detected.\nDefaulting to 9600.\n");
		baud = 9600;
	}
}
int main(int argc, char *argv[]) {
	if (argc != 3) {
		printArgUsage(argv[0]);
		return 0;
	}

	return 0;
}