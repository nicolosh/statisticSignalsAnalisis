//
// Created by nicol on 31/12/2020.
//

#include "../include/signals/signals.h"

int signals::InterpolatedSignal::getSampleCounter() const {
    return int((samples_[samples_.size() - 1].time_ - samples_[0].time_) / dt_);
    // trovo il numero N di campioni del mio segnale
}

bool signals::AsyncSignal::addSample(const Sample &sample) {
    if (samples_[samples_.size() - 1].time_ < sample.time_) // ordino i miei campioni a t crescente
    {
        samples_.push_back(sample);
        return true;
    }

    return false;
}


double signals::InterpolatedSignalZOH::getSample(int index) const {
    double time_star = samples_[0].time_ + index * dt_;

    for (int i = 1; i < samples_.size(); ++i) {
        if (samples_[i].time_ > time_star)
            return samples_[i - 1].x_;
    }
    return samples_[samples_.size() - 1].x_;
}

double signals::InterpolatedSignalLinear::getSample(int index) const {
    double time_star = samples_[0].time_ + index * dt_;

    for (int i = 1; i < samples_.size(); ++i) {
        if (samples_[i].time_ > time_star) {
            double x_tn = samples_[i - 1].x_;
            double x_tnp1 = samples_[i].x_;
            double tn = samples_[i - 1].time_;
            double tnp1 = samples_[i - 1].time_;
            return x_tn + (x_tnp1 - x_tn) * (time_star - tn) / (tnp1 - tn);
        }
    }
    return samples_[samples_.size() - 1].x_; // last sample
}
