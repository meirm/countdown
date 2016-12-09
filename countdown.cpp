#include<iostream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include <csignal>
#define VERSION "0.1.2"
using namespace std;

void signalHandler( int signum ) {
	int err=system("setterm -cursor on");
	cout << "Interrupt signal (" << signum << ") received.\n";
	// cleanup and close up stuff here  
	// terminate program  
	
	exit(signum);  
}

bool is_numeric(char *string)
{
    int sizeOfString = strlen(string);
    int iteration = 0;
    bool isNumeric = true;

    while(iteration < sizeOfString)
    {
        if(!isdigit(string[iteration]))
        {
            isNumeric = false;
            break;
        }

        iteration++;

    }

    return isNumeric;
}

void usage(int ec){
	cerr << "countdown version " << VERSION  << endl;
	cerr << "\tby Meir Michanie" << endl;
	cerr << "Usage" << endl;
	cerr << "\tcountdown <n>\t#any integer > 0" << endl;
	cerr << "\tcountdown -h\t#this help" << endl;
	exit(ec);
}

int main(int argc, char *argv[]){
	// register signal SIGINT and signal handler
	signal(SIGINT, signalHandler);
	if (argc != 2) usage(1);
	if (string(argv[1]) == "-h") usage(0);
	if (! is_numeric(argv[1])) usage(2);
	unsigned long top=atol(argv[1]);
	int err=system("setterm -cursor off");
	int bc = strlen(argv[1]);
	while (top > 0){
		cerr << top--  << string(bc, ' ') << "\r";
		sleep(1);
	}
	err=system("setterm -cursor on");
	return(0);
}
