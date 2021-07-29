.DEFAULT_GOAL := all

all: concordo

# Compila tudo e cria o executável "concordo"
concordo: objects
	g++ *.o -Iinclude -std=c++14 -Wall -o concordo

main.o: src/main.cpp executor.o
	g++ src/main.cpp -Iinclude -c

executor.o: src/executor.cpp 
	g++ src/executor.cpp -Iinclude -c

usuario.o: src/usuario.cpp
	g++ src/usuario.cpp -Iinclude -c

servidor.o: src/servidor.cpp
	g++ src/servidor.cpp -Iinclude -c

objects: main.o executor.o usuario.o servidor.o

clean:
	rm *.o concordo

run:
	./concordo