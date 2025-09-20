#include "../include/MLFQ.h"

MLFQ :: MLFQ(){
    rr1 = RR(1);
    rr1 = RR(3);
    rr1 = RR(4);
    Proceso* ac = nullptr;
    wich = 1;
    sjf = SJF();
    var = 0;
}

void MLFQ::addProcess(Proceso* p){
    rr1.addProcess(p);
}

int MLFQ::run(int time){
    int ans = 0, q;
    if(ac != nullptr){
        escogerCola();
        if(wich = 1){
            ac = rr1.peek();
            q = rr1.getQuantum();
        }
        if(wich = 2)
            ac = rr2.peek();
            q = rr2.getQuantum();
        if(wich = 3)
            ac = rr3.peek();
            q = rr2.getQuantum();
        if(wich = 4)
            ac = sjf.peek();
            q = ac->getRemaining();
        var = 0;
    }
    ac->run(time);
    if(wich = 1)
        rr1.updWT();
    if(wich = 2)
        rr2.updWT();
    if(wich = 3)
        rr3.updWT();
    if(wich = 4)
        sjf.updWT();
    var++;
    if(ac->isFinished())
        ans = 1;
    else if(var == q){
        next();
    }
    return ans;
}

void MLFQ::escogerCola(){
    if(rr1.hasProcessos())
        wich = 1;
    else if(rr2.hasProcessos())
        wich = 2;
    else if(rr3.hasProcessos())
        wich = 3;
    else wich = 4;
}

void MLFQ::next(){
    if(wich == 1)
        rr2.addProcess(ac);
    if(wich == 2)
        rr3.addProcess(ac);
    if(wich == 3)
        sjf.addProcess(ac);
}