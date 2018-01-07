/*
** the_joy_of_bob_ross.h for o in /home/peau_c/CPE_colle_semaine6
**
** Made by clement peau
** Login   <peau_c@epitech.net>
**
** Started on  Tue May 31 19:19:33 2016 clement peau
** Last update Tue May 31 21:58:44 2016 clement peau
*/

#ifndef _THE_JOY_OF_BOB_ROSS_H_
# define _THE_JOY_OF_BOB_ROSS_H_

# include <stdlib.h>

typedef char byte;

typedef struct		s_bmp_header
{
  byte			sig_b;
  byte			sig_m;
  int32_t		file_size;
  int16_t		resv1;
  int16_t		resv2;
  int32_t		pixel_offset;
}			t_bmp_header;

typedef struct		s_bmp_info_header
{
  int32_t		size;
  int32_t		width;
  int32_t		height;
  int16_t		color_planes;
  int16_t		bits_per_pixels;
  byte	       		zeros[24];
}			t_bmp_info_header;

typedef struct		s_pixel
{
  byte	       		blue;
  byte			green;
  byte			red;
  byte			reserved;
}			t_pixel;

typedef struct		s_bmp
{
  t_bmp_header	       	header;
  t_bmp_info_header	info_header;
  t_pixel	       	**pixel;
}	       		t_bmp;

void			my_memset(void *, char, int);
int			get_lines(t_bmp *);
int			get_file(char *, t_bmp *);

#endif /* _THE_JOY_OF_BOB_ROSS_H_ */
