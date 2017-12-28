# fillit
A project for 42. Find the smallest square that given tetronimos (tetris pieces) fit in to.

## Requirements
For full requirements, see <https://cdn.intra.42.fr/pdf/pdf/886/fillit.en.pdf>.

## How to use
`make`

`./fillit testfile`

`testfile` should consist of tetris pieces laid out as such:
```
....
##..
.##.
....

...#
...#
...#
...#
```

Incorrectly formatted files will not be handled.

## Results
The program will print the smallest possible square, with each piece denoted by a letter, corresponding with that pieces position in the input file.

So given the input file:
```
....
.##.
..##
....

...#
...#
...#
...#

....
....
###.
#...
```

fillit would print
```
AA.B
.AAB
CCCB
C..B
```
