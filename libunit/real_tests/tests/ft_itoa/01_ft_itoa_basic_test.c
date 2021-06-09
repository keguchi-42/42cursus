#include "itoa_test.h"

int	itoa_basic_test01(void)
{
	if ((ft_strcmp(ft_itoa(42), "42")) == 0)
		return (0);
	else
		return (-1);
}
