#include <iostream>
#include <stdexcept>
#include <cmath>
#include "neuron.hpp"

using namespace std;

/**
 * @brief Construct a new Neuron:: Neuron object
 * 
 * @param new_n 
 */
Neuron::Neuron(int new_n, double new_bias, double* new_weights, double* new_inputs){
    this->set_n(new_n);                     // Set the value of n

    this->weights = new double[n];          // Create the pointer to the weights array
    this->inputs = new double[n];           // Create the pointer to the inputs array

    this->set_bias(new_bias);               // Initialise the bias
    this->set_weights(new_weights);         // Initialise the weights
    this->set_inputs(new_inputs);           // Initialise the inputs
}

/**
 * @brief Destroy the Neuron:: Neuron object
 * 
 */
Neuron::~Neuron(){
    delete[] this->weights;
    delete[] this->inputs;
}

/**
 * @brief Setter function to change the value of the number of inputs and weights, n.
 * 
 * @param new_n 
 */
void Neuron::set_n(int new_n){
    if(new_n <= 0){ throw invalid_argument("Neuron initialised with a non-positive number of inputs."); }
    else {
        this->n = new_n;                        // Initialise the number of inputs and weights
        

        cout << "Neuron created with " << this->n << " inputs." << endl;
    }
};

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
    for(int i = 0; i < this->n; i++){
        this->weights[i] = new_weights[i];
    }
}

/**
 * @brief Setter function to change the values of the inputs. The pointer remains the same, however each
 * element is updated to reflect the new array.
 * 
 * @param new_inputs 
 */
void Neuron::set_inputs(double* new_inputs){
    for(int i = 0; i < this->n; i++){
        this->inputs[i] = new_inputs[i];
    }
}

double Neuron::activation(){
    double BX = this->bias;                         // Start with the bias
    for(int i = 0; i < this->n; i++){
        BX += (weights[i] * inputs[i]);             // Multiply each weight by each input to construct the B'X matrix
    }
    double activation = 1/(1 + exp(-(BX)));         // Compute the activation using the logistic regression function
    return activation;
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

/**
 * @brief Returns the pointer to the array of inputs.
 * 
 * @return double* 
 */
double* Neuron::get_inputs(){ return this->inputs; }