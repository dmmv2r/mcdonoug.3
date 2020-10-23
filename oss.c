//Auther: Donovan McDonough
//Date: 10/22/2020

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
	int opt;
	int maxC;
	char* file;
	int time;

	bool maxArg;
	bool fileArg;
	bool timeArg;

	maxArg = false;
	fileArg = false;
	timeArg = false;

	while((opt = getopt(argc, argv, "hc:l:t:")) != -1) {
		switch(opt) {
			case 'h':
				printf("%s: Usage: %s -h (help) -c x (x is max number of children) -l filename (filename is log file) -t z (z is max time program runs). All arguments have default values.\n", argv[0], argv[0]);
				return -1;
			case 'c':
				maxC = atoi(optarg);
				maxArg = true;
				break;
			case 'l':
				file = optarg;
				fileArg = true;
				break;
			case 't':
				time = atoi(optarg);
				timeArg = true;
				break;
			default:
				return -1;
		}
	}

	if(!maxArg) {
		maxC = 5;
	}
	if(!fileArg) {
		file = "log.out";
	}
	if(!timeArg) {
		time = 100;
	}
	printf("IN OSS.C\n");

	printf("maxC: %d\n", maxC);
	printf("file: %s\n", file);
	printf("time: %d\n", time);

	system("./user");

	printf("ENDING OSS.C\n");
	return 0;
}
