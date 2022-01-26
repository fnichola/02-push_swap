
void	print_stacks(t_data *data)
{
	t_stack	a;
	t_stack	b;

	a = data->a;
	b = data->b;
	while (a.top || b.top)
	{
		if (a.size > b.size)
		{
			ft_printf("%d", a.top->value);
			if (a.top == data->sorted)
				ft_printf("~\n");
			else if (a.top->pivot_marker)
				ft_printf("<\n");
			else if (a.top->partition)
				ft_printf("*\n");
			else
				ft_printf("\n");
			a.size--;
			a.top = a.top->prev;
		}
		else if (b.size > a.size)
		{
			ft_printf(" \t%d", b.top->value);
			if (b.top->partition)
				ft_printf("*\n");
			else if (b.top->pivot_marker)
				ft_printf("<\n");
			else
				ft_printf("\n");
			b.size--;
			b.top = b.top->prev;
		}
		else
		{
			ft_printf("%d", a.top->value);
			if (a.top == data->sorted)
				ft_printf("~\t");
			else if (a.top->pivot_marker)
				ft_printf("<\t");
			else if (a.top->partition)
				ft_printf("*\t");
			else
				ft_printf("\t");
			ft_printf("%d", b.top->value);
			if (b.top->partition)
				ft_printf("*\n");
			else if (b.top->pivot_marker)
				ft_printf("<\n");
			else
				ft_printf("\n");
			a.size--;
			b.size--;
			a.top = a.top->prev;
			b.top = b.top->prev;
		}
	}
	ft_printf("_\t_\na\tb\n\n");
	ft_printf("Instructions: %d\n", data->instruction_count);
	getchar();
}

