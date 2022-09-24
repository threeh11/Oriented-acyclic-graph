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

int getCountPointers(){
    printf("������� ���������� �������� ���������: ");
    int count;
    std::cin >> count;
    if (count > 0 && count < 10)
    {
        return count;
    }
    else 
    {
        std::cout << "������������ ����!" << std::endl;
        exit(0);
    }
}

struct Graph
{
    string typeAnimal;
    string race;
    string name;
    string mainColor;
    string gender;
    
    int countChild;
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
    start->countChild = getCountPointers();
    start = fillGraph(start);

    for (int i = 0; i < start->countChild; i++)
    {
        start->pointers[i] = NULL;
    }

    std::cout << "���� ������� ������!" << std::endl;

    return start;
}

int amount(struct Graph* graph, int count)
{
    int countGraph = count;
    if(graph != NULL){
        struct Graph* tmp = graph;

        for(int i = 0; i < tmp->countChild; i++)
        {
            countGraph++;
            amount(tmp->pointers[i], countGraph);
        } 
    }
    else
    {
        return countGraph - 1;
    }
}

void addGraph(struct Graph* tmp)
{
    struct Graph* graph = tmp; 
    struct Graph* fresh = new Graph;
    bool flag = false;

    fresh->countChild = getCountPointers();
    fresh = fillGraph(fresh);

    for (int i = 0; i < graph->countChild; i++)
    {
        if (graph->pointers[i] == NULL && flag == false)
        {
            flag = true;
            graph->pointers[i] = fresh;
            std::cout << "���� ������� ������!" << std::endl;   
        }
    }
    if (flag == false)
    {
        std::cout << "���� ��� ��������!" << std::endl;
    }
}

void getValue(struct Graph* graph)
{
    std::cout << std::endl;
    std::cout << "��� ��������� ���������: " << graph->typeAnimal << std::endl;
    std::cout << "������ ��������� ���������: " << graph->race << std::endl;
    std::cout << "��� ��������� ���������: "  << graph->name<< std::endl;
    std::cout << "������������� ���� ��������� ���������: " << graph->mainColor << std::endl;
    std::cout << "��� ��������� ���������: " << graph->gender << std::endl;
    std::cout << std::endl;
}

struct Graph* changePosition(struct Graph* root)
{  
    struct Graph* tmp = root;
    int countChildren = 0;

    for (int i = 0; i < tmp->countChild; i++)
    {
        if (tmp->pointers[i] != NULL)
        {
            countChildren++;        
        }
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
            return tmp;
        }
        else
        {
            std::cout << "������� �� ���������� ��������!" << std::endl;
            changePosition(tmp);
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
            tmp = tmp->pointers[answer];
        }
        else
        {
            answer = 0;
            std::cout << "������� �� ���������� ��������" << std::endl;
            changePosition(tmp);
        }

        return tmp;
    }
}

void removeGraph(struct Graph* graph)
{
    struct Graph* tmp = graph;
    std::cout << "��������� �������� � " << tmp << " �����" << endl;
    delete graph;

    for (int i = 0; i < tmp->countChild; i++)
    {
        tmp = tmp->pointers[i];
        delete tmp; 
    }
    
}

void removeGraphs(struct Graph* root)
{
    struct Graph* tmp = root;
    std::cout << "��������� �������� ��������� ������" << endl;
    delete root;

    for (int i = 0; i < tmp->countChild; i++)
    {
        tmp = tmp->pointers[i];
        delete tmp; 
    }
    
}

void insertGraph(struct Graph* root)
{
    
}