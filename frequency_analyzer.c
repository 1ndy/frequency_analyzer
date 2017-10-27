#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
// a program to anaylze the frequency of english letters and apply them to crack easy ciphers


//a function to count occurences in a file and store the data in an array

struct freq_point {
	char c;
	int freq;
};

typedef struct freq_point freq_point;


int isInRange(char c) {
	return (c >= 97 && c <= 122);
}

void count(freq_point chars[], char file[]) {
	//open the data file
	FILE *txt;
	txt = fopen(file, "r");
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

freq_point freq_pointConstructor(char c) {
	freq_point f;
	f.c = c;
	f.freq = 0;
	return f;
}

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

//print the characters alphabetcally and the number of times thet occur
void printResult(freq_point frequencies[], int sum) {
	int i;
	for(i = 0; i < 26; i++) {
		//index = getMax(frequency);
		printf("%c\t%10d\t%6.2f\n", frequencies[i].c, frequencies[i].freq, (double)frequencies[i].freq / sum * 100.0);
		//letterOrder[i] = index+32;
		//charFrequency[i] = frequency[index];
	}

}
void saveResult(char *fn, freq_point data[]) {
	FILE *f = fopen(fn, "w");
	int i;
	for(i = 0; i < 26; i++) {
		fprintf(f,"%c", data[i].c);
	}
	fprintf(f,"\n");
	fclose(f);
}

int main() {
	//the files to read data from, they should be books
	char *dataFiles[4] = {"text1","text2","text3","text4"};

	int i = 0;
	//call the count() method on each file and collect results in an array
	freq_point chars[26];
	for(i = 97; i <= 122; i++) {
		chars[i-97] = freq_pointConstructor(i);
	}
	for(i = 0; i < 4; i++)
		count(chars, dataFiles[i]);

	//sort the array by frequency
	sort(chars);

	//print out the counts
	printResult(chars, getSum(chars, 26));
	printf("Sum:\t%d\n", getSum(chars, 26));
	saveResult("frequencydata", chars);
	return 0;
}
