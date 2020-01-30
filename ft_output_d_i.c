/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_d_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 14:34:47 by ehafidi           #+#    #+#             */
/*   Updated: 2020/01/30 15:48:48 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*digit_overall(char *display, int digit, int nb, s_flags flags)
{
	int i;
	//printf("ici1\n"); ////////////////
	i = 0;
	int lngth;
	nb >= 0 ? (lngth = digit) : (lngth = digit + 1);
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	ft_itoa_custom(nb, display);
	return (display);
}

char	*prec_overall(char *display, int digit, int nb, s_flags flags)
{
	int lngth;
	int i;
	int y;

	//printf("ici2\n"); ////////////////
	y = 0;
	(nb >= 0) ? (lngth = flags.prec) : (lngth = flags.prec + 1);
	//(flags.chmp < flags.prec) ? lngth = -flags.chmp : (lngth = lngth);
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	i = lngth - digit;
	//printf("%d%s\n", digit, ": digit");
	while (y < lngth)
		display[y++] = '0';
	//printf("%d%s\n", i, ": i"); /////////	
	ft_itoa_custom_pos(nb, &display[i]);
	if (nb < 0)
		display[0] = '-';
	return (display);
}

char	*chmp_neg_prec_pos(char *display, int digit, int nb, s_flags flags)
{
	int lngth;
	int i;
	int y;
	//printf("ici0\n"); ///////////////***********************
	y = 0;
	-flags.chmp >= flags.prec ? lngth = -flags.chmp : (lngth = -flags.chmp + 1);
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	i = flags.prec - digit;
	while (y < lngth)
		display[y++] = ' ';
	if (flags.prec < digit)
		ft_itoa_custom_pos(nb, display);
	else
		ft_itoa_custom_pos(nb, &display[i]);
	y = 0;
	while (y < (flags.prec - digit))
	{
		display[--i] = '0';
		y++;
	}
	if (nb < 0)
		display[0] = '-';
	return (display);
}

char	*chmp_neg_prec_pos_nb_neg(char *display, int digit, int nb, s_flags flags)
{
	int lngth;
	int i;
	int y;
	//printf("ici0000\n"); ///////////////***********************
	//printf("%d%s\n", digit, ": digit"); ///////////////***********************
	y = 0;
	-flags.chmp >= flags.prec ? lngth = -flags.chmp : (lngth = -flags.chmp + 1);
	(digit + 1 >= flags.chmp) ? lngth = digit : (lngth = lngth); 
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	(nb >= 0) ? (i = flags.prec - digit) : (i = flags.prec - digit + 1);
	while (y < lngth)
		display[y++] = ' ';
	if (flags.prec < digit)
		ft_itoa_custom(nb, display);
	else
		ft_itoa_custom_pos(nb, &display[i]);
	y = 0;
	while (y < (flags.prec - digit))
	{
		display[--i] = '0';
		y++;
	}
	if (nb < 0)
		display[0] = '-';
	return (display);
}

char	*chmp_overall_thn_dgt_pos(char *display, int digit, int nb, s_flags flags) //regler ca
{
	int lngth;
	int i;
	int y;
	//printf("ici3\n"); ///////////////
	lngth = flags.chmp;
	y = 0;
	if (!(display = malloc(sizeof(char) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	i = lngth - digit;
	while (y < lngth)
		display[y++] = ' ';
	y = 0;
	if (flags.prec < 0 && flags.att > 0)
		while (y < lngth)
			display[y++] = '0';
	if (flags.att < 0)
		ft_itoa_custom(nb, display);
	else
		ft_itoa_custom(nb, &display[i]);
	return (display);
}

char	*chmp_overall_thn_dgt_neg(char *display, int digit, int nb, s_flags flags) //regler ca
{
	int lngth;
	int i;
	int y;

	//printf("ici4\n"); ///////////////*********************
	++digit;
	lngth = flags.chmp;
	if (nb < 0 && digit == flags.chmp + 1)
		lngth = digit;
	y = 0;
	if (!(display = malloc(sizeof(char) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0';
	i = lngth - digit;
	while (y < lngth)
		display[y++] = ' ';
	y = 0;	
	if (flags.att > 0 && nb < 0 && flags.prec < 0)
	{
		while (y < lngth)
			display[y++] = '0';
		display[0] = '-';	
		ft_itoa_custom_pos(nb, &display[lngth - digit + 1]);
	}
	else if (flags.att < 0)
		ft_itoa_custom(nb, display);
	else 
		ft_itoa_custom(nb, &display[i]);
	return (display);
}

char	*chmp_overall_thn_prec_pos(char *display, int digit, int nb, s_flags flags)
{
	int lngth;
	int i;
	int y;

	//printf("ici5\n"); ////////////////
	y = 0;
	lngth = flags.chmp;
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0'; ///////
	(flags.att >= 0) ? (i = lngth - digit) : (i = flags.prec - digit);
	while (y < lngth)
		display[y++] = ' ';
	if (flags.att < 0)
		ft_itoa_custom(nb, &display[flags.prec - digit]);
	else
		ft_itoa_custom(nb, &display[i]);
	y = 0;
	while (y < (flags.prec - digit))
	{
		display[--i] = '0';
		y++;
	}
	return (display);
}

char	*chmp_overall_thn_prec_neg(char *display, int digit, int nb, s_flags flags)
{
	int lngth;
	int i;
	int y;

	y = 0;
	lngth = flags.chmp;
	//printf("ici6\n"); ////////////////
	if (!(display = malloc(sizeof(*display) * (lngth + 1))))
		return (NULL);
	display[lngth] = '\0'; 
	(flags.att >= 0) ? (i = lngth - digit - 1) : (i = flags.prec - digit);
	while (y < lngth)
		display[y++] = ' ';
	if (flags.att < 0)
		ft_itoa_custom_pos(nb, &display[flags.prec - digit + 1]);
	else
		ft_itoa_custom_pos(nb, &display[i + 1]);
	y = 0;
	while (y < (flags.prec - digit))
	{
		display[i--] = '0';
		y++;
	}
	if (nb < 0)
		display[i--] = '-';
	return (display);
}

void 	printf_d_i(va_list *prms, s_flags flags) //separation de l'algo en fonction des situations
{
	int nb = va_arg(*prms, int);
	int digit;
	char *display;

/*	printf("%d%s\n", flags.att, ": att");
	printf("%d%s\n", flags.chmp, ": chmp");
	printf("%d%s\n", flags.prec, ": prec");*/
	digit = countdigit_d_i(nb);
	//printf("%d%s\n", digit, ": digit"); ////////
	if (digit >= flags.chmp && digit >= flags.prec && flags.chmp >= 0)
		display = digit_overall(display, digit, nb, flags);
	else if (flags.chmp < 0 && nb >= 0) 
		display = chmp_neg_prec_pos(display, digit, nb, flags);
	else if (flags.chmp < 0 && nb < 0) 
		display = chmp_neg_prec_pos_nb_neg(display, digit, nb, flags);	
	else if (flags.prec >= flags.chmp && flags.prec >= digit)
		display = prec_overall(display, digit, nb, flags);
	else if (flags.chmp >= flags.prec && flags.chmp >= digit && flags.prec <= digit && nb >= 0) 
		display = chmp_overall_thn_dgt_pos(display, digit, nb, flags);
	else if (flags.chmp >= flags.prec && flags.chmp >= digit && flags.prec <= digit && nb < 0) 
		display = chmp_overall_thn_dgt_neg(display, digit, nb, flags); 
	else if (flags.chmp >= flags.prec && flags.chmp >= digit && flags.prec > digit && nb >= 0)
		display = chmp_overall_thn_prec_pos(display, digit, nb, flags);
	else if (flags.chmp >= flags.prec && flags.chmp >= digit && flags.prec > digit && nb < 0)
		display = chmp_overall_thn_prec_neg(display, digit, nb, flags);
	write(1, display, ft_strlen(display));
	//display[0] = '\0';
	free(display);
}
