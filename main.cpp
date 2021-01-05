#include <iostream>
#include <signals/signals.h>
#include <signals/statistic.h>

using namespace std;
using namespace signals;

int main() {
    std::cout << "Analisis Statistic Of Signals " << std::endl;
    double dt = 0.5;

    InterpolatedSignalZOH interpolZOH("ZOH", dt);
    InterpolatedSignalLinear interpolLinear("Linear", dt);

    //aggiorno samples_ di interpolatedSignalZOH/interpolatedSIgnalLInear
    // che sono degli async signal quindi posso aggiungergli samples come fossero asincroni
    // (scrivo il segnale memorizzandolo con i t_n e x(t_n)
    const int N = 20;
    for (int i = 0; i < N; ++i) {
        interpolZOH.addSample(Sample(double(i), double(i ^ 2 + 3 - i * 9)));
        interpolLinear.addSample(Sample(double(i), double(i ^ 2 + 3 - i * 9)));
    }

    for (int i = 0; i < N; ++i) {
        interpolZOH.getSample(i);
        interpolLinear.getSample(i);
    }


    SyncSignalReader* signalSincronousedOne;
    SyncSignalReader* signalSincronousedTwo;
    signalSincronousedOne = &interpolZOH;
    signalSincronousedTwo = &interpolLinear;

    std::cout << "ciao";

    //analisi statistica sul segnale sincrono ottenuto
    Statistic statisticOne("StatisticOne");
    statisticOne.setSignal(signalSincronousedOne);
    statisticOne.meanCompute();
    std::cout << std::endl;
    statisticOne.varianceCompute();
    std::cout << std::endl;
    statisticOne.stdDevCompute();

    Statistic statistic("Statistic");
    statistic.setSignal(signalSincronousedTwo);
    statistic.meanCompute();
    std::cout << std::endl;
    statistic.varianceCompute();
    std::cout << std::endl;
    statistic.stdDevCompute();

    return 0;
}
