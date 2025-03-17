# Homework1_Luca-Camiscia Info

# Ej1

El ejercicio 1 se puede compilar y correr utilizando el comando "make Ej1". Esto correra el programa utilizando valgrind y solicitando al usuario ingresar la dimension de matriz que desee para luego crearla e imprimirla. Se espera que el usario ingrese un numero entero mayor a 0 y de lo contrario se le volvera a solicitar una entrada valida.

# Ej2

El ejercicio 2 puede compilarse y correrse utilizando los comandos "make Ej2" o "make Ej2_with_error". La primera forma corre el archivo con el comando generara un archivo txt llamado "Logsystem.txt" conteniendo un ejemplo para cada posible entrada de logmessage. De ya existir el archivo se escribiran las nuevas entradas luego de las anteriores. La segunda forma de correr el archivo realiza exactamente lo mismo que la anterior con el agregado de llamar a la funcion que prueba capturar el error. En el archivo resultante se escribiran las mismas entradas anteriores junto a una nueva que informe la aparicion de un error. Este error de codigo "1" tambien puede observarse en la terminal. 

# Ej3

El ejercicio 3 puede compilarse y correrse utilizando el comando "make Ej3". Por terminal se imprimira una lista junto a mensajes que muestran la funcino que se va a llamar y el estado de la lista luego aplicarse. Para las funciones donde el la funcion requiere de una posicion especifica para eliminar o agregar un nodo asumo que las posiciones comienzan en 1 (si alguien inserta algo en la segunda posicion, lo que inserta sera el segundo elemento de la lista).

# Ej4

El ejercicio 4 puede compilarse y correrse utilizando el comando "make Ej4" (en este ejercicio no use valgrind ya que altera la lectura de tiempos de ejecucion). Con el fin de comparar ambas opciones de Datos, en el codigo estan dos funciones recursivas (compare_texts1 y compare_texts2) que realizan exactamente lo mismo solo difiriendo en el tipo de dato que usan. Luego se utlizan las respectivas test_func() las cuales comprueban con ejemplos prestablecidos que las funciones puedan correctamente distingir entre textos iguales y distintos. Para mayor precision, los tiempos de ejecucion se miden 'n' veces siendo 'n' un posible argumento al correr el codigo (de no ingresarse ningun arguemnto se tomara como 100 y en la linea del makefile definido como 5000). Luego se imprimen los promedios de ambos junto a un mensaje que indica el tipo de dato que logro menor tiempo en promedio. 

Con respecto al 4.c sobre procesamiento, al principio del codigo se especifica la funcion Pre_compare_texts1() la cual realiza lo mismo que compare_texts1 pero en preprocesamiento. Luego de lo mencionando anteriormente se imprime cuanto tarda esta funcion en comparar dos textos. 

Los resultados muestran que la comparación utilizando char* es significativamente más rápida que con string. Esto ocurre porque char* trabaja directamente con punteros, sin la sobrecarga adicional de la gestión de memoria y comprobaciones internas de string.

NO es posible realizar una funcion de preprocesamiento con string. Las funciones constexpr solo pueden operar con datos que el compilador pueda evaluar completamente en tiempo de compilación (como lo dice la pagina 45 del ppt de conceptos basicos de cpp). Como stdstring depende de asignaciones dinámicas y estructuras internas que no pueden resolverse en esta etapa, el compilador no puede tratarlo como un valor constante. 
