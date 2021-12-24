#include "minitalk.h"

int ft_isdigit(int i)
{
	if (i > 47 && i < 58)
		return (1);
	else
		return (0);
}

int ft_isspace(int i)
{
	if (((i > 8 &&  i < 14)) || i ==  32)
		return(1);
	else
		return (0);
}

int	ft_atoi(const char *s)
{
	int	i;
	unsigned int	result;
	int	sign;
	
	i = 0;
	result = 0;
	sign = 1;
	while(ft_isspace(s[i]))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(s[i]))
	{
		result *= 10;
		result += s[i] - 48;
		i++;
	}
	return (sign * result);
}

void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int i, int fd)
{
	unsigned int num;
	if (i < 0)
	{
		ft_putchar_fd('-', fd);
		num = (unsigned int)(i *(-1));
	}
	else
		num = (unsigned int)i;
	if (num > 9)
		ft_putnbr_fd(num / 10, fd);
	ft_putchar_fd(num % 10 + 48, fd);
}