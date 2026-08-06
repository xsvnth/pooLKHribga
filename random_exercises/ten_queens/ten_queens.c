#include <unistd.h>

int pos[10];
int count;

void  ft_print(int *tab)
{
  char c;
  int i = 0;
  while (i < 10)
  {
    c = tab[i] + '0';
    write (1, &c, 1);
    i++;
  }
  write (1, "\n", 1);
  count++;
}

int ft_abs(int nb)
{
  if (nb < 0)
    nb = -nb;
  return (nb);
}

int is_safe(int row, int col)
{
  int i = 0;
  while (i < row)
  {
    if (pos[i] == col)
      return (0);
    if (ft_abs(row - i) == ft_abs(col - pos[i]))
      return (0);
    i++;
  }
  return (1);
}

void  solve (int row)
{
  int col;
  if (row == 10)
  {
    ft_print(pos);
    return ;
  }
  col = 0;
  while (col < 10)
  {
    if (is_safe(row, col))
    {
      pos[row] = col;
      solve(row + 1);
    }
    col++;
  }
}

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	main(void)
{
  count = 0;
  solve (0);
  ft_putnbr (count);
  write (1, "\n", 1);
  return (0);
}
