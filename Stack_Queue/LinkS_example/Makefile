main:main.o stack.o
	gcc $^ -o $@
main.o:main.c
	gcc -c $^ -o $@
stack.o:stack.c
	gcc -c $^ -o $@
clean:
	rm -f *~ *.o main
