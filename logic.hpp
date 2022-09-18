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
    printf("1)Получение количества элементов в структуре данных\n");
    printf("2)Добавление элемента в структуру данных\n");
    printf("3)Вставка дочернего элемента для текущего элемента\n");
    printf("4)Удаление текущего элемента структуры данных\n");
    printf("5)Очистка структуры данных\n");
    printf("6)Перемещение по элементам структуры данных\n");
    printf("7)Чтение информации из текущего элемента структуры данных\n");
}

int getTools()
{
    printTools();
    int numberTool;
    std::cin >> numberTool;
    return numberTool;
}

int getCountPointers(){
    printf("Введите количество дочерних элементов");
    int count;
    std::cin >> count;
    return count;
}

struct Graph* fillGraph(struct Graph* fresh)
{ 
    struct Graph* tmp = fresh;

    string answer[5];

    std::cout << "Введите тип домашнего животного\n" << std::endl;
    std::cin >> answer[0];
    std::cout << "Введите породу домашнего животного\n" << std::endl;
    std::cin >> answer[1];
    std::cout << "Введите имя домашнего животного\n" << std::endl;
    std::cin >> answer[2];
    std::cout << "Введите преоблодающий цвет домашнего животного\n" << std::endl;
    std::cin >> answer[3];
    std::cout << "Введите пол домашнего животного\n" << std::endl;
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