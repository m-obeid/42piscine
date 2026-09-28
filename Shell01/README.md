# C Piscine Shell01

## Required
### ex01: print_groups

The easiest way to get a clean list of a user's group is using 

```bash
id -nG $FT_USER
```

This will have the output seperated by spaces and ending with a newline, but the exercise requires commas and no newline at the end of output. So how do we fix this?

Using the `tr` command, we can replace one character with another character. So to replace ` ` with `,`:

```bash
id -nG $FT_USER | tr ' ' ','
```

And what about the newline? We can remove `\n` which is the escape sequence for the newline character using `tr` as well using it's `-d` parameter

So final command is:

```bash
id -nG $FT_USER | tr ' ' ',' | tr -d '\n'
```

Using the pipe (`|`) character, we can pass the output of the command to the left of it to the one on the right. So the output basically goes through all 3 of these commands that way.

### ex02: find_sh

Using the `basename` command we can get the filename of a path. Using `-s` we can remove the `.sh` suffix (see man page for basename)

But if we want to do it for every file found in the current directory, we need to use `find` alongside `basename` as follows:

```bash
basename -s ".sh" $(find . -name "*.sh")
```

The `$(...)` expression runs the command in the brackets and puts each line of the output in it's place. So this causes every found file to run `basename` on it and you get the desired result.

### ex03: count_files

This counts both how many regular files and regular dirs are in the directory.

Using 

```bash
find . -type f,d
```

we can list these files. Notice how every file has its own line? We can use `wc` (stands for word count) with it's `-l` parameter to count all the newlines, which there is 1 per file for.

```bash
find . -type f,d | wc -l
```

The result is the number we counted.


### ex04: MAC

In UNIX(-like) operating systems, the file system exposes almost everything through "files". Whether it's files, symlinks, hardlinks, system reports or even hardware it's all there and handled by the kernel.

In Linux, `/sys/class/net/` contains all the networking related information for all interfaces. Each interface has a "file" called `address` which contains that network interface's MAC address. So if we `cat` all `address` files available, we get every MAC address for that computer.

```bash
cat /sys/class/net/*/address
```

This only works on Linux tho. If that's an issue, I'll correct this solution.

### ex05: "\\?\$\*'MaRViN'\*\$?\\"

To name a file"\\?\$\*'MaRViN'\*\$?\\" you must put the file name in `touch` in single quotes, which ignores all special characters

```bash
touch '"\?$*’MaRViN’*$?\"'
```

Note that the `’` does not actually equal `'` which is why this works

Then write 42 inside.

## Optional

> [!NOTE]
> WIP