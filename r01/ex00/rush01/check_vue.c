int check_col(int **tab, int i, int j)
{
	int indicea;
	int indiceb;
	int taillea;
	int tailleb;
	int zero;

	indicea = 0;
	indiceb = 0;
	taillea = 0;
	tailleb = 0;


	while (++i < 5)
	{
		if (tab[i][j] == 0)
			zero = 1;
		else if (tab[i][j] > indicea)
		{
			indicea = tab[i][j];
			taillea++;
		}
	}	
	while (--i > 0 && i < 5)
	{
		if (tab[i][j] > indiceb)
		{
			indiceb = tab[i][j];
			tailleb++;
		}
	}
	if (taillea == tab[0][j] && tailleb == tab[6][j] && zero == 0)
		return (1);
	if (taillea == tab[0][j] && tailleb == tab[6][j] && zero == 1)
		return (-1);
	return (0);
}
