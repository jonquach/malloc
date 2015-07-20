/*
** main.c for  in /home/quach_a/rendu/PSU_2014_malloc
** 
** Made by Jonathan Quach
** Login  <jonathan.quach@epitech.eu>
** 
** Started on  Sun Feb 15 14:58:16 2015 Jonathan Quach
** Last update Sun Feb 15 17:22:50 2015 Jonathan Quach
*/

#include "unit_test.h"

int	main()
{
  printf("\033[1;32m[TEST] EXECUTION OF UNIT TEST\n");
  unit_test();
  return (0);
}

void	unit_test()
{
  char	*str;

  printf("\033[1;31m[TEST] --> basic malloc/free/realloc\n");
  str = malloc(sizeof(char) * 100);
  printf("\n\033[1;32m[TEST] --> OK !\033\n");
  printf("\033[1;31m[TEST] --> realloc\n");
  str = realloc(str, 200);
  printf("\n\033[1;32m[TEST] --> OK !\033\n");
  printf("\033[1;31m[TEST] --> free \n");
  free(str);
  printf("\n\033[1;32m[TEST] --> OK !\033\n");
  unit_test_big();
}

void	unit_test_big()
{
  char	*str;

  printf("\033[1;31m[TEST] --> big malloc/free/realloc \n");
  str = malloc(sizeof(char) * 10000);
  printf("\n\033[1;32m[TEST] --> OK !\033\n");
  printf("\033[1;31m[TEST] --> realloc \n");
  str = realloc(str, 1000);
  printf("\n\033[1;32m[TEST] --> OK !\033\n");
  printf("\033[1;31m[TEST] --> free \n");
  free(str);
  printf("\n\033[1;32m[TEST] --> OK !\033\n");
  unit_test_next();
}

void	unit_test_next()
{
  char	*str;

  printf("\033[1;31m[TEST] --> pagesize malloc/realloc/free \n");
  str = malloc(sizeof(char) * getpagesize());
  printf("\n\033[1;32m[TEST] --> OK !\033\n");
  printf("\033[1;31m[TEST] --> realloc \n");
  str = realloc(str, getpagesize());
  printf("\n\033[1;32m[TEST] --> OK !\033\n");
  printf("\033[1;31m[TEST] --> free \n");
  free(str);
  printf("\n\033[1;32m[TEST] --> OK !\033\n");
  unit_test_end();
}

void	unit_test_end()
{
  char	*str;

  printf("\033[1;31m[TEST] --> multiple malloc/realloc/free \n");
  str = malloc(sizeof(char) * 8);
  str = malloc(sizeof(char) * 10);
  str = malloc(sizeof(char) * 108);
  str = malloc(sizeof(char) * 28);
  str = malloc(sizeof(char) * 38);
  str = malloc(sizeof(char) * 48);
  str = malloc(sizeof(char) * 58);
  str = malloc(sizeof(char) * 98);
  printf("\n\033[1;32m[TEST] --> OK !\033\n");
  printf("\033[1;31m[TEST] --> realloc \n");
  str = realloc(str, 10);
  printf("\n\033[1;32m[TEST] --> OK !\033\n");
  printf("\033[1;31m[TEST] --> free \n");
  free(str);
  printf("\n\033[1;32m[TEST] --> OK !\033[0m\n");
}
