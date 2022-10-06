#include <iostream>
#include <math.h>
#include <string>

using namespace std;

void printTools()
{
    cout << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "|                         ����                                |" << endl;
    cout << "| 1)��������� ���������� ��������� � ��������� ������         |" << endl;
    cout << "| 2)���������� �������� � ��������� ������                    |" << endl;
    cout << "| 3)������� ��������� �������� ��� �������� ��������          |" << endl;
    cout << "| 4)�������� �������� �������� ��������� ������               |" << endl;
    cout << "| 5)������� ��������� ������                                  |" << endl;
    cout << "| 6)����������� �� ��������� ��������� ������                 |" << endl;
    cout << "| 7)������ ���������� �� �������� �������� ��������� ������   |" << endl;
    cout << "| 8)�����                                                     |" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << endl;
}

int getTools()
{
    printTools();
    int numberTool = 0;
    cout << "������� �����: ";
    cin >> numberTool;
    return numberTool;
}

struct Graph
{
    string typeAnimal;
    string race;
    string name;
    string mainColor;
    string gender;
    
    struct Graph* pointers[10];
};

struct Graph* fillGraph(struct Graph* fresh)
{
    cout << "---------------------------------------------------------------" << endl;
    cout << "|                     ��������� ����...                       |" << endl;
    cout << "---------------------------------------------------------------" << endl;
    struct Graph* tmp = fresh;

    string answer[5];

    cout << "������� ��� ��������� ���������: ";
    cin >> answer[0];
    cout << "������� ������ ��������� ���������: ";
    cin >> answer[1];
    cout << "������� ��� ��������� ���������: ";
    cin >> answer[2];
    cout << "������� ������������� ���� ��������� ���������: ";
    cin >> answer[3];
    cout << "������� ��� ��������� ���������: ";
    cin >> answer[4];

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

    cout << "�� ������� ������� ��������� ������ ����('y' - ��, 'n' - ���):" << endl;
    cin >> answer; 

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
        cout << "�� ��������� ������� ������!" << endl;
        exit(0);   
    }
    return NULL;
}

struct Graph* create()
{
    struct Graph* start = startCreate();
    start = fillGraph(start);

    cout << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "|                   ���� ������� ������!                      |" << endl;
    cout << "---------------------------------------------------------------" << endl;

    return start;
}

int amount(struct Graph* graph)
{
    int count = 0;

    if (graph == NULL)
    {
        return 0;
    }
    else if (graph != NULL)
    {
        count++;
    }
    for (int i = 0; i < 10; i++)
    {
        count += amount(graph->pointers[i]);
    }
    return count;
}

void addGraph(struct Graph* root)
{
    struct Graph* fresh = new Graph;

    fresh = fillGraph(fresh);

    for (int i = 0; i < 10; i++)
    {
        if (root->pointers[i] == NULL)
        {
            root->pointers[i] = fresh;
            break;
        }
        if (i == 9)
        {
            cout << "���������� �� �������� ���������� ������������ ���������� �������� ������!" << endl;    
        }
    }
}

void getValue(struct Graph* graph)
{
    cout << endl;

    cout << "---------------------------------------------------------------" << endl;
    cout << "                      {{" << graph << "}}" << endl;
    cout << "��� ��������� ���������: " << graph->typeAnimal << endl;
    cout << "������ ��������� ���������: " << graph->race << endl;
    cout << "��� ��������� ���������: "  << graph->name << endl;
    cout << "������������� ���� ��������� ���������: " << graph->mainColor << endl;
    cout << "��� ��������� ���������: " << graph->gender << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << endl;
}

struct Graph* changePosition(struct Graph* root)
{   
    struct Graph* startPosition = root;
    struct Graph* tmp = root;
    cout << "---------------------------------------------------------------" << endl;
    cout << "          �� ���������� � {{" << root << "}} �����." << endl;
    cout << "---------------------------------------------------------------" << endl;

    int countChildren = 0;

    while (tmp->pointers[countChildren] != NULL)
    {
        countChildren++;
    }

