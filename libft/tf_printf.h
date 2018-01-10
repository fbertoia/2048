/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bteissei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 03:22:12 by bteissei          #+#    #+#             */
/*   Updated: 2017/12/08 06:16:17 by bteissei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TF_PRINTF_H
# define TF_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 20

int				get_next_line(const int fd, char **line);
int				ft_printf(const char *format, ...);
int				ft_fdprintf(int fd, const char *format, ...);

typedef struct	s_attribut
{
	int diese;
	int zero;
	int minus;
	int space;
	int plus;
}				t_attribut;

typedef struct	s_sides
{
	t_attribut	*attributs;
	int			longueur;
	int			largeur;
	int			precision;
}				t_sides;

char			*checkarg(char *str, va_list ap);
int				setfd(int fd, int mode);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
int				ft_atoi(const char *str);
size_t			ft_strlen(const char *s);
char			*ft_strcpy(char *dst, const char *src);
void			ft_putstr(char const *s);
void			*ft_memalloc(size_t size);
void			ft_bzero(void *s, size_t n);
void			ft_memdel(void **ap);
char			*ft_strchr(const char *s, int c);
char			*ft_itoa(long long n, int base);
char			*ft_utoa(unsigned long long n, unsigned int base);
char			*ft_strdup(const char *s1);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*dosprecision(t_sides *sides, char *str);
int				ft_putcount(char c, int mode);
int				getattributs(char *str, char *end, t_sides *sides);
void			getlargeur(char *str, char *end, t_sides *sides);
void			getprecision(char *str, char *end, t_sides *sides);
void			getlongueur(char *str, char *end, t_sides *sides);
void			oklargeur(char *str, t_sides *sides);
void			okattributs(char *str, t_sides *sides);
int				parses(t_sides *sides, va_list ap);
int				parsed(t_sides *sides, va_list ap);
int				parseu(t_sides *sides, va_list ap);
int				parseo(t_sides *sides, va_list ap);
int				parsep(t_sides *sides, va_list ap);
int				parsec(t_sides *sides, va_list ap);
int				printc(t_sides *sides, int i);
int				parselc(t_sides *sides, va_list ap);
int				parsels(t_sides *sides, va_list ap);
int				checkbitsign(int i);
char			*givemetwo(int i);
char			*givemethree(int i);
char			*givemefour(int i, char *str);
int				parseprc(t_sides *sides);
int				parsex(t_sides *sides, va_list ap, int mode);
char			*rightalign(t_sides *sides, char *str);
char			*leftalign(t_sides *sides, char *str);
char			*checklongueuru(t_sides *sides, va_list ap);
char			*checklongueuro(t_sides *sides, va_list ap);
char			*checklongueurx(t_sides *sides, va_list ap);
char			*returnintx(va_list ap);
char			*returnintu(va_list ap);
char			*returninto(va_list ap);
char			*checkprecisionx(t_sides *sides, char *str);
char			*prints(int i);
char			*returnint(va_list ap);
char			*returnlong(va_list ap);
char			*returnlonglong(va_list ap);
char			*returnintmax(va_list ap);
char			*returnsizet(va_list ap);
char			*printuntil(char *str);
int				parseconvann2(char *end, t_sides *sides, va_list ap);
void			getattrann(t_sides *sides, char *str, char *end, int *point);

#endif
