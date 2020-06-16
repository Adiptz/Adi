#TODO before usse
#export LD_LIBRARY_PATH=~/adi-peretz/ds/vector

all: debug release

debug: debug_heap.out

release: release_heap.out

release_heap.out: heap_release.o heap_test.o $(release_library) ../../ds/vector
	$(gc) heap_release.o heap_test.o $(release_library) -I ../../ds/vector/  -o release_heap.out 
	
debug_heap.out: heap_debug.o heap_test.o $(debug_library) ../../ds/vector
	$(gd) heap_debug.o heap_test.o $(debug_library) -I ../../ds/vector/ -o debug_heap.out 
	
heap_debug.o: heap.h heap.c ../../ds/vector
	$(gd) -c heap.c -I ../../ds/vector/ -o heap_debug.o
	
heap_release.o: heap.h heap.c ../../ds/vector
	$(gc) -c heap.c -I ../../ds/vector/ -o heap_release.o
	
heap_test.o: heap.h heap_test.c
	$(gd) -c heap_test.c

clean: clean_o clean_out

clean_o:
	rm *.o

clean_out:
	rm *.out

################### variables ##########################
#don't forget update export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH'

#gcc in debug and release
gd=gcc -ansi -pedantic-errors -Wall -Wextra -g
gc=gcc -ansi -pedantic-errors -Wall -Wextra -DNDEBUG -O3

#vector library
debug_library = -L../../ds/vector/ -lvector_debug
release_library = -L../../ds/vector/ -lvector

