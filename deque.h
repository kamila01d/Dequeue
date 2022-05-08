#include <iostream>
#include <cassert>
#include <cstring>
#include<cmath>
template <typename T>
class MyDeque {
    T* tab;
    int msize; // największa możliwa liczba elementów plus jeden
    int head; // pierwszy do pobrania
    int tail; // pierwsza wolna pozycja
public:
    MyDeque(int s=10) : msize(s+1), head(0), tail(0) {
        tab = new T[s+1];
        assert( tab != nullptr );
    } // default constructor
    ~MyDeque() { delete [] tab; }
    MyDeque(const MyDeque& other){
        head = other.head;
        tail = other.tail;
        msize = other.msize;

        tab = new T[msize];

        for(int  i = 0; i < msize; ++i)
            tab[i] = other.tab[i];


    }
    // copy constructor
    MyDeque(MyDeque&& other){
        head = other.head;
        tail = other.tail;
        msize = other.msize;
        tab = other.tab;

        other.head = 0;
        other.msize = 0;
        other.tail = 0;
        other.tab = nullptr;
    }
    // move constructor
    MyDeque& operator=(const MyDeque& other){
        delete [] tab;

        head = other.head;
        tail = other.tail;
        msize = other.msize;

        tab = new T[msize];

        for(int  i = head; i != tail; i=(i+1) % msize)
            tab[i] = other.tab[i];

        return *this;
    }
    // copy assignment operator, return *this
    MyDeque& operator=(MyDeque&& other){
        delete tab;

        head = other.head;
        tail = other.tail;
        msize = other.msize;
        tab = other.tab;

        other.head = 0;
        other.tail = 0;
        other.msize = 0;
        other.tab = nullptr;

        return *this;
    } // move assignment operator, return *this
    bool empty() const { return head == tail; }
    bool full() const { return (tail + 1) % msize == head; }
    int size() const { return (tail - head + msize) % msize; }
    int max_size() const { return msize-1; }
    void push_front(const T& item); // dodanie na początek O(1)
    void push_front(T&& item); // dodanie na początek O(1)
    void push_back(const T& item); // dodanie na koniec O(1)
    void push_back(T&& item); // dodanie na koniec O(1)
    T& front() { return tab[head]; } // zwraca poczatek
    T& back() { return tab[(tail + msize -1) % msize]; } // zwraca koniec
    void pop_front(); // usuwa początek kolejki O(1)
    void pop_back(); // usuwa koniec kolejki O(1)
    void clear(); // czyszczenie listy z elementow
    void display();
    // Operacje z indeksami.
    T& operator[](int pos); // podstawienie L[pos]=item
    const T& operator[](int pos) const; // odczyt L[pos]
    void erase(int pos);
    int index(const T& item); // jaki index na liscie (-1 gdy nie ma)
    void insert(int pos, const T& item); // inserts item before pos
    void insert(int pos, T&& item); // inserts item before pos
};
template <typename T>
void MyDeque<T>::push_front(const T& item) {
    head = (head + msize -1) % msize;
    tab[head] = item;
   // tail = (tail + 1) % msize;
}
template <typename T>
void MyDeque<T>::push_front(T &&item) {
    head = (head + msize -1) % msize;
    tab[head] = item;

}
template <typename T>
void MyDeque<T>::push_back(T &&item) {
    tab[tail] = item;
    tail = (tail + 1) % msize;
}
template <typename T>
void MyDeque<T>::push_back(const T& item) {
    tab[tail] = item;
    tail = (tail + 1) % msize;
}
template <typename T>
void MyDeque<T>::display() {
    std::cout << "\t";
    for (int i = head; i != tail; i = (i + 1) % msize) {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "\t";
}
template <typename T>
void MyDeque<T>::pop_front() {
    if(empty())
        return;
    else{

        for(int i = head; i != tail; i=(i+1) % msize)
        {
            tab[(i  ) % msize] = tab[(i + 1 + msize ) % msize];
        }
        tail = (tail + msize - 1) % msize;
    }
}
template <typename T>
void MyDeque<T>::pop_back() {
    if(empty())
        return;
    else{
        tab[tail-1 % msize] = 0;

        tail = (tail - 1) % msize;
    }
}
template <typename T>
void MyDeque<T>::clear() {
    if (empty())
        return;
    else{
        head = tail;
    }
}
template <typename T>
T& MyDeque<T>::operator[](int pos) {
    for(int i = head; i!= tail; i = (i+1)%msize)
    {
        if(i == pos)
        {

            T& ret = tab[pos];
            return ret;
            break;
        }
    }
    int ret = -1;
    T& rett = static_cast<T&>(ret);
    return rett;

}
template <typename T>
const T& MyDeque<T>::operator[](int pos) const {


    for(int i = head; i!= tail; i = (i+1)%msize)
    {
        if(i == pos)
        {
            return &tab[pos];
            break;
        }
    }
    int ret = -1;
    const T& rett = static_cast<const T&>(ret);
    return rett;
}
template<typename T>
void MyDeque<T>::erase(int pos) {
    assert(!empty());
    if (pos == back()) { pop_back(); }
    else if (pos == front())
    { pop_front();

    }

   else{


        for(int i = pos; i != tail; i=(i+1) % msize)
        {
            tab[(i ) % msize] = tab[(i + 1 + msize ) % msize];
        }
        tail = (tail + msize - 1) % msize;

}
}
template<typename T>
void MyDeque<T>::insert(int pos, const T &item) {
    assert(!full());
    if(pos == head) { push_front(item); }
    else if(pos == (tail )%msize){push_back(item);}


   else{
   int j = 0;
   int i = tail;
   tail = (tail + 1) % msize;
    do
    {
        tab[i] = tab[(head + i+1 )% msize];
      //  i = (i-1)%(msize-1);
        if(i-1 <=0)
        {

             i = (msize -j)%msize;
             j++;
        }
        else{
            i = (i-1)%(msize);
        }
    }while( i != pos);

    tab[pos] = item;

}}
template <typename T>
void MyDeque<T>::insert(int pos, T &&item) {
    assert(!full());
    if (pos == head) { push_front(item); }
    else if (pos == (tail) % msize) { push_back(item); }


    else {

        int j = 0;
        int i = tail;
        tail = (tail + 1) % msize;
        do {
            tab[i] = tab[(head + i + 1) % msize];
            if (i - 1 <= 0) {

                i = (msize - j) % msize;
                j++;
            } else {
                i = (i - 1) % (msize);
            }
        } while (i != pos);
        tab[pos] = item;

    }
}
template <typename T>
int MyDeque<T>::index(const T &item) {

    for(int i = head; i!= tail; i = (i+1)%msize)
    {
        if(tab[i] == item)
        {
            return i;
            break;
        }
    }
        return -1;
}

