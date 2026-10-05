# C Piscine C03

### ex00: `ft_strcmp`

Compares two strings `char` by `char` till the end. If it runs into a `char` that does not match, the second is subtracted from the first. Returned value is either positive or negative ASCII index, or 0 if all match.
### ex01: `ft_strncmp`

Compares two strings `char` by `char` till the end or till `n` times. If it runs into a `char` that does not match, the second is subtracted from the first. Returned value is either positive or negative ASCII index, or 0 if all match.
### ex02: `ft_strcat`

Concatenates one string to another. The `\0` of the first string is replaced with the second string and ended with `\0`.
### ex03: `ft_strncat`

Concatenates one string to another. The `\0` of the first string is replaced with the second string but If there is more than `nb` characters, stop where you are. Finally ended with `\0`. 
### ex04: `ft_strstr`

Checks if a string is in another. It does this by walking through the first string and matching if the current (by default first) character in the to be found string matches the current character in the main string. If it is, it keeps note of that. If it suddenly doesn't encounter the expected character and the length is below the to be found string it resets the counter back to 0. Returns the `str` pointer back to the first matching `char` once it finds the last character in the to be found string. If `to_find` is empty return `str` immediately. See the C code for guidance.
### ex05: `ft_strlcat`

Concatenates one string to another, however it first checks the length of both the destination in `dlen` and source string in `slen`. If the `size` specified is shorter or equal to `dlen` do not attempt anything and return the length of the string it tried to make (`size+slen`). Then start actually iterating as long as the current `char` is not `\0` and `dlen` with one space for headroom to place the enforced `\0` at the end of the string fit into our target `size`, stop once no longer. Finally end with `\0`.
