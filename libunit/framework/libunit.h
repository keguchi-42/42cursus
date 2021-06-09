#ifndef LIBUNIT_H
# define LIBUNIT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <signal.h>

/*
** [allowd functions]
**
** malloc
** free
** exit
** fork
** wait
** write
** printf
*/

typedef struct s_unit_test
{
	char				*name;
	int					(*func)();
	struct s_unit_test	*next;
}				t_unit_test;

int		load_test(t_unit_test **testlist, char *testname, int (*testfunc)());
int		launch_tests(t_unit_test **testlist);

int		exec_test(t_unit_test *workingtest);

/*
** puts.c
*/
void	unit_puts(char *str);
void	put_result(t_unit_test *workinglist, char *result);

int		error_exit(char *type);

#endif
