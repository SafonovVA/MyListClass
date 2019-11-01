#include <iostream>
#include <ctime>
#include "SList.h"
using namespace std;

int main() {
    srand(time(0));
    SList<int> first, second;

    int size = 5;
    first.AddToTail(1);
    first.AddToTail(2);
    first.AddToHead(3);
    first.AddToHead(4);
    first.AddToHead(5);

    cout << "\nfirst" << endl;
    first.Show();

    //cout << endl << first[3];

    for (int i = 0; i<size; i++) {
        first.AddToHead(rand() % 10);
    }
    cout << "\nfirst" << endl;
    first.Show();

    first.DeleteFromHead();
    first.DeleteFromTail();
    cout << "\nfirst" << endl;
    first.Show();

    size = rand() % 10;
    for (int i = 0; i<size; i++) {
        second.AddToHead(rand() % 10);
    }
    cout << "\nsecond" << endl;
    second.Show();

    second.AddToTail(rand() % 10);
    cout << "\nsecond" << endl;
    second.Show();

    SList<int> third(second);
    cout << "\nthird" << endl;
    third.Show();

    SList<int> fourth;
    fourth = first;
    cout << "\nfourth" << endl;
    fourth.Show();

    first.sort();
    cout << "\nfirst" << endl;
    first.Show();

    first.reverse();
    cout << "\nfirst" << endl;
    first.Show();

    cout << "\nSomeNew" << endl;
    size = fourth.size();
    for (int i = 0; i < size; i++) {
        int value = fourth[i];
        cout << value << " " << endl;
    }
    cout << "\nSomeNew2 first" << endl;
    first.Show();
    first.DeleteAt(3);
    first.Show();
    cout << "\nSomeNew3 first" << endl;
    first.InsertAt(4, 99);
    first.Show();
    cout << "\nSomeNew3 first" << endl;
    //first.DeleteAll();
    first.Show();
    cout << "\nSomeNew3 first + third" << endl;
    first.Show();
    third.Show();
    first.splice(third);
    first.Show();
    first.splice(fourth);
    first.Show();

    /*size_t result = first.Find(10);
    if (result != 0)
        cout << "The number ten is in position: " << result << endl;
    else
        cout << "Numbers ten not found" << endl;

    first.FindAndReplace(10, 1000);

    first.begin();
    while (first.next())
    {
        cout << first.get() << " ";
    }*/

    //cin.get();
    return 0;
}