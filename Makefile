CC = gcc
CFLAGS =
SRCDIR = src
INCDIR = include

all: File.o Shader.o
	if [ ! -d build ]; then mkdir build; fi
	$(CC) -shared -o build/libsc.so *.o

File.o: $(SRCDIR)/File.c $(INCDIR)/File.h
	$(CC) $(CFLAGS) -c -fpic -I $(INCDIR) $(SRCDIR)/File.c

Shader.o: $(SRCDIR)/Shader.c $(INCDIR)/Shader.h
	$(CC) $(CFLAGS) -c -fpic -I $(INCDIR) $(SRCDIR)/Shader.c

clean:
	rm -rf build *.o

