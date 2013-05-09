#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main (int argc, const char * argv[]) {
	execlp("/bin/fash", "/bin/fash", NULL);
	return 0;
}
