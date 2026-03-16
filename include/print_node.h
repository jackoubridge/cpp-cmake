#pragma once
#include <oneapi/tbb.h>
#include "data_block.h"

class PrintNode
{
public:
    tbb::flow::function_node<DataBlock> node;

    PrintNode(tbb::flow::graph& g);
};
