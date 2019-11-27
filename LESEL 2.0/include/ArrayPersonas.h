#ifndef ARRAYPERSONAS_H
#define ARRAYPERSONAS_H
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
#include <Persona.h>
#include <vector>
#include <algorithm>

template <typename T>
class ArrayPersonas{
    private:
        void pausa();
    protected:
        T *ptr;
        int tam;
        int NroVariables;
        string archiv;
    public:
        ArrayPersonas();
        ArrayPersonas(string[], int, int);//
        ArrayPersonas(T[], int, int, string);
        ~ArrayPersonas();
        string* GetCodigos();
        string* GetNombres();
        string* GetApellidos();
        void MostrarPers();
        void MostrarPers2();

        void MenuPrincipal();
        void Agregar();
        void Eliminar();
        void Modificar();
        void MostrarInfoPersona();

        void MenuOrdenar();
        void Ordenar(string[]);
        void MenuBusqueda();
        void Busqueda(string[]);

        //void Citas();
        void AlmacenarDatos();
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
    NroVariables = 3;
}
template <typename T>
ArrayPersonas<T>::ArrayPersonas(string arr[], int tama, int Var){  //caso prueba
    NroVariables=Var;
    tam = tama/NroVariables;
    ptr= new T[tam];
    int x = 0;
    for(int a = 0; a < tam ; a++){
        *(ptr+a) = Persona(arr[x],arr[x+1],arr[x+2]);
        x += 3;
    }
}
template <typename T>
ArrayPersonas<T>::ArrayPersonas(T arr[], int tama, int Var, string F ){
    NroVariables=Var;
    tam = tama/NroVariables;
    archiv = F;
    ptr= new T[tam];
    int x = 0;
    for(int a = 0; a < tam ; a++){
        this ->ptr[a]=arr[a];
        }
}
template <typename T>
ArrayPersonas<T>::~ArrayPersonas(){
    delete[] ptr;
    cout<< "Destructor invoked"<< endl;
}
template <typename T>
string* ArrayPersonas<T>::GetCodigos(){
    string *cod = new string[tam];
    //string cod[tam];
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
void ArrayPersonas<T>::MostrarPers(){
    cout<<"\n\t\t\tEnlistado de registros"<<endl;
    for(int i = 0;i < tam;i++){
        cout<< "\n Persona " << i+1 << " :"<< endl;
        (ptr+i)->mostrar();
    }
    pausa();
}
template <typename T>
void ArrayPersonas<T>::MostrarPers2(){
    cout<< " Elija el registro a modificar: ";
    for(int i = 0;i < tam;i++){
        cout<< "\n  " << i+1 << " : " ;
        (ptr+i)->mostrar2();
    }
}
template <typename T>
void ArrayPersonas<T>::MenuPrincipal(){
    int opcion;
    do{
        cout<<"\n\t\t\t Registro"<< endl;
        cout<<" 1. Agregar registro"<< endl;
        cout<<" 2. Modificar registro"<< endl;
        cout<<" 3. Eliminar registro"<< endl;
        cout<<" 4. Mostrar detalles de registro "<< endl;
        cout<<" 5. Leer listado "<< endl;
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
            MenuOrdenar();
            break;
        case 6:
            MenuBusqueda();
            break;
        case 7:
            break;
        }
    }
    while(opcion!=7);
}
template <typename T>
void ArrayPersonas<T>::Agregar(){
    cout<<"\n\t\t\t Agregar registro"<<endl;
    tam = tam+1;
    T *ptr2 = new T[tam];
    T *ptrAux = ptr;
    for(int i = 0;i < tam-1;i++){
        ptr2[i] = *(ptr+i);
    }
    ptr = ptr2;
    ptr2 = ptrAux;
    (*(ptr+tam-1)).SetCodigo(GetCodigos(),tam);
    (*(ptr+tam-1)).SetDatos();
    (*(ptr+tam-1)).SubirDatos(archiv);
        cout<<"\n El registro se ha completado correctamente.\n\n";
    pausa();
}
template <typename T>
void ArrayPersonas<T>::Eliminar(){
    cout<<"\n\t\t\t Eliminar registro\n\n";
    MostrarPers2();
    int a;
    cout<<"\n\n Opci\242n: ";
    cin>>a;
    int c = 0;
    tam = tam-1;
    T *ptr2 = new T[tam];
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
    cout<<"\n\t\t\tModificar registro\n\n";
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
    cout<<"\n\t\t\tDetalles de registro\n\n";
    MostrarPers2();
    int c;
    cout<<"\n\n Opci\242n: ";
    cin>>c;
    (ptr+c-1)->mostrar();
    pausa();
}
template <typename T>
void ArrayPersonas<T>::MenuOrdenar(){
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
            Ordenar(GetNombres());
            break;
        case 2:
            Ordenar(GetApellidos());
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
void ArrayPersonas<T>::Ordenar(string Gets[]){
    string *Dat = Gets;
    for(int i=0 ; i < tam-1; i++){
        int m=i;
        for(int j = i+1 ; j < tam; j++){
                if(Dat[m] > Dat[j]){    //if Dat[j][k]=='\0'
                    m=j;
                }
            }
        T aux = ptr[m];
        ptr[m]= ptr[i];
        ptr[i] = aux;
    }
    MostrarPers();
    AlmacenarDatos();//
}
template <typename T>
void ArrayPersonas<T>::MenuBusqueda(){
int opcion;
    do{
        cout<<"\n\t\t\t Buscar por "<< endl;
        cout<<" 1. Nombre"<< endl;
        cout<<" 2. Apellido"<< endl;
        cout<<" 3. Salir \n"<< endl;
        cout<<" Opci\242n: ";
        cin>>opcion;
        system("CLS");
        switch(opcion){
        default:
            cout<<" Ha ingresado una opci\242n no valida!\n\n";
            break;
        case 1:
            Busqueda(GetNombres());
            break;
        case 2:
            Busqueda(GetApellidos());
            break;
        case 3:
            break;
        }
    }
    while(opcion!=4);
}
template <typename T>
void ArrayPersonas<T>::Busqueda(string Gets[]){
    cout<<"\n\t\t\t Busqueda "<< endl;
    cout<<" Introduzca dato a buscar: ";
    vector <int> aux;
    string ele;
    cin>>ele;
    string *arr = Gets;
    for(int b = 0;b <tam;b++){
       arr[b][0] = putchar(tolower(arr[b][0]));  //arreglar impresion de conversiones
    }
    ele[0]=putchar(tolower(ele[0]));
    int n;
    for(int i = 0;i<tam;i++){
        if(arr[i].find(ele)!=string::npos){
            ++n;
            aux.push_back(i);
            cout<< "\n  " << n << " : " ;
            ptr[i].mostrar2();
        }
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
/*template <typename T>
void ArrayPersonas<T>::Citas(){




}*/
template <typename T>
void ArrayPersonas<T>::AlmacenarDatos(){
    (ptr)->Limpiar(archiv);
    for(int i = 0;i < tam;i++){
        (ptr+i)->SubirDatos(archiv);
    }
}
#endif // ARRAYPERSONAS_H
