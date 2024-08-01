/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 09:10:40 by ysbai-jo          #+#    #+#             */
/*   Updated: 2024/08/01 09:11:33 by ysbai-jo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

// some includes
# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

// Reset
# define END "\x1b[0m"
// Bold
# define COLOR_BOLD_BLACK "\x1b[1;30m"
# define COLOR_BOLD_RED "\x1b[1;31m"
# define COLOR_BOLD_GREEN "\x1b[1;32m"
# define COLOR_BOLD_YELLOW "\x1b[1;33m"
# define CBB "\x1b[1;34m"
# define COLOR_BOLD_MAGENTA "\x1b[1;35m"
# define COLOR_BOLD_CYAN "\x1b[1;36m"
# define COLOR_BOLD_WHITE "\x1b[1;37m"

// Underline
# define COLOR_UNDERLINE_BLACK "\x1b[4;30m"
# define CUR "\x1b[4;31m"
# define COLOR_UNDERLINE_GREEN "\x1b[4;32m"
# define COLOR_UNDERLINE_YELLOW "\x1b[4;33m"
# define COLOR_UNDERLINE_BLUE "\x1b[4;34m"
# define COLOR_UNDERLINE_MAGENTA "\x1b[4;35m"
# define COLOR_UNDERLINE_CYAN "\x1b[4;36m"
# define COLOR_UNDERLINE_WHITE "\x1b[4;37m"

# define CHILD 0
# define MALLOC_ERR "philo: malloc: memory allocation failed"
# define LOCK sem_wait
# define UNLOCK sem_post
# define FORKS_SM "/Spoons"
# define PRINT_SM "/printt"
# define MEAL_SM "/potato"
# define DEAD_SM "/man_walking"

// structs
struct	s_all;
struct	s_philo;
struct	s_death;
struct	s_err;

typedef struct s_philo
{
	int				id;
	int				meal;
	size_t			last_meal;
	pthread_t		*t_parent;
	bool			finished;
	struct s_all	*ccu;
}					t_philo;

typedef struct s_err
{
	char			*err_str;
}					t_err;

typedef struct s_all
{
	int				t_eat;
	int				t_sleep;
	int				t_death;
	int				n_philo;
	size_t			creation_t;
	struct s_err	err;
	int				n_meals;
	struct s_philo	*philos;
	sem_t			*forks;
	sem_t			*meal_l;
	sem_t			*pd_l;
	int				*pids;
}					t_all;

// threads function
void				*life(void *philo);
void				*philo_parent(void *philo);

// printing function
//'E' for eating 'S' for sleaping 'T' for thinking
//'R' | 'L' for taking fork 'D' for died
void				printt(t_philo *philo, char flag);

// parsing functions
bool				parser(int ac, char *av[], t_all *ccu);
bool				ccu_init(t_all *ccu);

// external functions
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t n, size_t size);
int					ft_isdigit(int x);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				puterr(char *s);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *str);

// clear and exit funtions
void				destroy(t_all *ccu);
int					exit_v2(t_all *ccu);
void				puterr_msg(t_err *err, char flag);
void				puterr_msg2(t_err *err, char *str, char flag);
void				destroy_philos(t_philo *philo);

// Utils functions
size_t				get_time(void);
size_t				get_curr_time(t_philo *philo);
void				grap_fork(pthread_mutex_t *fork, int i);
void				down_fork(pthread_mutex_t *fork, int lf, int rf);
bool				eat(t_philo *philo);
bool				sleep_think(t_philo *philo);
bool				wait_pt(t_all *ccu);
void				usleep_v2(size_t ms);
void				init_philo_needs(t_philo *philo);
void				special_philo(t_philo *philo);

// Decrement semaphore by 2
void				grap_forks(t_philo *philo);

// Increase semaphore by 2
void				down_forks(t_philo *philo);

// parent wait for philos to exit
void				parent_action(t_all *ccu);

#endif
