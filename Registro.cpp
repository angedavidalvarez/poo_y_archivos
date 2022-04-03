#include "Registro.h"

void Registro::Guardar(Estudiante estudiante)
{
	this->archivo.open("Estudiante.dat", ios::out | ios::app);
	if (archivo.fail()) {
		cout << "Error al abrir el archivo \n";
	}
	else {
		this->archivo.write((char*)&estudiante, sizeof(Estudiante));
		this->archivo.close();
		cout << "Guardado Correctamente! " << endl;
	}
}

void Registro::Mostrar()
{
	Estudiante mostrar = Estudiante();
	this->archivo.open("Estudiante.dat", ios::in);
	if (archivo.fail()) {
		cout << "Error al abrir el archivo \n" ;
	}
	else {
		while (!this->archivo.eof())
		{
			this->archivo.read((char*)&mostrar, sizeof(Estudiante));
			if (!this->archivo.eof())
			{
				mostrar.imprimir();
			}
		}
		this->archivo.close();
	}
}

void Registro::Modificar(int id)
{
	bool encontrado = false;
	Estudiante aux;
	ifstream lectura;
	ofstream escritura;
	lectura.open("Estudiante.dat", ios::in);
	escritura.open("temporal.dat", ios::app);
	if (lectura.fail() or escritura.fail())
	{
		cout << "Error en el archivo! \n";
	}
	else {
		while (lectura.read((char*)&aux, sizeof(aux)))
		{
			if (aux.ObtenerCodigo() == id)
			{
				encontrado = true;
				int tel, cod;
				string no, ape, direc;
				cout << "Codigo: "; cin >> cod;
				cout << "Nombres: "; cin >> no;
				cout << "Apellidos: "; cin >> ape;
				cout << "Dirección: "; cin >> direc;
				cout << "Telefono: "; cin >> tel;
				aux.ActualizarDatos(cod, _strdup(no.c_str()), _strdup(ape.c_str()), _strdup(direc.c_str()), tel);
				escritura.write((char*)&aux, sizeof(aux));
			}
			else
			{
				escritura.write((char*)&aux, sizeof(aux));
			}
		}
		lectura.close();
		escritura.close();
		remove("Estudiante.dat");
		if (rename("temporal.dat", "Estudiante.dat"))
			printf("Error \n");
		if (!encontrado)
		{
			cout << "Modificado Correctamente!";
		}

	}
}


void Registro::Eliminar(int id)
{
	bool encontrado = false;
	Estudiante aux;
	ifstream lectura;
	ofstream escritura;
	lectura.open("Estudiante.dat", ios::in);
	escritura.open("temporal.dat", ios::app);
	if (lectura.fail() or escritura.fail())
	{
		cout << "Error en el archivo! \n";
	}
	else {
		while (lectura.read((char*)&aux, sizeof(aux)))
		{
			if (aux.ObtenerCodigo() != id)
			{
				escritura.write((char*)&aux, sizeof(aux));
			}
			else
			{
				encontrado = true;
			}
		}
		lectura.close();
		escritura.close();
		remove("Estudiante.dat");
		if (rename("temporal.dat", "Estudiante.dat"))
			printf("Error \n");
		if (!encontrado)
		{
			cout << "Modificado Correctamente!";
		}

	}
}
