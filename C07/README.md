# C Piscine C07

### ex00: `ft_strdup`

This function allocates memory and writes the characters of the string passed to it in there, then returns the pointer to that memory. 

To allocate memory in C, you may use `malloc` from `stdlib.h`. You pass the number of bytes to allocate to `malloc` and it will return either a pointer to that memory or `NULL` if memory allocation failed.

Once you are done working with memory allocated with `malloc`, it's recommended to use `free` to release that memory again. The `main` example function shows you exactly how that is done.
### ex01: `ft_range`

Behaves like Python's `range` function. Again new memory must be allocated for that using `malloc`.
### ex02: `ft_ultimate_range`

This behaves like `ft_range`, but instead of returning a pointer, it returns the length the array it created. The actual array is stored in a pointer called `range`. That means when using this function, you must pass the pointer to an empty pointer to it, which is why it's a double pointer in the prototype (`**range`)
### ex03: `ft_strjoin`

This function joins several strings together using a seperation `char` specified in `*sep`.

First of all it handles the case where `size` is 0, by allocating exactly 1 byte and storing `\0` in it to have an emptu string, then return that.

If it isn't it calculates the total memory needed to store the joined string in `get_total_size` For this it defines a `long` that's called `final`, starts with 0 and then goes through the whole 2D array `**strs`, adding the length of the strings to final, as well as the length of the seperator when it's not the last string and finally adds 1 more at the end to make space for the `\0`.

Then we allocate that memory using `malloc`.

We check if `malloc` failed the memory allocation by comparing `ptr` with `NULL`, if it matches then also return `NULL`, we cannot continue.

If it's all good, put a `\0` as the first `char` in our string, because `ft_strcat` which we will be using next expects it to be at the end of the string. Now we can use `ft_strcat` to stitch the current string `strs[i]` to `ptr`, our allocated memory, check if we need to add the seperator and if yes, use `ft_strcat` to do that as well. 

The end result is `ptr` being a string with all the little strings passed to it seperated by `sep`
### ex04: `ft_convert_base`

This one needed 2 files because Norminette only allows a certain amount of functions in one file, so the trick here is to put a few of them into the second file, then prototype the ones you need to use in the first to be able to use them. Moulinette will compile these into one program. We will be reusing a lot of our older functions:

- `ft_atoi_base`
- `ft_putstr`
- `ft_check_base`
- `ft_strcat`
- `ft_strncat`

`ft_nbr_base_str` will be a modified version of `ft_putnbr` that instead of printing to the standard output uses `ft_strcat` and `ft_strncat` to append to the string `*str`.

`ft_atoi_base` was also modified to return 0 for failure, 1 for success and to put it's output into a pointer passed to it.

Remember that these functions also have functions they depend on so make sure to bring those over too.

The primary job of `ft_convert_base` now is to validate the `base_to` through `ft_check_base`, convert the `nbr` using `ft_atoi_base` and `base_from` which then validates it and if successful should assign the integer to `dec` and return 1, otherwise returns 0 which in turn makes `ft_convert_base` return `NULL`, then the next step is to calculate the size for `malloc`, then return 0 if memory allocation failed and use `ft_nbr_base_str` to actually start the conversion into the new base using `base_to`.

It really is just a mix of previously written code!