#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int convertNumber(int,int,char*);
int tenPow(int);
int getCharNumber(char);
int randomSum(int,int);

//dice roll of format aDb +- c, e.g. 10D6+2 as argument
void main(int argc, char** argv) {
    char* command = argv[1];
	int count = 0, d = -1, modifier = -1, isPlus = 0;
	char current;
	while ((current = command[count++]) != '\0') {
        if (current == 'd' || current == 'D') {
            d = count -1;
        }
        else if (current == '+') {
            modifier = count -1;
            isPlus = 1;
        }
        else if (current == '-') {
            modifier = count -1;
            isPlus = 0;
        }
	}
	int a,b;
	signed int c;
    if (d == 0) {a = 1;} else {a = convertNumber(0,d-1,command);}
    if (modifier != -1) {b = convertNumber(d+1,modifier-1,command); c = convertNumber(modifier+1,count-2,command);}
    else {b = convertNumber(d+1,count-2,command); c = 0;}
    if (isPlus == 0) {c = -c;}
    unsigned int iseed = (unsigned int)time(NULL);
    srand (iseed);
    printf("\nSum of %.d random number(s) between 1 and %.d + %.d is equal to %.d",a,b,c,randomSum(a,b)+c);

}
    int randomSum(int count,int number) {
        int randomNumber = rand()%(number) +1;
        printf("[%.d] ",randomNumber);
        if (count == 1) {return randomNumber;}
        else {return (randomNumber + randomSum(count-1, number));}
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
