#include <stddef.h>

size_t extract_cry(char **);
void play_cry(char *, size_t);

int main(int argc, char *argv[])
{
	char *crydat;
	int crylen = extract_cry(&crydat);
	play_cry(crydat, crylen);

	return 0;
}
