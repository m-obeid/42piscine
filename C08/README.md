# C Piscine C 08

### ex00: `ft.h`

A `.h` file stands for Header file. A header file is a file that can be included into a C program to import a library for example. In it, you can prototype functions from other C files in your code, have shortcuts to values and macros. 

It is generally recommended to use include guards. These are special instructions read by the C compiler's pre-processor, that in this case prevent declaring something multiple times if the header file were to be imported in multiple C files of the project.

Assuming include guards are always used, here's a template to start any header file:

```c
#ifdef FT_H
# define FT_H

// insert your code here ...
#endif
```

So in this case, you literally just prototype the functions as written within those include guards, and that's it. Just make sure to replace `FT_H` with whatever your header file's name is to comply with the Norm, so in `ft_boolean.h`, that would be `FT_BOOLEAN_H`.
### ex01: `ft_boolean.h`

Another header file, but now we need to define macros. Macros are shortcuts to common values in your program. For example you can make TRUE always equal 1 in all of the code the header file is imported in. Macros values are inserted by your compiler automatically, so unlike variables, they do not take up any additional memory in your program. This makes them ideal for constants.

In this case if we assume that this header file will be used with the following C program:

```c
#include "ft_boolean.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

t_bool	ft_is_even(int nb)
{
	return ((EVEN(nbr)) ? TRUE : FALSE);
}

int		main(int argc, char **argv)
{
	(void)argv;
	if (ft_is_even(argc - 1) == TRUE)
		ft_putstr(EVEN_MSG);
	else
		ft_putstr(ODD_MSG);
	return (SUCCESS);
}
```

- `SUCCESS` would be 0 because 0 is the success errorlevel
- `EVEN_MSG` would be "I have an even number of arguments.\n" as specified in the subject
- `ODD_MSG` would be "I have an odd number of arguments.\n" as specified in the subject
- `EVEN(nbr)` is a macro function that returns 0 if `nbr` is even or not
- `TRUE` equals to 1
- `FALSE` equals to 0
- `t_bool` is a custom type that is equal to an `int`

In C, custom types can be created with `typedef`. Assuming `t_bool` is like an `int`:

```c
typedef int	t_bool;
```

The constants `EVEN_MSG`, `ODD_MSG`, `SUCCESS`, `TRUE` and `FALSE` will be macros defined like:

```c
# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"
```

And finally to define a macro function for `EVEN`:

```c
# define EVEN(nbr) (nbr % 2 == 0)
```

> [!NOTE]
> Use `norminette` with `-R CheckDefine` to check tasks when using header files with macros, or you will get false alarms.
### ex02: `ft_abs.h`

You guessed it, yet another header file. This time with a macro for the absolute value.

To do this in one line we can use a ternary expression like this:

```c
# define ABS(Value) (Value < 0 ? -Value : Value)
```

A ternary expression's syntax is as follows:

```c
condition ? value_if_yes : value_if_no
```
### ex03: `ft_point.h`

Ok bro that's enough. Another header file?

Ok fine, this time we have a new type we use, `struct`.

A struct is like an object, that can store multiple variables in itself. For example, for a point, that could be x and y. These values can be accessed by just doing `struct_name.x`

Assuming the C program:

```c
#include "ft_point.h"

void	set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}
int		main(void)
{
	t_point point;
	set_point(&point);
	return (0);
}
```
`t_point` is actually a `typedef` of a `struct`.

You see how these arrows are used to access the value inside of the `struct`?

This is actually a handy shortcut in C, for when accessing a `struct` behind a pointer. Normally you would do:

```c
(*point).x
```

But this can get hard to read over time, especially when you chain multiple struct arrays in a row. So the arrow makes this much easier. It means the same thing.

So all we really need to do is to define that struct in our header file like this:

```c
typedef struct s_point
{
	int	x;
	int	y;
}	t_point;
```

`s_point` is the name of the `struct`. We don't use it tho because we got our `typedef`. We only put the name there to pass the Norm. Generally speaking, if you left out the name of the `struct` it would still work.


### ex04: `ft_strs_to_tab.c`

Finally, normal C code! In this function, we turn an array of strings into an array of the `s_stock_str` struct, that is set to this by 42:

```c
typedef struct s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
}	t_stock_str;
```
Each property is defined as follows:

- `size` is the length of the string, which we can get using our previously written `ft_strlen`
- `*str` is the string itself, you literally just hand it the pointer as is.
- `*copy` which is a copy of `*str` on newly allocated memory, which we can use `ft_strdup` for.

So we just loop through all the strings in `**av` with the count in `ac` as our cap for the `while` loop.

Of course since we are working with `malloc` always do the `NULL` checks and return `NULL` if something's wrong.

The final `struct` of the `s_stock_str` array (I called it `strs`) should actually have it's `str` set to `0`. Not the character, neither in a string, literally the number. It's other values stay undefined.

`strs` is `malloc`ed, designed to store items of type `t_stock_str`, which is the `struct` `s_stocks_str. So we allocate like this:

```c
strs = malloc((ac + 1) * sizeof (t_stock_str));
```

Then return the whole thing as the output.

### ex05: `ft_show_tab.c`

This uses what was generated by `ft_strs_to_tab` and prints 3 lines for each `s_stocks_str` in that array:

1. `str` which is the string
2. `size` which is the length of the string
3. `copy` which is the copy of `str`. Although it does not neccesary need to match `str` anymore, since it might have been modified after the fact.

Since what the function receives is a pointer to it, we can make use of the arrow here.

And we can reuse old printing functions like `ft_putstr` and `ft_putnbr` to print them.

Because my `ft_putnbr` needs a `long`, I casted the `size` to `long` so it would compile. 

I also made this `ft_putstr` always insert a `\n` at the end to ensure newlines.

Essentially, it really is just 3 functions being called like this:

```c
void	ft_show_tab(struct s_stock_str *par)
{
	ft_putstr(par -> str);
	ft_putnbr((long)(par -> size));
	ft_putstr(par -> copy);
}
```