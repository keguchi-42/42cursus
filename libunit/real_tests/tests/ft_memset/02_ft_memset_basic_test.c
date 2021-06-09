#include "memset_test.h"

int	memset_basic_test_02(void)
{
	char	buff1[10];
	char	buff2[10];

	memset(buff1, '\n', 6);
	ft_memset(buff2, '\n', 6);
	if (memcmp(buff1, buff2, 6) == 0)
		return (0);
	else
		return (-1);
}
