#ifndef LAYER_HPP
#define LAYER_HPP

#include "config.hpp"
#include "neuron.hpp"

class Layer {
    private:
        int locked = 0;                                     // Locks changes to the Layer
        int type = NO_TYPE;                                 // Sets the type of Layer (hidden, input, etc.)

        int m = 0;                                          // Number of parallel neurons in Layer
        Neuron* neurons[MAX_NEURONS_PER_LAYER];             // An array of this layer's neurons

        int num_connections = 0;                            // The number of connections from the previous layer
        Neuron* connection_list[MAX_NEURONS_PER_LAYER];     // An array of the previous layer's neurons

        double* outputs[MAX_NEURONS_PER_LAYER];             // A pointer to an array of neurons' activations
    public:
        Layer();
        ~Layer();

        void lock();
        void init();
        void new_neuron();
        void set_connection_list(Neuron*, int);

        void set_weights(double**);
        void set_biases(double*);
        void set_type(int);

        int get_m();                        // Getter functions
        int get_type();
        Neuron* get_neurons();
        //double* get_layer_activations();

        //void output(double*);               // Compute the activations of all neurons in Layer
};

#endif