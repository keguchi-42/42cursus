#include "strlen_test.h"

int	strlen_hard_test_03(void)
{
	int		num;
	char	*str;

	num = 1;
	str = "Xello";
	*str = 'H';
	if (num)
		return (0);
	else
		return (-1);
}
