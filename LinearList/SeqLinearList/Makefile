#$@--目标文件，$^--所有的依赖文件，$<--第一个依赖文件
main:main.o linear.o
	gcc $^ -o $@
main.o:main.c
	gcc -c $< -o $@
linear.o:linear.c
	gcc -c $< -o $@
clean:
	rm -f *~ *.o main
