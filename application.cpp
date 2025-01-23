#include "model.hpp"

#include <iostream>

using namespace std;

int main(int argc, char** argv){

    // Create a new Model
    Model my_model;

    // Create some layers
    my_model.create_input_layer(2, INPUT);
    my_model.new_layer(2, HIDDEN);
    my_model.new_layer(1, OUTPUT);

    // Fully connect the layers
    my_model.connect();

    // Create some biases
    double L1_b[MAX_NEURONS_PER_LAYER];
    double L2_b[MAX_NEURONS_PER_LAYER];

    for(int i = 0; i < MAX_NEURONS_PER_LAYER; i++){
        L1_b[i] = 0;
        L2_b[i] = 0;
    }
    L1_b[0] = -30;  L1_b[1] = -30;
    L2_b[0] = -10;

    //my_model.get_layer(1)->set_biases(L1_b);          // Causes runtime error
    return 0;

}