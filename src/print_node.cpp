#include "print_node.h"
#include <iostream>

PrintNode::PrintNode(tbb::flow::graph& g)
    : node(g, tbb::flow::serial, [](const DataBlock& block)
    {
        for (size_t i = 0; i < block.data.size(); i++)
        {
            std::cout << block.data[i] << std::endl;
        }
    })
{}
