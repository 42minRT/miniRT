int	count_elements(char **elements)
{
	int	cnt;

	cnt = 0;
	while (elements[cnt])
		++cnt;
	return (cnt);
}
