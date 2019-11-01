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
    SList(const SList<T> &Data) {// конструктор копирования
        count = Data.count;
        iterator = Data.iterator;
        if (count != 0) {
            data<T> *time = Data.first;
            for (begin(); end(); next()) {
                data<T> *value = new data<T>;
                value->Data = time->Data;
                value->next = time->next;
                time = time->next;
                if (iterator == 0) {
                    first = value;
                }
                else if (iterator + 1 == count) {
                    last = value;
                }
            }
        }
    }

    SList(SList<T> &&Data) noexcept {// конструктор перемещения
        count = Data.count;
        iterator = Data.iterator;
        if (count != 0) {
            data<T> *time = Data.first;
            for (begin(); end(); next()) {
                data<T> *value = new data<T>;
                value->Data = time->Data;
                value->next = time->next;
                time = time->next;
                if (iterator == 0) {
                    first = value;
                }
                else if (iterator + 1 == count) {
                    last = value;
                }
            }
        }
        Data.first = nullptr;
        Data.last = nullptr;
    }

    SList<T> &operator=(const SList<T> &Data) {// оператор равно копированием
        count = Data.count;
        iterator = Data.iterator;
        if (count != 0) {
            data<T> *time = Data.first;
            for (begin(); end(); next()) {
                data<T> *value = new data<T>;
                value->Data = time->Data;
                value->next = time->next;
                time = time->next;
                if (iterator == 0) {
                    first = value;
                }
                else if (iterator + 1 == count) {
                    last = value;
                }
            }
        }
        return *this;
    }

    SList<T> &operator=(SList<T> &&Data) noexcept {// оператор равно перемещением
        count = Data.count;
        iterator = Data.iterator;
        if (count != 0) {
            data<T> *time = Data.first;
            for (begin(); end(); next()) {
                data<T> *value = new data<T>;
                value->Data = time->Data;
                value->next = time->next;
                time = time->next;
                if (iterator == 0) {
                    first = value;
                }
                else if (iterator + 1 == count) {
                    last = value;
                }
            }
        }
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
    /*
    T front() {// возвращает первое значение
        return first->Data;
    }

    T back() {// возвращает последнее значение
        return last->Data;
    }
     */
    T DeleteFromHead() {// удаление первого элемента
        T val = first->Data;
        first = first->next;
        count--;
        return val;
    }

    T DeleteFromTail() {// удаление последнего элемента
        data<T> *value = first;
        for(this->begin(); iterator < count - 2; this->next()) {
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
    }

    void Show() {// отображение всех элементов
        for(this->begin(); this->end(); this->next()) {
            cout << "[" << iterator << "] = " << this->get();
        }
        cout << endl;
        iterator = 0;
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
    }

    T &get() {// Получить значение по текущей позиции итератора
        if (iterator == 0) {
            return first->Data;
        }
        else if (iterator == (count - 1)) {
            return last->Data;
        }
        else {
            data<T> *value = new data<T>;
            value = first;
            for(size_t i = 1; i <= iterator; i++) {
                value = value->next;
            }
            return value->Data;
        }
    }
/*
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
            prevValue->next = value;
            value->Data = Data;
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
        }
    }

    size_t Find(const T &Data) {// поиск элемента (0 в случае неудачи)
        data<T> *value = first;
        if (value->Data == Data) {
            return 0;
        }
        size_t now = 0;
        while(value->next) {
            now++;
            if (value->Data == Data) {
                return now;
            }
        }
        return 0;
    }

    size_t FindAndReplace(const T &Data, const T &replData) {// поиск и замена всех элементов
        data<T> *value = first;
        size_t now = 0;
        if (value->Data == Data) {
            value->Data = replData;
            now++;
        }
        while(value->next) {
            if (value->Data == Data) {
                value->Data = replData;
                now++;
            }
        }
        return now;
    }*/


    /*void reverse();								// переворот списка

    */
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

        }
        else if (typeid(T) == typeid(string)) {

        }
    }

    /*
void vstavka(int array[], int size) {
	for (int i = 1; i < size; i++) {
		for (int j = i, max; j > 0; j--) {
			if (array[j] < array[j - 1]) {
				max = array[j];
				array[j] = array[j - 1];
				array[j - 1] = max;
			}
		}
	}
}*/



    /*
    void splice(const SList<T>& Data);*/				// перемещает элементы из другого list

    ~SList() {
        delete first;
        delete last;
    }								// деструктор
};

/*
 * void PopBack(){
            if(this->phead!=0){
                //Указатель на последний элемент
                CNode * pNode= this->phead;
                //Указатель на пред последний элемент
                CNode * pPrev=this->phead;
                while(pNode->pNext){
                    pPrev=pNode;
                    pNode=pNode->pNext;
                }
                //Удаляем последний
                delete pNode;
                //Обноляем последний pNext
                pPrev->pNext=0;
            }
        }
        void Insert(int index,CNode * pNew){
            CNode * pNode=this->phead;
            CNode * pTmp=this->phead;
            for(int i=0;i<index-1;i++){
                pNode=pNode->pNext;
                pTmp=pNode->pNext;
            }
            pNode->pNext=pNew;
            pNew->pNext=pTmp;
        }
 *
 * struct data
{
    T Data;		// Данные
    data<T> *next;	// Адрес следующего элемента списка
};*/
/*data<T> *first;								// Адрес первого элемента списка
data<T> *last;								// Адрес последнего элемента списка
size_t count;								// Количество элементов в списке
size_t iterator;*/

#endif //LIST_SLIST_H
