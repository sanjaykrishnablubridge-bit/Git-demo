#include <iostream>
using namespace std;

class Tensor {
public:
    void hello() {
        cout << "Hello from Tensor!" << endl;
    }

    void add() { cout << "Add function" << endl; }
    void multiply() { cout << "Multiply function" << endl; }
    void subtract() { cout << "Subtract function" << endl; }
    void divide() { cout << "Divide function" << endl; }
};

int main() {
    Tensor t;
    t.hello();
    return 0;
}
