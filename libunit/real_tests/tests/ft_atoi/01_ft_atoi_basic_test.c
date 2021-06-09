#include "atoi_test.h"

int	atoi_basic_test_01(void)
{
	if (ft_atoi("1234") == atoi("1234"))
		return (0);
	return (-1);
}