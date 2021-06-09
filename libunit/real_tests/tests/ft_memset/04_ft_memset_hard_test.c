#include "memset_test.h"

int	memset_hard_test_04(void)
{
	char	buff1[10];
	char	buff2[10];

	memset(buff1, ' ', 10);
	ft_memset(buff2, ' ', 10);
	if (memcmp(buff1, buff2, 10) == 0)
		return (0);
	else
		return (-1);
}
