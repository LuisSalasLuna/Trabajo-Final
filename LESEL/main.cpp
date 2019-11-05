#include <iostream>
#include <Paciente.h>
#include <Doctor.h>

using namespace std;

int main(){
    int opcion;
    Paciente A;
    Doctor B;
    do{
        cout<<"\n\t\t\t LESEL-Database\n"<< endl;
        cout<<" 1. Pacientes"<< endl;
        cout<<" 2. Doctores"<< endl;
        cout<<" 3. Organizar cita"<< endl;
        cout<<" 4. ++++++++++"<< endl;
        cout<<" 5. ++++++++++"<< endl;
        cout<<" 6. Salir \n"<< endl;
        cout<<" Opci\242n: ";
        cin>>opcion;
        system("CLS");
        switch(opcion){
        default:
            cout<<" Ha ingresado una opci\242n no valida!\n\n";
            break;
        case 1:
            A.MenuPrincipal();
            break;
        case 2:
            B.MenuPrincipal();
            break;
        /*case 3:
            Cita();
            break;
        case 4:
            --------();
            break;
        case 5:
            -------();
            break;*/
        case 6:
            break;
        }
    }
    while(opcion!=6);


    return 0;
}

