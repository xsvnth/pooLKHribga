#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		char	arr[4096] = {0};
		char	*str;
		char	*p = arr;
		int		i;
		int		depth;

		str = argv[1];
		i = 0;
		while(str[i])
		{
			if (str[i] == '+')
				(*p)++;
			else if (str[i] == '-')
				(*p)--;
			else if (str[i] == '>')
				p++;
			else if (str[i] == '<')
				p--;
			else if (str[i] == '.')
				write (1, p, 1);
			else if (str[i] == '[' && ((*p) == 0))
			{
				depth = 1;
				while (depth && str[i])
				{
					i++;
					if (str[i] == '[')
						depth++;
					else if (str[i] == ']')
						depth--;
				}
			}
			else if (str[i] == ']' && ((*p) != 0))
			{
				depth = 1;
				while (depth && i >= 0)
				{
					i--;
					if (str[i] == '[')
						depth--;
					else if (str[i] == ']')
						depth++;
					
				}
			}
			i++;
		}
	}
	return (0);
}
