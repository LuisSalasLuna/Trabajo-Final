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
    string archivo;
public:
    Persona();
    Persona(string, string, string);
    string GetCodigo();
    string GetNombre();
    string GetApellido();
    void SetCodigo(string*, int);
    virtual void SetDatos();
    virtual void mostrar();
    virtual void mostrar2();
    virtual void SubirDatos(string);
    void Limpiar();
    virtual void ReescribirDatos2(string);
};

#endif // PERSONA_H
