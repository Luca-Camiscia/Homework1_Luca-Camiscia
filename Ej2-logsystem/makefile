logsystem:
	g++ Ej2.cpp -o ej2.exe
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./ej2.exe 0
	rm ej2.exe

log_error:
	g++ Ej2.cpp -o ej2_error.exe
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./ej2_error.exe 1
	
