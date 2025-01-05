#include <iostream>
#include <string>

namespace My
{
    class Singleton
    {
    public:
        static Singleton &getInstance()
        {
            static Singleton instance;
            return instance;
        }

        static void sayHello()
        {
            std::cout << getInstance().message << std::endl;
            std::cout << "Count: " << getInstance().count << std::endl;
            std::cout << "Object: " << &getInstance() << std::endl;
        }

        Singleton(const Singleton &) = delete;
        Singleton &operator=(Singleton &) = delete;

    private:
        Singleton() { count++; }
        int count = 0;
        std::string message = "Hello new world";
    };
}