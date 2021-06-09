#include "memset_test.h"

int	memset_hard_test_03(void)
{
	char	buff1[10];
	char	buff2[10];

	memset(buff1, '\0', 9);
	ft_memset(buff2, '\0', 9);
	if (memcmp(buff1, buff2, 9) == 0)
		return (0);
	else
		return (-1);
}
