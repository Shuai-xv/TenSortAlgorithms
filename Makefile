cc=gcc
VPATH=Lib
c_files:= ./main.c ./Lib/sort.c
o_files:= $(patsubst %.c,%.o,$(c_files))
# o_files:= $(findstring %.o )
# $(wildcard *.o)

all:$(o_files)
	$(cc) *.o -o main 

$(o_files):
	$(cc) $(c_files) -c -g -Wall

rm:
	@del *.exe *.o