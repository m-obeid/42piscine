# C Piscine Shell00

## Required

### ex00. z

Create a file containing the letter “Z”

```bash
echo "Z" > z
```

### ex01. testShell00

Create a file called `testShell00`, then make it 40 bytes long. The easiest way to do that to fill it with 40 ASCII characters like digits or letters.

```bash
424242424242424242424242424242424242424
```

Now we also need to match the permissions using the `chmod` command, which works as follows:

```bash
chmod 445 testShell00
```

Refer to [https://www.theserverside.com/blog/Coffee-Talk-Java-News-Stories-and-Opinions/how-permissions-chmod-with-numbers-command-explained-777-rwx-unix](https://www.theserverside.com/blog/Coffee-Talk-Java-News-Stories-and-Opinions/how-permissions-chmod-with-numbers-command-explained-777-rwx-unix) to know how to set the number, each digit is essentially calculated.

To match the timestamp, we can use:

```bash
touch -d "1 Jun 2026 23:42" testShell00
```

Then create a tar using 

```bash
tar -cf testShell00.tar testShell00
```

and remove the original testShell00, leave only `testShell00.tar`

### ex02. Oh yeah, mooore…

Similar process to `ex01` with the permissions and timestamps, the only exception is that `test0` and `test2` are directories, `test5` is a hard link to `test3`, and `test6` is a symbolic link pointing to `test0`.

Think of a symbolic link as a shortcut, what is put into test6 goes into test0 and vise versa. A hard link is similar, but differs in how it is stored.

DON'T FORGET TO MAKE THE FILES THE RIGHT SIZE! If you want a 1 byte file you need to do:

```bash
printf "a" > file.name
```

Replace `file.name` with your file's name.

To give symlinks a new timestamp you need to add the `-h` attribute to the `touch` command

To create the symlink:

```bash
ln -s test0 test6
```

and to create the hardlink:

```bash
ln test5 test3
```

Please make sure to do it in this order to avoid messing it up:

1. Create files, folders, links
2. Change timestamps
3. Change permissions

For reference, I also made this shell script that you can use:

```bash
#!/bin/bash

# This script creates the notoriously tedious exo2.tar file for Shell00
# because running these commands by hand is hell

# STEP 0: Create sandbox so we don't suck in unintended files
mkdir exo2
cd exo2

# STEP 1: Create all files, dirs and links
mkdir test0
mkdir test2

printf "XXXX" > test1
printf "X" > test3
printf "XX" > test4

ln -s test0 test6
ln test3 test5

# STEP 2: Set timestamps
touch -d "1 Jun 2026 20:47" test0
touch -d "1 Jun 2026 21:46" test1
touch -d "1 Jun 2026 22:45" test2
touch -d "1 Jun 2026 23:44" test3
touch -d "1 Jun 2026 23:43" test4
touch -d "1 Jun 2026 23:44" test5
touch -h -d "1 Jun 2026 22:20" test6

# STEP 3: Set all permissions
chmod 404 test3
chmod 404 test5
chmod 714 test1
chmod 715 test0
chmod 504 test2
chmod 641 test4

# STEP 4: tar it all up
tar -cf ../exo2.tar *

# STEP 5: Exit sandbox
cd ..
```

Remember that you should only upload `exo2.tar` and nothing else in `ex02` otherwise Moulinette might complain (I can't tell you for sure)

### ex03: id_ed25519_pub

Using `ssh-keygen`, you can generate SSH keys. These always come with a private and public keypair.

```bash
ssh-keygen -t ed25519
```

Leave the default values for all 3 prompts by just leaving them empty and now your public key file is in `~/.ssh/id_ed25519.pub`, copy it to your `ex03` folder, rename and you’re done.

### ex04: midLS

The command is:

```bash
ls -tmp
```

and that’s because:

- `-t` sorts by time; newest first
- `-m` adds commas to the list
- `-p` adds the / to directory names

These flags can be found in the man page for ls, which can be opened by running

```bash
man ls
```

### ex05: GiT commit

This goes into git_commit.sh

```bash
#!/bin/bash
git log -5 --format="%H"
```

- `#!/bin/bash` is the shebang, it tells the shell what this script is designed to run with, in this case bash
- `git log` shows the commit log
- `-5` limits it to 5 entries
- `—format=”%H”` makes git only show the full commit hash (%H is a placeholder that tells git to show the full hash)

These flags can be found in git man pages. You can also open man pages for sub-commands like git log sometimes, for example 

```bash
man git logs
```

Finally to make the script executable, chmod +x git_commit.sh

## Optional

### ex06: gitignore

This goes into git_ignore.sh

```bash
#!/bin/bash
git ls-files --others --ignored --exclude-standard
```

- `git ls-files` lists the files that are in the repository.
- `--others` displays files that are not in the git index.
- `--ignored` displays the ignored files that were defined in .gitignore.
- `--exclude-standard` lists the files deleted by default.

### ex07: diff

First of all you need to download the `resources.tar.gz` file from the 42 Infra page. To unpack it in the terminal, `tar` command can be used as follows:

```bash
tar -xf resources.tar.gz
```

Make sure to be in the directory where the file was downloaded

Now to create `b`, we need to use patch to apply `sw.diff` to `a`, which will then turn `a` into our needed file `b`.

```bash
patch a sw.diff
```

To confirm the output is correct, you should get:

```bash
mobeid@c1r3s1 ~/Downloads> cat -e a
Episode V, A NEW H0PE It is a period of civil war$
Rebel spaceships, striking from a hidden base, have won their first victory against the evil Galactic Empire. $
During the battle, Rebel spies managed to steal secret plans to the Empire's ultimate weapon, the STAR DEATH, an armored space station with enough power to destroy an entire planet.$
$
$
Pursued by the Empire's sinister agents,$
Princess Mehdi races home aboard her starship, custodian of the stolen plans that can save her people and restore the dictatorship to the galaxie..$
$
$
$
$
```

`-e` tells cat to show a $ at every new line

Rename `a` to `b` by using `mv` (used for moving files but that also renames it)

```bash
mv a b
```

Delete the `sw.diff` and `resources.tar.gz`.

### ex08: clean

Inside the clean file:

```bash
find . -type f \( -name "*~" -o -name "#*#" \) -print -delete
```

- The brackets tell find to take multiple of these arguments. They are prepended by `\` to tell the shell to not interpret the brackets as script syntax
- `-type f` tells it to look for files
- `-name` tells it to look for a name using wildcards
- `-print` prints out the found results
- `-delete` deletes them after finding them

These can be found in `man` pages as well. Just read man pages.

### ex09: ft_magic

A plain text magic file has lines that tell the file command how to identify a certain file type. For our 42 file type, we need to check if after the 42nd byte, it contains the string “42”

The structure of the line is basically

```bash
[offset] TAB string [string] [type]
```

- `[offset]` is the number of bytes starting counting from 0. In our case it’s 41 cuz 0 is the first number, not 1
- Where `TAB` is shown you need to press Tab in your text editor. Use a command line text editor like `nano` or `nvim` as not all graphical editors actually put tab characters, some put regular spaces.
- `string` tells file that it needs to look for a string
- `[string]` is the string in question, 42 in our case
- `[type]` is the name of the filetype, in this case 42 file

So the final magic file is:

```bash
41	string 42 42 file
```

To verify if it works, create a file containing 42 spaces and then follow it up by "42", then run:

```bash
file -m ft_magic my42file
```

It should report it as a 42 file. Any other file type should not.
