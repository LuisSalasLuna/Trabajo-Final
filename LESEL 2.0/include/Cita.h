#ifndef CITA_H
#define CITA_H
#include <Paciente.h>
#include <Doctor.h>
#include <Date.h>

class Cita{
    private:
        Paciente Pac;
        Doctor Doc;
        Date fecha;
        string arch;
    public:
        Cita();
        Cita(Paciente, Doctor, Date, string);
        void SetDatos();
        void mostrar();
        void SubirDatos(string);
};

#endif // CITA_H
