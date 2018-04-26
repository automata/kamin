Programming Languages: An Interpreter-Based Approach, Addison-Wesley, 1990 by Sam Kamin
http://loome.cs.uiuc.edu/kamin/pubs.html

pascal/     Original Kamin's interpreters in Pascal
cpp/        Rewrite (from scratch) of Kamin's interpreters in C++ by Tim Budd

### Compiling the cpp interpreter

The original `Makefile` in `cpp/` directory was modified and `clean` and `all` rules added. So, to compile just type `make` at that directory as usual. It will build 8 executables, one for each chapter of the book (`chap1` to `chap8`).

The libraries `ncurses` and `readline` are used in the cpp interpreter, to enable history of commands and arrow key support. Hence, they should be installed in your operating system before compilation:

#### MAC OS X 

Using [brew](https://brew.sh/index_pt-br): `brew install readline ncurses`

#### Linux

Using apt-get: `sudo apt install libncurses5-dev libreadline-dev`
