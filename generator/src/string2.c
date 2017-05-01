/*
** string2.c for string in /home/nicolas94200/IA/dante/generator/src
** 
** Made by goedert nicolas
** Login   <nicolas94200@epitech.net>
** 
** Started on  Mon May  1 12:32:15 2017 goedert nicolas
** Last update Mon May  1 12:32:15 2017 goedert nicolas
*/

#include "string.h"
#include "dante.h"

int	my_getnbr(char *str)
{
  int	i;
  int	mult;
  int	res;

  i = my_strlen(str) - 1;
  mult = 1;
  res = 0;
  while (i >= 0)
    {
      res = res + ((str[i] - 48) * mult);
      mult *= 10;
      i -= 1;
    }
  return (res);
}

int	my_getnbr_char(char c)
{
  int	i;
  int	mult;
  int	res;

  i = 0;
  mult = 1;
  res = 0;
  while (i >= 0)
    {
      res = res + ((c - 48) * mult);
      mult *= 10;
      i -= 1;
    }
  return (res);
}
