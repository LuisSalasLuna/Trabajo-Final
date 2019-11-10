#ifndef ARRAYPERSONAS_H
#define ARRAYPERSONAS_H
#include <iostream>
#include <stdlib.h>

using namespace std;
#include <Persona.h>

class ArrayPersonas{
    protected:
        Persona *ptr;
        int tam;
    public:
        ArrayPersonas();
        ArrayPersonas(int);
        ArrayPersonas(string[], int);
        ArrayPersonas(const ArrayPersonas&);
        ~ArrayPersonas();
        int GetTam();
        void MenuPrincipal();
        void MostrarPers();
        void MostrarPers2();
        void Agregar();
        void Eliminar();
        void Modificar();
        void MostrarInfoPersona();
        void AlmacenarDatos();
};

#endif // ARRAYPERSONAS_H
