/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_side_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 10:54:14 by ehafidi           #+#    #+#             */
/*   Updated: 2020/02/10 20:01:45 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memcpy(void *dest, const void *src, size_t n) ///////////////////
{
	char *dest1;
	char *src1;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest1 = (char *)dest;
	src1 = (char *)src;
	while (n > 0)
	{
		if (*dest1 != *src1)
			*dest1 = *src1;
		dest1++;
		src1++;
		n--;
	}
	return (dest);
}

char	*ft_strndup(const char *str, size_t len) /////////////////////////////
{
	unsigned int	i;
	char			*copy;

	if (!(copy = malloc(sizeof(*copy) * (len + 1))))
		return (0);
	i = 0;
	while (i < len)
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int		ft_strlen(char *base)  //////////////////////////////
{
	int i = 0;

	while (base[i])
		i++;
	return (i);
}

int		ft_atoi(const char *str)  ////////////////////////////////
{
	long i;
	long nb;
	int j;

	i = 0;
	nb = 0;
	if (*str == '-')
	{
		i++;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		nb = nb * 10 + (*str - '0');
		str++;
		if (nb > LONG_MAX || nb < 0)
			return (i > 0) ? 0 : -1;
	}
	if (i % 2 != 0)
		nb = -nb;
	return (nb);
}//*/

int	countdigit_d_i(int nb)
{
	int digit = 0;
	unsigned int nbr;

	if (nb == 0)
        return (1);
	if (nb < 0)
		nbr = (unsigned int)(nb * -1);
	else
		nbr = (unsigned int)nb;
	if (nbr <= 9)
		return(++digit);
	while (nbr > 0)
	{
		nbr /= 10;
		digit++;
	}
	return(digit);
}

int	countdigit_u(unsigned int nb)
{
	int digit = 0;
	unsigned int nbr;

	if (nb == 0)
        return (1);
	nbr = (unsigned int)nb;
	if (nbr <= 9)
		return(++digit);
	while (nbr > 0)
	{
		nbr /= 10;
		digit++;
	}
	return(digit);
}

static int    count_no_diggity(int n)
{
    int                len;
    unsigned int    nb;

    len = 0;
    nb = 0;
    if (n == 0)
        return (1);
    if (n < 0)
        nb = (unsigned int)(n * -1);
    else
        nb = (unsigned int)n;
    while (nb > 0)
    {
        nb = nb / 10;
        len++;
    }
    return (len);
}

void       ft_itoa_custom_u(unsigned int n, char *arr)
{
    unsigned int    nb;
    int                sign;
    int                len;
 
    sign = 0;
    len = countdigit_u(n);
    nb = (unsigned int)n;
    while (len-- > sign)
    {
        arr[len] = nb % 10 + '0';
        nb = nb / 10;
    }
}

void       ft_itoa_custom(int n, char *arr)
{
    unsigned int    nb;
    int                sign;
    int                len;
 
    sign = 0;
    len = count_no_diggity(n);
    if (n < 0)
    {
        len++;
		sign = 1;
        nb = (unsigned int)(n * -1);
        *arr = '-';
    }
    else
        nb = (unsigned int)n;
    while (len-- > sign)
    {
        arr[len] = nb % 10 + '0';
        nb = nb / 10;
    }
}

void        ft_itoa_custom_pos(int n, char *arr)
{
    unsigned int    nb;
    int                len;
	
    len = count_no_diggity(n);
    if (n < 0)
        nb = (unsigned int)(n * -1);
    else
        nb = (unsigned int)n;
    while (len-- > 0)
    {
        arr[len] = nb % 10 + '0';
		nb = nb / 10;
    }
}

void        ft_itoa_custom_pos_u(unsigned int n, char *arr)
{
    unsigned int    nb;
    int                len;
	
    len = countdigit_u(n);
    nb = (unsigned int)n;
    while (len-- > 0)
    {
        arr[len] = nb % 10 + '0';
		nb = nb / 10;
    }
}

void        ft_ulltoa_base(unsigned long long n, char *arr, char *base)
{
    int                len;
	int					lenny;
 
    len = countdigit_base(n, base);
	lenny = ft_strlen(base);
    while (len-- > 0)
    {
        arr[len] = base[n % lenny];
        n = n / lenny;
    }
}

int	countdigit_base(unsigned long long nb, char *base)
{
	int digit = 0;
	int i = ft_strlen(base);

	if (nb == 0)
		return(1); 		
	while (nb > 0)
	{
		nb /= i;
		digit++;
	}	
	return(digit);
}

void		ft_putnbr_base(int n, char *base, char *str)
{
	unsigned int nb;
	int a;
	static int i = 0;
	int y;

	y = 0;
	if (i != 0)
		i = y;
	a = ft_strlen(base);
	nb = (unsigned int)n;
	if (nb >= a)
		ft_putnbr_base((nb / a), base, str);
	str[i++] = base[nb % a];
}

void	ft_putnbr_custom_pos(int n, char *src)
{
	unsigned int nb;
	static int i = 0;
	int y;

	y = 0;
	if (i != 0)
		i = y;

	if (n < 0)
	{
		nb = (unsigned int)(n * -1);
	}
	else
		nb = (unsigned int)n;
	if (nb > 9)
		ft_putnbr_custom_pos(nb / 10, src);
	src[i++] = nb % 10 + '0';
}

void	ft_putnbr_custom(int n, char *src)
{
	unsigned int nb;
	static int i = 0;
	int y;

	y = 0;
	if (i != 0)
		i = y;
 	if (n < 0)
	{
		nb = (unsigned int)(n * -1);
		src[i++] = '-';
	}
	else
		nb = (unsigned int)n;
	if (nb > 9)
		ft_putnbr_custom(nb / 10, src);
	src[i++] = nb % 10 + '0';
}

int	ft_putnbr_base_p(unsigned long long nbr, char *base)
{
	int a;
	static int p = 1;
	a = ft_strlen(base);
	if (nbr > a)
	{
		++p;
		ft_putnbr_base_p((nbr / a), base);
	}
	write(1, &base[nbr % a], 1);
	return (p);
}
