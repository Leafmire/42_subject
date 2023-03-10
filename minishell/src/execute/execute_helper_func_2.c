/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_helper_func_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 13:22:19 by hseong            #+#    #+#             */
/*   Updated: 2022/06/16 15:14:18 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

// IFS: Internal Field Seperator
int	is_ifs(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}
