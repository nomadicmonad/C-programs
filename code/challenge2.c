#include <stdio.h>
#include <stdlib.h>
int getCharNumber(char);
int convertNumber(int,int,char*);
int tenPow(int);

void main(int argc, char** argv) {
    //downtime of a fictional powerplant which is down every 3, 14 and 100 days
    char* command = argv[1]; //number of days
    int count = 0;
    while ((command[count++]) != '\0') {
    }
    int days = convertNumber(0,count-2,command);
    printf("Days in operation over %.d days: %.d",days,(days - days/3 - days/100 - days/14 + days/300 + days/42 + days/1400));
}
int convertNumber(int start,int end,char* command) {
        int i;
        int sum = 0;
        for (i = 0; i <= (end-start); i++) {
            sum += getCharNumber(command[i+start])*(tenPow((end-start) - i));}
        return sum;
    }
    int tenPow(int power) {
        if (power == 0) {return 1;}
        else {return 10*tenPow(power-1);}
    }
int getCharNumber(char character) {
	    int number;
        switch (character) {
        case '0' : {number = 0;break;}
        case '1' : {number = 1;break;}
        case '2' : {number = 2;break;}
        case '3' : {number = 3;break;}
        case '4' : {number = 4;break;}
        case '5' : {number = 5;break;}
        case '6' : {number = 6;break;}
        case '7' : {number = 7;break;}
        case '8' : {number = 8;break;}
        case '9' : {number = 9;break;}
        }
        return number;
	}
