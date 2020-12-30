/*Use of FILE I/O
 * Command line arguments
 * Double space input file to output file
 */

#include <stdio.h>
#include <stdlib.h> //exit()

void print_file(FILE *fptr) {
	int c, i, num;
	rewind(fptr);
	while((c = getc(fptr)) != EOF) {
		putc(c, stdout);
	}
	rewind(fptr);
	for(i = 0; i < 1; i++) {
		fscanf(fptr, "%d", &num);
	}
	printf("The first number is: %d", num);	
}

void double_space(FILE *ifp, FILE *ofp) {
	int c;
	rewind(ifp);
	while((c = getc(ifp)) != EOF) {
		putc(c, ofp);
		//putchar(c);
		if(c == '\n') {
			putc('\n', ofp);
		}
	}
}

int main(int argc, char *argv[]) {
	FILE *ifp, *ofp;
	if(argc != 3) {
		printf("Need executable inputfile  outputfile\n");
		exit(1);
	}

	ifp = fopen(argv[1], "r+");
	ofp = fopen(argv[2], "w+");
	printf("My %s file as read is \n\n", argv[1]);
	print_file(ifp);
	printf("\n\n");
	double_space(ifp, ofp);
	printf("My %s file double spaced is\n\n", argv[2]);
	print_file(ofp);
	printf("\n\n");
	fclose(ifp);
	fclose(ofp);

	return 0;
}
