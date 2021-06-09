#include "strlen_test.h"

int	strlen_null_test_04(void)
{
	if (ft_strlen(NULL) == strlen(NULL))
		return (0);
	return (-1);
}
