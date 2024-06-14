/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftanon <ftanon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:42:01 by ftanon            #+#    #+#             */
/*   Updated: 2023/12/07 17:06:10 by ftanon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# include <ctype.h>
# include <string.h>
# include <bsd/string.h>
# include <fcntl.h>

# include <limits.h>
# include <stdarg.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *string);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr_unsigned_fd(unsigned int n, int fd);
int		longlen(long longnum, int base);
int		longlonglen_unsigned(unsigned long long longnum, int base);
char	*ft_itoabase_unsigned(unsigned long long num, char *baselist, int base);
int		ft_printf(const char *str, ...);
void	ft_printxx(unsigned int num, char x, int *ptrlength);
void	ft_printc(int character, int *ptrlength);
void	ft_printp(unsigned long long num, int *ptrlength);
void	ft_prints(char *string, int *ptrlength);
void	ft_printdi(int number, int *ptrlength);
void	ft_printu(unsigned int number, int *ptrlength);
#endif