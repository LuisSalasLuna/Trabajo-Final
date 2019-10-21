#include "Paciente.h"
#include <iostream>

using namespace std;

void Paciente::MenuPrincipal(){
    int opcion;
    do{
        cout<<"\t\t\t\t Registro de pacientes del Hospital\n"<< endl;
        cout<<" 1. Agregar paciente"<< endl;
        cout<<" 2. Modificar datos de un paciente"<< endl;
        cout<<" 3. Eliminar datos de un paciente"<< endl;
        cout<<" 4. Mostrar informacion de paciente"<< endl;
        cout<<" 5. Leer lista de pacientes"<< endl;
        cout<<" 6. Salir \n"<< endl;
        cout<<" Opci\242n: ";
        cin>>opcion;
        system("CLS");
        switch(opcion){
        default:
            cout<<" Ha ingresado una opci\242n no valida!\n\n";
            break;

        /*case 1:
            AgregarPac();
            break;

        case 2:
            ModificarPac();
            break;

        case 3:
            EliminarPac();
            break;

        case 4:
            ListarPacs();
            break;

        case 5:
            break;*/
        }
    }
    while(opcion!=6);
}




