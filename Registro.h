#pragma once
#include"Estudiante.h"
#include<stdio.h>
#include<Windows.h>
#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
using namespace std;

class Registro {
private:
	fstream archivo;
public:
	void Guardar(Estudiante);
	void Mostrar();
	void Modificar(int);
	void Eliminar(int);
};