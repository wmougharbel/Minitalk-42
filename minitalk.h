/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmoughar <wmoughar@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:07:33 by wmoughar          #+#    #+#             */
/*   Updated: 2023/02/20 15:07:33 by wmoughar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "Libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <signal.h>
# include <stdlib.h>

void	ft_handler(int n, siginfo_t *info, void *ucontext);
int		ft_convert(char c, int client, int i);
void	success_msg(int n);

#endif
