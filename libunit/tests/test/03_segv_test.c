#include "../includes/test.h"

int	segv_test(void)
{
	if (ft_strlen(NULL) == strlen("Hello!"))
		return (0);
	else
		return (-1);
}
