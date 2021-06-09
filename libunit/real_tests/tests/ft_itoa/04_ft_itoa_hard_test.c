#include "itoa_test.h"

int	itoa_hard_test_04(void)
{
	if ((ft_strcmp(ft_itoa(-2147483648), "-2147483648")) == 0)
		return (0);
	else
		return (-1);
}
