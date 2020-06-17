GD=gcc -ansi -pedantic-errors -Wall -Wextra -g
GC=gcc -ansi -pedantic-errors -Wall -Wextra -DNDEBUG -O3
DLL_FLAGS=-L../../ds/stack/ -lstack
POW_FLAG=-lm

DEBUG=calculator_debug.out
RELEASE=calculator.out

DEPENDENCIES=calculator.c calculator_test.c
INCLUDES=-I ../../ds/stack/

DEBUG=calculator_debug.out
RELEASE=calculator.out

all: $(RELEASE) $(DEBUG)

$(RELEASE): $(DEPENDENCIES)
	  $(GC) $(DEPENDENCIES) $(POW_FLAG) $(INCLUDES) $(DLL_FLAGS) -o $(RELEASE)

$(DEBUG): $(DEPENDENCIES)
	$(GD) $(DEPENDENCIES) $(POW_FLAG) $(INCLUDES) $(DLL_FLAGS) -o $(DEBUG)

