#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello World and a Bogdan" << endl;
    for (int i = 1 ; i < 5; ++i) {
        cout << pow(i, 3);
        cout << "Последовательность" << endl;
    }
    auto f = []() { cout << "Hello"; };
    auto f = []() { cout << "Hello"; };


   //----------------------

    //Cikle ne ochen'
    return 0;
}

namespace  str {
class Max;
}

class str::Max{
public:
    explicit Max()
        :t(new int[3]) {}

private:
    int* t;
};
