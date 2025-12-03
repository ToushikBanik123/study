#include <iostream>
using namespace std;

class ComplexNumbers {
    private:
        int real;
        int imaginary;

    public:
        // Constructor
        ComplexNumbers(int r, int i) {
            real = r;
            imaginary = i;
        }

        // Plus function: adds two complex numbers
        void plus(ComplexNumbers const &c2) {
            // TODO: Implement addition
            // this->real = this->real + c2.real
            // this->imaginary = this->imaginary + c2.imaginary
        }

        // Multiply function: multiplies two complex numbers
        void multiply(ComplexNumbers const &c2) {
            // TODO: Implement multiplication
            // (a + ib) * (c + id) = (ac - bd) + i(ad + bc)
        }

        // Print function: prints complex number in format "a + ib"
        void print() {
            // TODO: Implement print
            // cout << real << " + i" << imaginary << endl;
        }
};

int main() {
    int real1, imaginary1, real2, imaginary2;
    int choice;

    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;
    cin >> choice;

    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    } else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }

    return 0;
}
