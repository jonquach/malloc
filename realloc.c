/*
** realloc.c for  in /home/quach_a/Lab/malloc
** 
** Made by Jonathan Quach
** Login  <jonathan.quach@epitech.eu>
** 
** Started on  Sat Feb 14 22:52:01 2015 Jonathan Quach
** Last update Sun Feb 15 20:38:35 2015 Jonathan Quach
*/

#include "malloc.h"

void		*realloc(void *ptr, size_t size)
{
  void		*data;
  t_metadata	*tmp;

  if (size <= 0)
    return (NULL);
  if (ptr != NULL && list != NULL)
    {
      tmp = list;
      while (tmp->data != ptr && tmp->next != NULL)
	tmp = tmp->next;
      if (tmp->data == ptr && tmp->size >= size)
	return (ptr);
      data = malloc(size);
      if (tmp->data == ptr && tmp->size < size)
	memcpy(data, ptr, tmp->size);
      free(ptr);
    }
  else
    data = malloc(size);
  return (data);
}
