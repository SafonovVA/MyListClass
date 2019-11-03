//
// Created by dev2 on 01.11.2019.
//

#ifndef LIST_SLIST_H
#define LIST_SLIST_H


#include <iostream>
#include <string>
#include <ctime>
using namespace std;

template<typename T>
struct data
{
    T Data;		// Данные
    data<T> *next;	// Адрес следующего элемента списка
};

template<typename T>
class SList {
    data<T> *first;								// Адрес первого элемента списка
    data<T> *last;								// Адрес последнего элемента списка
    size_t count;								// Количество элементов в списке
    size_t iterator;							// Итератор
public:
    SList() {// конструктор по умолчанию
        first = nullptr;
        last = nullptr;
        count = 0;
        iterator = 0;
    }

    SList(const SList<T> &Data) : SList() {// конструктор копирования
        size_t size = Data.count;
        data<T> *time = Data.first;
        for (size_t i = 0; i < size; i++) {
            AddToTail(time->Data);
            time = time->next;
        }
    }

    SList(SList<T> &&Data) noexcept {// конструктор перемещения
        count = Data.count;
        iterator = Data.iterator;
        first = Data.first;
        last = Data.last;
        Data.first = nullptr;
        Data.last = nullptr;
    }

    SList<T> &operator=(const SList<T> &Data) {// оператор равно копированием
        first = nullptr;
        last = nullptr;
        count = 0;
        iterator = 0;
        size_t size = Data.count;
        data<T> *time = Data.first;
        for (size_t i = 0; i < size; i++) {
            AddToTail(time->Data);
            time = time->next;
        }
        return *this;
    }

    SList<T> &operator=(SList<T> &&Data) noexcept {// оператор равно перемещением
        count = Data.count;
        iterator = Data.iterator;
        first = Data.first;
        last = Data.last;
        Data.first = nullptr;
        Data.last = nullptr;
        return *this;
    }

    T &operator[](size_t pos) {// оператор индексирования
        if (pos == 0) {
            return first->Data;
        }
        else if (pos == (count - 1)) {
            return last->Data;
        }
        else {
            data<T> *value = new data<T>;
            value = first;
            for(iterator = 1; iterator <= pos; this->next()) {
                value = value->next;
            }
            iterator = 0;
            return value->Data;
        }
    }

    void AddToHead(const T &Data) {// добавление элемента в начало
        if (first == nullptr) {
            data<T> *value = new data<T>;
            first = value;
            last = value;
            value->Data = Data;
            value->next = nullptr;
        }
        else {
            data<T> *value = new data<T>;
            value->next = first;
            value->Data = Data;
            first = value;
        }
        count++;
    }

    void AddToTail(const T &Data) {// добавление элемента в конец
        if (first == nullptr) {
            data<T> *value = new data<T>;
            first = value;
            last = value;
            value->Data = Data;
            value->next = nullptr;
        }
        else {
            data<T> *value = new data<T>;
            last->next = value;
            last = value;
            value->Data = Data;
            value->next = nullptr;
        }
        count++;
    }

    T front() {// возвращает первое значение
        return first->Data;
    }

    T back() {// возвращает последнее значение
        return last->Data;
    }

    T DeleteFromHead() {// удаление первого элемента
        T val = first->Data;
        first = first->next;
        count--;
        return val;
    }

    T DeleteFromTail() {// удаление последнего элемента
        data<T> *value = first;
        for(begin(); iterator < count - 2; next()) {
            value = value->next;
        }
        T val = value->Data;
        value->next = nullptr;
        last = value;
        count--;
        iterator = 0;
        return val;
    }

    void DeleteAll() {// удаление всех элементов
        count = 0;
        first = nullptr;
        last = nullptr;
        iterator = 0;
    }

    void Show() {// отображение всех элементов
        if (count == 0) {
            cout << "List is Empty\n";
        }
        else {
            for (this->begin(); this->end(); this->next()) {
                cout << "[" << iterator << "] = " << this->get() << ", ";
            }
            cout << endl;
            iterator = 0;
        }
    }

    size_t size() {// количество элементов
        return count;
    }

    void begin() {// Возвращает итератор на первый элемент
        iterator = 0;
    }

    bool end() {// Возвращает итератор на элемент, следующий за последним
        return iterator != count;
    }

    bool next() {// Перемещает итератор на следующий элемент
        iterator++;
        return iterator != count;
    }

