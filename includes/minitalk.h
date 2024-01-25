/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albestae <albestae@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:44:40 by albestae          #+#    #+#             */
/*   Updated: 2024/01/25 11:37:52 by albestae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putstr(char *s);
void	ft_putnbr(int n);
char	*ft_strjoin(char *s1, char const c);
int		ft_strlen(char *str);
int		ft_atoi(char *str);

#endif
