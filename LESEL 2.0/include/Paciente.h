#ifndef PACIENTE_H
#define PACIENTE_H
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#include <Persona.h>
#include <Date.h>

class Paciente : public Persona{
    private:
        Date nacimiento;
        string direccion;
    public:
        Paciente();
        Paciente(string, string, string, Date, string);
        void mostrar();
        void SetDatos();
        void SubirDatos(string);
};
#endif // PACIENTE_H
