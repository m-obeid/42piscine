# C Piscine C00

## Before you start - IDE Setup

You can use any IDE you want, I chose VSCode because I am too lazy to set up Neovim lmao.

If you are also using VSCode I recommend at least these extensions:

- [**42 Header:**](https://marketplace.visualstudio.com/items?itemName=kube.42header) This let's you quickly insert the header you need to have in every C file you create by pressing CTRL+ALT+H. It also automatically fills in the Updated date when you save the file. Neovim has an equivalent config, I do not know what it was.
- [**C/C++ Extension Pack:**](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack) For syntax highlighting, auto suggestions and general checks. Not needed on Neovim, I think lazyvim comes with it installed already.
- [**42 Norminette:**](https://marketplace.visualstudio.com/items?itemName=MariusvanWijk-JoppeKoers.codam-norminette-3) This automatically checks your project for Norme errors while you're coding to avoid silly mistakes. For Neovim you can use the offical 42 `norminette` CLI, that can be easily installed using `pip`

## Required

### ex00. `ft_putchar`

You need the Unix Standard Library (`unistd.h`) included in your project to use the `write` function, this is allowed by the Moulinette throughout the entirety of C00.

If you need to see how a function works, you can look up it's corresponding POSIX man page using `man 3p [functionName]` (replace `[functionName]` with your function name, eg. `write`)

Here's the synopsis of `write`:

```c
       #include <unistd.h>

       ssize_t pwrite(int fildes, const void *buf, size_t nbyte,
           off_t offset);
       ssize_t write(int fildes, const void *buf, size_t nbyte);
```

You can safely ignore the confusing variable types for now, these will only be more relevant later. They're essentially integers.

To `write` to the console you need to set the `fildes` (File Descriptor) to 1 and set `nbytes` to how many bytes are in your `*buf`, so if you have one character, that is 1 byte as per ASCII.

Notice how `*buf` has the `*`, in C this means this is a pointer. You can also safely ignore this being there for now, but basically instead of an actual `char` or if you're coming from other languages that have `string` (which doesn't technically exist in C), it expects a memory address that points to the value we want.

So since we need to take the `char c` from our function `ft_putchar` we need to get it's address using the `&` operator:

`write(1, &c, 1);`

This might seem strange at first, but you'll get used to it after some time.

Since the function type is `void`, it doesn't actually `return` anything, which is fine.

Now finally to test if your code actually works, you should have a `main` function, this function of type `int` always runs first whenever a C program is ran. The reason it's of type `int` is because per POSIX, a program always returns an integer value that tells the shell or other programs whether the program encountered an error. 

So make sure to `return (0);` which means success. The brackets are there to please `norminette`.

This is what this `main` function looks like:

```c
int main()
{
	ft_putchar('F');
	return (0);
}
```

Make sure to not use double quotes (`"`) as those are reserved for `char[]` (C equivalent of a string)

A `char` is not equal to a `char[]`

Then compile your C file using `gcc` as follows in Terminal:

```bash
gcc -Wall -Wextra -Werror ft_putchar.c
```

It will create `a.out` without any output if everything went correctly. This is an executable, you can run it in your terminal and it should output F

Congratulations, your first C code at 42! Read the C file in this repository for more help.

Remember that when you submit you should not include your `a.out` or `main` function. Remove these or at least comment out the `main` function before pushing to the Git repo.

### ex01: `ft_print_alphabet`

This function prints every character that is a lowercase character. And no you can't just manually type in every letter of course, that would be stupid.

Instead you have to think about how computers store data. Everything is digital.

So even characters are somehow mapped to specific numbers. Usually it's ASCII. This is a standard in computing that defines what number equals what character.

You can find ASCII tables online to see these numbers. But did you know that you don't even need to check what number each thing is? Instead, let's look at the pattern.

You can see that the lowercase letter 'a' is decimal number 97 in the ASCII table, followed up by lowercase letter 'b' which is decimal number 98.

In C, `char` is actually a number internally. So if you add +1 to a `char`, it jumps to the next one. You can even do number comparisons on them.

So technically all we need to do is while the character I'm on does not exceed the lowercase letter 'z', `write` and jump to the next (+1 on the `char`)

You can use a `while` loop to accomplish this easily. Check the C file to see how that looks in action. Once you know this, it should actually be straightforward how to do the remaining mandatory tasks!.. maybe except for `ex04`

### ex02: `ft_print_reverse_alphabet`

Same thing as `ex01` but instead of +1 we -1, and instead of checking if it exceeds, we check if it's lower than 'a'

### ex03: `ft_print_numbers`

Almost a 1:1 copy of `ft_print_alphabet` but with different start and end `char`s. Simple as that!

### ex04: `ft_is_negative`

This one is also very simple. We can use `if` to compare `n < 0`, if it is, its negative, otherwise using `else` we can assume it's positive.

## Optional

> [!NOTE]
> I'm still working on this project, so no info about `ex05`-`ex08` yet