#include "libunit.h"

int	error_exit(char *type)
{
	printf("Error: %s", type);
	exit(EXIT_FAILURE);
}
