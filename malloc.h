/*
** malloc.h for  in /home/quach_a/Dropbox/EPITECH PROJET/TEK2/quach_a/dumb_shit/PSU_2014_malloc
** 
** Made by Jonathan Quach
** Login  <jonathan.quach@epitech.eu>
** 
** Started on  Wed Jan 28 14:27:58 2015 Jonathan Quach
** Last update Sat Feb 14 23:31:18 2015 Jonathan Quach
*/

#ifndef MALLOC_H_
# define MALLOC_H_

#include <unistd.h>
#include <stdio.h>
#include <string.h>

typedef enum
  {
    false,
    true,
  } bool;

typedef struct		s_metadata
{
  void			*data;
  size_t		size;
  int			isFree;
  struct s_metadata	*next;
}			t_metadata;

t_metadata		*list;

void			*malloc(size_t);
void			*realloc(void *, size_t);
void			free(void *);
void			*add_new_page(size_t, t_metadata *, void *);
void			*try_split(size_t, t_metadata *);
void			*search_old_malloc(size_t);
void			show_malloc_mem();
size_t			get_alloc_by_page(size_t);

#endif	/* !MALLOC_H_ */
