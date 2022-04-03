#pragma once
using namespace std;
class Estudiante
{
private:
    int codigo;
    char nombre[20];
    char apellido[20];
    char direccion[20];
    int telefono;
public:

    Estudiante();
    void ActualizarDatos(int, char[20], char[20], char[20], int);
    void imprimir();
    int ObtenerCodigo();
    int obtenertelefono();
};