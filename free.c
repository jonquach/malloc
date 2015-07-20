/*
** free.c for  in /home/quach_a/Lab/malloc
** 
** Made by Jonathan Quach
** Login  <jonathan.quach@epitech.eu>
** 
** Started on  Sat Feb 14 22:56:15 2015 Jonathan Quach
** Last update Sun Feb 15 22:10:59 2015 Jonathan Quach
*/

#include "malloc.h"

void		free(void *ptr)
{
  t_metadata	*tmp;

  if (ptr == NULL)
    return;
  tmp = list;
  while (tmp != NULL)
    {
      if (tmp->data == ptr && tmp->isFree == false)
	{
	  tmp->isFree = true;
	  return;
	}
      tmp = tmp->next;
    }
}
