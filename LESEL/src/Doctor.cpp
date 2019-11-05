#include "Doctor.h"
#include <iostream>
#include <fstream>

using namespace std;

void Doctor::MenuPrincipal(){
    int opcion;
    do{
        cout<<"\n\t\t\t Registro de doctores del Hospital\n"<< endl;
        cout<<" 1. Agregar doctor"<< endl;
        cout<<" 2. Modificar datos de un doctor"<< endl;
        cout<<" 3. Eliminar datos de un doctor"<< endl;
        cout<<" 4. Mostrar informacion de doctor"<< endl;
        cout<<" 5. Leer lista de doctores"<< endl;
        cout<<" 6. Salir \n"<< endl;
        cout<<" Opci\242n: ";
        cin>>opcion;
        system("CLS");
        switch(opcion){
        default:
            cout<<" Ha ingresado una opci\242n no valida!\n\n";
            break;

        case 1:
            AgregarDoc();
            break;
        case 2:
            ModificarDoc();
            break;
        case 3:
            EliminarDoc();
            break;
        case 4:
            MostrarInfoDoc();
            break;
        case 5:
            ListarDocs();
            break;
        case 6:
            break;
        }
    }
    while(opcion!=6);
}
void IntroAgregarD();
void errorD();
void pausaD();
void Doctor::AgregarDoc(){
    ofstream escritura;
    ifstream verificador;
    string auxCodigo;
    bool coincidencia=false;
    verificador.open("doctores.txt",ios::in);
    escritura.open("doctores.txt",ios::app);
    if(escritura.is_open()&&verificador.is_open())
    {
        cout<<"\n\t\t\t Agregar un doctor\n\n";
        fflush(stdin);
        IntroAgregarD();
        cout<<" Ingrese el codigo del doctor: ";
        getline(cin,auxCodigo);
        if(auxCodigo=="")
            do
            {
                cout<<" Por favor ingrese un c\242digo v\240lido, intente nuevamente: ";
                getline(cin,auxCodigo);
            }
            while(auxCodigo=="");
        do
        {
            verificador.seekg(0);
            getline(verificador,codigo);
            while(!verificador.eof()){
                getline(verificador,especialidad);
                getline(verificador,nombre);
                getline(verificador,apellido);
                getline(verificador,DNI);
                getline(verificador,celular);
                if(codigo==auxCodigo)
                {
                    coincidencia=true;
                    cout<<"\nYa existe un doctor con ese c\242digo!"<< endl;
                    cout<<"El doctor con ese c\242digo es: "<<nombre<< "\n" << endl;
                    cout<<"Ingresa un c\242digo v\240lido!: ";
                    getline(cin,auxCodigo);
                    if(auxCodigo=="")
                        do
                        {
                            cout<<"Por favor ingrese un c\242digo v\240lido, intente nuevamente: ";
                            getline(cin,auxCodigo);
                        }
                        while(auxCodigo=="");

                    break;
                }

                getline(verificador,codigo);
            }

            if(verificador.eof()&&auxCodigo!=codigo)
                coincidencia=false;

        }
        while(coincidencia==true);

        system("CLS");
        codigo=auxCodigo;
        cout<<"\n\t\t\t Agregar un doctor\n" << endl;;
        IntroAgregarD();
        cout<<" Ingresa el c\242digo del doctor: "<< codigo <<endl;
        fflush(stdin);
        cout<<" Ingresa el especialidad del doctor: ";
        getline(cin,especialidad);
        fflush(stdin);
        cout<<" Ingresa el nombre del doctor: ";
        getline(cin,nombre);
        fflush(stdin);
        cout<<" Ingresa el apellido del doctor: ";
        getline(cin,apellido);
        fflush(stdin);
        cout<<" Ingresa el DNI del doctor: ";
        getline(cin,DNI);
        fflush(stdin);
        cout<<" Ingresa el n\243mero de telefono del doctor: ";
        getline(cin,celular);
        cout<< endl;
        escritura<<codigo<<"\n"<<especialidad<<"\n"<<nombre<<"\n"<<apellido<<"\n"<<DNI
                 <<"\n"<<celular<<"\n";

        cout<<" El registro se ha completado correctamente.\n\n";
    }
    else{
        errorD();
    }
    escritura.close();
    verificador.close();
    pausaD();
}
void Doctor::ModificarDoc(){
    ifstream lectura;
    ifstream verificador;
    ofstream auxiliar;
    string auxCodigo;
    string codigoModif;
    string auxEspecialidad;
    string auxNombre;
    string auxApellido;
    string auxDNI;
    string auxCelular;
    bool encontrado=false;
    bool coincidencia=false;
    bool mismoCodigo=false;
    lectura.open("doctores.txt",ios::in);
    verificador.open("doctores.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    cout<<"\n\t\t\tModificar los datos de un doctor\n\n";
    if(lectura.is_open()&&verificador.is_open()&&auxiliar.is_open())
    {
        fflush(stdin);
        cout<<" Ingresa el c\242digo del doctor a modificar: ";
        getline(cin,auxCodigo);
        if(auxCodigo==""){
            do{
                cout<<" Por favor ingrese un c\242digo v\240lido, intente nuevamente: ";
                getline(cin,auxCodigo);
            }
            while(auxCodigo=="");
        }
        codigoModif=auxCodigo;
        getline(lectura,codigo);
        while(!lectura.eof())
        {
            getline(lectura,especialidad);
            getline(lectura,nombre);
            getline(lectura,apellido);
            getline(lectura,DNI);
            getline(lectura,celular);
            if(auxCodigo==codigo){
                encontrado=true;
                MostrarRegs(codigoModif);
                cout<<" **********************************************";
                cout<<"\n\n";
                cout<<" Ingresa la nueva informaci\242n para el doctor\n\n";
                fflush(stdin);
                cout<<" Ingresa el c\242digo del doctor: ";
                getline(cin,auxCodigo);
                if(auxCodigo==codigoModif){
                    mismoCodigo=true;
                }
                if(mismoCodigo==false){
                    do{
                        if(auxCodigo==codigoModif){
                            coincidencia=false;
                            break;
                        }
                        verificador.seekg(0);
                        getline(verificador,codigo);
                        while(!verificador.eof()){
                            getline(verificador,especialidad);
                            getline(verificador,nombre);
                            getline(verificador,apellido);
                            getline(verificador,DNI);
                            getline(verificador,celular);
                            if(auxCodigo==codigo){
                                coincidencia=true;
                                cout<<"\n\n Ya existe un doctor con ese c\242digo!\n\n";
                                cout<<" El doctor con ese c\242digo es: "<<nombre<<"\n\n";
                                cout<<" Ingresa un c\242digo v\240lido!: ";
                                getline(cin,auxCodigo);
                                if(auxCodigo==""){
                                    do{
                                        cout<<"\n Por favor ingrese un c\242digo v\240lido, intente nuevamente: ";
                                        getline(cin,auxCodigo);
                                    }
                                    while(auxCodigo=="");
                                }
                                break;
                            }
                            getline(verificador,codigo);
                        }
                        if(verificador.eof()&&auxCodigo!=codigo){
                            coincidencia=false;
                        }
                    }
                    while(coincidencia==true);
                }
                system("CLS");
                cout<<" Modificar los datos del doctor\n\n";
                cout<<" Ingresa el c\242digo del doctor a modificar: ";
                cout<<codigoModif;
                MostrarRegs(codigoModif);
                cout<<" **********************************************";
                cout<<"\n\n";
                cout<<" Ingresa la nueva informaci\242n para el doctor\n\n";
                cout<<" Ingresa el c\242digo del doctor: "<<auxCodigo<<"\n\n";
                fflush(stdin);
                cout<<" Ingresa la especialidad del doctor: ";
                getline(cin,auxEspecialidad);
                fflush(stdin);
                cout<<" Ingresa el nombre del doctor: ";
                getline(cin,auxNombre);
                fflush(stdin);
                cout<<" Ingresa el apellido del doctor: ";
                getline(cin,auxApellido);
                fflush(stdin);
                cout<<" Ingresa el DNI del doctor: ";
                getline(cin,auxDNI);
                fflush(stdin);
                cout<<" Ingresa el n\243mero de telefono del doctor: ";
                getline(cin,auxCelular);
                cout<<"\n\n";
                auxiliar<<auxCodigo<<"\n"<<auxEspecialidad<<"\n"<<auxNombre<<"\n"<<auxApellido<<"\n"<<auxDNI
                        <<"\n"<<auxCelular<<"\n";
                cout<<"El Registro se ha modificado correctamente.\n\n";
            }
            else{
                auxiliar<<codigo<<"\n"<<especialidad<<"\n"<<nombre<<"\n"<<apellido<<"\n"<<DNI
                        <<"\n"<<celular<<"\n";
            }
            getline(lectura,codigo);
        }
    }
    else{
        errorD();
    }
    if(encontrado==false){
        cout<<"\n\nNo se encontr\242 ning\243n registro con ese c\242digo!\n\n";
    }
    lectura.close();
    verificador.close();
    auxiliar.close();
    remove("doctores.txt");
    rename("auxiliar.txt","doctores.txt");
    pausaD();
}
void Doctor::EliminarDoc(){
    ifstream lectura;
    ofstream auxiliar;
    bool encontrado=false;
    string auxCodigo;
    char respuesta[5];
    lectura.open("doctores.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    cout<<"\n\t\t\tEliminar un doctor\n\n";
    if(lectura.is_open()&&auxiliar.is_open()){
        fflush(stdin);
        cout<<" Ingresa el c\242digo del doctor que deseas eliminar: ";
        getline(cin,auxCodigo);
        getline(lectura,codigo);
        while(!lectura.eof()){
            getline(lectura,especialidad);
            getline(lectura,nombre);
            getline(lectura,apellido);
            getline(lectura,DNI);
            getline(lectura,celular);
            if(auxCodigo==codigo){
                encontrado=true;
                cout<<"\n\nRegistro Encontrado\n\n";
                cout<<" C\242digo: "<<codigo<<endl;
                cout<<" Especialidad: "<<especialidad<<endl;
                cout<<" Nombre: "<<nombre<<endl;
                cout<<" Apellido: "<< apellido<<endl;
                cout<<" DNI: "<<DNI<<endl;
                cout<<" Celular: "<<celular <<endl;
                cout<<"\n\n";
                cout<<" Realmente deseas eliminar a: "<<nombre<<" (s/n)?: ";
                cin.getline(respuesta,5);
                if(strcmp(respuesta,"s")==0||strcmp(respuesta,"S")==0||
                        strcmp(respuesta,"si")==0||strcmp(respuesta,"SI")==0||
                        strcmp(respuesta,"Si")==0||strcmp(respuesta,"sI")==0)
                    {cout<<"\n\n El doctor fue eliminado correctamente\n\n";}
                else{
                    cout<<"\n\n Doctor conservado\n\n";
                    auxiliar<<codigo<<"\n"<<especialidad<<"\n"<<nombre<<"\n"<<apellido<<"\n"<<DNI
                            <<"\n"<<celular<<"\n";
                }
            }
            else{
                auxiliar<<codigo<<"\n"<<especialidad<<"\n"<<nombre<<"\n"<<apellido<<"\n"<<DNI
                        <<"\n"<<celular<<"\n";
            }
            getline(lectura,codigo);
        }
        if(encontrado==false){
            cout<<"\n\nNo se encontr\242 el c\242digo: "<<auxCodigo<<"\n\n";
        }
    }
    else{
        errorD();
    }
    lectura.close();
    auxiliar.close();
    remove("doctores.txt");
    rename("auxiliar.txt","doctores.txt");
    pausaD();
}
void Doctor::MostrarInfoDoc(){
    string auxCodigo;
    ifstream mostrar;
    bool encontrado=false;
    mostrar.open("doctores.txt",ios::in);
    if(mostrar.is_open())
    {
        fflush(stdin);
        cout<<"\n\t\t\tDetalles de un doctor\n\n";
        cout<<" Ingresa el c\242digo del doctor a buscar: ";
        getline(cin,auxCodigo);
        getline(mostrar,codigo);
        while(!mostrar.eof()){
            getline(mostrar,especialidad);
            getline(mostrar,nombre);
            getline(mostrar,apellido);
            getline(mostrar,DNI);
            getline(mostrar,celular);
            if(auxCodigo==codigo){
                encontrado=true;
                cout<<"\n\n Registro Encontrado\n\n";
                cout<<" C\242digo: "<<codigo<<endl;
                cout<<" Especialidad: "<<especialidad<<endl;
                cout<<" Nombre: "<<nombre<<endl;
                cout<<" Apellido: "<< apellido<<endl;
                cout<<" DNI: "<<DNI<<endl;
                cout<<" Celular: "<<celular <<endl;
                cout<<"\n\n";
            }
            getline(mostrar,codigo);
        }
        if(encontrado==false){
            cout<<"\n\n No se encontro el registro: "<<auxCodigo<<"\n\n";
        }
    }

    else{
        errorD();
    }
    mostrar.close();
    pausaD();
}
void Doctor::ListarDocs(){
    int i=0;
    ifstream lectura;
    lectura.open("doctores.txt",ios::in);
    if(lectura.is_open())
    {
        cout<<"\n\t\t\tListado de todos los doctores\n\n";
        getline(lectura,codigo);
        while(!lectura.eof()){
            i++;
            getline(lectura,especialidad);
            getline(lectura,nombre);
            getline(lectura,apellido);
            getline(lectura,DNI);
            getline(lectura,celular);
            cout<<" C\242digo: "<<codigo<<endl;
            cout<<" Especialidad: "<<especialidad<<endl;
            cout<<" Nombre: "<<nombre<<endl;
            cout<<" Apellido: "<< apellido<<endl;
            cout<<" DNI: "<<DNI<<endl;
            cout<<" Celular: "<<celular <<endl;
            cout<<"\n\n";
            getline(lectura,codigo);
        }
        if(i==1){cout<<" Hay un solo doctor registrado en este hospital\n\n";}
        else{cout<<"Hay un total de "<<i<<" doctores registrados en este hospital\n\n";}
    }
    else{
        errorD();
    }
    lectura.close();
    pausaD();
}
void Doctor::MostrarRegs(string cod){
    ifstream mostrar;
    mostrar.open("doctores.txt",ios::in);
    getline(mostrar,codigo);
    while(!mostrar.eof()){
        getline(mostrar,especialidad);
        getline(mostrar,nombre);
        getline(mostrar,apellido);
        getline(mostrar,DNI);
        getline(mostrar,celular);
        if(cod==codigo){
            cout<<"\n\nRegistro Encontrado\n\n";
            cout<<" C\242digo: "<<codigo<<endl;
            cout<<" Especialidad: "<<especialidad<<endl;
            cout<<" Nombre: "<<nombre<<endl;
            cout<<" Apellido: "<< apellido<<endl;
            cout<<" DNI: "<<DNI<<endl;
            cout<<" Celular: "<<celular <<endl;
            cout<<"\n\n";
        }
        getline(mostrar,codigo);
    }
    mostrar.close();
}
void IntroAgregarD(){
    cout<<" Por favor ingrese los siguientes datos en orden: Codigo, especialidad, nombre,"<<endl;
    cout<<" apellido, DNI y celular en ese \242rden. \n"<<endl;
}
void errorD(){
    cout<<" No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en"<< endl ;
    cout<<" la misma ubicaci\242n que el programa o que reciba el nombre de: doctores.txt.\n" << endl;
}
void pausaD(){
    system("pause");
    system("CLS");
}

