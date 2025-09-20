#ifndef SCHEDULER_H
#define SCHEDULER_H
#include <memory>
#include "process.h"

using namespace std;

/// Clase base abstracta para cualquier algoritmo de planificación.
/// Cada algoritmo debe manejar internamente su propia cola/lista de procesos.
class Scheduler {
public:
    virtual ~Scheduler() = default;

    /// Inserta un proceso en la cola de listos del scheduler.
    virtual void addProceso(Proceso* proc) = 0;

    /// Devuelve true si hay al menos un proceso listo para ejecutarse.
    virtual bool hasProcesos() const = 0;

    /// Obtiene (sin remover) el siguiente proceso que sería ejecutado.
    virtual Proceso* peek();

    /// Extrae y devuelve el siguiente proceso a ejecutar.
    /// (Normalmente se combina con run() para simular un tick de CPU)
    virtual Proceso* next() = 0;

    /// Ejecuta el proceso indicado por un máximo de `timeSlice` ticks de CPU.
    ///  - Debe descontar el tiempo en el proceso.
    ///  - Retorna la cantidad de ticks que realmente se ejecutaron.
    ///    (puede ser < timeSlice si el proceso termina antes).
    virtual int run(Proceso* proc, int timeSlice) = 0;

    /// Nombre del algoritmo (útil para depuración/impresión).
    virtual const char* name() const = 0;
};

#endif