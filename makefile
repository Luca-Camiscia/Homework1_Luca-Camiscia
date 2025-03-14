Ej1:
	g++ Ej1-Matriz/Ej1.cpp -o ej1.exe
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./ej1.exe
	rm ej1.exe
Ej2:
	g++ Ej2-logsystem/Ej2.cpp -o ej2.exe
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./ej2.exe 0
	rm ej2.exe
Ej2_with_error:
	g++ Ej2-logsystem/Ej2.cpp -o ej2_error.exe
	-valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./ej2_error.exe 1
	rm ej2_error.exe
Ej3:
	g++ Ej3-ListaEnlazada/listaEnlazada.cpp -o listaEnlazada.exe
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./listaEnlazada.exe
	rm listaEnlazada.exe
Ej4:
	g++ Ej4-Comparar/ej4.cpp -o ej4.exe 
	./ej4.exe 5000
	rm ej4.exe

