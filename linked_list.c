#include "parse.h"

size_t	ft_arrlen(char **array)
{
	int	len;

	len = 0;
	while (array && array[len])
		++len;
	return (len);
}

char	**new_elements_without_type(char **content)
{
	char	**new;
	int		len;
	int		i;

	len = ft_arrlen(content);
	new = ft_calloc(len, sizeof(char *));
	i = 0;
	while (i < len - 1)
	{
		new[i] = ft_strdup(content[i + 1]);
		++i;
	}
	return (new);
}

t_list	*rt_lstnew(char **content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->type = ft_strdup(content[0]);
	new->elements = new_elements_without_type(content);
	new->next = NULL;
	return (new);
}

void	rt_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cur;

	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	cur = *lst;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}

// 출력용 임시 함수
void	rt_lstprint(t_list *lst)
{
	int	i;

	while (lst)
	{
		if (lst->type)
		{
			write(1, "type : ", 7);
			write(1, lst->type, ft_strlen(lst->type));
			write(1, "  ", 2);
		}
		i = 0;
		if (lst->elements)
		{
			while (lst->elements[i])
			{
				write(1, "    ", 4);
				write(1, lst->elements[i], ft_strlen(lst->elements[i]));
				++i;
			}
		}
		lst = lst->next;
	}
}