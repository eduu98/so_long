/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecruz-go <ecruz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:37:47 by ecruz-go          #+#    #+#             */
/*   Updated: 2022/03/01 12:56:28 by ecruz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Prints a error message in red and returns 0 */
int	print_error(char *message)
{
	char	*final_message;

	final_message = ft_strjoin("\033[31mError: ", message);
	final_message = ft_strjoin(final_message, "\n\e[0m");
	ft_putstr_fd(final_message, 1);
	return (0);
}

/* Prints a error message in red and returns NULL */
void	*null_error(char *message)
{
	char	*final_message;

	final_message = ft_strjoin("\033[31mError: ", message);
	final_message = ft_strjoin(final_message, "\n\e[0m");
	ft_putstr_fd(final_message, 1);
	return (0);
}

/* Prints a error message in red and returns 0 */
void	print_warning(char *message)
{
	char	*final_message;

	final_message = ft_strjoin("\033[33mWarning: ", message);
	final_message = ft_strjoin(final_message, "\n\e[0m");
	ft_putstr_fd(final_message, 1);
}