#include "../include/simulador.h"

Simulador:: Simulador(vector<Proceso*> ord)
    :order(ord),
    time(0),
    pr(0),
    numProcesos(ord.size()),
    terminados(0)
{}

void Simulador:: check(){
    while (pr < numProcesos && time == order[pr]->getArrival()) {
        colas.addProcess(order[pr]);
        pr++;
    }
}

void Simulador:: run(){
    while(terminados < numProcesos){
        check();
        terminados += colas.run(time);
        time++;
    }

}