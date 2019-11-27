#include "Persona.h"
#include <fstream>

Persona::Persona(){
    codigo = "C\242digo";
    nombre = "Nombre";
    apellido = "Apellido";
}
Persona::Persona(string Cod, string Nom, string Ape){
    codigo = Cod;
    nombre = Nom;
    apellido = Ape;
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
void Persona::SetCodigo(string *ptr, int tam){
    string *cod = ptr;
    fflush(stdin);
    cout<<"\n Ingrese el c\242digo: ";
    getline(cin,codigo);
    for(int i = 0; i != tam ; i++){
        while(codigo == cod[i] || codigo == ""|| codigo == " "){
            i = 0;
            fflush(stdin);
            cout<<" Este c\242digo ya esta en uso o no es valido, ingresa un c\242digo valido: ";
            getline(cin,codigo);
        }
    }
}
void Persona::SetDatos(){
    fflush(stdin);
    cout<<" Ingrese el nombre: ";
    getline(cin,nombre);
    fflush(stdin);
    cout<<" Ingrese el apellido: ";
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
void Persona::SubirDatos(string F){
    ofstream escritura;
    escritura.open(F.c_str(),ios::app);

    escritura<<codigo<<"\n"<<nombre<<"\n"<<apellido<<"\n";

    escritura.close();
}
void Persona::Limpiar(string F){
    ofstream escritura;
    escritura.open(F.c_str(),ios::out);

    escritura.close();
}