    if (countChildren == 0)
    {
        cout << "---------------------------------------------------------------" << endl;
        cout << "       � ����� ��� �������� ��������� ������� �� ��������!" << endl;
        cout << "---------------------------------------------------------------" << endl;
    }
    else if (countChildren == 1)
    {
        cout << "� ����� 1 �������� �������, ������� � ����('y' - ��, 'n' - ���):" << endl;
        string answer;
        cin >> answer;
        if (answer == "y") 
        {
            tmp = tmp->pointers[0];
            cout << "---------------------------------------------------------------" << endl;
            cout << "                    �� ������� �������� ����!" << endl;
            cout << "---------------------------------------------------------------" << endl;
            countChildren = 0;
            return tmp;
        }
        else if (answer == "n")
        {
            cout << "�� ���, ��� ���";
            return startPosition;
        }
        else
        {
            cout << "������� �� ���������� ��������!" << endl;
            changePosition(startPosition);
        }
    }
    else
    {
        int answer = 0;
        cout << "---------------------------------------------------------------" << endl;
        cout << "�������� ���� � �������� ������ �������, ����� �������� ������ = " << countChildren << endl;
        cout << "---------------------------------------------------------------" << endl;

        cout << "---------------------------------------------------------------" << endl;
        for (int i = 0; i < countChildren; i++)
        {
            cout << i+1 << ")" << root->pointers[i] << endl;
        }
        cout << "---------------------------------------------------------------" << endl;
        cout << "�������� ����: ";
        cin >> answer;
        
        if (answer > 0 && answer <= countChildren)
        {
            cout << "---------------------------------------------------------------" << endl;
            cout << "               �� ������� �������� ����!" << endl;
            cout << "---------------------------------------------------------------" << endl;
            tmp = tmp->pointers[answer-1];
            countChildren = 0;
            return tmp;
        }
        else
        {
            answer = 0;
            cout << "������� �� ���������� ��������" << endl;
            changePosition(startPosition);
        }
    }
    return tmp;
}

void removeGraph(struct Graph* graph)
{
    if (graph != NULL)
    {
        for (int i = 0; i < 10; i++)
        {
            removeGraph(graph->pointers[i]);
        }
    }
    delete graph;
}

void removeGraphs(struct Graph* start)
{
    if (start != NULL)
    {
        for (int i = 0; i < 10; i++)
        {
            removeGraphs(start->pointers[i]);
        }
    }
    delete start;
}

void insert(struct Graph* root, struct Graph* child)
{
    root->typeAnimal = child->typeAnimal;
    root->race = child->race;
    root->name = child->name;
    root->mainColor = child->mainColor;
    root->gender = child->gender;
}

void insertGraph(struct Graph* root)
{
    int countChildren = 0;
    for (int i = 0; i < 10; i++)
    {
        if (root->pointers[i] != NULL)
        {
            countChildren++;
        }
    }
    if (countChildren == 0)
    {
        cout << "---------------------------------------------------------------" << endl;
        cout << "      � ����� ��� �������� ��������� ������� ����������!" << endl;
        cout << "---------------------------------------------------------------" << endl;
    }
    else if (countChildren == 1)
    {
        cout << "� ����� ���� �������� ������� ��������� �������('y' - ��, 'n' - ���)?" << endl;
        string answer;
        cin >> answer;
        if (answer == "y")
        {
            insert(root, root->pointers[0]);
        }
        else if (answer == "n") 
        {
            cout << "�� ���, ��� ���" << endl;
        }
        else 
        {
            cout << "�� ��������� ��������� ������" << endl;
        }
    }
    else if (countChildren > 1)
    {
        cout << "---------------------------------------------------------------" << endl;
        cout << "       � ����� " << countChildren << "�������� ���������   ";
        cout << "---------------------------------------------------------------" << endl;

        cout << "---------------------------------------------------------------" << endl;
        for (int i = 0; i < countChildren; i++)
        {
            cout << i+1 << ")" << root->pointers[i] << endl;
        }
        cout << "---------------------------------------------------------------" << endl;
        cout << "�������� ����: ";
        int answer = 0;
        cin >> answer;
        insert(root, root->pointers[answer-1]);
    }
}

