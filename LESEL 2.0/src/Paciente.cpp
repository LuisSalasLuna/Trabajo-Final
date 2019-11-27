#include "Paciente.h"
#include <fstream>

Paciente::Paciente(): Persona(){
    nacimiento = Date();
    direccion = "Direcci\242n";
}
Paciente::Paciente(string C,string N,string A,Date F, string D) : Persona(C,N,A){
    nacimiento = F;
    direccion = D;
}
void Paciente::SetDatos(){
    Persona::SetDatos();
    cout<<" Ingrese la fecha de nacimiento:\n ";
    nacimiento.SetDatos();
    cout<<" Ingrese la Direcci\242n: ";
    getline(cin,direccion);
    fflush(stdin);
}
void Paciente::mostrar(){
    Persona::mostrar();
    nacimiento.mostrar2();
    cout<< " Direcci\242n: "<< direccion<< endl;
}
void Paciente::SubirDatos(string F){
    Persona::SubirDatos(F);
    ofstream escritura;
    escritura.open("pacientes.txt",ios::app);
    nacimiento.SubirDatos();
    escritura<<direccion<<"\n";

    escritura.close();
}
