# C Piscine Rush01

The first Rush I ever did looked terrifying at first, and I misinterpreted what the input of the user means on my first time reading it, thankfully the group leader understood the assignment better. It took us quite a while to think abot a possible algorithm, and the group leader had the ideas but tried to do a lot manually, so the first version was very messy.

On that day I was really tired so I couldn't think straight, so understanding was really difficult that way. But when I went home and took a quick nap, I was much better already, and figured out that it's kind of a bruteforce.

The assignment PDF is in the folder for your convenience.

We have rules, we have 4 different numbers that could fit into the cell, so why don't we just put any number that works with the rules, bam bam bam, and all the cells would be filled right? Well no because if a previous cell fit but later we hit a roadblock then many cases wouldn't be handled.

So we used a backtracking approach to handle this: the function would go back to previous numbers it tried to change them, if those succeed we can continue further.

We did not have enough time to implement more than 4x4, and honestly I don't think anyone in the Piscine even attempted to do that. `malloc` would definetely be involved in that, and I'm not quite ready for that either. 

We had to split the code into multiple C files and many functions to conform with the Norme.

Our evaluator told us some useful tips for later when we use `malloc`:

- Use Valgrind to look for memory leaks. This is memory allocated using `malloc` but never freed again. When submitting projects they should have 0 memory leaks.
- Use `gdb` to debug C code. A `Segmentation fault` output is not very helpful to understand where the program has failed handling memory safely.

To compile the code into one program, use:

```bash
cc -Werror -Wextra -Wall *.c -o rush-01
```

Also apparently according to our evaluator we were supposed to use `static` functions where we had functions that are only used in that file, but I honestly haven't seen this be a requirement. So after looking it up, there is not any mention of that, and he let us through. Thank you again. This was quite a learning experience.