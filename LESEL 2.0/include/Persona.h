#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Persona{
protected:
    string codigo;
    string nombre;
    string apellido;
public:
    Persona();
    Persona(string, string, string);
    //Persona(const Persona&);
    string GetCodigo();
    string GetNombre();
    string GetApellido();
    //virtual int NroVariables();
    void SetCodigo(string*, int);
    virtual void SetDatos();
    virtual void mostrar();
    virtual void mostrar2();
    virtual void SubirDatos();
    virtual void ReescribirDatos();
    virtual void ReescribirDatos2();
};

#endif // PERSONA_H
