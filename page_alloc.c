/*
** page_alloc.c for  in /home/quach_a/Lab/malloc
** 
** Made by Jonathan Quach
** Login  <jonathan.quach@epitech.eu>
** 
** Started on  Sat Feb 14 23:00:21 2015 Jonathan Quach
** Last update Sun Feb 15 20:15:41 2015 Jonathan Quach
*/

#include "malloc.h"

size_t		get_alloc_by_page(size_t size)
{
  size_t	nb;
  static int	pages = 0;

  if (pages == 0)
    pages = getpagesize();
  nb = pages;
  while (nb < size)
    nb += pages;
  return (nb);
}

void		*add_new_page(size_t size, t_metadata *node, void *data)
{
  size_t	alloc;

  alloc = get_alloc_by_page(size + sizeof(t_metadata));
  if ((data = sbrk(alloc)) == (void *) -1)
    return (NULL);
  node = data;
  node->data = data + sizeof(t_metadata);
  node->size = alloc - sizeof(t_metadata);
  node->isFree = true;
  node->next = list;
  list = node;
  if ((data = try_split(size, list)))
    return (data);
  node->isFree = false;
  return (node->data);
}
