#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//a struct that contains a character and its frequency
struct freq_point {
	char c;
	int freq;
};

typedef struct freq_point freq_point;

//check if it is a lower case char
int isInRange(char c) {
	return (c >= 97 && c <= 122);
}

//count the number of each character from the file parameter
void count(freq_point chars[], char file[]) {
	//open the data file
	FILE *txt;
	txt = fopen(file, "r");
	if(!txt) {
		printf("File %s not found.\n", file);
		return;
	}
	//add one to the place in the array representing the char
	char c;
	do {
		c = fgetc(txt);
		c = tolower(c);
		if(isInRange(c))
			chars[c-97].freq++;
	} while(c != EOF);
}

//a function to sum up the chars
int getSum(freq_point nums[], int size) {
	int sum = 0;
	int i;
	for(i = 0; i < size; i++) {
		sum += nums[i].freq;
	}
	return sum;
}

//make a frequency point thing
freq_point freq_pointConstructor(char c) {
	freq_point f;
	f.c = c;
	f.freq = 0;
	return f;
}

//bubble sort!
void sort(freq_point p[]) {
	int i,j,f,ch;
	for(i = 0; i < 26-1; i++) {
		for(j = 0; j < 26-1; j++) {
			if(p[j].freq < p[j+1].freq) {
				f = p[j+1].freq;
				ch = p[j+1].c;
				p[j+1].freq = p[j].freq;
				p[j+1].c = p[j].c;
				p[j].freq = f;
				p[j].c = ch;

			}
		}
	}
}

//print the array of characters, used after a call to sort() to display the result
void printResult(freq_point frequencies[], int sum) {
	int i;
	for(i = 0; i < 26; i++) {
		printf("%c\t%10d\t%6.2f%%\n", frequencies[i].c, frequencies[i].freq, (double)frequencies[i].freq / sum * 100.0);
	}

}

//save the reult to a file
//saved as one line of characters sorted according to frequency
void saveResult(char *fn, freq_point data[]) {
	FILE *f = fopen(fn, "w");
	int i;
	for(i = 0; i < 26; i++) {
		fprintf(f,"%c", data[i].c);
	}
	fprintf(f,"\n");
	fclose(f);
}

//find the index of something in an array
//used for cipher cracking in frequency analysis
int getIndex(char c, freq_point arr[], int len) {
  int i;
  for(i = 0; i < len; i++) {
    if(arr[i].c == c)
      return i;
  }
  return -1;
}
