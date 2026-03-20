#include "main.h"

int main()
{
    tbb::flow::graph g;

    FileReaderNode fileReader(g);
    FileWriterNode fileWriter(g);

    make_edge(fileReader.node, fileWriter.node);

    fileReader.node.activate();

    g.wait_for_all();

    return 0;
}
