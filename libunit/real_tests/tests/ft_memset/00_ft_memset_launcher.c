#include "memset_test.h"

int	memset_launcher(void)
{
	t_unit_test	*testlist;

	puts("MEMSET:");
	testlist = NULL;
	load_test(&testlist, "Basic test01", &memset_basic_test_01);
	load_test(&testlist, "Basic test02", &memset_basic_test_02);
	load_test(&testlist, "Hard test03", &memset_hard_test_03);
	load_test(&testlist, "Hard test03", &memset_hard_test_04);
	return (launch_tests(&testlist));
}
