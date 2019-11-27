#ifndef DOCTOR_H
#define DOCTOR_H
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#include <Persona.h>

class Doctor:public Persona
{
    private:
        string especialidad;
    public:
        Doctor();
        Doctor(string, string, string, string);
        void mostrar();
        void SetDatos();
        void SubirDatos(string);
};

#endif // DOCTOR_H
