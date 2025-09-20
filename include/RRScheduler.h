#ifndef RRSCHEDULER_H
#define RRSCHEDULER_H
#include "scheduler.h"
#include <queue>
#include <memory>
#include <list>

using namespace std;

/// Implementación de Round Robin como hijo de Scheduler.
class RRScheduler : public Scheduler {
private:
    int quantum;  ///< Quantum de RR
    list<Proceso> ready; ///< cola de listos
    list<Proceso>::iterator current;

public:
    RRScheduler(int q);

    void addProceso(Proceso* proc) override;
    bool hasProcesos() const override;
    Proceso* peek() override;
    Proceso* next() override;

    /// Ejecuta el proceso indicado hasta un máximo de timeSlice ticks
    /// (normalmente timeSlice = quantum).
    int run(Proceso* proc, int timeSlice) override;

    const char* name() const override { return "Round Robin"; }

    /// Devuelve el quantum configurado.
    int getQuantum() const { return quantum; }
};

#endif