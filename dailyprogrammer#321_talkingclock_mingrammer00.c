//reddit dailyprogrammer challenge #321 talking clock
//by mingrammer00
//mingrammer.blogspot.sg

#include <stdio.h>
#include <string.h>

int checkPM(char []);
int convertHour(char []);
int convertMin(char []);
void writeMin(char [], int);

int main(void) {
	char time[5], minutes[99], 
		 hour[][20] = {"twelve", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven"},
		 timing[][3] = {"am", "pm"};
	int isPM = 0, timeH, timeM;

	printf("Enter the time in HH:MM : ");
	scanf("%s", time);

	isPM = checkPM(time);
	timeH = convertHour(time);
	timeM = convertMin(time);
	writeMin(minutes, timeM);

	if (isPM == 2 || timeH >= 12 || timeM >= 60){
		printf("Invalid time\n");
	}
	else if (timeM != 0){
		printf("It\'s %s %s %s\n", hour[timeH], minutes, timing[isPM]);
	}
	else{
		printf("It\'s %s %s\n", hour[timeH], timing[isPM]);
	}
	return 0;
}

//function checks if time is AM or PM
//returns 1 if PM, returns 0 if AM
//invalid return 2
int checkPM(char time[]){
	//if time is between 00:00 to 11:59 incl
	if((int)time[0] == 48 || ((int)time[0] == 49 && (int)time[1] < 50)){
		return 0;
	}
	//if time is between 12:00 to 23:59 incl
	else if (((int)time[0] == 49 && (int)time[1] >= 50) || ((int)time[0] == 50 && (int)time[1] <= 51)){
		return 1;
	}
	//other random time from 24:00 etc onwards
	return 2;
}

//function returns numerical number of hour
int convertHour(char time[]){
	int timeHour;
	timeHour = ( (int)time[0] -48) * 10;
	timeHour += (int)time[1] - 48;
	//for convenience, 0 is represented as 'twelve' in array in main function
	if(timeHour >= 12) {
		timeHour -= 12;
	}
	return timeHour;
}

//function returns numerical number of minute
int convertMin(char time[]){
	int timeMin;
	timeMin = ( (int)time[3] - 48) * 10;
	timeMin += (int)time[4] - 48;
	return timeMin;
}
//function checks the written form of minute
//pre-cond: min > 0
void writeMin(char minutes[99], int min){
	char digits[10][99] = {" one", " two", " three", " four", " five", " six", " seven", " eight", " nine"},
		 tens[10][99] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fiften", "sixteen", "seventeen", "eighteen", "nineteen"};

	switch(min/10){
		case 0:
			if(min != 0){
				strcpy(minutes, "oh");
			}
			break;
		case 2:
			strcpy(minutes, "twenty");
			break;
		case 3:
			strcpy(minutes, "thirty");
			break;
		case 4:
			strcpy(minutes, "forty");
			break;
		case 5:
			strcpy(minutes, "fifty");
			break;
	}
	if(min/10 != 1 && min%10 > 0) {
		strcat(minutes, digits[min%10-1]);
	}

	if (min/10 == 1){
		strcpy(minutes, tens[min%10]);
	}
}

