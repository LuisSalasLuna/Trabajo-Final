#include "Doctor.h"
#include <fstream>

Doctor::Doctor(): Persona(){
    especialidad = "Especialidad";
}
Doctor::Doctor(string C,string N,string A,string E) : Persona(C,N,A){
    especialidad = E;
}
void Doctor::SetDatos(){
    Persona::SetDatos();
    cout<<" Ingresa la especialidad: ";
    getline(cin,especialidad);
    fflush(stdin);
}
void Doctor::mostrar(){
    Persona::mostrar();
    cout<< " Especialidad: "<< especialidad<< endl;
}
void Doctor::SubirDatos(){
    Persona::SubirDatos();
    ofstream escritura;
    escritura.open("pacientes.txt",ios::app);

    escritura<<especialidad<<"\n";

    //cout<<"\n El registro se ha completado correctamente.\n\n";

    escritura.close();
}
void Doctor::ReescribirDatos(){
    Persona::ReescribirDatos();
    ofstream escritura;
    escritura.open("pacientes.txt",ios::out);

    escritura<<especialidad<<"\n";

    escritura.close();
}
