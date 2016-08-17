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
int connect(char *cport, char *cbaud = "9600") {
	string port(cport);
	string sbaud(cbaud);
	//Validate baud
	int baud;
	try {
		baud = stoi(sbaud);
	}
	catch (out_of_range) {
		printf("\nBaud rate was out of range!\nDefaulting to 9600.\n");
		baud = 9600;
	}
	catch (invalid_argument) {
		printf("\nNo valid number detected.\nDefaulting to 9600.\n");
		baud = 9600;
	}
	return baud;
}
int main(int argc, char *argv[]) {
	if (argc < 2 || argc > 3) {
		printArgUsage(argv[0]);
		return 0;
	}
	if (argc == 2) {
		printf("%i\n", connect(argv[1]));
	}
	else {
		printf("%i\n", connect(argv[1], argv[2]));
	}
	pause();
	return 0;
}