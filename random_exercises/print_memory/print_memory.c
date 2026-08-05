#include <unistd.h>

void    print_hex(unsigned char c)
{
    char    *hex;

    hex = "0123456789abcdef";
    write(1, &hex[c / 16], 1);
    write(1, &hex[c % 16], 1);
}

void	print_memory(const void *addr, size_t size)
{
	unsigned char	*ptr;
	size_t	i;
	size_t	j;

	ptr = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		j = 0;
		// hexadecimal number
		while (j < 16)
		{
			if (i + j < size)
				print_hex(ptr[i + j]);
			else
				write (1, "  ", 2);
			if (j % 2 != 0)
				write (1, " ", 1);
			j++;
		}
		// ascii character
		j = 0;
		while (j < 16 && (i + j) < size)
		{
			if (ptr[i + j] < 32 || ptr[i + j] > 126)
				write (1, ".", 1);
			else
				write (1, &ptr[i + j], 1);
			j++;
		}
		write (1, "\n", 1);
		i += 16;
	}
}

int	main(void)
{
	int	tab[10] = {0, 23, 150, 255,
	              12, 16,  21, 42};

	print_memory(tab, sizeof(tab));
	return (0);
}
