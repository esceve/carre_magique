/*
** carre_magique.c for carre_magique in /home/esceve/Documents/C/carre_magique
** 
** Made by Clement Scherpereel
** Login esceve <clement.scherpereel@outlook.fr>
** 
** Started on  Fri May 20 08:48:50 2016 Clement Scherpereel
** Last update Fri May 27 10:10:40 2016 Clement Scherpereel
*/
#include	<stdlib.h>
#include	<stdio.h>
#include	<ctype.h>


ssize_t		get_array_size(void)
{
  size_t	n;
  ssize_t	ret;
  char		*buffer;

  n = 0;
  buffer = NULL;
  printf("Saisir la taille du tableau à deux dimensions desiré \
  (la taille doit être impaire)");
  if ((ret = getline(&buffer, &n, stdin)) > 0) {
    n = 0;
    while (buffer && buffer[n]) {
      if (isdigit(buffer[n]))
	return (-1);
      n++;
    }
    ret = strtol(buffer, NULL, 0);
    free(buffer);
    return (ret);
  }
  return (-1);
}

int		main(void)
{
  int		i;
  int		j;
  int		size;
  int		start;
  int		max;
  int		insert;
  int		result;

  i = 0;
  j = 0;
  insert = 0;
  max = 0;
  size = 0;
  start = 0;

  printf("saisir la taille du tableaux à 2 Dimmensions avec un nombre impaire: ");
  scanf("%d",&size);
  while((size%2)!=1)
  {
    printf("\n");
    printf("votre nombre n'est pas impair,veuillez le ressaisir ");
    scanf("%d",&size);
  }
  max = size*size;
  int		tab[size][size];
  start = (size/2);
  for (i = 0; i < size ; i++)
    {
      for (j = 0; j < size; j++)
      {
        tab[i][j]=0;
      }
    }
    printf("\n\n");
    i=0;
    j=0;
    tab[i][start]=1;
    printf("__________CARRE MAGIQUE__________ :\n\n");
    j = start;
    max = max +1;
  for(insert = 2 ; insert < max ; insert++)
    {
      i--;
      if (i < 0)
        {
          i += size ;
        }
      if (i >= 0)
        {
          j--;
        }
      if (j < 0)
        {
          j += size  ;
        }
      if (tab[i][j] == 0)
        {
          tab[i][j]= insert;
        }
      else if (tab[i][j] != 0)
        {
          j++;
          i += 2;
          tab[i][j]=insert;
        }
       if( i==0 && j == 0 )
        {
          insert++;
          i++;
          tab[i][j]=insert;
        }
    }
  for (i = 0; i < size; i++)
    {
      for(j = 0; j < size; j++)
        {
          printf("[%d]", tab[i][j]);
        }
    printf("\n");
    }
  printf("\n\n");
  for(i=0; i< size; i++)
    {
      result=0;
      for(j=0; j< size; j++)
        {
          result += tab[i][j];
        }
    printf("la ligne  %d vaut : %d\n", i , result);
    }
  printf("\n");
  for(j=0; j < size; j++)
    {
      result = 0;
      for(i = 0; i < size; i++)
        {
          result += tab[i][j];
        }
    printf("la colonne  %d vaut : %d\n", j, result);
    }
  printf("\n");
  result = 0;
  j=0;
  for(i = 0; i < size; i++)
    {
      result += tab[i][j];
      j++;
    }
  printf("la diagonal droite vaut : %d\n", result);
  j = 0;
  result = 0;
  for(i = size-1; i != -1; i--)
    {
      result += tab[i][j];
      j++;
    }
  printf("la diagonal gauche vaut : %d\n", result);
  return(EXIT_SUCCESS);
}
