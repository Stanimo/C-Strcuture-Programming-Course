#include <stdio.h>
#include <stdlib.h>

void print_file(FILE *ftpr) {
	int c;
	rewind(ftpr);
	while((c == getc(ftpr)) != EOF) {
		putc(c, stdout);
	}
}

int main(int argc, char *argv[]) {
	int i, size, *s = &size;
	int data[*s];
	FILE *ifp, *ofp;

	printf("Hello\n");

	if(argc != 3) {
		printf("Not enought files given\n");
		exit(1);
	}
	
	ifp = fopen(argv[1], "r+");
	ofp = fopen(argv[2], "w+");
	rewind(ifp);
	fscanf(ifp, "%d", &size);
	printf("The first value of the file is: %d", size);

	fclose(ifp);
	fclose(ofp);

	return 0;
}
