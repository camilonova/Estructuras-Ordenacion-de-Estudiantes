#include <iostream.h>

#define TAMANO 5										// Definimos el numero de estudiantes

void ordenarDatosCodigo(struct Persona a[]);			// Funcion para ordenar los datos por Codigo
void ordenarDatosNombre(struct Persona a[]);			// Funcion para ordenar los datos por Nombre

// Estructura de dos valores internos codigo y nombre
struct Persona {
	int codigo;
	char nombre[50];
};

void main() {
	// Estructura que representa los datos de los estudiantes
	struct Persona estudiantes[TAMANO];

	// Variable para uso en los ciclos for
	int i = 0;

	cout<< "Bienvenido, Usted esta registrando a " << TAMANO << " Estudiantes\n" << endl;

	cout<< "Digite el nombre del estudiante (Sin espacios) separado por \'_\' " << endl;
	cout<< "y el codigo (En numeros) separado por un espacio del nombre\n" << endl;

	// Recolectamos los datos
	for( i=0; i < TAMANO; i++) {
		cout<< "\nEstudiante " << i+1 << ":\t";
		cin>> estudiantes[i].nombre >> estudiantes[i].codigo;
	}

	char eleccion;				// Variable donde se almacenara la eleccion del usuario
	bool salir = false;			// Variable para determinar si el usuario quiere salir

	// Opciones del programa

	cout<< "\n\nDigite: 1. Para visualizar los datos ordenados por Nombre." << endl;
	cout<< "\t2. Para visualizar los datos ordenados por Codigo." << endl;
	cout<< "\t3. Para Salir del programa." << endl;
	
	// Hace el bucle mientras la variable salir sea falso
	do {
		cout<< "\nDigite su opcion:\t";
		cin>> eleccion;

		switch(eleccion) {
			case '1':
				// Ordenar datos por Nombre
				ordenarDatosNombre(estudiantes);
				// Imprimimos los datos ordenados
				for( i=0; i < TAMANO; i++)
					cout<< estudiantes[i].nombre << " " << estudiantes[i].codigo << endl;

				break;
			case '2':
				// Ordenar datos por Codigo
				ordenarDatosCodigo(estudiantes);
				// Imprimimos los datos ordenados
				for( i=0; i < TAMANO; i++)
					cout<< estudiantes[i].nombre << " " << estudiantes[i].codigo << endl;

				break;
			case '3':
				// Salir
				salir = true;
				cout<< "\n\nGracias...";
				break;
			default:
				// Opcion incorrecta
				cout<< "\nOpcion incorrecta, digite una opcion correcta (1-3)." << endl;
				break;
		}

	} while (!salir);			// Si es falso continua el bucle

}

// Algoritmo de ordenacion por burbuja para ordenar Codigos.
void ordenarDatosCodigo(struct Persona a[]) {
	int pass, j;
	struct Persona hold;

	for(pass = 1; pass <= TAMANO - 1; pass++)
		for(j = 0; j <= TAMANO - 2; j++)
			if(a[j].codigo > a[j+1].codigo) {
				hold = a[j];
				a[j] = a[j+1];
				a[j+1] = hold;
			}
}

// Algoritmo de ordenacion por burbuja para ordenar Nombres (MODIFICADO).
void ordenarDatosNombre(struct Persona a[]) {
	int pass, j, k;
	struct Persona hold;

	for(pass = 1; pass <= TAMANO - 1; pass++) {
		for(j = 0; j <= TAMANO - 2; j++)
			for(k = 0; k <= 50; k++) {							// Comparamos dentro de las cadenas
				if(a[j].nombre[k]-48 > a[j+1].nombre[k]-48) {	// Convertimos el caracter a entero y lo comparamos
					hold = a[j];
					a[j] = a[j+1];
					a[j+1] = hold;
				}
			}
	}
}
