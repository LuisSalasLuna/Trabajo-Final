#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <Persona.h>
#include <ArrayPersonas.h>
#include <Paciente.h>

using namespace std;
#include <fstream>

int ObtenerTam(){
    string contador;
    ifstream extraccion;//
    int i=0;
    extraccion.open("pacientes.txt",ios::in);
    while(!extraccion.eof()){
        getline(extraccion,contador);
        if(contador != ""){++i;}
    }
    //cout<< i;
    extraccion.close();
    return i;    //dejarlo por defecto?
}

string* ObtenerPuntero(){
    string codigo;
    string nombre;
    string apellido;
    string liberador;
    ifstream extraccion;
    int i = ObtenerTam();
    //string arr[i];
    string *arr= new string[i];
    int c = 0;
    string elem[] ={codigo,nombre,apellido};
    extraccion.open("pacientes.txt",ios::in);
    while(!extraccion.eof()){
        for(int a = 0; a < i; a++){
            if(c == 3){c = 0;}
            getline(extraccion,elem[c]);
            arr[a] = elem[c];
            //cout << c <<"   "<< arr[a]<<endl;
            c++;

        }
        getline(extraccion,liberador);
    }
    extraccion.close();
    return arr;
}
/*ArrayPersonas Eleccion(){
    string *arr = ObtenerRegistro();
    if(*(arr) == ""){
        return ArrayPersonas(0);
    }
    else{
        return ArrayPersonas(9);
    }
}*/
int main(){
    //Paciente A;
    //A.SetDatos();
    int a = ObtenerTam()/3;
    string *p = ObtenerPuntero();
    ArrayPersonas A(p,a);
    //A = Eleccion();
    int opcion;
    do{
        cout<<"\n\t\t\t LESEL-Database\n"<< endl;
        cout<<" 1. Pacientes"<< endl;
        cout<<" 2. Doctores"<< endl;
        cout<<" 3. Organizar cita"<< endl;
        cout<<" 4. ++++++++++"<< endl;
        cout<<" 5. ++++++++++"<< endl;
        cout<<" 6. Salir \n"<< endl;
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
        /*case 2:
            B.MenuPrincipal();
            break;
        case 3:
            Cita();
            break;
        case 4:
            --------();
            break;
        case 5:
            //-------();
            break;*/
        case 6:
            break;
        }
    }
    while(opcion!=6);

    return 0;
}
