/*
** wordtab.c for wordtab in /home/nicolas94200/IA/dante/tournament/src
** 
** Made by goedert nicolas
** Login   <nicolas94200@epitech.net>
** 
** Started on  Mon May  1 12:28:46 2017 goedert nicolas
** Last update Mon May  1 12:28:47 2017 goedert nicolas
*/

#include "string.h"
#include "wordtab.h"
#include "dante.h"

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;
  int	c;

  i = 0;
  c = n;
  while (c > 0)
    {
      dest[i] = src[i];
      i += 1;
      c = c - 1;
    }
  return (dest);
}

int	my_countsize(int *i, int *size_lines, char *str)
{
  while (str[*i] != '\n' && str[*i] != '\0')
    {
      *size_lines += 1;
      *i += 1;
    }
  return (0);
}

int	my_size_of_lines(char *str, char **word_tab)
{
  int	i;
  int	j;
  int	size_lines;
  int	i_backup;

  i = 0;
  j = 0;
  while (str && str[i] != '\0')
    {
      if (str[i] == '\n')
	i += 1;
      else if (str[i] != '\n' && str[i] != '\0')
	{
	  size_lines = 0;
	  i_backup = i;
	  my_countsize(&i, &size_lines, str);
	  i += 1;
	  if ((word_tab[j] = malloc(sizeof(char) * (size_lines + 1))) == NULL)
	    return (84);
	  my_strncpy(word_tab[j], str + i_backup, (size_lines));
	  j += 1;
	}
    }
  word_tab[j] = '\0';
  return (0);
}

int	my_countlines(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str && str[i] != '\0')
    {
      if (str[i] == '\n')
	{
	  j += 1;
	}
      i += 1;
    }
  j += 1;
  return (j);
}

char	**my_str_to_wordtab(char *str)
{
  int	nb_lines;
  char	**wordtab;

  nb_lines = my_countlines(str);
  wordtab = malloc((nb_lines + 1) * sizeof(char *));
  if (wordtab == NULL)
    return (NULL);
  wordtab[nb_lines] = NULL;
  my_size_of_lines(str, wordtab);
  return (wordtab);
}
