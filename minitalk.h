#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>

int     ft_isdigit(int c);
int     ft_isspace(int c);
int	    ft_atoi(const char *s);
void    ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif