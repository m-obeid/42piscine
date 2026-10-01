# C Piscine C02

### ex00: `ft_strcpy`

Create a pointer `*ptr` and set it to `dest` so we have a backup of it's original state since we need to `return` it, then walk through until we hit null terminator, setting `*dest` to `*src` and incrementing the pointers with every iteration.
### ex01: `ft_strncpy`

Similar to `ft_strcpy` except we also check if `i` is lower than `n` because if it is, the rest has to be filled with `\0`. Remember to make `i` an `unsigned int` or it won't compile.
### ex02: `ft_str_is_alpha`

Walk through the `*str` pointer and doing a check if the `char` we are currently on is outside the ranges of either A-Z or a-z.
### ex03: `ft_str_is_numeric`

Walk through the `*str` pointer and doing a check if the `char` we are currently on is outside the range of 0-9.
### ex04: `ft_str_is_lowercase`

Walk through the `*str` pointer and doing a check if the `char` we are currently on is outside the range of a-z.
### ex05: `ft_str_is_uppercase`

Walk through the `*str` pointer and doing a check if the `char` we are currently on is outside the range of A-Z.
### ex06: `ft_str_is_printable`

Walk through the `*str` pointer and doing a check if the `char` we are currently on has its ASCII representation being 31 or lower, as in ASCII 0-31 are the non-printable characters.
### ex07: `ft_strupcase`

Walk through the `*str` pointer and doing a check if the `char` we are currently on is outside the range of a-z, if it is, subtract the `char` by 32 to jump to the uppercase equivalent.

Do not do this by incrementing the pointer, use index integer because otherwise Moulinette wil complain since the pointer is not at the start of the when returning it.
### ex08: `ft_strlowcase`

Walk through the `*str` pointer and doing a check if the `char` we are currently on is outside the range of A-Z, if it is, increment the `char` by 32 to jump to the lowercase equivalent.

Do not do this by incrementing the pointer, use index integer because otherwise Moulinette wil complain since the pointer is not at the start of the string when returning it.
### ex09: `ft_strcapitalize`

I made a function `ft_isalnum` to check if a `char` is alphanumeric, so if it matches the ranges of either A-Z, a-z or 0-9, returning 1 if true, otherwise 0.

Then the `ft_strcapitalize` function walks through the `*str` pointer using `i` as our incrementing `int`, checking if the previous character is not alphanumeric, not the first and the current is in the range of a-z and if all 3 conditions are met, we subtract the `char` by 32 to get it's uppercase equivalent. 

If it is the first character we only check if the current character is in the range of a-z, as the previous character doesn't exist, then if that's the case also subtract the `char` by 32.

If neither checks earlier fired up, that can only mean that we need to check if this isn't first `char` because first `char` should always stay uppercased and the `char` is in the range of A-Z and if it is, increment it by 32 to get it's lowercase equivalent. 

Finally return the `str`.
### ex10: `ft_strlcpy`

`strlcpy` ensures that at least one byte is reserved for `\0` so the string is guranteed to end, if there's too much headroom, unlike `strncpy` it leaves them and does not overwrite the remaining with `\0`; Remember to make `i` an `unsigned int` or it won't compile.

Do not walk the string by incrementing the pointer, use index integer because otherwise Moulinette wil complain since the pointer is not at the start of the string when returning it.
### ex11: `ft_putstr_non_printable`

For this, I had to port `ft_putnbr` from an earlier project to base 16 which is hexadecimal. So instead of diving/modulo by 10, we do 16. And of course we need to map those numbers to the actual hexadecimal digits, which I just did by having a string with all of them listed

```c
digits = "0123456789abcdef"
```

Now the function just walks through the `*str` pointer, and when it hits a `char` that is lower than 31, as stated in `ft_str_is_printable`, it runs my function `ft_putnpchar` which writes the `char` in hexadecimal. To avoid errors, `c` is casted (basically converted) to an `unsigned char` stored in `uc`. `unsigned` means that it cannot go negative. If you don't do that, some non-printable characters will break the output.

Do not walk the string by incrementing the pointer, use index integer because otherwise Moulinette wil complain since the pointer is not at the start of the string when returning it.

```c
uc = (unsigned char)c;
```
### ex12: `ft_print_memory`

This one looked terrifying at first but after spending some time thinking it through I realized it's just a glorified version of the `ft_putnpchar` I wrote earlier. So I made 2 versions, one  named `ft_putaddr16` that prints exactly 16 hexadecimal digits which equals to the size of a 64-bit `unsigned` integer, as in 64-bit computers, memory addresses are, 64-bits, shocker right?

A 64-bit integer is also known as `long` in C, `long long` being used for compatibility with Microslop Windows as there, a regular `long` is somehow still 32-bit which is cursed...

And the other function is `ft_putbyte16`, which does 2 hexadecimal digits, also known as a byte, which is 8-bit, a `char` being 8-bit as well, which is why I chose it `unsigned` for representing a byte. But it actually has more to do, it receives an `int i`, which is an index stating what the current byte index processed in the 16 byte line is, and `int max` which is expected to be the amount of bytes processed minus the total target size, or the bytes remaining basically. 

Why does it need this data? It's used to do a comparison on which wouldn't have fit in the 25 line limit of 42's Norme for functions, if `i` is lower than maxsize then we can be confident that we won't print bytes outside the requested range. If it isn't, 2 spaces are printed in place for padding.

Another function we need is `ft_putchar`, which is unrelated to the one in the earlier project, actually prints . if the `char` is non-printable, otherwise prints the `char`

So then `ft_print_memory` receives a `void *` named `addr` and the `unsigned int` telling us the size of the window. 

A `void` pointer means any data can be passed, but that also means we should cast it to `unsigned char *` stored in a pointer I called `*ptr` so we can work with it bit for bit. If we try to use it directly, code won't compile :(

Then we also define two `int`s one `unsigned` and the other not used for incrementing and keeping track of our progress:

- `i` which as mentioned in the explanation for my `ft_putbyte16` is the progress in the current 16 byte chunk used to render the line. I'll call these "group" from now on.
- `g` which is `unsigned int` which stands for group, it tracks the progress throughout the whole thing. It get's incremented by 16 for every group processed.

The reason `i` is not `unsigned int` is because later in the logic we set `i` to -1, and `unsigned` does not allow going below 0. That means however whenever we do comparisons with an `unsigned int`, we have to cast `i` to `unsigned int` as long as `i` is not negative

We initialize `g` with 0, then while `g < size`, we use `ft_putaddr16` to print the address of `addr` which equals to just `ptr`, except we have to cast it to `unsigned long long` to get rid of a warning about unsupported conversions preventing our code from compiling. 

Then we set `i` to 0 and loop while `i` is less than 16 cuz 16 bits. We run `ft_putbyte16` for both the current and next byte, passing `i` and for our `max` we pass `size - g`. This way we can then just print a space for seperation and increment `i` by 2 to continue the loop like normal. 

The loop ends with a trailing space which is perfect cuz that's what we need for what comes next: the string representation of these bytes.

To start that we set `i` to -1. Why -1?

Because we need to save lines of code to fit the rest of the logic, I decided to make use of the fact that `++i` increments `i` and returns the incremented value as well (`i++` returns the value before incrementing), which means we can do the increment right in the `while` condition, saving us one line, and we check if `i` (casted to `unsigned int` because we're comparing with another `unsigned int`) is less than `size - (unsigned int)g` (`g` is also regular int so we need casting) because if it's larger then it isn't in an allowed range, which we handed with padding in `ft_putbyte16`, then we just call `ft_putchar` with `ptr[i]` as the `c` inside the `while` loop to print. If `i` started at 0, the loop would skip the first byte which has index 0. 

Here's how that looks:

```c
i = -1;
while (++i < 16 && (unsigned)i < size - (unsigned int)g)
	ft_putchar(ptr[i]);
```

`i` starts negative here, but as soon as `++i` is run, it jumps to 0, making it a valid `unsigned int` once casted.

Top it off with a newline, increment `g` and `ptr` to 16 so we can get the next data in the next line.

Once `g` matches or becomes larger than `size` we know we're done.