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
void Doctor::SubirDatos(string F){
    Persona::SubirDatos(F);
    ofstream escritura;
    escritura.open("doctores.txt",ios::app);

    escritura<<especialidad<<"\n";

    escritura.close();
}
