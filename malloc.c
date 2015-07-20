/*
** malloc.c for  in /home/quach_a/Lab/malloc
** 
** Made by Jonathan Quach
** Login  <jonathan.quach@epitech.eu>
** 
** Started on  Wed Jan 28 14:32:23 2015 Jonathan Quach
** Last update Sun Feb 15 21:38:45 2015 Jonathan Quach
*/

#include "malloc.h"

void		*search_old_malloc(size_t size)
{
  t_metadata	*tmp;

  if (list)
    {
      tmp = list;
      while (tmp != NULL)
	{
	  if (tmp->size >= size && tmp->isFree == true)
	    {
	      tmp->isFree = false;
	      return (tmp->data);
	    }
	  tmp = tmp->next;
	}
    }
  return (NULL);
}

void		*try_split(size_t size, t_metadata *tmp)
{
  size_t	old_size;
  t_metadata	*new;

  new = NULL;
  while (tmp->next != NULL && tmp->size < size + sizeof(t_metadata))
      tmp = tmp->next;
  if (tmp->size > size + sizeof(t_metadata) && tmp->isFree == true)
    {
      old_size = tmp->size;
      tmp->size = size;
      tmp->isFree = false;
      new = tmp->data + tmp->size;
      new->data = tmp->data + tmp->size + sizeof(t_metadata);
      new->size = old_size - (size + sizeof(t_metadata));
      new->isFree = true;
      new->next = list;
      list = new;
      return (tmp->data);
    }
  return (NULL);
}

void		*malloc(size_t size)
{
  void		*data;
  t_metadata	*node;

  if ((int)size <= 0)
    return NULL;
  node = NULL;
  data = NULL;
  if (list == NULL)
    data = add_new_page(size, node, data);
  else
    {
      if ((data = try_split(size, list)))
	return (data);
      if ((data = search_old_malloc(size)))
	return (data);
      data = add_new_page(size, node, data);
    }
  return (data);
}
