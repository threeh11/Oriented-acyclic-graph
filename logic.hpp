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
    printf("1)��������� ���������� ��������� � ��������� ������\n");
    printf("2)���������� �������� � ��������� ������\n");
    printf("3)������� ��������� �������� ��� �������� ��������\n");
    printf("4)�������� �������� �������� ��������� ������\n");
    printf("5)������� ��������� ������\n");
    printf("6)����������� �� ��������� ��������� ������\n");
    printf("7)������ ���������� �� �������� �������� ��������� ������\n");
}

int getTools()
{
    printTools();
    int numberTool;
    std::cin >> numberTool;
    return numberTool;
}

int getCountPointers(){
    printf("������� ���������� �������� ���������");
    int count;
    std::cin >> count;
    return count;
}

struct Graph* fillGraph(struct Graph* fresh)
{ 
    struct Graph* tmp = fresh;

    string answer[5];

    std::cout << "������� ��� ��������� ���������\n" << std::endl;
    std::cin >> answer[0];
    std::cout << "������� ������ ��������� ���������\n" << std::endl;
    std::cin >> answer[1];
    std::cout << "������� ��� ��������� ���������\n" << std::endl;
    std::cin >> answer[2];
    std::cout << "������� ������������� ���� ��������� ���������\n" << std::endl;
    std::cin >> answer[3];
    std::cout << "������� ��� ��������� ���������\n" << std::endl;
    std::cin >> answer[4];

    tmp->typeAnimal = answer[0];
    tmp->race = answer[1];
    tmp->name = answer[2];
    tmp->mainColor = answer[3];
    tmp->gender = answer[4];

    return tmp; 
}

struct Graph
{
    string typeAnimal;
    string race;
    string name;
    string mainColor;
    string gender;
    
    int N;
    int countChild;
    struct Graph* pointers[];
};

struct Graph* create()
{
    struct Graph* start = new Graph;
    start->countChild = getCountPointers();
    for (int i = 0; i < start->countChild; i++)
    {
        start->pointers[i] = NULL;
    }

    return start;
}

void amount(struct Graph* start)
{
    struct Graph* tmp = start;
    int count = 0;
    for(int i = 0; i < tmp->countChild; i++)
    {
        count++;
        if(tmp->pointers[i] != NULL)
        {
            count++;
            tmp = tmp->pointers[i];
            for(int i = 0; i < tmp->countChild; i++)
            {
                count++;
                if(tmp->pointers[i] != NULL)
                {
                    
                }
            }
        }
    }
}

void addGraph(struct Graph* tmp, string typeAnimal,
              string race,string name, 
              string mainColor, string gender)
{
    struct Graph* start = tmp; 
    struct Graph* fresh = new Graph;
    fresh = fillGraph(fresh);
    start->pointers[0] = fresh;
    
}