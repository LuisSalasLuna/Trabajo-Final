#ifndef DOCTOR_H
#define DOCTOR_H
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Doctor
{
    private:
        string codigo;
        string especialidad;
        string nombre;
        string apellido;
        string DNI;
        string celular;
    public:
        void MenuPrincipal();
        void AgregarDoc();
        void ModificarDoc();
        void EliminarDoc();
        void MostrarInfoDoc();
        void ListarDocs();
        void MostrarRegs(string cod);
};


#endif // DOCTOR_H
