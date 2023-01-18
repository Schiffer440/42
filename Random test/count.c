/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:36:16 by adugain           #+#    #+#             */
/*   Updated: 2022/11/18 11:36:17 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
int count(int n)
    {
        int i;

        i = 1;
        while(n / 10)
        {
            n /= 10;
            i++;
        }
        return(i);
    
    }

int main()
    {
        printf("%d\n", count(123456789123456789));
    }
