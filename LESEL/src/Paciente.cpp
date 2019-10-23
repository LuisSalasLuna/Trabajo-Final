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

        /*case 2:
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
            break;*/

        case 6:
            break;
        }
    }
    while(opcion!=6);
}
void error();
void pausa();
void Paciente::AgregarPac()
{
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
        cout<<" Ingresa el c\242digo del paciente: ";
        cout<<codigo;
        cout<<endl;
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

    else
    {
        error();
    }

    escritura.close();
    verificador.close();
    pausa();
}
void error()
{
    cout<<" No se pudo abrir el archivo de registros, asegurese que el archivo se encuentre en"<< endl ;
    cout<<" la misma ubicaci\242n que el programa o que reciba el nombre de: Pacientes.txt.\n" << endl;
}

void pausa()
{
    system("pause");
    system("CLS");
}