    T &get() {// Получить значение по текущей позиции итератора
        if (iterator == 0) {
            return first->Data;
        }
        else if (iterator == (count - 1)) {
            return last->Data;
        }
        else {
            data<T> *value = first;
            for(size_t i = 1; i <= iterator; i++) {
                value = value->next;
            }
            return value->Data;
        }
    }

    void InsertAt(size_t pos, const T &Data) {// вставка в указанную позицию
        if (pos == 0) {
            this->AddToHead(Data);
        }
        else if ((count - 1) == pos) {
            this->AddToTail(Data);
        }
        else if (pos < 0 || pos >= count) {}
        else {
            data<T> *value = first;
            data<T> *prevValue = value;
            for(iterator = 1; iterator <= pos; this->next()) {
                prevValue = value;
                value = value->next;
            }
            data<T> *now = new data<T>;
            now->Data = Data;
            now->next = value;
            prevValue->next = now;
            count++;
        }
    }

    void DeleteAt(size_t pos) {// удаление по указанной позиции
        if (pos < 0 || pos >= count) {}
        else if (pos == 0) {
            this->DeleteFromHead();
        }
        else if (pos == (count - 1)) {
            this->DeleteFromTail();
        }
        else {
            data<T> *value = first;
            data<T> *prevValue = value;
            for(iterator = 1; iterator <= pos; this->next()) {
                prevValue = value;
                value = value->next;
            }
            prevValue->next = value->next;
            value = nullptr;
            count--;
        }
    }

    size_t Find(const T &Data) {// поиск элемента (0 в случае неудачи)
        data<T> *value = first;
        size_t now = 0;
        for (begin(); end(); next()) {
            now++;
            if (value->Data == Data) {
                return iterator;
            }
            value = value->next;
        }
        return 0;
    }

    size_t FindAndReplace(const T &Data, const T &replData) {// поиск и замена всех элементов
        data<T> *value = first;
        size_t now = 0;
        for (begin(); end(); next()) {
            if (value->Data == Data) {
                value->Data = replData;
                now++;
            }
            value = value->next;
        }
        return now;
    }


    void reverse(){// переворот списка
        if (typeid(T) == typeid(int) ||
            typeid(T) == typeid(float) ||
            typeid(T) == typeid(double) ||
            typeid(T) == typeid(unsigned long int) ||
            typeid(T) == typeid(long int) ||
            typeid(T) == typeid(unsigned int) ||
            typeid(T) == typeid(unsigned short int) ||
            typeid(T) == typeid(short int) ||
            typeid(T) == typeid(long long))
        {
            T *array = new T[count];
            data<T> *time = first;
            for (begin(); end(); next()) {
                array[iterator] = time->Data;
                time = time->next;
            }
            size_t size = count;
            DeleteAll();

            T x;
            for(int i = 0; i < size - i - 1; i++) {
                x = array[i];
                array[i] = array[size - i - 1];
                array[size - i - 1] = x;
            }

            for (begin(); iterator < size; next()) {
                AddToTail(array[iterator]);
            }
        }
    }

    void sort(){// сортирует элементы
        if (typeid(T) == typeid(int) ||
            typeid(T) == typeid(float) ||
            typeid(T) == typeid(double) ||
            typeid(T) == typeid(unsigned long int) ||
            typeid(T) == typeid(long int) ||
            typeid(T) == typeid(unsigned int) ||
            typeid(T) == typeid(unsigned short int) ||
            typeid(T) == typeid(short int) ||
            typeid(T) == typeid(long long))
        {
            T *array = new T[count];
            data<T> *time = first;
            for (begin(); end(); next()) {
                array[iterator] = time->Data;
                time = time->next;
            }
            size_t size = count;
            DeleteAll();
            for (size_t i = 1; i < size; i++) {
                for (int j = i, max; j > 0; j--) {
                    if (array[j] < array[j - 1]) {
                        max = array[j];
                        array[j] = array[j - 1];
                        array[j - 1] = max;
                    }
                }
            }
            for (begin(); iterator < size; next()) {
                AddToTail(array[iterator]);
            }
        }
    }

    void splice(SList<T>& Data){// перемещает элементы из другого list
        if (count == 0) {
            count = Data.count;
            first = Data.first;
        }
        else {
            count += Data.count;
            last->next = Data.first;
        }
        last = Data.last;
        Data.DeleteAll();
     }


    ~SList() {// деструктор
        delete first;
        delete last;
    }
};

#endif //LIST_SLIST_H
