#include "Solver.h"
using namespace std;


void sort(Student* students, Ski* skis, int l, int r);
void sortStudentsById(Student *students, Ski *skis, int l, int r);
void quickSort(Student *students, Ski *skis, int l, int r);


//You can add some methods in main.cpp file

int main()
{
    ReadWriter rw;

    Student* students = nullptr;
    Ski* skis = nullptr;
    int n;

    //Read n from file
    n = rw.readInt();

    //Create arrays
    students = new Student[n];
    skis = new Ski[n];

    //read Students and Skis from file
    rw.readStudents(students, n);
    rw.readSkis(skis, n);

    //Find pairs
    Solver s;
    s.findPairs(students, skis, n);

    //Write answer to file
    rw.writeStudentsAndSkis(students, skis, n);

    delete[] students;
    delete[] skis;
    return 0;
}


//You can add some methods in main.cpp file
//Задача реализовать этот метод, можно добавлять любые вспомогательные методы в этот файл.
void Solver::findPairs(Student* students, Ski* skis, int n)
{

    sort(students, skis, 0, n - 1);
    sortStudentsById(students, skis, 0, n - 1);
}

void print_arrays(Student* students, Ski* skis, int n)
{
    for (int i = 0; i < n; i++)
        cout << students[i].height << ";" << " ";
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << skis[i].length << ";" << " ";

    cout<<endl<<endl;
}



void sort(Student *students, Ski *skis, int l, int r)
{

    int i = l, j = r;
    int index = l;
    Student st = students[index]; //pivot для лыж, взятый из студентов
    int suit_ski = 0;

    //сортируем лыжи по pivot, взятый у студентов
    do{
        while(compare(st, skis[i]) == -1)
            ++i;
        while(compare(st, skis[j]) == 1)
            --j;
        if(i <= j)
        {
            std::swap(skis[i], skis[j]);

            if(compare(st, skis[i]) == 0)
                suit_ski = i;
            else if(compare(st, skis[j]) == 0)
                suit_ski = j;

            ++i;
            --j;
        }

    }while(i <= j);

//    for(suit_ski = l; suit_ski <= r; ++suit_ski)//для выбранного студента находим соотв. пару лыж
//        if(compare(st, skis[suit_ski]) == 0)
//            break;


    Ski ski = skis[suit_ski];//запоминаем подходящую пару лыж, как pivot

    //располагаем лыжи так, чтобы слева были все меньше, а справа - больше
    if(suit_ski < j)
        swap(skis[j], skis[suit_ski]);
    if(suit_ski > i)
        swap(skis[i], skis[suit_ski]);









//
//    cout<<st.height<<"; "<<ski.length<<endl;
//    print_arrays(students, skis, 6);





    i = l, j = r;
    //сортируем студентов по pivot, взятый у лыж
    do{
        while(compare(students[i], ski) == 1)
            ++i;
        while(compare(students[j], ski) == -1)
            --j;
        if(i <= j)
            std::swap(students[i++], students[j--]);
    }while(i <= j);

    for(index = l; index <= r; ++index)
        if(students[index].id == st.id)
            break;

    //ставим студента так, чтобы слева были все меньше, а справа - меньше
    if(index < j)
        swap(students[j], students[index]);
    if(index > i)
        swap(students[i], students[index]);




//    print_arrays(students, skis, 6);




    //запускаем сортировку для правых и левых отрезков от пивота
    //количество элементов слева, стоящих у студентов и лыж будет одинаково, тк
    //студенты разного роста (как и лыжи) и для каждого студента найдется лишь 1 пара лыж
    if(j > l)
        sort(students, skis, l, j);
    if(i < r)
        sort(students, skis, i, r);

}

void sortStudentsById(Student *students, Ski *skis, int l, int r)
{
    int i = l, j = r;
    Student pivot = students[l];

    do
    {
        while(students[i].id < pivot.id)
            ++i;

        while(students[j].id  > pivot.id)
            --j;

        if(i <= j)
        {
            swap(students[j], students[i]);
            swap(skis[j], skis[i]);
            ++i;
            --j;
        }

    }while(i <= j);

    if(j > l)
        sortStudentsById(students, skis, l, j);
    if(i < r)
        sortStudentsById(students, skis, i, r);

}

void quickSort(Student *students, Ski *skis, int l, int r)
{
    int mid = l;
    int index = rand()%(r-l+1) + l;
    Student st = students[index]; //pivot для лыж, взятый из студентов
    int i = l, j = r;
    while (mid <= j)
    {
        if (compare(st, skis[mid]) == -1)
            swap(skis[i++], skis[mid++]);
        else if (compare(st, skis[mid]) == 0)
            mid++;
        else if (compare(st, skis[mid]) == 1)
            swap(skis[mid], skis[j--]);
    }

    int suit_ski;
    for(suit_ski = l; suit_ski <= r; ++suit_ski)//для выбранного студента находим соотв. пару лыж
        if(compare(st, skis[suit_ski]) == 0)
            break;

    Ski ski = skis[suit_ski];

    Ski pivot = skis[suit_ski];
    mid = l;
    i = l, j = r;
    while (mid <= j)
    {
        if (compare(students[mid], pivot) == 1)
            swap(students[i++], students[mid++]);
        else if (compare(students[mid], pivot) == 0)
            mid++;
        else if (compare(students[mid], pivot) == -1)
            swap(students[mid], students[j--]);
    }



    print_arrays(students, skis, 5);



    //update i and j
    i--;
    j = mid; //or high-1

    if(i > l)
        quickSort(students, skis, l, i);
    if(j < r)
        quickSort(students, skis, j, r);
}
