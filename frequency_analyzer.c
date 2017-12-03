#include "frequency_analyzer.h"
// a program to anaylze the frequency of english letters and apply them to crack easy ciphers

int main(int argc, char *argv[]) {
	//the files to read data from, they should be books
	//char *dataFiles[4] = {"text1","text2","text3","text4"};
	if(argc == 1) {
		printf("usage: %s <file1> [file2 [file3]...]", argv[0]);
		return 1;
	}
	int i = 0;
	//call the count() method on each file and collect results in an array
	freq_point chars[26];
	for(i = 97; i <= 122; i++) {
		chars[i-97] = freq_pointConstructor(i);
	}
	for(i = 1; i < argc; i++)
		count(chars, argv[i]);

	//sort the array by frequency
	sort(chars);

	//print out the counts
	printResult(chars, getSum(chars, 26));
	printf("Total characters analyzed:\t%d\n", getSum(chars, 26));
	saveResult("frequencydata", chars);
	return 0;
}
