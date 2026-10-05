# C Piscine C04

### ex00: `ft_strlen`

Repeat of `C01` `ex06`

We create an `int i` and start at 0, then while we don't have a `\0` in `str[i]` keep incrementing `i` to move forward.

At the end, `i` is the length of our string since we finished walking it.

### ex01: `ft_putstr`

While the current `char` that `*str` points at isn't `\0`, use `write` to write said character and move `*str` forward by incrementing it.

### ex02: `ft_putnbr`

Repeat of `C00` `ex07`

I solved this one through recursion.

Basically when the function is first run, it checks if the number entered is -2147483648 because this is the overflow point for `int`, so it would cause unintended behavior if we try to calculate it. For this special case number we manually do the `write`.

If it is not, then we go on to check if the number is negative, and if it is we need to put a dash so it shows up as negative, then we set `nb = -nb` which basically makes it positive so we can work with it, otherwise the algorithm will fail.

Then if the number only has 1 digit (more or equal to 0 and less than 10) we can easily reuse `ft_putchar` again to output that. Otherwise, we will call `ft_putnbr` again, this time dividing `nb` by 10 so we remove the rightmost digit and do the same procedure on top of it again, and this keeps repeating until we only have one digit we can output using `ft_putchar`. Then after all these recursive operations, it does the same but this time using the `%` operator, which does the opposite of division by 10: it removes the leftmost digit. And this way, both halves are eventually reduced to single characters that can be outputted using `ft_putchar`, leading to our number!

### ex03: `ft_atoi`

We start by defining 2 `int`:

- `res` for storing the result so far
- `neg` stores a number thats either 1 or -1, that gets multiplied by `res` as the result in the end to support negative numbers.

We skip spaces and other empty ASCII chars by incrementing the pointer while it still is these

Then we go through the + and - signs. If +, we simply ignore it, if - we invert `neg`, so 1 becomes -1 or -1 becomes 1.

And then while we have number `char` remaining, we add them to `res` as follows:

```c
while (*str >= '0' && *str <= '9')
{
	res = res * 10 + (*str - '0');
	str++;
}
```

Finally, we return `res` times `neg` as the result.

### ex04: `ft_putnbr_base`

Similar approach to `ft_putnbr` except we also have to convert decimal to a new base. We first check the base with 42's rules, so it shouldn't contain +, - or space and no duplicate characters, and at least 2 characters long. If all of that passes we also check if the number is negative and print - if it is, then we make it positive again to do the math properly. Now instead of dividing by 10 we divide by our base length and we choose the digits from the base instead of decimal digits.

### ex05: `ft_atoi_base`

We do basically the same checks to the base we did in `ft_putnbr_base` in the beginning.

Using `ft_find_dval` we find the value of a digit inside the `str` (and that's basically the index of the found digit in the base) and then add it if found. Once it is no longer found, that's our end value.