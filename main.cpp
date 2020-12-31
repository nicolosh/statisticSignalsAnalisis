#include <iostream>
#include <signals/signals.h>
#include <signals/statistic.h>

using namespace std;
using namespace signals;

int main() {
    std::cout << "Analisis Statistic Of Signals (input = AsyncSignal)" << std::endl;
    AsyncSignal asyncSignal("A");

    //aggiorno samples_ di asyncsignal (scrivo il segnale memorizzandolo con i t_n e x(t_n)
    const int N = 20;
    for (int i = 0; i < N; ++i) {
        asyncSignal.addSample(Sample(double(i), double(i ^ 2 + 3 - i * 9)));
        std::cout << "x(" << i << ") = " << asyncSignal.getSamples()[i].x_ <<
        "t(" << i << ") = " << asyncSignal.getSamples()[i].time_;
    }
    double dt = 0.5;


    Statistic statistic("Statistic", signalSincronous);
    statistic.meanCompute();
    std::cout << std::endl;
    statistic.varianceCompute();
    std::cout << std::endl;
    statistic.stdDevCompute();
    return 0;
}
