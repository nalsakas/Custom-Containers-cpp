#include <iostream>
#include <algorithm>
using namespace std;

#include "Singleton.h"
#include "Array.h"
#include "List.h"

int main()
{
    My::Singleton::sayHello();
    My::Singleton::sayHello();
    My::Singleton::sayHello();

    My::Array<int> ar = {0, 1, 2, 3, 4, 5, 6};

    for (int i : ar)
    {
        cout << i << " ";
    }
    cout << endl;

    for_each(ar.begin(), ar.end(), [](int&x){return x = x * x;});

    for (int i : ar)
    {
        cout << i << " ";
    }
    cout << endl;


    My::List<int> list = {1, 2, 3, 4, 5};
    list.append(6);
    list.append(7);
    
    for (auto i : list.getList())
    {
        cout << i << " ";
    }
    cout << endl;

    list.clear();
    list.append(9);
    list.append(8);

    My::List<int> list2;
    list2 = list;

    for(auto i : list2)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}