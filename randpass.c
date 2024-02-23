/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocubukcu <ocubukcu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:57:15 by ocubukcu          #+#    #+#             */
/*   Updated: 2024/02/23 21:42:05 by ocubukcu         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cb_atoi(char *str)
{
	int i;
	int p;
	int ne;

	i = 0;
	p = 1;
	ne = 0;

	while(str[i] == 32 || (str[i] >= 0 && str[i] <= 13))
		i++;
	while(str[i] == '-' || str[i] == '+')
	{
		p *= (str[i] == '-') * -1 + !(str[i] == '-');
		i++; 
	}
	while(str[i] >= '0' && str[i] <= '9')
		ne = ne * 10 + str[i++] - 48;
	return (ne * p);
}

void RandPass(int len) 
{
   char writable[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()";
   char password[len+1];
   
   srand(time(0));
   int i = 0;
   while(i < len) 
   {
       int randomIndex = rand() % (sizeof(writable) - 1);
       password[i] = writable[randomIndex];
       i++;
   }
   password[len] = '\0';
   printf("Generated password is: %s\n", password);
}

int main(int argc, char *argv[]) 
{
   if(argc != 2) {
       printf("Usage: %s", argv[0]);
       printf(" <password_length>\n");
       return 1;
   }

   int len = cb_atoi(argv[1]);
   if(len <= 0) 
   {
       printf("Please enter a valid positive integer for password length.\n");
       return 1;
   }

   RandPass(len);
   return 0;
}
