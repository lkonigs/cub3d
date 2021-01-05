#include "libft.h"

char				*ft_free(char *s)
{
	free(s);
	s = NULL;
	return (s);
}