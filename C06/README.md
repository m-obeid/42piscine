# C Piscine C06
### ex00: `ft_print_program_name`

To get the program's parameters, the `main` function always receives 2 arguments in the following order:

1. `int argc` is the number of parameters given to the program. This also includes the name of the program, so it always starts at 1.
2. `char **argv`, also sometimes typed as `char *argv[]` is an array of strings, containing each parameter. Remember that the first is always the programs name.

So we just have to print `argv[0]`. Yes. It's that simple.
### ex01: `ft_print_params`

As we said earlier, we need to get the args from `argv` and print them. We already wrote `ft_putstr` before.
We basically just skip `argv[0]` since we don't need it.
### ex02: `ft_rev_params`

Same thing as `ft_print_params`, only difference is we step `i` backwards and start at `argc - 1`,  it's minus one because we don't want `argv[0]`

### ex03: `ft_sort_params`

Same as `ft_print_params`, but before we start printing `argv` we must sort it. We first skip the first one by incrementing `argv` and lowering `argc`. Then we can adapt `ft_sort_int_tab` from earlier projects to move pointers instead of `int`:

```c
void	ft_sort_argv(int argc, char **argv)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (j < argc - i - 1)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
			{
				tmp = argv[j + 1];
				argv[j + 1] = argv[j];
				argv[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
```

We use `ft_strcmp` that we also wrote in an earlier project to find differences between the 2 strings. Conveniently, `ft_strcmp` already operates in ASCII order.

Then we can continue just like we did in `ft_print_params`, since `argv` is now in the wanted order.