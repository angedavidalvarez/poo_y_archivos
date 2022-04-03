#include<iostream>
#include"Registro.h"
#include"Estudiante.h"

#define CL system("cls")
#define PA system("PAUSE")

using namespace std;

int main() {
	int opcion;
	Registro registro;

	do {
		CL;
		cout << "Bienvenido" << endl;
		cout << "1. Insertar" << endl;
		cout << "2. Mostrar" << endl;
		cout << "3. Modificar" << endl;
		cout << "4. Eliminaar" << endl;
		cout << "5. Salir" << endl;
		cout << "Opción: ";
		cin >> opcion;
		if (opcion == 1) {
			CL;
			int cod, tel;
			string nom, ape, dir;
			cout << "Ingrese el Codigo: "; cin >> cod;
			cout << "Ingrese el Nombre: "; cin >> nom;
			cout << "Ingrese Apellido: "; cin >> ape;
			cout << "Ingrese Dirección: "; cin >> dir;
			cout << "Ingrese Telefono: "; cin >> tel;
			Estudiante nueva = Estudiante();
			nueva.ActualizarDatos(cod, _strdup(nom.c_str()), _strdup(ape.c_str()), _strdup(dir.c_str()), tel);
			registro.Guardar(nueva);
			PA;
		}
		else if (opcion == 2) {
			CL;
			cout << "Datos \n";
			registro.Mostrar();
			PA;
		}
		else if (opcion == 3) {
			CL;
			int id;
			cout << "Ingrese Codigo de Estudiante a Modificar: "; cin >> id;
			registro.Modificar(id);
			PA;
		}
		else if (opcion == 4) {
			CL;
			int id;
			cout << "Ingrese Codigo de Estudiante a Eliminar: "; cin >> id;
			registro.Eliminar(id);
			PA;
		}

	} while (opcion != 5);
}
