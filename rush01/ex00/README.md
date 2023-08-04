# Rush01 - ex00

## Build & Run

build command example
```
gcc -Wall -Wextra -Werror -o rush-01 *.c
```

run command structure
```
./rush-01 "col1up col2up [...] col1down col2down [...] row1left row2left
[...] row1right row2right [...]" [a|v]
```

## Arguments

### first argument

the first argument is a string of numbers separated by spaces
each number represents the number of blocks that should be visible
from that position (cf. subject)

exemple of a valid 4x4 input (2 solutions)
```
"1 2 2 4 4 2 2 1 1 2 2 4 4 2 2 1"
```

exemple of a valid 6x6 input (1 solution)
```
"4 3 4 3 2 1  2 2 1 3 4 3  6 4 3 1 2 2  1 2 3 4 2 2"
```

### second argument

the second argument is optional and is a letter that represents the
display option

- 'a' for all possible grids (not solutions)
- 'v' for all valid grids (solutions)
- *nothing* for the first valid grid (solution)

## Examples

run the program with default display option
```
./rush-01 "1 2 2 4 4 2 2 1 1 2 2 4 4 2 2 1"
```

run the program with all valid grids display option
```
./rush-01 "1 2 2 4 4 2 2 1 1 2 2 4 4 2 2 1" v
```
