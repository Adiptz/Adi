#TODO before usse
#export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/adi-peretz/ds/vector

all: create_dynamic_lib;
clean: clean_obj clean_out;

################### create dynamic librarys ##########################
create_dynamic_lib: dynamic_lib debug_dynamic_lib;

dynamic_lib: obj lib;

debug_dynamic_lib: debug_obj debug_lib;

debug_lib: 
	$(gd) $(create_debug_lib_name)

debug_obj: $(c_files)
	$(gd) $(obj_for_shared_lib) $(c_files)
	
lib: 
	$(gc) $(create_lib_name)

obj: $(c_files)
	$(gc) $(obj_for_shared_lib) $(c_files)

############################# clean obj files ##################################
clean_obj:
	rm *.o

############################# clean obj files ##################################
clean_out:
	rm *.out

############################# clean obj files ##################################
clean_so:
	rm *.so

################### variables ##########################
#library named
create_debug_lib_name = -shared -Wl,-soname,libvector_debug.so -o libvector_debug.so *.o
create_lib_name = -shared -Wl,-soname,libvector.so -o libvector.so *.o

#obj of Position Independent Code
obj_for_shared_lib = -fPIC -c

#gcc in debug and release
gd=gcc -ansi -pedantic-errors -Wall -Wextra -g
gc=gcc -ansi -pedantic-errors -Wall -Wextra -DNDEBUG -O3

#files for execute
c_files = vector.c
