#ifndef PHILO_H
# define PHILO_H


//some includes
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdbool.h>

#ifndef COLORS_H
# define COLORS_H

// Reset
#define END   "\x1b[0m"

// Regular Colors
#define COLOR_BLACK   "\x1b[0;30m"
#define COLOR_RED     "\x1b[0;31m"
#define COLOR_GREEN   "\x1b[0;32m"
#define COLOR_YELLOW  "\x1b[0;33m"
#define COLOR_BLUE    "\x1b[0;34m"
#define COLOR_MAGENTA "\x1b[0;35m"
#define COLOR_CYAN    "\x1b[0;36m"
#define COLOR_WHITE   "\x1b[0;37m"

// Bold
#define COLOR_BOLD_BLACK   "\x1b[1;30m"
#define COLOR_BOLD_RED     "\x1b[1;31m"
#define COLOR_BOLD_GREEN   "\x1b[1;32m"
#define COLOR_BOLD_YELLOW  "\x1b[1;33m"
#define COLOR_BOLD_BLUE    "\x1b[1;34m"
#define COLOR_BOLD_MAGENTA "\x1b[1;35m"
#define COLOR_BOLD_CYAN    "\x1b[1;36m"
#define COLOR_BOLD_WHITE   "\x1b[1;37m"

// Underline
#define COLOR_UNDERLINE_BLACK   "\x1b[4;30m"
#define COLOR_UNDERLINE_RED     "\x1b[4;31m"
#define COLOR_UNDERLINE_GREEN   "\x1b[4;32m"
#define COLOR_UNDERLINE_YELLOW  "\x1b[4;33m"
#define COLOR_UNDERLINE_BLUE    "\x1b[4;34m"
#define COLOR_UNDERLINE_MAGENTA "\x1b[4;35m"
#define COLOR_UNDERLINE_CYAN    "\x1b[4;36m"
#define COLOR_UNDERLINE_WHITE   "\x1b[4;37m"

// Background
#define COLOR_BG_BLACK   "\x1b[40m"
#define COLOR_BG_RED     "\x1b[41m"
#define COLOR_BG_GREEN   "\x1b[42m"
#define COLOR_BG_YELLOW  "\x1b[43m"
#define COLOR_BG_BLUE    "\x1b[44m"
#define COLOR_BG_MAGENTA "\x1b[45m"
#define COLOR_BG_CYAN    "\x1b[46m"
#define COLOR_BG_WHITE   "\x1b[47m"

// High Intensity
#define COLOR_INTENSE_BLACK   "\x1b[0;90m"
#define COLOR_INTENSE_RED     "\x1b[0;91m"
#define COLOR_INTENSE_GREEN   "\x1b[0;92m"
#define COLOR_INTENSE_YELLOW  "\x1b[0;93m"
#define COLOR_INTENSE_BLUE    "\x1b[0;94m"
#define COLOR_INTENSE_MAGENTA "\x1b[0;95m"
#define COLOR_INTENSE_CYAN    "\x1b[0;96m"
#define COLOR_INTENSE_WHITE   "\x1b[0;97m"

// Bold High Intensity
#define COLOR_BOLD_INTENSE_BLACK   "\x1b[1;90m"
#define COLOR_BOLD_INTENSE_RED     "\x1b[1;91m"
#define COLOR_BOLD_INTENSE_GREEN   "\x1b[1;92m"
#define COLOR_BOLD_INTENSE_YELLOW  "\x1b[1;93m"
#define COLOR_BOLD_INTENSE_BLUE    "\x1b[1;94m"
#define COLOR_BOLD_INTENSE_MAGENTA "\x1b[1;95m"
#define COLOR_BOLD_INTENSE_CYAN    "\x1b[1;96m"
#define COLOR_BOLD_INTENSE_WHITE   "\x1b[1;97m"

// High Intensity Backgrounds
#define COLOR_BG_INTENSE_BLACK   "\x1b[0;100m"
#define COLOR_BG_INTENSE_RED     "\x1b[0;101m"
#define COLOR_BG_INTENSE_GREEN   "\x1b[0;102m"
#define COLOR_BG_INTENSE_YELLOW  "\x1b[0;103m"
#define COLOR_BG_INTENSE_BLUE    "\x1b[0;104m"
#define COLOR_BG_INTENSE_MAGENTA "\x1b[0;105m"
#define COLOR_BG_INTENSE_CYAN    "\x1b[0;106m"
#define COLOR_BG_INTENSE_WHITE   "\x1b[0;107m"

#endif

# define MALLOC_ERR "philo: malloc: memory allocation failed"
# define LOCK pthread_mutex_lock
# define UNLOCK pthread_mutex_unlock
# define DSTR pthread_mutex_destroy

// structs
struct s_all;
struct s_philo;
struct s_death;
struct s_err;

typedef struct s_philo
{
    int id;
    int meal;
    size_t  last_meal;
    pthread_t   *t;
    bool    finished;
    struct s_all *ccu;
    pthread_mutex_t *r_fork;
    pthread_mutex_t *l_fork;
}       t_philo;

typedef struct s_death
{
    int philo_id;
    int death_time;
}       t_death;

typedef struct s_err
{
    char *err_str;
}       t_err;

typedef struct s_all
{
    int t_eat;
    int t_sleep;
    int t_death;
    int n_philo;
    bool all_alive;
    size_t creation_t;
    pthread_mutex_t *forks;
    struct s_death dead;
    struct s_err err;
    int n_meals;
    struct s_philo  *philos;
    pthread_mutex_t global_l;
    pthread_mutex_t meal_l;
}       t_all;

 
//threads function
void    *life(void *philo);

//printing philo status
bool    printt(t_philo *philo, char flag);


//parsing functions
bool    parser(int ac, char *av[], t_all *ccu);
bool    ccu_init(t_all *ccu);



//clear and exit funtions
bool    destroy(t_all *ccu);
int     exit_v2(t_all *ccu);
void    puterr_msg(t_err *err, char flag);
void    puterr_msg2(t_err *err, char *str, char flag);



/*                      >>>>>UTILS FUNCTIONS<<<<<                    */

//gettings current time
size_t  get_time(void);
size_t  get_curr_time(t_philo *philo);

//thread eating routine function
bool    eat(t_philo *philo);

//thread sleeping and thinking routine funtion
bool    sleep_think(t_philo *philo);

//wait for philos to join them
bool    wait_pt(t_all *ccu);

//control pair and umpair philos to prevente dead lock, also exit if one philos is existing
bool    special_philo(t_philo *philo);

//check whatever a philo is dead and release locked mutexes
bool    check_alive(t_philo *philo, char flag);

//improved sleep function, it sleeps the exact time given
void    usleep_v2(size_t ms);

//setting death flag to threads in order to quit
bool    death_action(t_all *ccu, int i);

//setting finished flag to thread in order to terminate simulation
void    meal_action(t_all *ccu, int i, int *all_eat);



/*                      >>>>>external functions<<<<<                 */
int     ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t n, size_t size);
int     ft_isdigit(int x);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	puterr(char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);





#endif




