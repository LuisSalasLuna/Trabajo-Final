#ifndef PACIENTE_H
#define PACIENTE_H
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#include <Persona.h>

class Paciente : public Persona{
    private:
        string nacimiento;
        string direccion;
    public:
        Paciente();
        Paciente(string, string, string, string, string);
        void mostrar();
        void SetDatos();
        void SubirDatos();
};
#endif // PACIENTE_H
