# FloatTexter: The dumbest way of encoding text at compile time

Inspired by [this tweet](https://twitter.com/LunarLambda/status/1096227870345703425).
This program generates a C program which prints the contents of a float array as a text string.

## Compilation and Configuration

Check `config.h`  for number of digits used and platform endianness.
Check `config.mk` for C compiler and C compiler flags.

Then just hit `make` ¯\\\_(ツ)\_/¯

## Usage

`floattexter <string>` will print the generated program to stdout, so just redirect or pipe it to where you need it

## Example

![Example](https://cdn.discordapp.com/attachments/506367803473788930/546036604846735360/Lf02KqNV.png)

## FAQ

Q: Why?
A: Why not. I love stupid shit.

Q: Is that seriously all?
A: Yep.

## License

GPL3, I guess? Does it matter? Do what you want with this thing lmao
