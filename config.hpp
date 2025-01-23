#ifndef CONFIG_HPP
#define CONFIG_HPP

#define MAX_LAYERS_PER_MODEL 64
#define MAX_NEURONS_PER_LAYER 1024

enum LayerType {
    NO_TYPE,
    HIDDEN,
    INPUT,
    OUTPUT,
};

#endif