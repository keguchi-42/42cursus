#include "../includes/test.h"

int	test_launcher(void)
{
	t_unit_test	*testlist;

	puts("TEST:");
	testlist = NULL;
	load_test(&testlist, "Basic test", &basic_test);
	load_test(&testlist, "KO test", &ko_test);
	load_test(&testlist, "SEGV test", &segv_test);
	load_test(&testlist, "BUSE test", &buse_test);
	return (launch_tests(&testlist));
}
