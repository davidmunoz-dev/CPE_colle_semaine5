/*
** bzero.c for ptet in /home/peau_c/CPE_colle_semaine6
**
** Made by clement peau
** Login   <peau_c@epitech.net>
**
** Started on  Tue May 31 19:57:07 2016 clement peau
** Last update Tue May 31 20:00:25 2016 clement peau
*/

void	my_memset(void	*ptr, char c, int size)
{
  int	i;
  char	*cursor;

  i = 0;
  cursor = (char *)ptr;
  while (i < size)
    cursor[i++] = c;
}
