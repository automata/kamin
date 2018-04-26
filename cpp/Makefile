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
	$(CXX) $(LIBS) $(OPTS) -o chap1 $(ifiles) chap1.o

chap2: $(ifiles) chap2.o
	$(CXX) $(LIBS) $(OPTS) -o chap2 $(ifiles) chap2.o

chap3: $(ifiles) chap3.o
	$(CXX) $(LIBS) $(OPTS) -o chap3 $(ifiles) chap3.o

chap4: $(ifiles) chap4.o
	$(CXX) $(LIBS) $(OPTS) -o chap4 $(ifiles) chap4.o

chap5: $(ifiles) chap5.o
	$(CXX) $(LIBS) $(OPTS) -o chap5 $(ifiles) chap5.o

chap6: $(ifiles) chap6.o
	$(CXX) $(LIBS) $(OPTS) -o chap6 $(ifiles) chap6.o

chap7: $(ifiles) chap7.o
	$(CXX) $(LIBS) $(OPTS) -o chap7 $(ifiles) chap7.o

chap8: $(ifiles) chap8.o
	$(CXX) $(LIBS) $(OPTS) -o chap8 $(ifiles) chap8.o

package:
	packmail -o'kamin' Makefile *.tex *.sty *.cc *.h 

clean:
	rm -f chap{1..8} *.o
