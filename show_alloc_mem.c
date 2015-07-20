/*
** show_alloc_mem.c for  in /home/quach_a/Lab/malloc
** 
** Made by Jonathan Quach
** Login  <jonathan.quach@epitech.eu>
** 
** Started on  Sat Feb 14 22:57:55 2015 Jonathan Quach
** Last update Sun Feb 15 18:16:58 2015 Jonathan Quach
*/

#include "malloc.h"

void		show_alloc_mem()
{
  t_metadata	*tmp;
  void		*data;

  tmp = list;
  if ((data = sbrk(0)) == (void *) -1)
    return;
  printf("break : %p\n", data);
  if (tmp == NULL)
    return;
  else
    {
      while (tmp != NULL)
	{
	  if (tmp->isFree == false)
	    printf("%p - %p : %lu octets\n", &tmp->data,
		   &tmp->next->data, tmp->size);
	  tmp = tmp->next;
	}
    }
}
