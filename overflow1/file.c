#include <stdio.h>

int main(int argc, const char * argv) {
	int i;
	FILE * fp = fopen("test.txt", "w");
	for (i = 0; i < 64; i++) {
		fprintf(fp, "a");
	}
	fprintf(fp, "%c", 1);
	fclose(fp);
	return 0;
}
