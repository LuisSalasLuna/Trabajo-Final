#include "Paciente.h"
#include <fstream>

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
void Paciente::mostrar(){
    Persona::mostrar();
    cout<< " Fecha de nacimiento: "<< nacimiento<< endl;
    cout<< " Direcci\242n: "<< direccion<< endl;
}
void Paciente::SubirDatos(){
    Persona::SubirDatos();
    ofstream escritura;
    escritura.open("pacientes.txt",ios::app);

    escritura<<nacimiento<<"\n"<<direccion<<"\n";

    //cout<<"\n El registro se ha completado correctamente.\n\n";

    escritura.close();
}
void Paciente::ReescribirDatos(){
    Persona::ReescribirDatos();
    ofstream escritura;
    escritura.open("pacientes.txt",ios::out);

    escritura<<nacimiento<<"\n"<<direccion<<"\n";

    escritura.close();
}
/*void Paciente::mostrar2(){
    Persona::mostrar2();
    cout<< nacimiento <<"\t"<< nombre << " " << apellido;
}*/
