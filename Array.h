#include <initializer_list>
using namespace std;

namespace My
{
    template <typename T>
    class Array
    {
    public:
        struct Iterator
        {
            using iterator_category = forward_iterator_tag;
            using value_type = T;
            using difference_type = ptrdiff_t;
            using pointer = T *;
            using reference = T &;

            Iterator(T *ptr) : ptr(ptr) {}

            Iterator& operator++()
            {
                ++ptr;
                return *this;
            }

            Iterator operator++(int)
            {
                Iterator tmp = *this;
                this->ptr++;
                return tmp;
            }

            reference operator*() const
            {
                return *ptr;
            }

            pointer operator->() const
            {
                return ptr;
            }

            bool operator==(const Iterator &other) const
            {
                return ptr == other.ptr;
            }

            bool operator!=(const Iterator &other) const
            {
                return !(*this == other);
            }

            T *ptr;
        };

        Array() = default;

        Array(initializer_list<T> list)
        {
            this->data = new T[list.size()];
            this->m_size = list.size();

            size_t i = 0;
            for (auto it = list.begin(); it != list.end(); it++)
            {
                data[i] = *it;
                i++;
            }
        }

        Array(Array& rhs)
        {
            if (*this == rhs)
                return;

            delete[] this->data;
            this->data = new T[rhs.size()];
            this->m_size = rhs.size();

            for (size_t i = 0; i < rhs.size(); i++)
            {
                this->data[i] = rhs.data[i];
            }
        }

        Array(Array&& rhs)
        {
            if (*this == rhs)
                return;

            delete[] this->data;
            this->data = rhs.data;
            this->m_size = rhs.m_size;
            rhs.data = nullptr;
            rhs.m_size = 0;
        }

        bool operator==(Array &rhs)
        {
            return this == &rhs;
        }

        Array &operator=(Array &rhs)
        {
            if (*this == rhs)
                return *this;

            delete[] this->data;
            this->data = new T[rhs.size()];
            this->m_size = rhs.size();

            for (size_t i = 0; i < rhs.size(); i++)
            {
                this->data[i] = rhs.data[i];
            }

            return *this;
        }

        T& operator[](unsigned int index)
        {
            return this->data[index];
        }

        size_t size()
        {
            return this->m_size;
        }

        ~Array()
        {
            delete[] this->data;
            this->m_size = 0;
        }

        Iterator begin()
        {
            return Iterator(this->data);
        }

        Iterator end()
        {
            return Iterator(this->data + this->m_size);
        }

    private:
        T *data = nullptr;
        size_t m_size = 0;
    };
}