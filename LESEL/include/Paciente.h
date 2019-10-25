#ifndef PACIENTE_H
#define PACIENTE_H
#include <iostream>
#include <string.h>
#include <stdlib.h>


using namespace std;

class Paciente
{
    private:
        string codigo;
        string nombre;
        string apellido;
        string DNI;
        string nacimiento;
        string celular;
        string direccion;
    public:
        void MenuPrincipal();
        void AgregarPac();
        void ModificarPac();
        void EliminarPac();
        void MostrarInfoPac();
        void ListarPacs();
        void MostrarRegs(string cod);
};

#endif // PACIENTE_H
