#include "neuron.hpp"

#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace std;

/**
 * @brief Construct a new Neuron:: Neuron object
 * 
 */
Neuron::Neuron(){
    for(int i = 0; i < MAX_NEURONS_PER_LAYER; i++){
        this->weights[i] = 0;
    }
    this->bias = 0;
}

/**
 * @brief Construct a new Neuron:: Neuron object
 * 
 * @param new_n 
 */
Neuron::Neuron(int new_n){
    this->n = new_n;                        // Set the value of n
    
    for(int i = 0; i < MAX_NEURONS_PER_LAYER; i++){
        this->weights[i] = 1;
    }
    this->bias = 0;
}

/**
 * @brief Destroy the Neuron:: Neuron object
 * 
 */
Neuron::~Neuron(){}

/**
 * @brief Setter function to change the value of the bias.
 * 
 * @param new_bias 
 */
void Neuron::set_bias(double new_bias){ this->bias = new_bias; }

/**
 * @brief Setter function to change the values of the weights. The pointer remains the same, however each
 * element is updated to reflect the new array.
 * 
 * @param new_weights 
 */
void Neuron::set_weights(double* new_weights){
    for(int i = 0; i < MAX_NEURONS_PER_LAYER; i++){
        this->weights[i] = new_weights[i];
    }
}

/**
 * @brief A handy function which connects the neurons horizontally only, rather than being fully connected.
 * 
 */
void Neuron::straight_through_weights(){
    this->weights[0] = 1;
    for(int i = 1; i < MAX_NEURONS_PER_LAYER; i++){
        this->weights[i] = 0;
    }
}

/**
 * @brief Returns the activation of the neuron for a given (pointer to an) array of inputs.
 * 
 * @param inputs 
 * @return double 
 */
double Neuron::activation(double* inputs){
    if(this->weights == nullptr){ cout << "Error: Space for weights is not yet allocated." << endl; } else {
        double BX = this->bias;                         // Start with the bias
        for(int i = 0; i < this->n; i++){
            BX += (weights[i] * inputs[i]);             // Multiply each weight by each input to construct the B'X matrix
        }
        double activation = 1/(1 + exp(-(BX)));         // Compute the activation using the logistic regression function
        return activation;
    }   return 0.0;
}

/**
 * @brief Returns the number of inputs and weights.
 * 
 * @return int 
 */
int Neuron::get_n(){ return this->n; }

/**
 * @brief Returns the neuron's bias.
 * 
 * @return double 
 */
double Neuron::get_bias(){ return this->bias; }

/**
 * @brief Returns the pointer to the array of weights.
 * 
 * @return double* 
 */
double* Neuron::get_weights(){ return this->weights; }