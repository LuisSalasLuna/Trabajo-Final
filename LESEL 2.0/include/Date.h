#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;


class Date{
    private:
        string dia;
        string mes;
        string anho;
        string arch;
    public:
        Date();
        Date(string, string, string, string);
        void SetDatos();
        void mostrar();
        void SubirDatos(string);
        string GetDia();
        string GetMes();
        string GetAnho();
};

#endif // DATE_H
