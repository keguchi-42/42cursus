#include "memset_test.h"

int	memset_basic_test_01(void)
{
	char	buff1[10];
	char	buff2[10];

	memset(buff1, 'c', 3);
	ft_memset(buff2, 'c', 3);
	if (memcmp(buff1, buff2, 3) == 0)
		return (0);
	else
		return (-1);
}
