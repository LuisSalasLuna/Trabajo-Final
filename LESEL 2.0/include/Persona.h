#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
using namespace std;

class Persona{
protected:
    string codigo;
    string nombre;
    string apellido;
public:
    Persona();
    Persona(string, string, string);
    string GetCodigo();
    string GetNombre();
    string GetApellido();
    virtual void SetDatos();
    virtual void mostrar();
    void mostrar2();
    void SubirDatos();
    void ReescribirDatos();
};

#endif // PERSONA_H
