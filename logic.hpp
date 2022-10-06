#include <iostream>
#include <math.h>
#include <string>

using namespace std;

void printTools()
{
    cout << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "|                         МЕНЮ                                |" << endl;
    cout << "| 1)Получение количества элементов в структуре данных         |" << endl;
    cout << "| 2)Добавление элемента в структуру данных                    |" << endl;
    cout << "| 3)Вставка дочернего элемента для текущего элемента          |" << endl;
    cout << "| 4)Удаление текущего элемента структуры данных               |" << endl;
    cout << "| 5)Очистка структуры данных                                  |" << endl;
    cout << "| 6)Перемещение по элементам структуры данных                 |" << endl;
    cout << "| 7)Чтение информации из текущего элемента структуры данных   |" << endl;
    cout << "| 8)Выйти                                                     |" << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << endl;
}

int getTools()
{
    printTools();
    int numberTool = 0;
    cout << "Введите цифру: ";
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
    cout << "|                     Заполняем граф...                       |" << endl;
    cout << "---------------------------------------------------------------" << endl;
    struct Graph* tmp = fresh;

    string answer[5];

    cout << "Введите тип домашнего животного: ";
    cin >> answer[0];
    cout << "Введите породу домашнего животного: ";
    cin >> answer[1];
    cout << "Введите имя домашнего животного: ";
    cin >> answer[2];
    cout << "Введите преоблодающий цвет домашнего животного: ";
    cin >> answer[3];
    cout << "Введите пол домашнего животного: ";
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

    cout << "Вы желаете создать структуру данных граф('y' - да, 'n' - нет):" << endl;
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
        cout << "Не правильно введены данные!" << endl;
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
    cout << "|                   Граф успешно создан!                      |" << endl;
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
            cout << "Добавление не возможно достигнуто максимальное количество дочерних графов!" << endl;    
        }
    }
}

void getValue(struct Graph* graph)
{
    cout << endl;

    cout << "---------------------------------------------------------------" << endl;
    cout << "                      {{" << graph << "}}" << endl;
    cout << "Тип домашнего животного: " << graph->typeAnimal << endl;
    cout << "Порода домашнего животного: " << graph->race << endl;
    cout << "Имя домашнего животного: "  << graph->name << endl;
    cout << "Преоблодающий цвет домашнего животного: " << graph->mainColor << endl;
    cout << "Пол домашнего животного: " << graph->gender << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << endl;
}

struct Graph* changePosition(struct Graph* root)
{   
    struct Graph* startPosition = root;
    struct Graph* tmp = root;
    cout << "---------------------------------------------------------------" << endl;
    cout << "          Вы находитесь в {{" << root << "}} графе." << endl;
    cout << "---------------------------------------------------------------" << endl;

    int countChildren = 0;

    while (tmp->pointers[countChildren] != NULL)
    {
        countChildren++;
    }

    if (countChildren == 0)
    {
        cout << "---------------------------------------------------------------" << endl;
        cout << "       У графа нет дочерних элементов переход не возможен!" << endl;
        cout << "---------------------------------------------------------------" << endl;
    }
    else if (countChildren == 1)
    {
        cout << "У графа 1 дочерний элемент, перейти к нему('y' - да, 'n' - нет):" << endl;
        string answer;
        cin >> answer;
        if (answer == "y") 
        {
            tmp = tmp->pointers[0];
            cout << "---------------------------------------------------------------" << endl;
            cout << "                    Вы успешно поменяли граф!" << endl;
            cout << "---------------------------------------------------------------" << endl;
            countChildren = 0;
            return tmp;
        }
        else if (answer == "n")
        {
            cout << "Ну нет, так нет";
            return startPosition;
        }
        else
        {
            cout << "Введено не корректное значение!" << endl;
            changePosition(startPosition);
        }
    }
    else
    {
        int answer = 0;
        cout << "---------------------------------------------------------------" << endl;
        cout << "Выберите Граф к которому хотите перейти, всего дочерних графов = " << countChildren << endl;
        cout << "---------------------------------------------------------------" << endl;

        cout << "---------------------------------------------------------------" << endl;
        for (int i = 0; i < countChildren; i++)
        {
            cout << i+1 << ")" << root->pointers[i] << endl;
        }
        cout << "---------------------------------------------------------------" << endl;
        cout << "Выберите граф: ";
        cin >> answer;
        
        if (answer > 0 && answer <= countChildren)
        {
            cout << "---------------------------------------------------------------" << endl;
            cout << "               Вы успешно поменяли граф!" << endl;
            cout << "---------------------------------------------------------------" << endl;
            tmp = tmp->pointers[answer-1];
            countChildren = 0;
            return tmp;
        }
        else
        {
            answer = 0;
            cout << "Введено не корректное значение" << endl;
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
        cout << "      У графа нет дочерних элементов вставка невозможна!" << endl;
        cout << "---------------------------------------------------------------" << endl;
    }
    else if (countChildren == 1)
    {
        cout << "У графа один дочерний элемент выполнить вставку('y' - да, 'n' - нет)?" << endl;
        string answer;
        cin >> answer;
        if (answer == "y")
        {
            insert(root, root->pointers[0]);
        }
        else if (answer == "n") 
        {
            cout << "Ну нет, дак нет" << endl;
        }
        else 
        {
            cout << "Не корректно введенные данные" << endl;
        }
    }
    else if (countChildren > 1)
    {
        cout << "---------------------------------------------------------------" << endl;
        cout << "       У графа " << countChildren << "дочерних элементов   ";
        cout << "---------------------------------------------------------------" << endl;

        cout << "---------------------------------------------------------------" << endl;
        for (int i = 0; i < countChildren; i++)
        {
            cout << i+1 << ")" << root->pointers[i] << endl;
        }
        cout << "---------------------------------------------------------------" << endl;
        cout << "Выберите граф: ";
        int answer = 0;
        cin >> answer;
        insert(root, root->pointers[answer-1]);
    }
}

