main:main.o queue.o
	gcc $^ -o $@
main.o:main.c
	gcc -c $^ -o $@
queue.o:queue.c
	gcc -c $^ -o $@
clean:
	rm -f *~ *.o main
