#include "../includes/test.h"

int	buse_test(void)
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
