#ifndef ARRAY_H
#define ARRAY_H

class Array {
  public:
    Array();

    int getSize();
    int at(int position);

    int* begin();
    int* end();

    void append(int value);
    void pop();
    void print();
    void printMore();
    void fill(std::initializer_list<int> valuse);
    void clear();

    ~Array();

  private:
    int *array;
    int size;
};

#endif