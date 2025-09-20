#ifndef SIMULADOR_H
#define SIMULADOR_H
#include <vector>
#include "process.h"
#include "MLFQ.h"

class Simulador{
    private:
    int time;
    int pr;
    int terminados;
    int numProcesos;
    MLFQ colas;
    vector<Proceso*> order;
    
    public: 
    Simulador(vector<Proceso*> order);

    void run();

    void check();
};

#endif