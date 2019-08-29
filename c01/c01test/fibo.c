void	ft_fib(int index)
{
	if (index > 0)
		(ft_fib(index - 1) * (ft_fib(index - 2)));
}

int main()
{
	ft_fib(7);	
}
