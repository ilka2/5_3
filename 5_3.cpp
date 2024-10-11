#include <iostream>
#include <windows.h>

using namespace std;

template <class T>
class vector
{
    private:
        int now_size;
        int max_size;
        T* arr;

        void expansion_array()
        {
            max_size *= 2;
            int* array = new int[now_size]();

            for (int i = 0; i < now_size; i++)
            {
                array[i] = arr[i];
            }
            delete[] arr;

            arr = new int[max_size]();
            for (int i = 0; i < max_size; i++)
            {
                arr[i] = array[i];
            }

            delete[] array;
        }
    public:
        vector()
        {
            arr = new T[1];
            now_size = 0;
            max_size = 1;
        }

        ~vector()
        {
            delete[] arr;
        }

        void push_back(T value)
        {
            if (now_size == max_size)
            {
                expansion_array();
            }

            arr[now_size] = value;
            now_size++;
        }

        T at(int index)
        {
            return arr[index];
        }

        int size()
        {
            return now_size;
        }

        int capacity()
        {
            return max_size;
        }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i) << endl;
    }
    cout << "Занятый размер вектора: " << vec.size() << endl;
    cout << "Реальный размер вектора" << vec.capacity() << endl;

    return 0;
}