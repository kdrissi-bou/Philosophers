/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrissi- <kdrissi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 19:59:38 by kdrissi-          #+#    #+#             */
/*   Updated: 2021/10/06 19:37:36 by kdrissi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_philo *philo, char *str)
{
	t_time currently;

	currently = now() - philo->start;
	pthread_mutex_lock(&philo->print);
	printf("%d time %d id %s\n",currently , philo->id, str);
	pthread_mutex_unlock(&philo->print);
}

void	zzzz(t_time	time)
{
	t_time	this_time;

	this_time = now();
	usleep((time - 18) * 1000);
	while (now() <= this_time + time)
		;
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->fork[i]);
	print(philo, "has taken a fork");
	pthread_mutex_lock(philo->fork[i + 1]); // tada % philo.nbr;
	print(philo, "has taken a fork");
	print(philo, "is eating");
	zzzz(philo->time_to_eat);
	philo->last_time_eated = now();
	pthread_mutex_unlock(philo->fork[i]);
	pthread_mutex_unlock(philo->fork[i + 1]);
}

void	sleeping(t_philo *philo)
{
	print(philo, "is sleeping");
	zzzz(philo->time_to_sleep);
}

void	*life_of_a_philo(t_philo *philo)
{
	while (1)
	{
		eating(philo);
		sleeping(philo);
		print(philo, "is thinking");
	}
}

void	checker(t_philo *philo)
{
	
	while (philo->last_time_eated[i] < philo->time_to_die) // check i
	{
		
	}
}

int		main(int ac, char **av)
{
	t_philo		*philo;

	if (!get_input(ac, av, philo))
		return(1);
	if (!create(philo))
		return;
}
