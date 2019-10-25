#include "Paciente.h"
#include <iostream>
#include <fstream>

using namespace std;

void Paciente::MenuPrincipal(){
    int opcion;
    do{
        cout<<"\n\t\t\t Registro de pacientes del Hospital\n"<< endl;
        cout<<" 1. Agregar paciente"<< endl;
        cout<<" 2. Modificar datos de un paciente"<< endl;
        cout<<" 3. Eliminar datos de un paciente"<< endl;
        cout<<" 4. Mostrar informacion de paciente"<< endl;
        cout<<" 5. Leer lista de pacientes"<< endl;
        cout<<" 6. Salir \n"<< endl;
        cout<<" Opci\242n: ";
        cin>>opcion;
        system("CLS");
        switch(opcion){
        default:
            cout<<" Ha ingresado una opci\242n no valida!\n\n";
            break;

        case 1:
            AgregarPac();
            break;
        case 2:
            ModificarPac();
            break;
        case 3:
            EliminarPac();
            break;
        case 4:
            MostrarInfoPac();
            break;
        case 5:
            ListarPacs();
            break;
        case 6:
            break;
        }
    }
    while(opcion!=6);
}
void IntroAgregar();
void error();
void pausa();
void Paciente::AgregarPac(){
    ofstream escritura;
    ifstream verificador;
    string auxCodigo;
    bool coincidencia=false;
    verificador.open("pacientes.txt",ios::in);
    escritura.open("pacientes.txt",ios::app);
    if(escritura.is_open()&&verificador.is_open())
    {
        cout<<"\n\t\t\t Agregar un paciente\n\n";
        fflush(stdin);
        IntroAgregar();
        cout<<" Ingrese el codigo del paciente: ";
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
            while(!verificador.eof())
            {
                getline(verificador,nombre);
                getline(verificador,apellido);
                getline(verificador,DNI);
                getline(verificador,nacimiento);
                getline(verificador,celular);
                getline(verificador,direccion);

                if(codigo==auxCodigo)
                {
                    coincidencia=true;
                    cout<<"\nYa existe un paciente con ese c\242digo!"<< endl;
                    cout<<"El paciente con ese c\242digo es: "<<nombre<< "\n" << endl;
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
        cout<<"\n\t\t\t Agregar un paciente\n" << endl;;
        IntroAgregar();
        cout<<" Ingresa el c\242digo del paciente: "<< codigo <<endl;
        fflush(stdin);
        cout<<" Ingresa el nombre del paciente: ";
        getline(cin,nombre);
        fflush(stdin);
        cout<<" Ingresa el apellido del paciente: ";
        getline(cin,apellido);
        fflush(stdin);
        cout<<" Ingresa el DNI del paciente: ";
        getline(cin,DNI);
        fflush(stdin);
        cout<<" Ingresa la fecha de nacimiento del paciente: ";
        getline(cin,nacimiento);
        fflush(stdin);
        cout<<" Ingresa el n\243mero de telefono del paciente: ";
        getline(cin,celular);
        fflush(stdin);
        cout<<" Ingresa la direcci\242n del paciente: ";
        getline(cin,direccion);
        cout<< endl;

        escritura<<codigo<<"\n"<<nombre<<"\n"<<apellido<<"\n"<<DNI<<"\n"<<nacimiento
                 <<"\n"<<celular<<"\n"<<direccion<<"\n";

        cout<<" El registro se ha completado correctamente.\n\n";
    }
    else{
        error();
    }
    escritura.close();
    verificador.close();
    pausa();
}
void Paciente::ModificarPac(){
    ifstream lectura;
    ifstream verificador;
    ofstream auxiliar;
    string auxCodigo;
    string codigoModif;
    string auxNombre;
    string auxApellido;
    string auxDNI;
    string auxNacimiento;
    string auxCelular;
    string auxDireccion;
    bool encontrado=false;
    bool coincidencia=false;
    bool mismoCodigo=false;
    lectura.open("pacientes.txt",ios::in);
    verificador.open("pacientes.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    cout<<"\n\t\t\tModificar los datos de un paciente\n\n";
    if(lectura.is_open()&&verificador.is_open()&&auxiliar.is_open())
    {
        fflush(stdin);
        cout<<" Ingresa el c\242digo del paciente a modificar: ";
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
            getline(lectura,nombre);
            getline(lectura,apellido);
            getline(lectura,DNI);
            getline(lectura,nacimiento);
            getline(lectura,celular);
            getline(lectura,direccion);
            if(auxCodigo==codigo){
                encontrado=true;
                MostrarRegs(codigoModif);
                cout<<" **********************************************";
                cout<<"\n\n";
                cout<<" Ingresa la nueva informaci\242n para el paciente\n\n";
                fflush(stdin);
                cout<<" Ingresa el c\242digo del paciente: ";
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
                            getline(verificador,nombre);
                            getline(verificador,apellido);
                            getline(verificador,DNI);
                            getline(verificador,nacimiento);
                            getline(verificador,celular);
                            getline(verificador,direccion);
                            if(auxCodigo==codigo){
                                coincidencia=true;
                                cout<<"\n\n Ya existe un paciente con ese c\242digo!\n\n";
                                cout<<" El paciente con ese c\242digo es: "<<nombre<<"\n\n";
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
                cout<<" Modificar los datos del paciente\n\n";
                cout<<" Ingresa el c\242digo del paciente a modificar: ";
                cout<<codigoModif;
                MostrarRegs(codigoModif);
                cout<<" **********************************************";
                cout<<"\n\n";
                cout<<" Ingresa la nueva informaci\242n para el paciente\n\n";
                cout<<" Ingresa el c\242digo del paciente: "<<auxCodigo<<"\n\n";
                fflush(stdin);
                cout<<" Ingresa el nombre del paciente: ";
                getline(cin,auxNombre);
                fflush(stdin);
                cout<<" Ingresa el apellido del paciente: ";
                getline(cin,auxApellido);
                fflush(stdin);
                cout<<" Ingresa el DNI del paciente: ";
                getline(cin,auxDNI);
                fflush(stdin);
                cout<<" Ingresa la fecha de nacimiento del paciente: ";
                getline(cin,auxNacimiento);
                fflush(stdin);
                cout<<" Ingresa el n\243mero de telefono del paciente: ";
                getline(cin,auxCelular);
                fflush(stdin);
                cout<<" Ingresa la direcci\242n del paciente: ";
                getline(cin,auxDireccion);
                cout<<"\n\n";
                auxiliar<<auxCodigo<<"\n"<<auxNombre<<"\n"<<auxApellido<<"\n"<<auxDNI<<"\n"<<auxNacimiento
                        <<"\n"<<auxCelular<<"\n"<<auxDireccion<<"\n";
                cout<<"El Registro se ha modificado correctamente.\n\n";
            }
            else{
                auxiliar<<codigo<<"\n"<<nombre<<"\n"<<apellido<<"\n"<<DNI<<"\n"<<nacimiento
                        <<"\n"<<celular<<"\n"<<direccion<<"\n";
            }
            getline(lectura,codigo);
        }
    }
    else{
        error();
    }
    if(encontrado==false){
        cout<<"\n\nNo se encontr\242 ning\243n registro con ese c\242digo!\n\n";
    }
    lectura.close();
    verificador.close();
    auxiliar.close();
    remove("pacientes.txt");
    rename("auxiliar.txt","pacientes.txt");
    pausa();
}
void Paciente::EliminarPac(){
    ifstream lectura;
    ofstream auxiliar;
    bool encontrado=false;
    string auxCodigo;
    char respuesta[5];
    lectura.open("pacientes.txt",ios::in);
    auxiliar.open("auxiliar.txt",ios::out);
    cout<<"\n\t\t\tEliminar un paciente\n\n";
    if(lectura.is_open()&&auxiliar.is_open()){
        fflush(stdin);
        cout<<" Ingresa el c\242digo del paciente que deseas eliminar: ";
        getline(cin,auxCodigo);
        getline(lectura,codigo);
        while(!lectura.eof()){
            getline(lectura,nombre);
            getline(lectura,apellido);
            getline(lectura,DNI);
            getline(lectura,nacimiento);
            getline(lectura,celular);
            getline(lectura,direccion);
            if(auxCodigo==codigo){
                encontrado=true;
                cout<<"\n\nRegistro Encontrado\n\n";
                cout<<" C\242digo: "<<codigo<<endl;
                cout<<" Nombre: "<<nombre<<endl;
                cout<<" Apellido: "<< apellido<<endl;
                cout<<" DNI: "<<DNI<<endl;
                cout<<" Fecha de nacimiento: "<<nacimiento<<endl;
                cout<<" Celular: "<<celular <<endl;
                cout<<" Direcci\242n: "<<direccion<<endl;
                cout<<"\n\n";
                cout<<" Realmente deseas eliminar a: "<<nombre<<" (s/n)?: ";
                cin.getline(respuesta,5);
                if(strcmp(respuesta,"s")==0||strcmp(respuesta,"S")==0||
                        strcmp(respuesta,"si")==0||strcmp(respuesta,"SI")==0||
                        strcmp(respuesta,"Si")==0||strcmp(respuesta,"sI")==0)
                    {cout<<"\n\n El paciente fue eliminado correctamente\n\n";}
                else{
                    cout<<"\n\n Paciente conservado\n\n";
                    auxiliar<<codigo<<"\n"<<nombre<<"\n"<<apellido<<"\n"<<DNI<<"\n"<<nacimiento
                            <<"\n"<<celular<<"\n"<<direccion<<"\n";
                }
            }
            else{
                auxiliar<<codigo<<"\n"<<nombre<<"\n"<<apellido<<"\n"<<DNI<<"\n"<<nacimiento
                        <<"\n"<<celular<<"\n"<<direccion<<"\n";
            }
            getline(lectura,codigo);
        }
        if(encontrado==false){
            cout<<"\n\nNo se encontr\242 el c\242digo: "<<auxCodigo<<"\n\n";
        }
    }
    else{
        error();
    }
    lectura.close();
    auxiliar.close();
    remove("pacientes.txt");
    rename("auxiliar.txt","pacientes.txt");
    pausa();
}
void Paciente::MostrarInfoPac(){
    string auxCodigo;
    ifstream mostrar;
    bool encontrado=false;
    mostrar.open("pacientes.txt",ios::in);
    if(mostrar.is_open())
    {
        fflush(stdin);
        cout<<"\n\t\t\tDetalles de un paciente\n\n";
        cout<<" Ingresa el c\242digo del paciente a buscar: ";
        getline(cin,auxCodigo);
        getline(mostrar,codigo);
        while(!mostrar.eof()){
            getline(mostrar,nombre);
            getline(mostrar,apellido);
            getline(mostrar,DNI);
            getline(mostrar,nacimiento);
            getline(mostrar,celular);
            getline(mostrar,direccion);
            if(auxCodigo==codigo){
                encontrado=true;
                cout<<"\n\n Registro Encontrado\n\n";
                cout<<" C\242digo: "<<codigo<<endl;
                cout<<" Nombre: "<<nombre<<endl;
                cout<<" Apellido: "<< apellido<<endl;
                cout<<" DNI: "<<DNI<<endl;
                cout<<" Fecha de nacimiento: "<<nacimiento<<endl;
                cout<<" Celular: "<<celular <<endl;
                cout<<" Direcci\242n: "<<direccion<<endl;
                cout<<"\n\n";
            }
            getline(mostrar,codigo);
        }
        if(encontrado==false){
            cout<<"\n\n No se encontro el registro: "<<auxCodigo<<"\n\n";
        }
    }

    else{
        error();
    }
    mostrar.close();
    pausa();
}
void Paciente::ListarPacs(){
    int i=0;
    ifstream lectura;
    lectura.open("pacientes.txt",ios::in);
    if(lectura.is_open())
    {
        cout<<"\n\t\t\tListado de todos los pacientes\n\n";
        getline(lectura,codigo);
        while(!lectura.eof()){
            i++;
            getline(lectura,nombre);
            getline(lectura,apellido);
            getline(lectura,DNI);
            getline(lectura,nacimiento);
            getline(lectura,celular);
            getline(lectura,direccion);
            cout<<" C\242digo: "<<codigo<<endl;
            cout<<" Nombre: "<<nombre<<endl;
            cout<<" Apellido: "<< apellido<<endl;
            cout<<" DNI: "<<DNI<<endl;
            cout<<" Fecha de nacimiento: "<<nacimiento<<endl;
            cout<<" Celular: "<<celular <<endl;
            cout<<" Direcci\242n: "<<direccion<<endl;
            cout<<"\n\n";
            getline(lectura,codigo);
        }
        if(i==1){cout<<" Hay un solo paciente registrado en este hospital\n\n";}
        else{cout<<"Hay un total de "<<i<<" pacientes registrados en este hospital\n\n";}
    }
    else{
        error();
    }
    lectura.close();
    pausa();
}
void Paciente::MostrarRegs(string cod){
    ifstream mostrar;
    mostrar.open("pacientes.txt",ios::in);
    getline(mostrar,codigo);
    while(!mostrar.eof()){
        getline(mostrar,nombre);
        getline(mostrar,apellido);
        getline(mostrar,DNI);
        getline(mostrar,nacimiento);
        getline(mostrar,celular);
        getline(mostrar,direccion);
        if(cod==codigo){
            cout<<"\n\nRegistro Encontrado\n\n";
            cout<<" C\242digo: "<<codigo<<endl;
            cout<<" Nombre: "<<nombre<<endl;
            cout<<" Apellido: "<< apellido<<endl;
            cout<<" DNI: "<<DNI<<endl;
            cout<<" Fecha de nacimiento: "<<nacimiento<<endl;
            cout<<" Celular: "<<celular <<endl;
            cout<<" Direcci\242n: "<<direccion<<endl;
            cout<<"\n\n";
        }
        getline(mostrar,codigo);
    }
    mostrar.close();
}
void IntroAgregar(){
    cout<<" Por favor ingrese los digientes datos en orden: Codigo, nombre, apellido,"<<endl;
    cout<<" DNI, fecha de nacimiento, celular y direcci\242n en ese \242rden. \n"<<endl;
}
void error(){
    cout<<" No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en"<< endl ;
    cout<<" la misma ubicaci\242n que el programa o que reciba el nombre de: Pacientes.txt.\n" << endl;
}
void pausa(){
    system("pause");
    system("CLS");
}

