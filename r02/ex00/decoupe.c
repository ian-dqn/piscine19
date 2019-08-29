#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUF_SIZE 4096
typedef struct	s_parse
{
	char		*num;
	char		*char_num;
}	t_parse;

int	ft_strcmp(char s1, char s2)
{
	//	printf("s1:%c\ts2:%c\n");
	if (s1 != s2)
		return (s1 - s2);
	else
		return (0);
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

struct	t_parse	*strs_to_tab(char *strs, int size)
{
	t_parse *str;
	int i;
	int j;
	int k;
	int l;
	int on;

	i = 0;
	j = 0;
	on = 1;
	k = 0;
	l = 0;

	//	if (!(str = malloc (sizeof(strs) * size + 1)))
	//		return (0);

	while (*strs)
	{
		while (on == 1)
		{
			if (*strs == ':')
			{
				on = 0;
				strs++;
			}
			else if (*strs >= '0' && *strs <= '9')
			{
				str[l].num = strs;
				l++;
				strs++;
			}
		}
		while (on == 0)
		{
			while (*strs == ' ')
				strs++;
			if (*strs == '\n')
			{
				on = 1;
				strs++;
			}
			else
			{
				str[k].char_num = strs;
				k++;
				strs++;
			}
		}
	printf("num=%s\tchar=%s\n", str->num, str->char_num);
	}
	printf("num=%s\tchar=%s\n", str->num, str->char_num);
}
/*
void	ft_tab_char(char *str, char *result)
{
	int p;
	int w;
	int x;
	int ret;
	int m;
	char buf[BUF_SIZE];

	p = open(str, O_RDONLY);
	if (p == -1)
		write(1, "ERROR open\n", 11);
	w = 0;
	m = 0;
	while ((ret = read(p, buf, BUF_SIZE)))
	{
		result[w] = buf[m];
		w++;
		m++;
		printf("%c\n", buf[m]);
	}
	result[w] = '\0';
	printf("%s\n", result);
	x = ft_strlen(result);
	strs_to_tab(result, x);
}
*/
int main(int argc, char **argv)
{
	int h;
	char *result;

/*	h = 0;
	if (argc < 2 || argc > 3)
		write(1, "ERROR arg\n", 10);
	else if (argc == 2)
	{
		ft_tab_char("text.dict", result);
	}
	else if (argc == 3)
	{
		ft_tab_char(argv[1], result);
		printf("%s\n", result[5]);
	}
	*/
	int p;
	int w;
	int x;
	int ret;
	char buf[BUF_SIZE + 1];
	int m;

	p = open("text.dict", O_RDONLY);
	if (p == -1)
		write(1, "ERROR open\n", 11);
	ret = read(p, buf, BUF_SIZE);
	w = 0;
	m = 0;
	printf("ret%d\n", ret);
	while (buf[m] != '\0')
	{
		printf("%s\n", buf);
		result[w] = buf[m];
		w++;
		m++;
	}
	result[w] = '\0';
	printf("%s\n", result);
	x = ft_strlen(result);
	strs_to_tab(result, x);
}

