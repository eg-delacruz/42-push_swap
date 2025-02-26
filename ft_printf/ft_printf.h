/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erde-la- <erde-la-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:01:23 by erde-la-          #+#    #+#             */
/*   Updated: 2024/12/04 12:43:04 by erde-la-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char*s, ...);
int		ft_putchar_fd_custom(char c, int fd);
int		ft_putstr_fd_custom(char *s, int fd);
int		ft_putnbr_fd_custom(int n, int fd);
int		ft_hexa(int n, char x);
size_t	ft_strlen(const char *str);
int		ft_put_unsign(unsigned int nb, int fd);
int		ft_putptr(void *ptr, int fd);

#endif
