void    ft_rev_int_tab(int *tab, int size);

int main()
{
	int i;

	int tab[16]= {0,1,2,3,4,5,6,7,8,9, 10, 11, 12, 13, 14, 15};

	 ft_rev_int_tab(tab, 16);
	for (i = 0; i < 16; i++)
	{
		printf("%d\n", tab[i]);
	}
}
