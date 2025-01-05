#include <initializer_list>
#include <vector>
#include <ostream>
using namespace std;

namespace My
{
    template <typename T>
    class List
    {
    public:
        struct Node
        {
            Node() = default;

            Node(T val)
            {
                this->data = val;
            }
            bool operator==(const Node& other)
            {
                return this->data == other.data;
            }
            bool operator!=(const Node& other)
            {
                return this->data != other.data;
            }
            friend ostream& operator<<(ostream& out, const Node& node)
            {
                out << node.data;
                return out;
            }

            T data;
            Node* next = nullptr;
        };

        struct Iterator
        {
            using iterator_category = forward_iterator_tag;
            using value_type = Node;
            using difference_type = ptrdiff_t;
            using pointer = Node *;
            using reference = Node &;

            Iterator(pointer ptr) : ptr(ptr) {}

            Iterator& operator++()
            {
                this->ptr = this->ptr->next;
                return *this;
            }

            Iterator operator++(int)
            {
                Iterator tmp = *this;
                this->ptr = this->ptr.next;
                return tmp;
            }

            reference operator*() const
            {
                return *this->ptr;
            }

            pointer operator->() const
            {
                return this->ptr;
            }

            bool operator==(const Iterator &other) const
            {
                return this->ptr == other.ptr;
            }

            bool operator!=(const Iterator &other) const
            {
                return this->ptr != other.ptr;
            }

            pointer ptr;
        };
        List() = default;

        List(initializer_list<T> list)
        {
            Node* current = nullptr;

            for (auto item : list)
            {
                auto node =  new Node(item);

                if (this->head == nullptr)
                {
                    this->head = node;
                    current = this->head;
                    continue;
                }
                 
                current->next = node;
                current = current->next;
            }
        }

        void append(T val)
        {    
            auto node =  new Node(val);

            if(this->head == nullptr)
            {
                this->head = node;
                return;
            }

            auto prev = this->head;
            auto current = this->head;

            while(current)
            {
                prev = current;
                current = current->next;
            }
            prev->next = node;
        }

        void clear()
        {
            auto prev = this->head;
            auto current = this->head;
            
            while(current)
            {
                prev = current;
                current = current->next;
                delete prev;
            }
            this->head = nullptr;
        }

        vector<T> getList()
        {
            vector<T> list;
            auto current = this->head;
            
            while(current)
            {
                list.push_back(current->data);
                current = current->next;
            }
            return list;
        }

        List &operator=(List &rhs)
        {
            if (*this == rhs)
                return *this;

            this->clear();

            auto rlist = rhs.getList(); 
            
            for (auto i : rlist)
                this->append(i);

            return *this;
        }

        bool operator==(const List &rhs)
        {
            return this == &rhs;
        }
        
        size_t size()
        {
            Node* current = this->head;
            size_t size = 0;
            while (current)
            {
                size++;
                current = current->next;
            }
            return size;
        }

        Node& operator[](unsigned int index)
        {
            Node* current = this->head;
            unsigned int i = 0;
            while (current)
            {
                if (i == index)
                {
                    return *current;
                }
                current = current->next;
                i++;
            }
        }

        ~List()
        {
            this->clear();
        }

        Iterator begin()
        {
            return Iterator(this->head);
        }

        Iterator end()
        {
           return nullptr;
        }

    private:
        Node *head = nullptr;
    };
}