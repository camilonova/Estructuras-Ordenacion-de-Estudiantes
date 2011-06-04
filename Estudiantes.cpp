#include <iostream.h>

#define SIZE 3										// Define el numero de estudiantes.

void ordenarPorBurbuja(int []);						// Funcion que ordena un array de enteros.
int busquedaBinaria(int [], int, int, int);			// Funcion que busca un elemento en el array.

void main() {
	// Almacena la eleccion hecha por el usuario en el menu.
	char eleccion;

	// Entero para el ciclo for que imprime en pantalla el array.
	int a;

	// Entero que representa el elemento a buscar en alguno de los arrays.
	int elementoABuscar;

	// Entero que representa el resultado de la busqueda.
	int resultadoBusqueda;

	// booleano que es verdadero mientras el usuario quiera continuar en el menu.
	bool continuar = true;

	
	// Array unidimensional que representa el codigo.
	int codigo[SIZE];

	// Array unidimensional que representa la edad.
	int edad[SIZE];
	
	// Array unidimensional que representa la estatura.
	int estatura[SIZE];

	cout<< "Bienvenido." << endl;
	
	// Tomamos los datos del codigo
	for(int i = 0; i < SIZE; i++) {
		cout<< "\nDigite el codigo de seis cifras del estudiante " << i+1 << "\t";
		cin>> codigo[i];
	}

	// Tomamos los datos de la edad
	for(int j = 0; j < SIZE; j++) {
		cout<< "\nIngrese la edad del estudiante " << j+1 << "\t";
		cin>> edad[j];
	}

	// Tomamos los datos de la estatura
	for(int k = 0; k < SIZE; k++) {
		cout<< "\nIngrese la estatura del estudiante " << k+1 << "\t";
		cin>> estatura[k];
	}

	// Mostramos en pantalla el menu, mientras el usuario no quiera salir.
	do {

		cout<< "\n\nDigite la opcion deseada:" << endl;
		cout<< "1.\tOrdenar datos por codigo" << endl;
		cout<< "2.\tOrdenar datos por edad" << endl;
		cout<< "3.\tOrdenar datos por estatura" << endl;
		cout<< "4.\tBuscar un elemento" << endl;
		cout<< "5.\tSalir" << endl;
		cout<< "\nCual es su eleccion:\t";

		cin>> eleccion;

		// Evaluamos mediante la estructura switch la eleccion del usuario.
		switch(eleccion) {
			case '1':
				// Ordenar por codigo
				ordenarPorBurbuja(codigo);
				// Imprimimos los datos
				cout<< "\nLos datos ordenados por codigo son:" << endl;
				for(a=0; a < SIZE; a++)
					cout<< codigo[a] << endl;
				cout<< endl << endl;
				break;
			case '2':
				// Ordenar por edad
				ordenarPorBurbuja(edad);
				// Imprimimos los datos
				cout<< "\nLos datos ordenados por edad son:" << endl;
				for(a=0; a < SIZE; a++)
					cout<< edad[a] << endl;
				cout<< endl << endl;
				break;
			case '3':
				// Ordenar por estatura
				ordenarPorBurbuja(estatura);
				// Imprimimos los datos
				cout<< "\nLos datos ordenados por estatura son:" << endl;
				for(a=0; a < SIZE; a++)
					cout<< estatura[a] << endl;
				cout<< endl << endl;
				break;
			case '4':
				// Buscar un elemento
				cout<< "\nDigite el elemento a buscar:\t";
				cin>> elementoABuscar;
				
				// Buscamos en la lista de codigos
				resultadoBusqueda = busquedaBinaria(codigo, elementoABuscar, 0, SIZE-1);
				if(resultadoBusqueda != -1)
					cout<< "\nElemento encontrado en la lista de codigos en la posicion " << resultadoBusqueda+1 << endl;
				else
					cout<< "\nElemento no encontrado en la lista de codigos" << endl;
				
				// Buscamos en la lista de edades
				resultadoBusqueda = busquedaBinaria(edad, elementoABuscar, 0, SIZE-1);
				if(resultadoBusqueda != -1)
					cout<< "\nElemento encontrado en la lista de edad en la posicion " << resultadoBusqueda+1 << endl;
				else
					cout<< "\nElemento no encontrado en la lista de edad" << endl;
				
				// Buscamos en la lista de estaturas
				resultadoBusqueda = busquedaBinaria(estatura, elementoABuscar, 0, SIZE-1);
				if(resultadoBusqueda != -1)
					cout<< "\nElemento encontrado en la lista de estatura en la posicion " << resultadoBusqueda+1 << endl;
				else
					cout<< "\nElemento no encontrado en la lista de estatura" << endl;
				break;
			case '5':
				// Salir
				cout<< "\nGracias." << endl;
				continuar = false;
				break;
			default:
				// Opcion no valida.
				cout<< "\nHa ingresado una opcion no valida...";
				break;
		}
	} while(continuar);

}

// Algoritmo de ordenacion por burbuja.
void ordenarPorBurbuja(int a[]) {
	int pass, j, hold;

	for(pass = 1; pass <= SIZE - 1; pass++)
		for(j = 0; j <= SIZE - 2; j++)
			if(a[j] > a[j+1]) {
				hold = a[j];
				a[j] = a[j+1];
				a[j+1] = hold;
			}
}

// Algoritmo de busqueda binaria.
int busquedaBinaria(int b[], int elemento, int bajo, int alto) {
	int mitad;

	while(bajo <= alto) {
		mitad = (bajo + alto) / 2;

		if(elemento == b[mitad])
			return mitad;				// Elemento encontrado
		else if(elemento < b[mitad])
			alto = mitad - 1;
		else
			bajo = mitad + 1;
	}

	return -1;							// Elemento no encontrado
}
