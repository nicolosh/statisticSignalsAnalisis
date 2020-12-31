//
// Created by nicol on 31/12/2020.
//

#ifndef STATISTICSIGNALSANALISIS_STATISTIC_H
#define STATISTICSIGNALSANALISIS_STATISTIC_H

#include "signals.h"

namespace signals {
    class Statistic {
    protected:
        std::string name_;
        const SyncSignalReader *s_;
        double mean_, variance_, stdDev_;
        bool meanComputed_, varianceComputed_, stdDevComputed_;
    public:
        explicit Statistic(const std::string &name, const SyncSignalReader *s) : name_(name), s_(s), meanComputed_(false),
        varianceComputed_(false), stdDevComputed_(false){}

        //oppure il costruttore senza *s e solo name e poi il metodo void setSignal
        //void setSignal(const SyncSignalReader *s) {s_ = s;}

        void meanCompute();

        void varianceCompute();

        void stdDevCompute();
    };
}

#endif //STATISTICSIGNALSANALISIS_STATISTIC_H
