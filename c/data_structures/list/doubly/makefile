GD=gcc -ansi -pedantic-errors -Wall -Wextra -g
GC=gcc -ansi -pedantic-errors -Wall -Wextra -DNDEBUG -O3

DEPENDENCIES=dlist.c dlist_test.c

DEBUG=dlist_debug.out
RELEASE=dlist.out

C_DEPS=dlist.c
OBJ_DEPS=dlist.o

all: $(DEBUG) $(RELEASE) create_objs create_shared_lib remove_objs

# Create debug executable
$(DEBUG): $(DEPENDENCIES)
	$(GD) $(DEPENDENCIES) -o $(DEBUG)

# Create release executable
$(RELEASE): $(DEPENDENCIES)
	$(GC) $(DEPENDENCIES) -o $(RELEASE)

# Create shared library
create_objs: $(C_DEPS)
	$(GC) -fPIC -c $(C_DEPS)

create_shared_lib: $(OBJ_DEPS)
	$(GC) -shared -Wl,-soname,libdlist.so $(OBJ_DEPS) -o libdlist.so

remove_objs: $(OBJ_DEPS)
	rm *.o

