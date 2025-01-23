#ifndef MODEL_HPP
#define MODEL_HPP

#include "config.hpp"
#include "layer.hpp"

using namespace std;

class Model {
    private:
        int L = 0;
        Layer* layers[MAX_LAYERS_PER_MODEL];
    public:
        ~Model();

        void new_layer(int, int);
        void create_input_layer(int, int);
        void connect();
        void set_weights(double***);

        int get_L();            // Getter functions
        Layer* get_layer(int);
};

#endif