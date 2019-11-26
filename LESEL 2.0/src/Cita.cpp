#include "Cita.h"
#include <fstream>

Cita::Cita(){
    Pac = Paciente();
    Doc = Doctor();
    fecha = Date();
    arch = "citas.txt";
}
Cita::Cita(Paciente P,Doctor D, Date C, string F){
    Pac = P;
    Doc = D;
    fecha = C;
    arch = F;
}
void Cita::SetDatos(){
    cout<<" Ingresa el nombre del doctor: ";
    cout<<" Ingresa el nombre del paciente: ";
    cout<<" Ingresa la fecha de la cita: ";
    fecha.SetDatos();
}
void Cita::mostrar(){
    cout<< " Paciente "<< Pac.GetNombre()<< " " << Pac.GetApellido() << endl;
    cout<< " Doctor "<< Doc.GetNombre()<< " " << Doc.GetApellido() << endl;
    cout<< "Fecha" << fecha.GetDia() << "/" << fecha.GetMes() << "/" << fecha.GetAnho() << endl;
}
void Cita::SubirDatos(string arch){
    ofstream escritura;
    escritura.open(arch.c_str(),ios::app);

    escritura<<Pac.GetNombre()<< " " << Pac.GetApellido() << "\n"
             <<Doc.GetNombre()<< " " << Doc.GetApellido() << "\n"
             <<fecha.GetDia() << "\n" << fecha.GetMes() << "\n" << fecha.GetAnho() <<"\n";

    //cout<<"\n El registro se ha completado correctamente.\n\n";

    escritura.close();
}
