
main.o:main.c 
	gcc main.c -c -Wall -g -o main.o
File.o:File.c 
	gcc File.c -c -Wall -g -o File.o
User.o: User.c 
	gcc User.c -c -Wall -g -o User.o


function.o: function.c
	gcc -c -fPIC function.c -o function.o

staticAnddynamic: File.o User.o function.o
	ar rcs libmylib.a File.o User.o
	gcc -shared -o libcommand.so function.o

main: main.c libmylib.a
	gcc main.c User.o File.o -L. -lcommand -o main

install:
	sudo cp libmylib.a /usr/local/lib/
	sudo cp libcommand.so /usr/local/lib/
clean:
	rm main *.o
