#include <iostream>
#include "neuron.hpp"

using namespace std;

int main(int argc, char** argv){

    double my_bias = -100;
    double my_weights[3] = {1, 2, 3};
    double my_inputs[3] = {5, 6, 7};
    Neuron instance(3, my_bias, &my_weights[0], &my_inputs[0]);
    cout << "Activation: " << instance.activation() << endl;
    return 0;

}