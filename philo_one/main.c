/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:08:44 by ichougra          #+#    #+#             */
/*   Updated: 2021/05/12 16:07:52 by ichougra         ###   ########lyon.fr   */
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

void    *funct2(void *arg)
{
    int i = 0;

    while (i < 10)
    {
        printf("thread 2: %d\n", i);   
        i++;
    }
    return (NULL);
}

int main()
{
    pthread_t t1;
    pthread_t t2;

    pthread_create(&t1, NULL, funct1, NULL);
    pthread_create(&t2, NULL, funct2, NULL);
    
    pthread_create(&t1, NULL, funct1, NULL);
    pthread_create(&t1, NULL, funct1, NULL);

    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return (0);
}