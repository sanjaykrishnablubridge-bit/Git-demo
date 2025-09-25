#include <iostream>
#include <vector>
using namespace std;

class Tensor {
private:
    vector<float> data;  // simple 1D tensor

public:
    // Constructor
    Tensor(const vector<float>& values) : data(values) {}

    // Print tensor
    void print() const {
        cout << "[ ";
        for (auto v : data) {
            cout << v << " ";
        }
        cout << "]" << endl;
    }

    // Add operation (element-wise)
    Tensor add(const Tensor& other) const {
        if (data.size() != other.data.size()) {
            throw runtime_error("Size mismatch in add");
        }
        vector<float> result(data.size());
        for (size_t i = 0; i < data.size(); i++) {
            result[i] = data[i] + other.data[i];
        }
        return Tensor(result);
    }

    // Subtract operation
    Tensor subtract(const Tensor& other) const {
        if (data.size() != other.data.size()) {
            throw runtime_error("Size mismatch in subtract");
        }
        vector<float> result(data.size());
        for (size_t i = 0; i < data.size(); i++) {
            result[i] = data[i] - other.data[i];
        }
        return Tensor(result);
    }

    // Multiply operation (element-wise)
    Tensor multiply(const Tensor& other) const {
        if (data.size() != other.data.size()) {
            throw runtime_error("Size mismatch in multiply");
        }
        vector<float> result(data.size());
        for (size_t i = 0; i < data.size(); i++) {
            result[i] = data[i] * other.data[i];
        }
        return Tensor(result);
    }

    // Divide operation (element-wise)
    Tensor divide(const Tensor& other) const {
        if (data.size() != other.data.size()) {
            throw runtime_error("Size mismatch in divide");
        }
        vector<float> result(data.size());
        for (size_t i = 0; i < data.size(); i++) {
            if (other.data[i] == 0) {
                throw runtime_error("Division by zero");
            }
            result[i] = data[i] / other.data[i];
        }
        return Tensor(result);
    }
};

int main() {
    // Create two tensors
    Tensor t1({1, 2, 3, 4});
    Tensor t2({5, 6, 7, 8});

    cout << "Tensor 1: ";
    t1.print();

    cout << "Tensor 2: ";
    t2.print();

    // Perform operations
    Tensor sum = t1.add(t2);
    cout << "Addition: ";
    sum.print();

    Tensor diff = t1.subtract(t2);
    cout << "Subtraction: ";
    diff.print();

    Tensor prod = t1.multiply(t2);
    cout << "Multiplication: ";
    prod.print();

    Tensor quot = t1.divide(t2);
    cout << "Division: ";
    quot.print();

    return 0;
}
