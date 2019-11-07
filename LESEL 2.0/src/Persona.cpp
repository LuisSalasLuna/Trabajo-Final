#include "Persona.h"

Persona::Persona(){
    codigo = "C\242digo";
    nombre = "Nombre";
    apellido = "Apellido";
}
Persona::Persona(string C, string N, string A){
    codigo = C;
    nombre = N;
    apellido = A;
}
string Persona::GetCodigo(){
    return codigo;
}
string Persona::GetNombre(){
    return nombre;
}
string Persona::GetApellido(){
    return apellido;
}
void Persona::SetDatos(){
    fflush(stdin);
    cout<<"\n Ingresa el c\242digo de la persona: ";
    getline(cin,codigo);
    fflush(stdin);
    cout<<" Ingresa el nombre de la persona: ";
    getline(cin,nombre);
    fflush(stdin);
    cout<<" Ingresa el apellido de la persona: ";
    getline(cin,apellido);
    fflush(stdin);
}
void Persona::mostrar(){
    cout<< " C\242digo: "<< codigo<< endl;
    cout<< " Nombre: "<< nombre<< endl;
    cout<< " Apellido: "<< apellido<< endl;
}
void Persona::mostrar2(){
    cout<< codigo <<"\t"<< nombre << " " << apellido;
}
void Persona::SubirDatos(){


}
