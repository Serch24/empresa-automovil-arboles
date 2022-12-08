todo: arbol.o listas.o listas_dobles.o automovil.o main.o
	g++ arbol.o listas.o automovil.o listas_dobles.o main.o -o todo.out

main.o: main.cpp
	g++ -c main.cpp

arbol.o: arbol.cpp
	g++ -c arbol.cpp

listas.o: listas.cpp 
	g++ -c listas.cpp

listas_dobles.o: listas_dobles.cpp
	g++ -c listas_dobles.cpp

automovil.o: automovil.cpp
	g++ -c automovil.cpp

clean:
	rm *.o todo.out
