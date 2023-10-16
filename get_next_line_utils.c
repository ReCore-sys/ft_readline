/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:33:41 by kshore            #+#    #+#             */
/*   Updated: 2023/10/16 16:34:22 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dst_c;
	const char	*src_c;

	dst_c = (char *)dst;
	src_c = (const char *)src;
	if (!dst && !src)
		return (NULL);
	while (n--)
		*dst_c++ = *src_c++;
	return (dst);
}

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	new_ptr = malloc(size);
	if (!new_ptr)
		return (NULL);
	if (ptr)
	{
		ft_memcpy(new_ptr, ptr, size);
		free(ptr);
	}
	return (new_ptr);
}
