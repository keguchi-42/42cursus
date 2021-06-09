#include "libunit.h"

void	unit_puts(char *str)
{
	printf("%s\n", str);
}

void	put_result(t_unit_test *workinglist, char *result)
{
	printf("	> %s : ", workinglist->name);
	printf("[%s]\n", result);
}

void	print_test(t_unit_test **list)
{
	t_unit_test		*now;

	now = *list;
	while (now)
	{
		printf("%s\n", now->name);
		now = now->next;
	}
}
