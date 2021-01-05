//
// Created by nicol on 31/12/2020.
//

#include <cmath>
#include "../include/signals/statistic.h"

void signals::Statistic::meanCompute() {
    double sum = 0.0;
    for (int i = 0; i < s_->getSampleCounter(); ++i) {
        sum += s_->getSample(i); // sommo tutti i campioni del mio segnale originario asincrono che è stato
        //interpolato con un determinato orderOfInterpolation facendolo diventare sincrono cioè s_
    }
    mean_ = sum / s_->getSampleCounter();
    meanComputed_ = true;
    //return mean_;
    std::cout << "Mean of your signal is " << mean_ << std::endl;
}

void signals::Statistic::varianceCompute() {
    if (!meanComputed_) // perchè la variance è funzione della mean
        meanCompute();

    double sum = 0.0;
    for (int i = 0; i < s_->getSampleCounter(); ++i) {
        sum += (s_->getSample(i) - mean_) * (s_->getSample(i) - mean_);
    }
    variance_ = sum / s_->getSampleCounter();
    varianceComputed_ = true;
    //return variance_;
    std::cout << "Variance of your signal is " << variance_ << std::endl;
}

void signals::Statistic::stdDevCompute() {
    if (!varianceComputed_) // perchè la variance è funzione della mean
        varianceCompute();

    stdDev_ = sqrt(variance_);
    stdDev_ = true;
    //return stdDev_;
    std::cout << "StdDev of your signal is " << stdDev_ << std::endl;
}
