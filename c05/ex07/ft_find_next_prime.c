/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiliu <yiliu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:17:45 by yiliu             #+#    #+#             */
/*   Updated: 2023/08/26 18:04:35 by yiliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	baby_root(int nb)
{
	int	num;

	num = 0;
	if (nb >= 0)
	{
		while (num <= 46340)
		{
			if (num * num >= nb)
				return (num);
			num++;
		}
		return (46340);
	}
	return (0);
}

int	ft_is_prime(int nb)
{
	int	babyroot;
	int	num;

	babyroot = baby_root(nb);
	num = 1;
	if (nb <= 1)
		return (0);
	while (num <= babyroot)
	{
		if (nb % num == 0 && nb / num != nb)
			return (0);
		num++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 0)
		return (2);
	if (ft_is_prime(nb))
		return (nb);
	else
	{
		while (!(ft_is_prime(nb)))
			nb++;
		return (nb);
	}
}

// #include <stdio.h>
// int	main()
// {
// 	int	nb = -2147483600;
// 	printf("%d", ft_find_next_prime(nb));
// }
