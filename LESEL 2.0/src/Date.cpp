#include "Date.h"
#include <fstream>

Date::Date(){
    dia = "Dia";
    mes = "Mes";
    anho = "Anho";
    arch = "pacientes.txt";
}
Date::Date(string D, string M, string A, string F){
    dia = D;
    mes = M;
    anho = A;
    arch = F;
}
string Date::GetDia(){
    return dia;
}
string Date::GetMes(){
    return mes;
}
string Date::GetAnho(){
    return anho;
}
void Date::SetDatos(){
    fflush(stdin);
    cout<<" Ingresa el dia de nacimiento(DD): ";
    getline(cin,dia);
    fflush(stdin);
    cout<<" Ingresa el mes de nacimiento(MM): ";
    getline(cin,mes);
    fflush(stdin);
    cout<<" Ingresa el anho de nacimiento(AAAA): ";
    getline(cin,anho);
    fflush(stdin);
}
void Date::mostrar(){
    cout<< " Dia: "<< dia<< endl;
    cout<< " Mes: "<< mes<< endl;
    cout<< " Anho: "<< anho<< endl;
}
void Date::SubirDatos(string arch){
    ofstream escritura;
    escritura.open(arch.c_str(),ios::app);

    escritura<<dia<<"\n"<<mes<<"\n"<<anho<<"\n";

    //cout<<"\n El registro se ha completado correctamente.\n\n";

    escritura.close();
}
