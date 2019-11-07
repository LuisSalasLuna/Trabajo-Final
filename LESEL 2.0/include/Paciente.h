#ifndef PACIENTE_H
#define PACIENTE_H
#include <iostream>
using namespace std;
#include <Persona.h>

class Paciente : public Persona{
    private:
        string nacimiento;
        string direccion;
    public:
        Paciente();
        Paciente(string, string, string, string, string);
        void SetDatos();
};
#endif // PACIENTE_H
