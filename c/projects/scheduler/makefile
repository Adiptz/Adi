# For using shared library add PATH to LD_LIBRARY_PATH.

# Recipes. GD - debug, GC - no debug.
GD = gcc -ansi -pedantic-errors -Wall -Wextra -g
GC = gcc -ansi -pedantic-errors -Wall -Wextra -DNDEBUG -O3
OBJ_FLAGS = -fPIC -c
SHARED_LIB_FLAGS = -shared -Wl,-soname,libscheduler.so

# Dependencies for debug and release executables.
DEPENDENCIES = scheduler.c scheduler_test.c task.c ../../ds/uid/uid.c ../../ds/pqueue/pqueue.c ../../ds/sorted_list/sorted_list.c ../../ds/dlist/dlist.c
INCLUDES = -I ../../ds/uid/ -I ../../ds/scheduler/ -I ../../ds/pqueue/ -I ../../ds/sorted_list/ -I ../../ds/dlist/

# Dependencies for shared library.
OBJ_DEPENDENCIES = scheduler.o task.o uid.o dlist.o sorted_list.o pqueue.o 

# Names of the made files.
DEBUG = scheduler_debug.out
RELEASE = scheduler.out
LIB = libscheduler.so

all: $(DEBUG) $(RELEASE) create_objs create_shared_lib remove_objs

# Create debug executable.
$(DEBUG): $(DEPENDENCIES)
	$(GD) $(DEPENDENCIES) $(INCLUDES) -o $(DEBUG)

# Create release executable.
$(RELEASE): $(DEPENDENCIES)
	$(GC) $(DEPENDENCIES) $(INCLUDES) -o $(RELEASE)

# Create shared library.
create_objs: $(DEPENDENCIES)
	$(GC) $(INCLUDES) $(OBJ_FLAGS) $(DEPENDENCIES)

create_shared_lib: $(OBJ_DEPENDENCIES)
	$(GC) $(INCLUDES) $(SHARED_LIB_FLAGS) $(OBJ_DEPENDENCIES) -o $(LIB)

remove_objs: $(OBJ_DEPENDENCIES)
	rm *.o

