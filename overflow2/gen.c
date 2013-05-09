#include <stdio.h>

int main(int argc, const char * argv[]) {
	FILE * fp = fopen("data.txt", "w");
	int j, i = 0x48 + 8;
	for (j = 0; j < i; j++) {
		fprintf(fp, "a");
	}
	fprintf(fp, "%c", 1);
	fclose(fp);
	return 0;
}
