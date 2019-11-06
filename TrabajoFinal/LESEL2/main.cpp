#include <iostream>

using namespace std;

class Persona{
    private:
        string codigo;
        string nombre;
        string apellido;
    public:
        Persona(string,string,string);
        virtual void Print();
};
    Persona::Persona(string C,string N,string A){
        codigo = C;
        nombre = N;
        apellido = A;
    }
    void Persona::Print(){
        cout<< " C\242digo: " << codigo <<endl;
        cout<< " Nombre: " << nombre <<endl;
        cout<< " Apellido: " << apellido <<endl;
    }
class Paciente: public Persona{
     private:
         string nacimiento;
         string direccion;
     public:
        Paciente(string,string,string,string,string);
        void Print();
};
    Paciente::Paciente(string C,string N,string A,string F, string D) : Persona(C,N,A){
        nacimiento = F;
        direccion = D;
    }
    void Paciente::Print(){
        Persona::Print();
        cout<< " Fecha de nacimiento: " << nacimiento <<endl;
        cout<< " Direcci\242n: " << direccion <<endl;
    }
class Doctor: public Persona{
     private:
         string especialidad;
     public:
        Doctor(string,string,string,string);
        void Print();
};
    Doctor::Doctor(string C,string N,string A,string E) : Persona(C,N,A){
        especialidad = E;
    }
    void Doctor::Print(){
        Persona::Print();
        cout<< " Especialidad: " << especialidad <<endl;
    }
int main()
{
    cout<<"\n";
    Persona A("1","Luis","Salas");
    A.Print();
    cout<<"\n";
    Paciente B("23","Luis","Salas","22/12/01","Pablo VI O-22");
    B.Print();
    cout<<"\n";
    Doctor C("54","Bergie","Salas","Traumatologia");
    C.Print();
    cout<<"\n";
    Persona *arr[3];
    arr[0]= new Paciente("23","Luis","Salas","22/12/01","Pablo VI O-22");
    arr[0]->Print();
    return 0;
}
