/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:17:36 by kshore            #+#    #+#             */
/*   Updated: 2023/10/17 22:17:54 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*get_next_line(int fd);
int		main(void);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_realloc(void *ptr, size_t size);
char	*append_and_extend(char *src, char inp);
