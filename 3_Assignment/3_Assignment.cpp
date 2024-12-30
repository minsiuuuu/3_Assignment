#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class SimpleVector
{
private:
    T* data;
    int currentSize;
    int currentCapacity;
    void resize();

public:
    SimpleVector(int capacity = 10) : data(new T[capacity]), currentCapacity(capacity), currentSize(0) {}
    ~SimpleVector() { delete[] data; }

    void push_back(const T& value) 
    {
        if (currentCapacity > currentSize)
        {
            data[currentSize++] = value;
        }
    }
    void pop_back() 
    {
        if (currentSize > 0)
        {
            --currentSize;
        }
    }
    int size() const { return currentSize; }
    int capacity() const { return currentCapacity; }

    void printArray() const
    {
        for (int i = 0; i < currentSize; i++)
        {
            cout << data[i] << endl;
        }
    }
};

int main()
{
    SimpleVector<int> sv(2);
    sv.push_back(10);
    sv.push_back(5);
    sv.push_back(15);
    sv.pop_back();
    sv.printArray();

    return 0;
}