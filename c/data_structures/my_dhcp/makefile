all: debug release

debug: debug_dhcp.out

release: release_dhcp.out

release_dhcp.out: dhcp_release.o dhcp_test.o trie_release.o
	$(gc) -o release_dhcp.out dhcp_release.o dhcp_test.o trie_release.o -lm 
	 
#trie_release.o 

debug_dhcp.out: dhcp_debug.o dhcp_test.o trie_debug.o 
	$(gd) -o debug_dhcp.out dhcp_debug.o dhcp_test.o trie_debug.o  -lm 
	
#trie_debug.o 
	
dhcp_debug.o: dhcp.c
	$(gd) -c dhcp.c -o dhcp_debug.o
	
dhcp_release.o: dhcp.c 
	$(gc) -c dhcp.c -o dhcp_release.o

trie_release.o: trie.c
	$(gc) -c trie.c -o trie_release.o

trie_debug.o: trie.c
	$(gd) -c trie.c -o trie_debug.o


dhcp_test.o: dhcp_test.c
	$(gd) -c dhcp_test.c

clean: clean_o clean_out

clean_o:
	rm *.o

clean_out:
	rm *.out

gd=gcc -ansi -pedantic-errors -Wall -Wextra -g
gc=gcc -ansi -pedantic-errors -Wall -Wextra -DNDEBUG -O3
