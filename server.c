#include "minitalk.h"

void    print_msg(int b)
{
    static int i;
    static int size;

    i += (((b) & 1) << size);
    size++;
    if(size == 7)
    {
        ft_putchar_fd(i, 1);
        if (!i)
            ft_putchar_fd('\n', 1);
        i = 0;
        size = 0;
    }
}

void    ft_get_signal(int signum, siginfo_t *info, void *context)
{
    if (info != NULL && context != NULL)
        print_msg(signum == SIGUSR2);
}


int main(void)
{
    int                 pid;
    struct sigaction    signal;

    signal.sa_flags = SA_SIGINFO;
    signal.sa_sigaction = ft_get_signal;
    pid = (int)getpid();
    ft_putnbr_fd(pid, 1);
    ft_putchar_fd('\n', 1);
    while(1)
    {
        sigaction(SIGUSR1, &signal, NULL);
        sigaction(SIGUSR2, &signal, NULL);
        pause();
    }
}