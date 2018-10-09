#include <iostream>
#include <memory>
#include "../array_list/array_list.h"

int main(int argc, char const *argv[])
{

    size_t array_capacity = 100;
    // shared_ptr<ArrayList<int>> p_arr = make_shared<ArrayList<int>>(array_capacity);

    // ArrayList<int> *test = new ArrayList<int>(array_capacity);

    ArrayList<int> test(array_capacity);
    cout << test.capacity() << ", " << test.size() << endl;

    // ArrayList<int> arrayList(10);
    // cout << p_arr->capacity() << ", " << p_arr->size() << endl;

    return 0;
}
