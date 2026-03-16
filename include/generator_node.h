#pragma once
#include <oneapi/tbb.h>
#include "data_block.h"

class GeneratorNode
{
public:
    tbb::flow::input_node<DataBlock> node;

    GeneratorNode(tbb::flow::graph& g);
};
