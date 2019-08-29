int main ()
{
	int i;
	int tab[20]= {2,3,0,1,2,0,3,2,2,2,3,2,2,0,2,5,2,1,3,5};
	ft_sort_int_tab(tab, 20);

	for (i=0; i < 20  ; i++) {
		printf("%d\n",tab[i]);
	}
	return (0);
}
