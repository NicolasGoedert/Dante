/*
** string1.c for string in /home/nicolas94200/IA/dante/generator/src
** 
** Made by goedert nicolas
** Login   <nicolas94200@epitech.net>
** 
** Started on  Mon May  1 12:32:03 2017 goedert nicolas
** Last update Mon May  1 12:32:04 2017 goedert nicolas
*/

#include "string.h"
#include "dante.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	x;

  x = 0;
  while (str[x] != '\0')
    {
      my_putchar(str[x]);
      x = x + 1;
    }
}

void	my_put_nbr(int nb)
{
  int	div;

  div = 1;
  if (nb < 0)
    {
      my_putchar('-');
      nb *= -1;
    }
  while ((nb/div) >= 10)
    {
      div *= 10;
    }
  while (div > 0)
    {
      my_putchar((nb/div) % 10 + 48);
      div /= 10;
    }
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str && str[i])
    i += 1;
  return (i);
}

char	*my_strcpy(char *dest, char *src)
{
  int	i;
  int	destl;
  int	srcl;

  destl = my_strlen(dest);
  srcl = my_strlen(src);
  i = 0;
  if (srcl > destl)
    {
      while (src[i] != '\0')
	{
	  dest[i] = src[i];
	  i = i + 1;
	}
    }
  else if (srcl < destl)
    {
      while (dest[i] != '\0')
	{
	  dest[i] = src[i];
	  i = i + 1;
	}
    }
  return (dest);
}
