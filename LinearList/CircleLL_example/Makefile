main:main.o linear.o
	gcc $^ -o $@
main.o:main.c
	gcc -c $^ -o $@
linear.o:linear.c
	gcc -c $^ -o $@
clean:
	rm -f *~ *.o main
