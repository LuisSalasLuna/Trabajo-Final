#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <Persona.h>
#include <ArrayPersonas.h>
#include <Paciente.h>
#include <Doctor.h>

using namespace std;
#include <fstream>

int ObtenerTam(string arch){
    ofstream creacion;
    string contador;
    ifstream extraccion;//
    int i=0;
    creacion.open(arch.c_str(),ios::app);
    creacion.close();
    extraccion.open(arch.c_str(),ios::in);
    while(!extraccion.eof()){
        getline(extraccion,contador);
        if(contador != ""){++i;}
    }
    extraccion.close();
    return i;
}
string* ObtenerStrings(string arch){
    string texto;
    ifstream extraccion;
    int i = ObtenerTam(arch);
    string *arr= new string[i];
    int c = 0;
    extraccion.open(arch.c_str(),ios::in);
    while(c != i){
            getline(extraccion,texto);
            arr[c] =texto;
            c++;
    }
    extraccion.close();
    return arr;
}
Persona *GetPerson1(int tam, string *cad){
    //int tam =ObtenerTam(file);
    string *sol = cad;
    int x = 0;
    Persona *Per = new Persona[tam/3];
    for(int i=0; i<tam/3;i++){
        *(Per+i)=Persona(sol[x],sol[x+1],sol[x+2]);
        x += 3;
    }
    return Per;
}
Paciente *GetPac(int tam, string *cad){
    //int tam =ObtenerTam(file);
    string *sol = cad;
    int x = 0;
    Paciente *Per = new Paciente[tam/5];
    for(int i=0; i<tam/5;i++){
        *(Per+i)=Paciente(sol[x],sol[x+1],sol[x+2],sol[x+3],sol[x+4]);
        x += 5;
    }
    return Per;
}
Doctor *GetDoc(int tam, string *cad){
    //int tam =ObtenerTam(file);
    string *sol = cad;
    int x = 0;
    Doctor *Per = new Doctor[tam/4];
    for(int i=0; i<tam/4;i++){
        *(Per+i)=Doctor(sol[x],sol[x+1],sol[x+2],sol[x+3]);
        x += 4;
    }
    return Per;
}
int main(){
    int a = ObtenerTam("pacientes.txt");
    int b = ObtenerTam("doctores.txt");
    string *p = ObtenerStrings("pacientes.txt");
    Doctor *Doc =GetDoc(ObtenerTam("doctores.txt"),p);
    Paciente *Per1 =GetPac(ObtenerTam("pacientes.txt"),p);
    ArrayPersonas <Paciente> A(Per1,a,5,"pacientes.txt");
    ArrayPersonas <Doctor> B(Doc,b,4,"doctores.txt");
    int opcion;
    do{
        cout<<"\n\t\t\t LESEL-Database\n"<< endl;
        cout<<" 1. Pacientes"<< endl;
        cout<<" 2. Doctores"<< endl;
        cout<<" 3. Organizar cita"<< endl;
        cout<<" 4. Salir \n"<< endl;
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
            break;*/
        case 4:
            break;
        }
    }
    while(opcion!=4);

    return 0;
}
