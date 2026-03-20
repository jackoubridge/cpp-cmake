#include "file_reader_node.h"

FileReaderNode::FileReaderNode(tbb::flow::graph& g)
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

        std::ifstream file("tone.raw", std::ios::binary);

        if (!file)
        {
            std::cerr << "Failed to open file\n";
        }

        file.seekg(0, std::ios::end);
        std::streamsize size = file.tellg();
        file.seekg(0, std::ios::beg);

        size_t numSamples = size / sizeof(float);

        block.data.resize(numSamples);
        block.sampleRate = 44100;

        if (!file.read(reinterpret_cast<char*>(block.data.data()), size))
        {
            std::cerr << "Failed to read file\n";
        }

        return block;
    })
{}
