GD=gcc -ansi -pedantic-errors -Wall -Wextra -g
GC=gcc -ansi -pedantic-errors -Wall -Wextra -DNDEBUG -O3
DLL_FLAGS=-L../dlist/ -ldlist

DEPENDENCIES=hash_table.c hash_table_test.c ../dlist/dlist.c
INCLUDES=-I ../dlist/

DEBUG=hash_table_debug.out
RELEASE=hash_table.out

all: $(DEBUG) $(RELEASE)

$(DEBUG): $(DEPENDENCIES)
	$(GD) $(DEPENDENCIES) $(INCLUDES) $(DLL_FLAGS) -o $(DEBUG)

$(RELEASE): $(DEPENDENCIES)
	$(GC) $(DEPENDENCIES) $(INCLUDES) $(DLL_FLAGS) -o $(RELEASE)

