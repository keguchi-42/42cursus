#include "itoa_test.h"

int	itoa_launcher(void)
{
	t_unit_test	*testlist;

	puts("ITOA:");
	testlist = NULL;
	load_test(&testlist, "Basic test01", &itoa_basic_test_01);
	load_test(&testlist, "Basic test02", &itoa_basic_test_02);
	load_test(&testlist, "Hard test03", &itoa_hard_test_03);
	load_test(&testlist, "Hard test03", &itoa_hard_test_04);
	return (launch_tests(&testlist));
}


