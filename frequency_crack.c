#include "frequency_analyzer.h"

int main(int argc, char *argv[]) {

	//the frequency data
	char ref[26];
	int i,j;
	FILE *data;
	if(argc != 3) {
		printf("usage: %s datafile textfile", argv[0]);
		exit(1);
	}

	data = fopen(argv[1],"r");
	for(i = 0; i < 26; i++) {
		fscanf(data, "%c", &ref[i]);
	}

	char *ciphertext = argv[2];

	//call the count() method on the input and collect results in an array
	freq_point chars[26];
	for(i = 97; i <= 122; i++) {
		chars[i-97] = freq_pointConstructor(i);
	}
	count(chars, ciphertext);

	sort(chars);

	char c;
	int p;
	FILE *f = fopen(ciphertext, "r");
	do {
		c = getc(f);
		if(c == ' ') {
			putchar(' ');
		} else if(c == '\n') {
			putchar('\n');
		} else {
			p = getIndex(c,chars,26);
			putchar(ref[p]);
		}
	} while(c != EOF);

}
