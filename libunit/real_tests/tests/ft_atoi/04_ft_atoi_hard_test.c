#include "atoi_test.h"

int	atoi_hard_test_04(void)
{
	if (ft_atoi("-2147483648") == atoi("-2147483648"))
		return (0);
	return (-1);
}

