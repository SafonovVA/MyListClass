#include <iostream>
#include <ctime>
#include "SList.h"
using namespace std;

int main() {
    srand(time(0));
    SList<int> first, second;

    int size = rand() % 100;

    for (int i = 0; i<size; i++) {
        first.AddToHead(rand() % 10);
    }
    first.Show();

    first.DeleteFromHead();
    first.DeleteFromTail();
    first.Show();

    size = rand() % 100;
    for (int i = 0; i<size; i++) {
        second.AddToHead(rand() % 10);
    }
    second.Show();

    second.AddToTail(rand() % 10);
    second.Show();

    SList<int> third(second);
    third.Show();

    SList<int> fourth;
    fourth = first;
    fourth.Show();

    first.sort();
    first.Show();

    first.reverse();
    first.Show();

    size = fourth.size();
    for (int i = 0; i < size; i++) {
        int value = fourth[i];
        cout << value << " " << endl;
    }

    first.DeleteAt(3);
    first.Show();

    first.InsertAt(4, 4);
    first.Show();

    first.DeleteAll();
    first.Show();

    first.splice(third);
    first.Show();
    first.splice(fourth);
    first.Show();

    size_t result = first.Find(10);
    if (result != 0)
        cout << "The number ten is in position: " << result << endl;
    else
        cout << "Numbers ten not found" << endl;

    first.FindAndReplace(10, 1000);

    first.begin();
    while (first.next())
    {
        cout << first.get() << " ";
    }

    //cin.get();
    return 0;
}