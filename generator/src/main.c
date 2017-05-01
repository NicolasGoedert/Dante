/*
** main.c for main in /home/nicolas94200/IA/dante/generator/src
** 
** Made by goedert nicolas
** Login   <nicolas94200@epitech.net>
** 
** Started on  Mon May  1 12:31:49 2017 goedert nicolas
** Last update Mon May  1 12:31:50 2017 goedert nicolas
*/

#include "wordtab.h"
#include "dante.h"
#include "string.h"

char	**sec_fill(char **map)
{
  int	i;
  int	j;
  int	nb;

  i = 0;
  j = 0;
  while (map[j] != NULL)
    {
      i = 0;
      while (map[j][i] != '\0')
	{
	  if (map[j][i] == '#')
	    {
	      nb = (rand() % (2 - 1 + 1)) + 1;
	      if (nb == 1)
		map[j][i] = '*';
	    }
	  i = i + 1;
	}
      j = j + 1;
    }
  return (map);
}

char	**create_path(char **map, int i_max, int j_max)
{
  int	i;
  int	j;
  int	nb;

  i = 0;
  j = 0;
  map[0][0] = '*';
  while (map[j_max][i_max] != '*')
    {
      nb = (rand() % (2 - 1 + 1)) + 1;
      if (nb == 1)
	{
	  if (i != i_max)
	    {
	      i = i + 1;
	      map[j][i] = '*';
	    }
	}
      else if (nb == 2)
	{
	  if (j != j_max)
	    {
	      j = j + 1;
	      map[j][i] = '*';
	    }
	}
    }
  map = sec_fill(map);
  return (map);
}

char	**fill_map(char **map, int i_max, int j_max)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  srand(time(NULL));
  while (j != j_max + 1)
    {
      i = 0;
      while (i != i_max + 1)
	{
	  map[j][i] = '#';
	  i = i + 1;
	}
      j = j + 1;
    }
  map = create_path(map, i_max, j_max);
  return (map);
}

char	**create_map(char **map, char **argv)
{
  int	i;
  int	j;
  int	j_save;

  i = my_getnbr(argv[1]);
  i = i - 1;
  j = my_getnbr(argv[2]);
  j = j - 1;
  j_save = j;
  map = malloc(sizeof(char*) * (j + 1));
  while (j_save != -1)
    {
      map[j_save] = malloc(sizeof(char) * (i + 1));
      j_save = j_save - 1;
    }
  i = my_getnbr(argv[1]);
  i = i - 1;
  j = my_getnbr(argv[2]);
  j = j - 1;
  j_save = j;
  map = fill_map(map, i, j);
  return (map);
}

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
	  my_putchar(map[j][i]);
	  i = i + 1;
	}
      my_putchar('\n');
      j = j + 1;
    }
}

void	launch(char **argv)
{
  char	**map;

  map = NULL;
  map = create_map(map, argv);
  print_map(map);
  // write_map(map, fd);
}

int	main(int argc, char **argv)
{
  if (argc != 3)
    return (84);
  launch(argv);
}
