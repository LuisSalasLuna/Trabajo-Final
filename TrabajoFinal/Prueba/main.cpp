#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdio>

using namespace std;
class Persona{
private:
    string codigo;
    string nombre;
    string apellido;
public:
    Persona();
    Persona(string, string, string);
    string GetCodigo();
    void SetPersona();
    void mostrar();
};
    Persona::Persona(){
        codigo = "C\242digo";
        nombre = "Nombre";
        apellido = "Apellido";
    }
    Persona::Persona(string C, string N, string A){
        codigo = C;
        nombre = N;
        apellido = A;
    }
    string Persona::GetCodigo(){
        return codigo;
    }
    void Persona::SetPersona(){
        cout<<"\n Ingresa el c\242digo de la persona: ";
        getline(cin,codigo);
        fflush(stdin);
        cout<<" Ingresa el nombre de la persona: ";
        getline(cin,nombre);
        fflush(stdin);
        cout<<" Ingresa el nombre de la persona: ";
        getline(cin,apellido);
        fflush(stdin);
    }
    void Persona::mostrar(){
        cout<< " C\242digo: "<< codigo<< endl;
        cout<< " Nombre: "<< nombre<< endl;
        cout<< " Apellido: "<< apellido<< endl;
}
class ArrayPersonas{
private:
    Persona *ptr;
    int tam;
public:
    ArrayPersonas();
    ~ArrayPersonas();

    void Amostrar();
    void Agregar();
    void Eliminar(int);
};
    ArrayPersonas::ArrayPersonas(){
        tam = 0;
        ptr= new Persona[tam];
    }
    ArrayPersonas::~ArrayPersonas(){
        delete[] ptr;
    }
    void ArrayPersonas::Amostrar(){
        for(int i = 0;i < tam;i++){  //->
            cout<< "\n Persona " << i+1 << " :"<< endl;
            (ptr+i)->mostrar();
        }
    }
    void ArrayPersonas::Agregar(){
        tam = tam+1;
        Persona *Narr= new Persona[tam];//donde delete?
        Persona *ptr2 = ptr;
        for(int i = 0;i < tam-1;i++){
            Narr[i]=*(ptr+i);
        }
        ptr = Narr;
        Narr = ptr2;
        delete[] Narr;
        (*(ptr+tam-1)).SetPersona();
    }
    void ArrayPersonas::Eliminar(int a){
        int c = 0;
        tam = tam-1;
        Persona *Narr= new Persona[tam];
        Persona *ptr2 = ptr;
        Persona x = *(ptr+a-1);
        for(int i = 0;i < tam-1;i++){
            if( x.GetCodigo() != (*(ptr+i)).GetCodigo()){ //faltan detalles
                Narr[i]=*(ptr+c);
            }
            else{
                c = c+1;
                Narr[i]=*(ptr+c);
            }
            c++;
        }
        ptr = Narr;
        Narr = ptr2;
        delete[] Narr;
    }
int main(){
    ArrayPersonas A;
    A.Agregar();
    A.Amostrar();
    cout<<"\n";
    A.Agregar();
    A.Amostrar();
    cout<<"\n";
    A.Agregar();
    A.Amostrar();
    cout<<"\n";
    A.Eliminar(2);
    A.Amostrar();
    return 0;
}
