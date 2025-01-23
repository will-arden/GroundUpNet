#ifndef NEURON_HPP
#define NEURON_HPP

#include "config.hpp"

class Neuron {
    private:
        int n = 0;
        double bias;
        double weights[MAX_NEURONS_PER_LAYER];
    public:
        Neuron();
        Neuron(int);
        Neuron(int, double, double*);
        ~Neuron();

        void set_n(int);                    // Setter functions
        void set_bias(double);
        void set_weights(double*);
        void straight_through_weights();
        void set_inputs(double*);

        int get_n();                        // Getter functions
        double  get_bias();
        double* get_weights();

        double activation(double*);
        //void alloc_weights(int);
};

#endif