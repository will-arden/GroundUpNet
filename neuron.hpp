#ifndef NEURON_HPP
#define NEURON_HPP

class Neuron {
    private:
        int n;
        double bias;
        double* weights;
        double* inputs;
    public:
        Neuron(int, double, double*, double*);
        ~Neuron();

        void set_n(int);                    // Setter functions
        void set_bias(double);
        void set_weights(double*);
        void set_inputs(double*);

        double activation();                // Getter functions
        int get_n();
        double  get_bias();
        double* get_weights();
        double* get_inputs();
};

#endif