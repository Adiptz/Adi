# Makefile for dynamic library creation

C_DEPS=stack.c
OBJ_DEPS=stack.o

all: create_objs create_shared_lib remove_objs

create_objs: $(C_DEPS)
	gcc -ansi -pedantic-errors -Wall -Wextra -DNDEBUG -O3 -fPIC -c $(C_DEPS)

create_shared_lib: $(OBJ_DEPS)
	gcc -ansi -pedantic-errors -Wall -Wextra -DNDEBUG -O3 -shared -Wl,-soname,libstack.so $(OBJ_DEPS) -o libstack.so

remove_objs: $(OBJ_DEPS)
	rm *.o

