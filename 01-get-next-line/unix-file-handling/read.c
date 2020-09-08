#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	char buff[128];
	int nread;

	nread = read(0, buff, 128);
	if (nread == -1)
	{
		write(2, "A read error has ocurred\n", 26);
	}
	if ((write(1, buff, nread)) != nread)
	{
		write(2, "A write error has ocurred\n", 27);
	}
	exit(0);
}
