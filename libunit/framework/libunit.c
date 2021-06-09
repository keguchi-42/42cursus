#include "libunit.h"

t_unit_test	*list_last(t_unit_test **list, t_unit_test *new)
{
	t_unit_test		*now;

	now = *list;
	while (now->next)
		now = now->next;
	now->next = new;
	return (now);
}

int	load_test(t_unit_test **testlist, char *testname, int (*testfunc)())
{
	t_unit_test		*newlist;

	newlist = malloc(sizeof(t_unit_test));
	if (!newlist)
		return (-1);
	newlist->next = NULL;
	newlist->name = testname;
	newlist->func = testfunc;
	if (*testlist)
		list_last(testlist, newlist);
	else
		*testlist = newlist;
	return (0);
}

int	free_testlist(t_unit_test **list)
{
	t_unit_test		*save;
	t_unit_test		*del;

	del = *list;
	while (del)
	{
		save = del->next;
		free(del);
		del = save;
	}
	return (0);
}

int	launch_tests(t_unit_test **testlist)
{
	t_unit_test		*workinglist;
	int				success;
	int				total;

	success = 0;
	total = 0;
	workinglist = *testlist;
	while (workinglist)
	{
		success += exec_test(workinglist);
		workinglist = workinglist->next;
		total++;
	}
	free_testlist(testlist);
	printf("\n  successful tests : %d/%d\n", success, total);
	if (success == total)
		return (0);
	else
		return (-1);
}
