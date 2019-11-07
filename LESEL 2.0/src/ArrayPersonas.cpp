#include "ArrayPersonas.h"
void pausa();
ArrayPersonas::ArrayPersonas(){
    tam = 0;
    ptr= new Persona[tam];
}
ArrayPersonas::ArrayPersonas(int tama ){  //mejorar
    tam = tama;
    ptr= new Persona[tama];
}
ArrayPersonas::~ArrayPersonas(){
    delete[] ptr;
    cout<< "Destructor invoked"<< endl;
}
void ArrayPersonas::MenuPrincipal(){
    int opcion;
    do{
        cout<<"\n\t\t\t Registro de personas"<< endl;
        cout<<" 1. Agregar persona"<< endl;
        cout<<" 2. Modificar datos de una persona"<< endl;
        cout<<" 3. Eliminar datos de una persona"<< endl;
        cout<<" 4. Mostrar informacion de persona"<< endl;
        cout<<" 5. Leer listado de personas"<< endl;
        cout<<" 6. Salir \n"<< endl;
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
            cout<<"\n\t\t\tModificar los datos de una persona\n\n";
            MostrarPers2();
            int opcionM;
            cout<<"\n\n Opci\242n: ";
            cin>>opcionM;
            Modificar(opcionM);
            break;
        case 3:
            cout<<"\n\t\t\tEliminar los datos de una persona\n\n";
            MostrarPers2();
            int opcionE;
            cout<<"\n\n Opci\242n: ";
            cin>>opcionE;
            Eliminar(opcionE);
            break;
        case 4:
            cout<<"\n\t\t\tDetalles de una persona\n\n";
            MostrarPers2();
            int opcionI;
            cout<<"\n\n Opci\242n: ";
            cin>>opcionI;
            MostrarInfoPersona(opcionI);
            break;
        case 5:
            MostrarPers();
            break;
        case 6:
            break;
        }
    }
    while(opcion!=6);
}
void ArrayPersonas::MostrarPers(){
    cout<<"\n\t\t\tListado de todas las personas"<<endl;
    for(int i = 0;i < tam;i++){
        cout<< "\n Persona " << i+1 << " :"<< endl;
        (ptr+i)->mostrar();
    }
}
void ArrayPersonas::MostrarPers2(){
    cout<< " Elija la opci\242n de la persona a modificar: ";
    for(int i = 0;i < tam;i++){
        cout<< "\n  " << i+1 << " : " ;
        (ptr+i)->mostrar2();
    }
}
void ArrayPersonas::Agregar(){
    cout<<"\n\t\t\t Agregar una persona"<<endl;
    tam = tam+1;
    Persona *Narr= new Persona[tam];
    Persona *ptr2 = ptr;
    for(int i = 0;i < tam-1;i++){
        Narr[i]=*(ptr+i);
    }
    ptr = Narr;
    Narr = ptr2;
    delete[] Narr;
    (*(ptr+tam-1)).SetDatos();
    pausa();
}
void ArrayPersonas::Eliminar(int a){
    int c = 0;
    tam = tam-1;
    Persona *Narr= new Persona[tam];
    Persona *ptr2 = ptr;
    Persona x = *(ptr+a-1);
    for(int i = 0;i < tam;i++){
        if( x.GetCodigo()!=(*(ptr+i)).GetCodigo()){
            Narr[i]=*(ptr+c);
        }
        else{
            c = c+1;//
            Narr[i]=*(ptr+c);
        }
        c++;
    }
    ptr = Narr;
    Narr = ptr2;
    delete[] Narr;
}
void ArrayPersonas::Modificar(int b){
    Persona *Narr= new Persona[tam];
    Persona *ptr2 = ptr;
    for(int i = 0;i < tam;i++){
        if( (*(ptr+b-1)).GetCodigo()==(*(ptr+i)).GetCodigo()){
            (*(ptr+b-1)).SetDatos();
        }
        Narr[i]=*(ptr+i);
    }
    ptr = Narr;
    Narr = ptr2;
    delete[] Narr;
    pausa();
}
void ArrayPersonas::MostrarInfoPersona(int c){
        (ptr+c-1)->mostrar();
}
void pausa(){
    system("pause");
    system("CLS");
}
