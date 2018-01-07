/*
** main.c for mian in /home/peau_c/CPE_colle_semaine6
**
** Made by clement peau
** Login   <peau_c@epitech.net>
**
** Started on  Tue May 31 19:10:22 2016 clement peau
** Last update Tue May 31 22:06:43 2016 clement peau
*/

#include <unistd.h>
#include "the_joy_of_bob_ross.h"

void	free_all(t_bmp bmp)
{
  int	i;

  i = 0;
  while (i < bmp.info_header.height)
    {
      free(bmp.pixel[i]);
      i++;
    }
  free(bmp.pixel);
}

int	main(int ac, char **av)
{
  t_bmp	file;

  if (ac != 2)
    {
      write(2, "Usage : ./bob_ross [bmp_file.bmp]\n", 34);
      return (1);
    }
  if (get_file(av[1], &file))
    return (1);
  if (get_lines(&file))
    {
      write(2, "Error while printing characters\n", 32);
      return (1);
    }
  free_all(file);
  return (0);
}
