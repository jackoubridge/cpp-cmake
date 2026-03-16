#include "generator_node.h"

GeneratorNode::GeneratorNode(tbb::flow::graph& g)
    : node(g, [](tbb::flow_control& fc) -> DataBlock
    {
        static bool done = false;

        if(done)
        {
            fc.stop();
            return {};
        }

        done = true;

        DataBlock block;
        block.data = {1.0f};

        return block;
    })
{}
