/*
** get_file.c for file in /home/peau_c/CPE_colle_semaine6
**
** Made by clement peau
** Login   <peau_c@epitech.net>
**
** Started on  Tue May 31 19:29:17 2016 clement peau
** Last update Tue May 31 21:00:59 2016 clement peau
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "the_joy_of_bob_ross.h"

int	get_file(char *name, t_bmp *file)
{
  int	fd;
  int	i;

  i = 0;
  my_memset(file, 0, sizeof(t_bmp));
  if ((fd = open(name, O_RDONLY)) == -1)
    return (write(2, "Could not locate file\n", 22), 1);
  if (read(fd, &file->header, 14) < 14
      || read(fd, &file->info_header, 40) < 17)
    return (write(2, "File has been modified\n", 23), 1);
  if ((file->pixel = malloc(sizeof(void *) * file->info_header.height)) == NULL)
    return (write(2, "Malloc failed\n", 14), 1);
  while (i < file->info_header.height)
    {
      if ((file->pixel[i] = malloc(4 * file->info_header.width)) == NULL)
      	return (write(2, "Wrong height\n", 13), 1);
      if (read(fd, file->pixel[i], 4 * file->info_header.width) <
	  4 * file->info_header.width)
	return (write(2, "Wrong width\n", 12), 1);
      i++;
    }
  return (0);
}
