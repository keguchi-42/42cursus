#include "libunit.h"

int	set_test_status(t_unit_test *workingtest, int wstatus)
{
	if (WIFEXITED(wstatus))
	{
		if (WEXITSTATUS(wstatus) == 0)
		{
			put_result(workingtest, "OK");
			return (1);
		}
		else
			put_result(workingtest, "KO");
	}
	if (WIFSIGNALED(wstatus))
	{
		if (WTERMSIG(wstatus) == SIGSEGV)
			put_result(workingtest, "SEGV");
		else if (WTERMSIG(wstatus) == SIGBUS)
			put_result(workingtest, "BUSE");
	}
	return (0);
}

int	exec_test(t_unit_test *workingtest)
{
	pid_t	pid;
	int		wstatus;

	pid = fork();
	if (pid < 0)
		return (error_exit("fork"));
	if (pid == 0)
	{
		if (workingtest->func() == 0)
			exit(EXIT_SUCCESS);
		else
			exit(EXIT_FAILURE);
	}
	else
	{
		wait(&wstatus);
		if (set_test_status(workingtest, wstatus))
			return (1);
	}
	return (0);
}
