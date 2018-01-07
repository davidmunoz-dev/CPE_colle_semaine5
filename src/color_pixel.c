/*
** main.c for  in /home/munoz_d/CPE_colle_semaine6
**
** Made by Munoz David
** Login   <munoz_d@epitech.net>
**
** Started on  Tue May 31 20:28:53 2016 Munoz David
** Last update Tue May 31 21:55:01 2016 clement peau
*/

#include "the_joy_of_bob_ross.h"
#include <unistd.h>
#include <stdio.h>

int	my_putchar(char c)
{
  if (write(1, &c, 1) == -1)
    return (1);
  return (0);
}

int	my_put_nbr(int nbr)
{
  int   neg;

  neg = 0;
  if (nbr < 0)
    {
      if (my_putchar('-') == 1)
	return (-1);
      nbr = nbr * -1;
    }
  if (nbr >= 10)
    if (my_put_nbr(nbr / 10) == -1)
      return (-1);
  if (neg == 1)
    {
      neg = 0;
      if (my_putchar(nbr % 10 + '1') == -1)
	return (-1);
    }
  else
    if (my_putchar(nbr % 10 + '0') == -1)
      return (-1);
  return (0);
}


int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (my_putchar(str[i]) == 1)
	return (1);
      i++;
    }
  return (0);
}

int	print_char_color(int red, int green, int blue, char c)
{
  if (my_putstr("\033[48;2;") ||
      my_put_nbr(red) ||
      my_putchar(';') ||
      my_put_nbr(green) ||
      my_putchar(';') ||
      my_put_nbr(blue) ||
      my_putchar('m') ||
      my_putchar(c) ||
      my_putstr("\033[00m"))
    return (1);
  return (0);
}

int	get_lines(t_bmp *file)
{
  int	x;
  int	y;

  y = file->info_header.height - 1;
  while (y >= 0)
    {
      x = 0;
      while (x < file->info_header.width)
	{
	  if (print_char_color(file->pixel[y][x].blue,
			   file->pixel[y][x].green,
			       file->pixel[y][x].red, ' '))
	    return (1);
	  x++;
	}
      y--;
      my_putchar('\n');
    }
  return (0);
}
