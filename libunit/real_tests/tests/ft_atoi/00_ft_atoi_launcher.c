#include "atoi_test.h"

int	atoi_launcher(void)
{
	t_unit_test	*testlist;

	puts("ATOI:");
	testlist = NULL;
	load_test(&testlist, "Basic test01", &atoi_basic_test_01);
	load_test(&testlist, "Basic test02", &atoi_basic_test_02);
	load_test(&testlist, "Hard test03", &atoi_hard_test_03);
	load_test(&testlist, "Hard test03", &atoi_hard_test_04);
	return (launch_tests(&testlist));
}

