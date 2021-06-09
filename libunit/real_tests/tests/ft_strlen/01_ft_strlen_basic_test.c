#include "strlen_test.h"

int	strlen_basic_test_01(void)
{
	if (ft_strlen("Hello") == strlen("Hello"))
		return (0);
	return (-1);
}
