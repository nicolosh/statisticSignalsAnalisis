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
        Statistic(const std::string &name) : name_(name), meanComputed_(false),
                                             varianceComputed_(false), stdDevComputed_(false) {}

        //aggiunto
        Statistic(const std::string &name, const SyncSignalReader *s) : Statistic(name) {
            s_ = s;
        }

        void setSignal(const SyncSignalReader *s) { s_ = s; }

        //cambiato double con void
        void meanCompute();

        void varianceCompute();

        void stdDevCompute();
    };
}

#endif //STATISTICSIGNALSANALISIS_STATISTIC_H
