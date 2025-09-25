#include <iostream>
using namespace std;

class Tensor {
public:
    void hello() {
        cout << "Hello from Tensor!" << endl;
    }
};

int main() {
    Tensor t;
    t.hello();
    return 0;
}
