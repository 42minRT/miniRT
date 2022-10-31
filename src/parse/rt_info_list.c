#include "../../include/parse.h"

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

t_rt_list	*new_rt_lst(char **content)
{
	t_rt_list	*new;

	new = malloc(sizeof(t_rt_list));
	if (new == NULL)
		return (NULL);
	new->type = ft_strdup(content[0]);
	new->elements = new_elements_without_type(content);
	new->next = NULL;
	return (new);
}

void	rt_lstadd_back(t_rt_list **lst, t_rt_list *new)
{
	t_rt_list	*cur;

	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	cur = *lst;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = new;
}

char	**get_elements_by_type(t_rt_list *file, char *type)
{
	while (file->next)
	{
		if (ft_strncmp(type, file->type, ft_strlen(file->type)) == 0)
			return (file->elements);
		file = file->next;
	}
	return (NULL);
}

// 출력용 임시 함수
void	rt_lstprint(t_rt_list *lst)
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
