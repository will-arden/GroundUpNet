#include <iostream>
#include "neuron.hpp"

#define N_INPUTS 2

using namespace std;

int main(int argc, char** argv){

    // Create a bias and some weights and inputs for the neuron
    double my_bias = -10;
    double my_weights[N_INPUTS] = {30, 30};
    double my_inputs[N_INPUTS] = {0, 0};

    double threshold = 0.5;     // Threshold for binary activation
    int bin;                    // Binary output depending on the threshold

    Neuron OR_Gate(N_INPUTS, my_bias, &my_weights[0]);
    
    // Check output (0,0)
    my_inputs[0] = 0;   my_inputs[1] = 0;
    if(OR_Gate.activation(&my_inputs[0]) >= threshold) { bin = 1; } else { bin = 0; }
    cout << "A: 0 | B: 0 | Y: " << bin << endl;

    // Check output (0,1)
    my_inputs[0] = 0;   my_inputs[1] = 1;
    if(OR_Gate.activation(&my_inputs[0]) >= threshold) { bin = 1; } else { bin = 0; }
    cout << "A: 0 | B: 1 | Y: " << bin << endl;

    // Check output (1,0)
    my_inputs[0] = 1;   my_inputs[1] = 0;
    if(OR_Gate.activation(&my_inputs[0]) >= threshold) { bin = 1; } else { bin = 0; }
    cout << "A: 1 | B: 0 | Y: " << bin << endl;

    // Check output (1,1)
    my_inputs[0] = 1;   my_inputs[1] = 1;
    if(OR_Gate.activation(&my_inputs[0]) >= threshold) { bin = 1; } else { bin = 0; }
    cout << "A: 1 | B: 1 | Y: " << bin << endl;

    return 0;

}