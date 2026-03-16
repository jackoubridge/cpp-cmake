#include "main.h"

int main()
{
    tbb::flow::graph g;

    GeneratorNode generator(g);
    PrintNode printer(g);

    make_edge(generator.node, printer.node);

    generator.node.activate();

    g.wait_for_all();

    return 0;
}
