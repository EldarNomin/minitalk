#include "minitalk.h"

void send_msg(pid_t pid, char *msg)
{
    int i;
    int size;
    int b;

    size = 0;
    while (msg[size] != '\0')
        size++;
    i = 0;
    while (i <= size)
    {
        b = 0;
        while (b < 7)
        {
            if ((msg[i] >> b) & 1)
                kill(pid, SIGUSR2);
            else
                kill(pid, SIGUSR1);
            b++;
            usleep(100);
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    pid_t server_pid;

    if (argc != 3)
    {
        write(1, "Invalid arguments\n", 18);
        return (1);
    }
    server_pid = (pid_t)ft_atoi(argv[1]);
    if (server_pid < 1)
    {
        write(1, "Invalid arguments\n", 18);
        return (1);
    }
    send_msg(server_pid, argv[2]);
    return (0);
}