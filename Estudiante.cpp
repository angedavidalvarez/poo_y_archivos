#include"Estudiante.h"
#include<iostream>
#include<string>


Estudiante::Estudiante()
{
    this->codigo = 0;
    this->telefono = 0;
    strcpy_s(this->nombre, "\0");
    strcpy_s(this->apellido, "\0");
    strcpy_s(this->direccion, "\0");
}

void Estudiante::ActualizarDatos(int cod, char nom[20], char ape[20], char dir[20], int tel)
{
    this->codigo = cod;
    this->telefono = tel;
    strcpy_s(this->nombre, nom);
    strcpy_s(this->apellido, ape);
    strcat_s(this->direccion, dir);
}

void Estudiante::imprimir()
{
    cout << "Codigo: " << this->codigo << endl;
    cout << "Nombre: " << this->nombre << endl;
    cout << "Apellido: " << this->apellido << endl;
    cout << "Dirección: " << this->direccion << endl;
    cout << "Télefono: " << this->telefono << endl;
}
int Estudiante::ObtenerCodigo() {
    return this->codigo;
}
int Estudiante::obtenertelefono() {
    return this->telefono;
}