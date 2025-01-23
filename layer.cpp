#include "layer.hpp"

#include <iostream>

using namespace std;

/**
 * @brief Construct a new Layer:: Layer object
 * 
 */
Layer::Layer(){
    this->init();
}

/**
 * @brief Destroy the Layer:: Layer object
 * 
 */
Layer::~Layer(){}

void Layer::lock(){ this->locked = 1; }

/**
 * @brief Zero-initialise the pointers to the weights and outputs of the Layer object.
 * 
 */
void Layer::init(){
    for(int i = 0; i < MAX_NEURONS_PER_LAYER; i++){
        this->neurons[i] = nullptr;
        this->outputs[i] = nullptr;
        m = 0;
    }
}

/**
 * @brief Dynamically allocates a new Neuron object and increments m (the number of Neuron objects associated with this Layer).
 * 
 */
void Layer::new_neuron(){
    this->neurons[m] = new Neuron;
    m++;
}

/**
 * @brief Provides information to the Layer on the previous Layer's neurons.
 * 
 * @param prev_addr 
 * @param prev_m 
 */
void Layer::set_connection_list(Neuron* prev_addr, int prev_m){
    this->num_connections = prev_m;
    for(int i = 0; i < num_connections; i++){
        this->connection_list[i] = &prev_addr[i];
    }
}

/**
 * @brief Sets the weights for all Neuron objects in this Layer. Accepts a 2D matrix.
 * 
 * @param new_weights 
 */
void Layer::set_weights(double** new_weights){
    for(int i = 0; i < MAX_NEURONS_PER_LAYER; i++){
        this->neurons[i]->set_weights(new_weights[i]);
    }
}

/**
 * @brief Sets the biases for all Neuron objects in this Layer. Accepts a 1D array.
 * 
 * @param new_biases 
 */
void Layer::set_biases(double* new_biases){
    for(int i = 0; i < MAX_NEURONS_PER_LAYER; i++){
        this->neurons[i]->set_bias(new_biases[i]);
    }
}

/**
 * @brief Sets the type of the Layer. See "config.hpp".
 * 
 * @param new_type 
 */
void Layer::set_type(int new_type){ this->type = new_type; }

/**
 * @brief Getter function which returns the number of Neuron objects associated with this Layer.
 * 
 * @return int 
 */
int Layer::get_m(){ return this->m; }

/**
 * @brief Getter function which returns the enumerated type of the Layer. See "./config.hpp".
 * 
 * @return int 
 */
int Layer::get_type(){ return this->type; }

/**
 * @brief Getter function which returns a pointer to the first Neuron in the array of pointers to Neurons associated with this Layer.
 * 
 * @return Neuron* 
 */
Neuron* Layer::get_neurons(){ return this->neurons[0]; }