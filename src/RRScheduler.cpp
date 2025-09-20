#include "../include/rr.h"

RR::RR(int q) : quantum(q), current(ready.begin()){}

void RR::addProcess(Proceso* proc) {
    proc->setState(Estado::READY);
    ready.push_back(proc);
}

bool RR::hasProcesos() const {
    return !ready.empty();
}

Proceso* RR::peek(){
    Proceso* p = *current;
    current = ready.erase(current);
    return p;   
}

void RR::updWT(){
    for (list<Proceso*>::iterator it = ready.begin(); it != ready.end(); ++it) {
        if (it != current) 
            (*it)->incrementWT();
    }
}
