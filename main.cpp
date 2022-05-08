#include <iostream>
#include "deque.h"

int main() {

    MyDeque<int> deque_1;
    int x = 11;
    int z = 33;
    MyDeque<int> o;
    o.push_back(34);
    o.push_front(10);
    o.push_front(23);


    std::cout << "\n\tUtworzono deque_1" << std::endl;

    deque_1.push_back(x);
    std::cout << "\n\tdeque_1 po operacji push_back(const T& item): ";
    deque_1.display();

    deque_1.push_back(12);
    std::cout << "\n\tdeque_1 po operacji push_back(T &&item): ";
    deque_1.display();

    deque_1.push_front(z);
    std::cout << "\n\tdeque_1 po operacji push_front(constT &item): ";
    deque_1.display();

    deque_1.push_front(44);
    std::cout << "\n\tDeque a po operacji push_front(T &&item): ";
    deque_1.display();

    int w = 5;
    deque_1.insert(10,w);
    std::cout << "\n\tdeque_1 po operacji insert(int pos, const T &item): ";
    deque_1.display();

    deque_1.insert(0, 89);
    std::cout << "\n\tdeque_1 po operacji insert(int pos,T &&item): ";
    deque_1.display();

    std::cout << "\n\tRozmiar deque_1 to: " << deque_1.size() << std::endl;

    deque_1.erase(10);
    std::cout << "\n\tdeque_1 po operacji erase(pos): ";
    deque_1.display();

    std::cout << "\n\tPierwszy elemement deque1 (head) to: " << deque_1.front() << ", ostatni zaś to:  " << deque_1.back() << std::endl;

    deque_1.pop_front();
    std::cout << "\n\tDeque deque_1 po operacji pop_front(): ";
    deque_1.display();

    deque_1.pop_back();
    std::cout << "\n\tDeque deque_1 po operacji pop_back(): ";
    deque_1.display();

    deque_1[0] = 9;
    std::cout << "\n\tDeque deque_1 po operacji T& operator[](int pos): ";
    deque_1.display();

    std::cout << "\n\tElement deque1[10] jest równy: " << deque_1[10] << std::endl;

    std::cout << "\n\tIndeks wartości  33 jest rówwny: " << deque_1.index(33) << std::endl;

    std::cout << "\n\tWywołanie konstruktora kopiujacego: MyDeque<int> deque_2(deque_1)";
    std::cout << "\n\tDeque_2: ";
    MyDeque<int> deque_2(deque_1);
    deque_2.display();

    MyDeque<int> deque_3(std::move(deque_2));
    std::cout <<"\n\tPo wywolaniu konstruktora przenoszacego MyDeque<int> deque_3(std::move(deque_2)):\n";
    deque_3.display();

    deque_3 = o;

    std::cout << "\n\tPo wywolaniu kopiujacego operatora przypisania deque_3 = o" << std::endl;
    deque_3.display();

    MyDeque<int> deque_4;
    std::cout << "\n\tPo wywolaniu kopiujacego operatora przypisania deque_4 = std::move(deque_3):" << std::endl;
    deque_4 = std::move(deque_3);
    deque_4.display();

    deque_4.clear();
    deque_4.display();

    return 0;
}
