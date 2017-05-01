/*
** main.c for main in /home/nicolas94200/IA/dante/tournament/src
** 
** Made by goedert nicolas
** Login   <nicolas94200@epitech.net>
** 
** Started on  Mon May  1 12:28:32 2017 goedert nicolas
** Last update Mon May  1 12:28:33 2017 goedert nicolas
*/

#include "wordtab.h"
#include "dante.h"
#include "string.h"
/*
**  'c' ==> case condamné
**  'y' ==> chemin en cours
**  A l'affichage final remplacer 'y' par 'o' et 'c' par '*'
**
**
*/

void	print_map(char **map)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (map[j] != NULL)
    {
      i = 0;
      while (map[j][i] != '\0')
	{
	  if (map[j][i] == 'y')
	    my_putchar('*');
	  else if (map[j][i] == 'c')
	    my_putchar('*');
	  else if (map[j][i] == 's')
	    my_putchar('o');
	  else
	    my_putchar(map[j][i]);
	  i = i + 1;
	}
      my_putchar('\n');
      j = j + 1;
    }
}

int	*reculer(int *value, char **map)
{
  if (value[1] != 0)
    {
      if (map[value[1] - 1][value[0]] == 'y')
	{
	  map[value[1]][value[0]] = 'c';
	  value[1] = value[1] - 1;
	  return (value);
	}
    }
  if (value[0] != 0)
    {
      if (map[value[1]][value[0] - 1] == 'y')
	{
	  map[value[1]][value[0]] = 'c';
	  value[0] = value[0] - 1;
	  return (value);
	}
    }
  if (value[0] < value[2])
    {
      if (map[value[1]][value[0] + 1] == 'y')
	{
	  map[value[1]][value[0]] = 'c';
	  value[0] = value[0] + 1;
	  return (value);
	}
    }
  if (value[1] < value[3])
    {
      if (map[value[1] + 1][value[0]] == 'y')
	{
	  map[value[1]][value[0]] = 'c';
	  value[1] = value[1] + 1;
	  return (value);
	}
    }
  return (value);
}

int	*add_case(int *value, char **map)
{
  if (value[1] < value[3])
    {
      if (map[value[1] + 1][value[0]] == '*')
	{
	  map[value[1] + 1][value[0]] = 'y';
	  value[1] = value[1] + 1;
	  return (value);
	}
    }
  if (value[0] < value[2])
    {
      if (map[value[1]][value[0] + 1] == '*')
	{
	  map[value[1]][value[0] + 1] = 'y';
	  value[0] = value[0] + 1;
	  return (value);
	}
    }
  if (value[0] != 0)
    {
      if (map[value[1]][value[0] - 1] == '*')
	{
	  map[value[1]][value[0] - 1] = 'y';
	  value[0] = value[0] - 1;
	  return (value);
	}
    }
  if (value[1] != 0)
    {
      if (map[value[1] - 1][value[0]] == '*')
	{
	  map[value[1] - 1][value[0]] = 'y';
	  value[1] = value[1] - 1;
	  return (value);
	}
    }
  value = reculer(value, map);
  return (value);
}

char	**final_map(char **map, int i_max, int j_max)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  map[0][0] = 's';
  while (i != i_max || j != j_max)
    {
      if (j < j_max)
	{
	  if (map[j + 1][i] == 'y')
	    {
	      map[j + 1][i] = 's';
	      j = j + 1;
	    }
	}
      if (i < i_max)
	{
	  if (map[j][i + 1] == 'y')
	    {
	      map[j][i + 1] = 's';
	      i = i + 1;
	    }
	}
      if (i != 0)
	{
	  if (map[j][i - 1] == 'y')
	    {
	      map[j][i - 1] = 's';
	      i = i - 1;
	    }
	}
      if (j != 0)
	{
	  if (map[j - 1][i] == 'y')
	    {
	      map[j - 1][i] = 's';
	      j = j - 1;
	    }
	}
    }
  return (map);
}

void	solve_map(char **map)
{
  int	*value;

  value = malloc(sizeof(int) * (5));
  value[0] = 0;
  value[1] = 0;
  value[2] = 0;
  value[3] = 0;
  while (map[0][value[2]] != '\0')
    value[2] = value[2] + 1;
  value[2] = value[2] - 1;
  while (map[value[3]] != NULL)
    value[3] = value[3] + 1;
  value[3] = value[3] - 1;
  if (map[0][0] != '*')
    exit(84);
  map[0][0] = 'y';
  while (map[value[3]][value[2]] != 'y')
    value = add_case(value, map);
  map = final_map(map, value[2], value[3]);
  print_map(map);
}

void	launch(char **argv)
{
  int	fd;
  char	*buf;
  char	**map;

  if ((fd = open(argv[1], O_RDONLY)) == -1)
    exit(84);
  buf = malloc(sizeof(char) * (32000));
  read(fd, buf, 32000);
  map = my_str_to_wordtab(buf);
  solve_map(map);
}

int	main(int argc, char **argv)
{
  if (argc != 2)
    return (84);
  launch(argv);
}
