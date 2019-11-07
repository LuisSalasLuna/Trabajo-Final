#include "Paciente.h"

Paciente::Paciente(): Persona(){
    nacimiento = "Nacimiento";
    direccion = "Direcci\242n";
}
Paciente::Paciente(string C,string N,string A,string F, string D) : Persona(C,N,A){
    nacimiento = F;
    direccion = D;
}

void Paciente::SetDatos(){
    Persona::SetDatos();
    cout<<" Ingresa la fecha de nacimiento de la persona: ";
    getline(cin,nacimiento);
    fflush(stdin);
    cout<<" Ingresa la Direcci\242n de la persona: ";
    getline(cin,direccion);
    fflush(stdin);
}
