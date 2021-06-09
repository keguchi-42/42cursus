#include "strlen_test.h"

int	strlen_launcher(void)
{
	t_unit_test	*testlist;

	puts("strlen:");
	testlist = NULL;
	load_test(&testlist, "Basic test01", &strlen_basic_test_01);
	load_test(&testlist, "Basic test02", &strlen_basic_test_02);
	load_test(&testlist, "Hard test03", &strlen_hard_test_03);
	load_test(&testlist, "Hard test03", &strlen_hard_test_04);
	return (launch_tests(&testlist));
}
