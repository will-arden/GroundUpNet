#include "model.hpp"

#include <iostream>

/**
 * @brief Dyanmically allocate the memory for a new Layer object and increment L (the number of Layer objects in this Model).
 * 
 * @param m 
 */
void Model::new_layer(int m, int type){
    this->layers[L] = new Layer;        // Dynamically allocate memory for a new Layer object
    this->layers[L]->set_type(type);    // Set the Layer type
    
    // Give the Layer m neurons
    for(int i = 0; i < m; i++){
        this->layers[L]->new_neuron();
    }

    this->L++;                      // Increase the layer count
}

void Model::create_input_layer(int m, int type){

    this->layers[L] = new Layer;        // Dynamically allocate memory for a new Layer object
    this->layers[L]->set_type(type);    // Set the Layer type
    
    // Give the Layer m neurons
    for(int i = 0; i < m; i++){
        this->layers[L]->new_neuron();
    }

    // Lock the Layer
    this->layers[L]->lock();

    this->L++;                          // Increase the layer count
}

/**
 * @brief Destroy the Model:: Model object
 * 
 */
Model::~Model(){
    for(int i = 0; i < this->L; i++){       // Free allocated memory for each Layer
        delete this->layers[i];
    }
}

/**
 * @brief The Model object instructs its associated Layer objects to share information about the Neurons, such that they are
 * then able to fully connect themselves.
 * 
 */
void Model::connect(){
    for(int i = 1; i < this->L; i++){
        cout << "Transferring data from Layer " << i-1 << " to Layer " << i << "." << endl;
        int prev_m = (this->layers[i-1])->get_m();
        Neuron* prev_addr = (this->layers[i-1])->get_neurons();
        cout << "There are " << prev_m << " Neurons in Layer " << i-1 << " which is at address: " << prev_addr << endl;

        if(prev_addr == nullptr){
            cout << "Error: Null pointer." << endl;
            return;
        } else {

            // Share the information about the Neurons of the previous Layer
            (this->layers[i])->set_connection_list(prev_addr, prev_m);

        }
    }
}

/**
 * @brief Sets the weights for all valid layers (anything except NO_TYPE and INPUT)
 * 
 * @param new_weights 
 */
void Model::set_weights(double*** new_weights){
    for(int i = 0; i < MAX_LAYERS_PER_MODEL; i++){              // Iterate through all Layers of the Model

        int type = this->layers[i]->get_type();                 // Retrieve the type of Layer

        if(type == HIDDEN || type == OUTPUT){                   // Only apply the weights on valid Layer types
            this->layers[i]->set_weights(new_weights[i]);
        }
    }
}

/**
 * @brief Getter function which returns L (the number of Layer objects in this Model).
 * 
 * @return int 
 */
int Model::get_L(){
    return this->L;
}

/**
 * @brief Getter function which returns a pointer to the array of Layer objects.
 * 
 * @return Layer* 
 */
Layer* Model::get_layer(int i){
    return this->layers[i];
}