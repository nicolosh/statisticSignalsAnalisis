//
// Created by nicol on 31/12/2020.
//

#ifndef STATISTICSIGNALSANALISIS_SIGNALS_H
#define STATISTICSIGNALSANALISIS_SIGNALS_H

#include <vector>
#include <string>
#include <iostream>

namespace signals {
    struct Sample {
        double time_, x_;

        Sample(double time, double x) : time_(time), x_(x) {}
    };

    class SyncSignalReader {
    public:
        virtual int getSampleCounter() const = 0;

        virtual double getSample(int index) const = 0; // con i istante discreto di campionamento
    };

    class AsyncSignalWriter //memorizza segnali come campionati asincronamente cioè il campione all'istante
        // t_n = n*dt e il valore dell'istante t_n a cui il campione è stato letto
    {
    public:
        virtual bool addSample(const Sample &sample) = 0;
    };

    class AsyncSignal : public AsyncSignalWriter {
    protected:
        std::vector<Sample> samples_;
        std::string name_;
    public:
        AsyncSignal(const std::string &name) : name_(name) {}

        const std::string &getName() { return name_; }

        virtual bool addSample(const Sample &sample) override;

        //AGGIUNTO std::vector<Sample> &getSamples() { return samples_; }
    };


    class InterpolatedSignal : public AsyncSignal, SyncSignalReader {
    protected:
        double dt_; // time step
    public:
        InterpolatedSignal(const std::string &name, double dt) : AsyncSignal(name), dt_(dt) {}

        double getTimeStep() const { return dt_; }

        virtual double getSample(int index) const override = 0;

        virtual int getSampleCounter() const override;
    };

    class InterpolatedSignalZOH : public InterpolatedSignal {
    public:
        //AGGIUNTO->InterpolatedSignalZOH(const std::string &name, double dt) : InterpolatedSignal(name, dt) {};

        virtual double getSample(int index) const override;
    };

    class InterpolatedSignalLinear : public InterpolatedSignal {
    public:
        //AGGIUNTO->InterpolatedSignalLinear(const std::string &name, double dt) : InterpolatedSignal(name, dt) {};

        virtual double getSample(int index) const override;
    };
}

#endif //STATISTICSIGNALSANALISIS_SIGNALS_H
