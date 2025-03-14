run:
	g++ listaEnlazada.cpp -o listaEnlazada.exe
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./listaEnlazada.exe
	rm listaEnlazada.exe