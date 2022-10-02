#include <iostream>
#include <math.h>
#include <string>

using namespace std;

void setRussianLangue()
{
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
}

void printTools()
{
    std::cout << std::endl;
    printf("1)��������� ���������� ��������� � ��������� ������\n");
    printf("2)���������� �������� � ��������� ������\n");
    printf("3)������� ��������� �������� ��� �������� ��������\n");
    printf("4)�������� �������� �������� ��������� ������\n");
    printf("5)������� ��������� ������\n");
    printf("6)����������� �� ��������� ��������� ������\n");
    printf("7)������ ���������� �� �������� �������� ��������� ������\n");
    printf("8)�����\n");
    std::cout << std::endl;
}

int getTools()
{
    printTools();
    int numberTool;
    std::cin >> numberTool;
    return numberTool;
}

struct Graph
{
    string typeAnimal;
    string race;
    string name;
    string mainColor;
    string gender;
    
    struct Graph* pointers[];
};

struct Graph* fillGraph(struct Graph* fresh)
{ 
    struct Graph* tmp = fresh;

    string answer[5];

    std::cout << "������� ��� ��������� ���������: ";
    std::cin >> answer[0];
    std::cout << "������� ������ ��������� ���������: ";
    std::cin >> answer[1];
    std::cout << "������� ��� ��������� ���������: ";
    std::cin >> answer[2];
    std::cout << "������� ������������� ���� ��������� ���������: ";
    std::cin >> answer[3];
    std::cout << "������� ��� ��������� ���������: ";
    std::cin >> answer[4];

    tmp->typeAnimal = answer[0];
    tmp->race = answer[1];
    tmp->name = answer[2];
    tmp->mainColor = answer[3];
    tmp->gender = answer[4];

    for (int i = 0; i < 10; i++)
    {
        tmp->pointers[i] = NULL;
    }

    return tmp; 
}

struct Graph* startCreate()
{
    string answer;
    std::cout << "�� ������� ������� ��������� ������ ����('y' - ��, 'n' - ���):" << std::endl;
    std::cin >> answer; 
    if (answer == "y")
    {
        struct Graph* start = new Graph;
        return start;
    }
    else if (answer == "n")
    {
        exit(0);
    }
    else
    {
        std::cout << "�� ��������� ������� ������!" << std::endl;
        startCreate();    
    }
}

struct Graph* create()
{
    struct Graph* start = startCreate();
    start = fillGraph(start);

    std::cout << "���� ������� ������!" << std::endl;

    return start;
}

int amount(struct Graph* graph, int countGraph)
{
    int count = countGraph;
    count++;
    if (graph->pointers[0] != NULL)
    {
        int childGraph = 0;
        while (graph->pointers[childGraph] != NULL)
        {
            amount(graph->pointers[childGraph], count);
            childGraph++;
        }
    }
    return count;
}

void addGraph(struct Graph* root)
{
    struct Graph* graph = root;
    struct Graph* fresh = new Graph;

    fresh = fillGraph(fresh);

    int childGraph = 0;
    do {
        if (graph->pointers[childGraph] == NULL)
        {
            graph->pointers[childGraph] = fresh;
            break;
        }
            childGraph++;
    } while (graph->pointers[childGraph] != NULL);
}

void getValue(struct Graph* graph)
{
    std::cout << std::endl;
    std::cout << graph << std::endl;
    std::cout << "��� ��������� ���������: " << graph->typeAnimal << std::endl;
    std::cout << "������ ��������� ���������: " << graph->race << std::endl;
    std::cout << "��� ��������� ���������: "  << graph->name<< std::endl;
    std::cout << "������������� ���� ��������� ���������: " << graph->mainColor << std::endl;
    std::cout << "��� ��������� ���������: " << graph->gender << std::endl;
    std::cout << std::endl;
}

struct Graph* changePosition(struct Graph* root)
{   
    struct Graph* startPosition = root;
    struct Graph* tmp = root;

    std::cout << "�� ���������� � " << tmp << " �����." << std::endl;

    int countChildren = 0;

    while (tmp->pointers[countChildren] != NULL)
    {
        std::cout << tmp->pointers[countChildren] << std::endl;
        countChildren++;
    }

    if (countChildren == 0)
    {
        std::cout << "� ����� ��� �������� ��������� ������� �� ��������!" << std::endl;
    }
    else if (countChildren == 1)
    {
        std::cout << "� ����� 1 �������� �������, ������� � ����('y' - ��, 'n' - ���):" << std::endl;
        string answer;
        std::cin >> answer;
        if (answer == "y") 
        {
            tmp = tmp->pointers[0];
            std::cout << "�� ������� �������� ����!" << std::endl;
            countChildren = 0;
            return tmp;
        }
        else if (answer == "n")
        {
            std::cout << "�� ���, ��� ���";
            return startPosition;
        }
        else
        {
            std::cout << "������� �� ���������� ��������!" << std::endl;
            changePosition(startPosition);
        }
    }
    else
    {
        int answer;
        std::cout << "�������� ���� � �������� ������ �������, ����� �������� ������ = " << countChildren << std::endl;
        std::cin >> answer;
        
        if (answer > 0 && answer <= countChildren)
        {
            std::cout << "�� ������� �������� ����!" << std::endl;
            tmp = tmp->pointers[answer-1];
            countChildren = 0;
            return tmp;
        }
        else
        {
            answer = 0;
            std::cout << "������� �� ���������� ��������" << std::endl;
            changePosition(startPosition);
        }
        return tmp;
    }
}

void removeGraph(struct Graph* graph)
{
    if (graph->pointers[0] != NULL)
    {
        int i = 0;
        while (graph->pointers[i] != NULL)
        {
            removeGraph(graph->pointers[i]);
            i++;
        }
    }
    else 
    {
        delete graph;   
    }
    std::cout << "��������� �������� �����" << endl;

}

void removeGraphs(struct Graph* start)
{
    if (start->pointers[0] != NULL)
    {
        int i = 0;
        while (start->pointers[i] != NULL)
        {
            removeGraphs(start->pointers[i]);
            i++;
        }
    }
    else 
    {
        delete start;   
    }
    std::cout << "��������� �������� ��������� ������" << endl;
}

void insertGraph(struct Graph* root)
{
    
}