#include <inetreg.h>
#include <cstring>
#include <iostream>
#include "logic.hpp"

using namespace std;

int main()
{
    setRussianLangue();

    struct Graph* graph = create();
    struct Graph* start = graph;
    struct Graph* root = graph;

    int tool = getTools();
    while (tool != 8)
    {    
        switch (tool)
        {
            case 1:
            {
                int countGraph = amount(start, 0);
                std::cout << countGraph << std::endl;

                break;
            }
            case 2:
            {
                addGraph(root);
                break;
            }
            case 3:
            {
                

                break;
            }
            case 4:
            {
                removeGraph(root);
                break;
            }
            case 5:
            {
                removeGraphs(start);
                break;
            }
            case 6:
            {
                root = changePosition(root);
                break;
            }
            case 7:
            {
                getValue(root);
                break;
            }
        }
        tool = getTools();
    }
    
    return 0;
}
