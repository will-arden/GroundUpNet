#ifndef NEURON_HPP
#define NEURON_HPP

class Neuron {
    private:
        int n;
        double bias;
        double* weights;
    public:
        Neuron(int, double, double*);
        ~Neuron();

        void set_n(int);                    // Setter functions
        void set_bias(double);
        void set_weights(double*);
        void set_inputs(double*);

        int get_n();                        // Getter functions
        double  get_bias();
        double* get_weights();

        double activation(double*);
};

#endif