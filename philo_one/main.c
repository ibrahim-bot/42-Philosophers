/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:08:44 by ichougra          #+#    #+#             */
/*   Updated: 2021/05/12 17:20:15 by ichougra         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void    *funct1(void *arg)
{
    int i = 0;

    while (i < 10)
    {
        printf("thread 1: %d\n", i);   
        i++;
    }
    return (NULL);
}

int main(int ac, char **av)
{
    pthread_t t1;

    

 
    pthread_create(&t1, NULL, funct1, NULL);




    pthread_join(t1, NULL);

    return (0);
}