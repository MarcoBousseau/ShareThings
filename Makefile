LIB= $(wildcard lib/*)
INCLUDE_PATH=lib/

cli: libraries
	gcc main.c $(wildcard libraries/*) -I$(INCLUDE_PATH) -o cli

libraries:
	mkdir libraries/
	for dir in $(LIB); do \
		cd $$dir; \
		gcc -c *.c -I../; \
		mv *.o ../../libraries; \
		cd -; \
	done
clean: 
	rm -rf libraries/ cli