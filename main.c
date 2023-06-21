#include "monty.h"

info_t info;

int main(int argc, char *argv[])
{
	info.format = LIFO;
	info.arg = NULL;
	(void)argv; /* will come to it later */
	(void)argc; /* also this */

	return 0;
}
