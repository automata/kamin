####################################################################### 
#      Makefile for use with C++ kamin interpreters
# #######################################################################
CXX = g++
LIBS = -lncurses -lreadline
OPTS = -Wall
.SUFFIXES: .cc
.cc.o:
	$(CXX) -c $<
#######################################################################
ifiles = main.o reader.o expression.o list.o function.o environment.o lisp.o

all: chap1 chap2 chap3 chap4 chap5 chap6 chap7 chap8

chap1: $(ifiles) chap1.o
	$(CXX) $(OPTS) -o chap1 $(ifiles) chap1.o $(LIBS)

chap2: $(ifiles) chap2.o
	$(CXX) $(OPTS) -o chap2 $(ifiles) chap2.o $(LIBS)

chap3: $(ifiles) chap3.o
	$(CXX) $(OPTS) -o chap3 $(ifiles) chap3.o $(LIBS)

chap4: $(ifiles) chap4.o
	$(CXX) $(OPTS) -o chap4 $(ifiles) chap4.o $(LIBS)

chap5: $(ifiles) chap5.o
	$(CXX) $(OPTS) -o chap5 $(ifiles) chap5.o $(LIBS)

chap6: $(ifiles) chap6.o
	$(CXX) $(OPTS) -o chap6 $(ifiles) chap6.o $(LIBS)

chap7: $(ifiles) chap7.o
	$(CXX) $(OPTS) -o chap7 $(ifiles) chap7.o $(LIBS)

chap8: $(ifiles) chap8.o
	$(CXX) $(OPTS) -o chap8 $(ifiles) chap8.o $(LIBS)

package:
	packmail -o'kamin' Makefile *.tex *.sty *.cc *.h 

clean:
	rm -f chap{1..8} *.o
