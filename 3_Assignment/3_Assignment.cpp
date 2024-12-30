#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class SimpleVector
{
private:
    T* data;
    int currentSize;
    int currentCapacity;

    void resize(int newCapacity)
    {
        if (newCapacity <= currentCapacity) return;

        T* newData = new T[newCapacity];

        for (int i = 0; i < currentSize; i++)
        {
            newData[i] = data[i];
        }

        delete[] data;

        data = newData;
        currentCapacity = newCapacity;

    }

public:
    SimpleVector(int capacity = 10) : data(new T[capacity]), currentCapacity(capacity), currentSize(0) {}
    SimpleVector(const SimpleVector& other) 
        : data(new T[other.currentCapacity]), currentCapacity(other.currentCapacity), currentSize(other.currentSize) 
    {
        for (int i = 0; i < currentSize; i++)
        {
            data[i] = other.data[i];
        }
    }
    ~SimpleVector() { delete[] data; }

    void push_back(const T& value) 
    {
        if (currentCapacity <= currentSize)
        {
            resize(currentSize + 5);
        }
        data[currentSize++] = value;
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
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void sortData()
    {
        if (currentSize > 1)
        {
            sort(data, data + currentSize);
        }
    }
};

int main()
{
    SimpleVector<int> sv(2);
    sv.push_back(10);
    sv.push_back(5);
    sv.push_back(15);
    sv.sortData();
    sv.pop_back();
    sv.printArray();

    SimpleVector<int> svCopy(sv);
    svCopy.push_back(20);
    svCopy.printArray();

    sv.printArray();

    return 0;
}