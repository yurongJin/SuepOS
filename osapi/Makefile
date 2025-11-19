flags=-O2 -Wall -std=c2x -fPIC
soflags=-ldl -shared 
ldflags=

.PHONY: clean

all: clean osapi.so diskutil

osapi.so : osapi.o disk.o omnistd.o fs.o
	cc $(flags) $(soflags) $^ -o $@

osapi.o : osapi.c osapi.h os.h
	cc $(flags) -c $<

disk.o : disk.c disk.h
	cc $(flags) -c $<

omnistd.o : omnistd.c omnistd.h
	cc $(flags) -c $<

fs.o : fs.c fs.h
	cc $(flags) -c $<

diskutil : diskutil.o osapi.o disk.o omnistd.o fs.o
	cc $(flags) $^ -o $@
	mv -f diskutil ../util

diskutil.o : diskutil.c
	cc $(flags) -c $<

clean:
	rm -f *.o *.so