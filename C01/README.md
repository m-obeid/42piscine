# C Piscine C01
## Required (all)

### ex00. `ft_ft`

In C, a pointer stores a memory address. This can be used to change a variable inside one function using another.

A pointer is defined with it's type and the `*` symbol:

```c
int *nbr;
```

To send an `int` as a pointer, you can use the `&` operator to get it's address, that's the value a pointer stores, and then to access the `int` you would:

```c
*nbr = ...;
```

So all we have to do is:

```c
void ft_ft(int *nbr)
{
	*nbr = 42;
}
```
### ex01: `ft_ultimate_ft

The same as `ex00` except there are more pointers to go through. Yes, it's that simple.

```c
void ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}
```

### ex02: `ft_swap`

We have 2 `int`: `aval` and `bval`, in which we store the current values of the pointers `*a` and `*b`. Then we restore the values to `*a` and `*b` from `bval` and `aval`

### ex03: `ft_div_mod`

This functions takes two integers and divides the first one by the second, then sets `*div` to that, and `*mod` is set to the modulo (also known as remainder). See the C file for more clarification.

### ex04: `ft_ultimate_div_mod`

The same as `ex02` except the numbers to divide are behind the pointers. Because we need to keep their original values to properly calculate and set them, we store `div` and `mod` as regular `int` inside the function and then at the end set the values of `*a` and `*b`

### ex05: `ft_putstr`

A string is literally a `char` pointer in C. That's what I also said in C00 explanations. So we can just walk on it and print every `char` we see in there, until we hit `\0` which is a special character that indicates the end of a string.

If you increment a pointer, you basically move it forward in memory, so that's exactly how to move in the pointer.

### ex06: `ft_strlen`

We create an `int i` and start at 0, then while we don't have a `\0` in `str[i]` keep incrementing `i` to move forward.

At the end, `i` is the length of our string since we finished walking it.
### ex07: `ft_rev_int_tab`

We need a `tmp` integer to temporarily store the current value before moving it over to it's new spot.

The way this algorithm works is simple, we walk the pointer (again) but this time we're just waiting to reach half of the size of  `*tab` 

You might ask: Why half?
Because if we don't it'll just do a 360 and revert to it's original state, if you want to move a to b's spot that's just one movement, not 2.

See the C code for better reference.

### ex08: `ft_sort_int_tab`

This uses the same `int tmp` method to swap numbers. Sorting is done through the Bubble Sort algorithm for simplicity's sake. I won't explain it cuz there are many explanations of it. See the C code.
