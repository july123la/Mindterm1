#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm> 
#include <queue>
#include <list>
#include "../include/simulador.h"
#include "../include/process.h"

using namespace std;
int numProcesos;

vector<Proceso> procesos;
vector<Proceso*> order;

bool compare(const Proceso* a, const Proceso* b){
    bool ans;
    if(a->getArrival() == b->getArrival())
        ans = a->getPid() < b->getPid();
    else ans = a->getArrival() < b->getArrival();
    return ans;
}

void imprimirTabla() {
    int n = numProcesos;

    cout << "P\tAT\tBT\tQ\tCT\tTAT\tWT\tRT\n";
    cout << "---------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << procesos[i].getLabel()   << "\t"
             << procesos[i].getArrival()  << "\t"
             << procesos[i].getBurst()  << "\t"
             << procesos[i].getInitialQueue()  << "\t"
             << procesos[i].getCompletionTime()  << "\t"
             << procesos[i].getTurnAroundTime() << "\t"
             << procesos[i].getWaitingTime()  << "\t"
             << procesos[i].getResponseTime()  << "\n";
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Uso: " << argv[0] << " <archivo_entrada.txt>\n";
        return 1;
    }
    ifstream file(argv[1]);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo: " << argv[1] << "\n";
        return 1;
    }
    string line;
    int i = 0;
    while (getline(file, line)) {
        // ignorar comentarios o líneas vacías
        if (line.empty() || line[0] == '#') continue;
        stringstream ss(line);
        string label, bt, at, q, p;
        getline(ss, label, ';');
        getline(ss, bt, ';');
        getline(ss, at, ';');
        getline(ss, q, ';');
        getline(ss, p, ';');
        // función para limpiar espacios
        auto trim = [](string &s) {
            s.erase(remove_if(s.begin(), s.end(), ::isspace), s.end());
        };
        trim(label); trim(bt); trim(at); trim(q); trim(p);
        procesos.push_back(Proceso(i, label, stoi(at), stoi(bt), stoi(q), stoi(p)));
        order.push_back(&procesos[i]);
        i++;
    }
    file.close();
    numProcesos = i;
    sort(order.begin(), order.end(), compare);
    Simulador simulacion(order);
    simulacion.run();
    imprimirTabla();

    return 0;
}
