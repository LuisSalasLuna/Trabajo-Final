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
        void OrdenarApellido2();
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
            //OrdenarApellido2();
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
    (*(ptr+tam-1)).SubirDatos();
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
            }
        }
    }
    MostrarPers();
    AlmacenarDatos2();//
}
template <typename T>
void ArrayPersonas<T>::OrdenarApellido(){
    string *Dat = GetApellidos();
    for(int i=0 ; i < tam-1; i++){
        int m=i;
        for(int j = i+1 ; j < tam; j++){
            for(int k = 1 ; Dat[m][k] != '\0'; k++){
                if(Dat[m][k-1] == Dat[j][k-1] && Dat[m][k] > Dat[j][k]){    //if Dat[j][k]=='\0'
                    m=j;
                }
            }
        }
        T aux = ptr[m];
        ptr[m]= ptr[i];
        ptr[i] = aux;
    }
    MostrarPers();
    AlmacenarDatos2();//
}
/*template <typename T>
void ArrayPersonas<T>::OrdenarApellido2(){
    string *ape = GetApellidos();
    int z = sizeof(ape)/sizeof(ape[0]);
    sort(ape,ape+tam); //Use the start and end like this
  for(int y = 0; y < z; y++)
  {
    cout << ape[y] << endl;
  }
  pausa();
}*/
template <typename T>
void ArrayPersonas<T>::Busqueda(){
    cout<<"\n\t\t\t Busqueda "<< endl;
    cout<<" Introduzca dato a buscar: ";
    vector <int> aux;
    string ele;
    cin>>ele;
    string *arr = GetApellidos();
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
template <typename T>
void ArrayPersonas<T>::AlmacenarDatos(){
    (ptr)->Limpiar();
    for(int i = 0;i < tam;i++){
        (ptr+i)->SubirDatos();
    }
}
template <typename T>
void ArrayPersonas<T>::AlmacenarDatos2(){
    for(int i = 0;i < tam;i++){
        (ptr+i)->ReescribirDatos2(archiv);
    }
    remove("pacientes.txt");
    rename("auxiliar.txt","pacientes.txt");
}
#endif // ARRAYPERSONAS_H
