#include <inetreg.h>
#include <cstring>
#include <iostream>
#include "logic.hpp"

using namespace std;

int main()
{
    struct Graph* graph = create();
    struct Graph* start = graph;
    struct Graph* root = graph;
    struct Graph* previosRoot = NULL;

    int tool = getTools();
    while (tool != 8)
    {    
        switch (tool)
        {
            case 1:
            {
                int count = amount(start);
                cout << "---------------------------------------------------------------" << endl;
                cout << "|       Количество графов в структуре данных = "<< count <<"              |" << endl;
                cout << "---------------------------------------------------------------" << endl;
                break;
            }
            case 2:
            {
                addGraph(root);
                break;
            }
            case 3:
            {   
                insertGraph(root);
                break;
            }
            case 4:
            {
                removeGraph(root);
                cout << "---------------------------------------------------------------" << endl;
                cout << "|        Выполнено удаление с графа {{"<< root <<"}}             |" << endl;
                cout << "---------------------------------------------------------------" << endl;
                root = previosRoot;
                break;
            }
            case 5:
            {
                removeGraphs(start);
                cout << "---------------------------------------------------------------" << endl;
                cout << "|            Выполнено удаление структуры данных              |" << endl;
                cout << "---------------------------------------------------------------" << endl;
                graph = create();
                start = graph;
                root = graph;
                break;
            }
            case 6:
            {
                previosRoot = root;
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
