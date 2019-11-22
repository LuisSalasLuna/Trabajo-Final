#ifndef ARRAYPERSONAS_H
#define ARRAYPERSONAS_H
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
#include <Persona.h>
#include <vector>

template <typename T>
class ArrayPersonas{
    private:
        void pausa();
    protected:
        T *ptr;
        T *ptr2;
        int tam;
        int NroVariables;
    public:
        ArrayPersonas();
        ArrayPersonas(string[], int,int);//
        ArrayPersonas(T[], int,int);
        ~ArrayPersonas();
        int GetTam();
        string* GetCodigos();
        string* GetNombres();
        string* GetApellidos();
        virtual void ModificarSalida();
        void MenuPrincipal();
        void MenuEnlistar();
        void MostrarPers();
        void MostrarPers2();
        void Agregar();
        void Eliminar();
        void Modificar();   //error al cerrar en el proceso
        void MostrarInfoPersona();
        void OrdenarNombre();
        void OrdenarApellido();
        void Busqueda();
        void AlmacenarDatos();
        void AlmacenarDatos2();
};
template <typename T>
void ArrayPersonas<T>::pausa(){
    cout<<"\n";
    system("pause");
    system("CLS");
}
template <typename T>
ArrayPersonas<T>::ArrayPersonas(){
    tam = 0;
    ptr= new T[tam];
    ptr2= new T[tam];
    NroVariables = 3;
}
template <typename T>
ArrayPersonas<T>::ArrayPersonas(string arr[], int tama, int Var){  //caso prueba
    NroVariables=Var;
    tam = tama/NroVariables;
    ptr= new T[tam];
    ptr2= new T[tam];
    int x = 0;
    for(int a = 0; a < tam ; a++){
        *(ptr+a) = Persona(arr[x],arr[x+1],arr[x+2]);
        x += 3;
    }
}
template <typename T>
ArrayPersonas<T>::ArrayPersonas(T arr[], int tama, int Var ){
    NroVariables=Var;
    tam = tama/NroVariables;
    ptr= new T[tam];
    ptr2= new T[tam];
    int x = 0;
    for(int a = 0; a < tam ; a++){
        this ->ptr[a]=arr[a];
        }
}
template <typename T>
ArrayPersonas<T>::~ArrayPersonas(){
    delete[] ptr;
    delete[] ptr2;
    cout<< "Destructor invoked"<< endl;
}
template <typename T>
int ArrayPersonas<T>::GetTam(){
    return tam;
}
template <typename T>
void ArrayPersonas<T>::ModificarSalida(){
    T *Narr= new T[tam];
    T *ptrAux = ptr2;
    ptr2 = Narr;
    Narr = ptrAux;
    delete[] Narr;
}
template <typename T>
string* ArrayPersonas<T>::GetCodigos(){
    string *cod = new string[tam];
    for(int i = 0; i <tam;i++){
        *(cod+i) = (ptr+i)->GetCodigo();
    }
    return cod;
}
template <typename T>
string* ArrayPersonas<T>::GetNombres(){
    string *nom = new string[tam];
    for(int i = 0; i <tam;i++){
        *(nom+i) = (ptr+i)->GetNombre();
    }
    return nom;
}
template <typename T>
string* ArrayPersonas<T>::GetApellidos(){
    string *ape = new string[tam];
    for(int i = 0; i <tam;i++){
        *(ape+i) = (ptr+i)->GetApellido();
    }
    return ape;
}
template <typename T>
void ArrayPersonas<T>::MenuPrincipal(){
    int opcion;
    do{
        cout<<"\n\t\t\t Registro de personas"<< endl;
        cout<<" 1. Agregar persona"<< endl;
        cout<<" 2. Modificar datos de una persona"<< endl;
        cout<<" 3. Eliminar datos de una persona"<< endl;
        cout<<" 4. Mostrar informacion de persona"<< endl;
        cout<<" 5. Leer listado de personas"<< endl;
        cout<<" 6. Busqueda "<< endl;
        cout<<" 7. Salir \n"<< endl;
        cout<<" Opci\242n: ";
        cin>>opcion;
        system("CLS");
        switch(opcion){
        default:
            cout<<" Ha ingresado una opci\242n no valida!\n\n";
            break;
        case 1:
            Agregar();
            break;
        case 2:
            Modificar();
            break;
        case 3:
            Eliminar();
            break;
        case 4:
            MostrarInfoPersona();
            break;
        case 5:
            MenuEnlistar();
            break;
        case 6:
            Busqueda();
            break;
        case 7:
            break;
        }
    }
    while(opcion!=7);
}
template <typename T>
void ArrayPersonas<T>::MenuEnlistar(){
int opcion;
    do{
        cout<<"\n\t\t\t Elegir forma de ordenar "<< endl;
        cout<<" 1. Nombre"<< endl;
        cout<<" 2. Apellido"<< endl;
        cout<<" 3. ---------"<< endl;
        cout<<" 4. Salir \n"<< endl;
        cout<<" Opci\242n: ";
        cin>>opcion;
        system("CLS");
        switch(opcion){
        default:
            cout<<" Ha ingresado una opci\242n no valida!\n\n";
            break;
        case 1:
            OrdenarNombre();
            break;
        case 2:
            OrdenarApellido();
            break;
        /*case 3:
            //Eliminar();
            break;*/
        case 4:
            break;
        }
    }
    while(opcion!=4);
}
template <typename T>
void ArrayPersonas<T>::MostrarPers(){
    cout<<"\n\t\t\tListado de todas las personas"<<endl;
    for(int i = 0;i < tam;i++){
        cout<< "\n Persona " << i+1 << " :"<< endl;
        (ptr+i)->mostrar();
    }
    pausa();
}
template <typename T>
void ArrayPersonas<T>::MostrarPers2(){
    cout<< " Elija la opci\242n de la persona a modificar: ";
    for(int i = 0;i < tam;i++){
        cout<< "\n  " << i+1 << " : " ;
        (ptr+i)->mostrar2();
    }
}
template <typename T>
void ArrayPersonas<T>::Agregar(){
    cout<<"\n\t\t\t Agregar una persona"<<endl;
    tam = tam+1;
    ModificarSalida();
    T *ptrAux = ptr;
    for(int i = 0;i < tam-1;i++){
        ptr2[i]=*(ptr+i);
    }
    ptr = ptr2;
    ptr2 = ptrAux;
    cout<<1;
    (*(ptr+tam-1)).SetCodigo(GetCodigos(),tam);
    cout<<1;
    (*(ptr+tam-1)).SetDatos();
    cout<<1;
    (*(ptr+tam-1)).SubirDatos();
    cout<<1;
    pausa();
}
template <typename T>
void ArrayPersonas<T>::Eliminar(){
    cout<<"\n\t\t\tEliminar los datos de una persona\n\n";
    MostrarPers2();
    int a;
    cout<<"\n\n Opci\242n: ";
    cin>>a;
    int c = 0;
    tam = tam-1;
    ModificarSalida();
    T *ptrAux = ptr;
    T x = *(ptr+a-1);
    for(int i = 0;i < tam;i++){
        if( x.GetCodigo()!=(*(ptr+i)).GetCodigo()){
            ptr2[i]=*(ptr+c);
        }
        else{
            c = c+1;//
            ptr2[i]=*(ptr+c);
        }
        c++;
    }
    ptr = ptr2;
    ptr2 = ptrAux;
    AlmacenarDatos();
    pausa();
}
template <typename T>
void ArrayPersonas<T>::Modificar(){  //Buscar obtimizacion de funcion
    cout<<"\n\t\t\tModificar los datos de una persona\n\n";
    MostrarPers2();
    int b;
    cout<<"\n\n Opci\242n: ";
    cin>>b;
    T *Narr= new T[tam];
    T *ptr2 = ptr;
    for(int i = 0;i < tam;i++){
        if( (*(ptr+b-1)).GetCodigo()==(*(ptr+i)).GetCodigo()){
            (*(ptr+b-1)).SetDatos();
        }
        Narr[i]=*(ptr+i);
    }
    ptr = Narr;
    Narr = ptr2;
    delete[] Narr;
    AlmacenarDatos();
    pausa();
}
template <typename T>
void ArrayPersonas<T>::MostrarInfoPersona(){
    cout<<"\n\t\t\tDetalles de una persona\n\n";
    MostrarPers2();
    int c;
    cout<<"\n\n Opci\242n: ";
    cin>>c;
    (ptr+c-1)->mostrar();
    pausa();
}
template <typename T>
void ArrayPersonas<T>::OrdenarNombre(){
    for(int i=0 ; i < tam-1; i++){
        int m=i;
        for(int k = 0 ; ptr[m].GetNombre()[k] != '\0'; k++){
            for(int j = i+1 ; j < tam; j++){
                if(ptr[m].GetNombre()[k] > ptr[j].GetNombre()[k]){
                    m=j;
                }
            T aux = ptr[m];
            ptr[m]= ptr[i];
            ptr[i] = aux;
        //ptr[i].mostrar();
            }
        }
    }
    MostrarPers();
    AlmacenarDatos2();//
}
template <typename T>
void ArrayPersonas<T>::OrdenarApellido(){
    for(int i=0 ; i < tam-1; i++){
        int m=i;
        for(int k = 0 ; ptr[m].GetApellido()[k] != '\0'; k++){
            for(int j = i+1 ; j < tam; j++){
                if(ptr[m].GetApellido()[k] > ptr[j].GetApellido()[k]){
                    m=j;
                }
            T aux = ptr[m];
            ptr[m]= ptr[i];
            ptr[i] = aux;
            }
        }
    }
    MostrarPers();
    AlmacenarDatos2();//
}
template <typename T>
void ArrayPersonas<T>::Busqueda(){
    cout<<"\n\t\t\t Busqueda "<< endl;
    cout<<" Introduzca dato a buscar: ";
    string *ape = GetApellidos();
    vector <int> aux;
    string elemento;
    bool coincidencia = false;
    int n = 0;
    cin>>elemento;
    for(int i = 0; i < tam ; i++){
        for(int j = 0 ; elemento[j] != '\0' ; j++){
            if(elemento[j] == ape[i][j]){coincidencia=true;}
            else{coincidencia=false;}
        }
        if (coincidencia == true){
            ++n;
            aux.push_back(i);
            cout<< "\n  " << n << " : " ;
            (ptr+i)->mostrar2();}
    }
    if (aux.size()==0){cout<< " No se han encontrado resultados ";}
    else{
        int c;
        cout<<"\n Opci\242n: ";
        cin>>c;
        int h =aux[c-1];
        cout<<"\n";
        (ptr+h)->mostrar();}
    pausa();
}
template <typename T>
void ArrayPersonas<T>::AlmacenarDatos(){
    for(int i = 0;i < tam;i++){
        (ptr+i)->ReescribirDatos();
    }
}
template <typename T>
void ArrayPersonas<T>::AlmacenarDatos2(){
    for(int i = 0;i < tam;i++){
        (ptr+i)->ReescribirDatos2();
    }
    remove("pacientes.txt");
    rename("auxiliar.txt","pacientes.txt");
}


#endif // ARRAYPERSONAS_H
