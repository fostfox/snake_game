#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello World and a Bogdan" << endl;
    for (int i = 1 ; i < 5; ++i) {
        cout << pow(i, 2);
        cout << "Последовательность Фиббоначи" << endl;
    }
    auto f = []() { cout << "Hello"; };
    auto f = []() { cout << "Hello"; };

    //Cikle ne ochen'
    return 0;
}
