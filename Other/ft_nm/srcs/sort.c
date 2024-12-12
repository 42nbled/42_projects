#include "ft_nm.h"

static int diff_underscore(char *a, char *b)
{
	if (!*a || !*b)
		return *a - *b;
	while (*a && *b)
	{
		if (*a == '_')
		{
			a++;
			continue ;
		}
		if (*b == '_')
		{
			b++;
			continue ;
		}
		if (*a != *b)
			return *a - *b;
		a++;
		b++;
	}
	return 0;
}

static int	diff_start(char *a, char *b)
{
	int	i = 0;
	int	j = 0;
	for (i=0; a[i] && a[i] == '_'; ++i) ;
	for (j=0; b[j] && b[j] == '_'; ++j) ;

	return (j - i);
}

static int	diff_end(char *a, char *b)
{
	int	i=strlen(a);
	int	j=strlen(b);
	if (!i || !j)
		return (0);

	for (i -= 1; i >= 0 && a[i] && a[i] == '_'; --i) ;
	for (j -= 1; j >= 0 && b[j] && b[j] == '_'; --j) ;

	return (i - j);
}

static int	diff_middle(char *a, char *b)
{
	for (; a && (*a) == '_'; ++a) ;
	for (; b && (*b) == '_'; ++b) ;

	int k=strlen(a);
	int l=strlen(b);
	if (!k || !l)
		return (0);
	for (k -= 1; k >= 0 && a[k] && a[k] == '_'; --k) ;
	for (l -= 1; l >= 0 && b[l] && b[l] == '_'; --l) ;

	int	i = 0;
	int	j = 0;
	int	c = 0;
	int	d = 0;
	for (i=0; a[i] < k; ++i)
		if (a[i] == '_')
			c++;
	for (j=0; b[j] < l; ++j)
		if (b[j] == '_')
			d++;

	return (d - c);
}

int diff_str(t_lst *a, t_lst *b)
{
	if (!a || !a->data || !a->data->name)
		return 0;
	if (!b || !b->data || !b->data->name)
		return 0;

	int ds = diff_start(a->data->name, b->data->name);
	int dm = diff_middle(a->data->name, b->data->name);
	int de = diff_end(a->data->name, b->data->name);
	int status = diff_underscore(a->data->name, b->data->name);

	if (status != 0)	return status;
	if (ds)				return ds;
	if (dm)				return dm;
	if (de)				return de;
	return (a->data->i_value - b->data->i_value);
}

int	reverse_diff_str(t_lst *a, t_lst *b)
{
	return (diff_str(b, a));
}
