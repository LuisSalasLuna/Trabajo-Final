#ifndef PACIENTE_H
#define PACIENTE_H
#include <iostream>

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
        void MostratInfoPac(string cod);
        void ListarPacs();
};

#endif // PACIENTE_H
