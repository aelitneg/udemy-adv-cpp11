#include <iostream>

template <class T, class K>
T divide(T a, K b)
{
    return a / b;
}

using namespace std;

int main()
{
    cout << "Normal: " << 3 / 2 << endl;
    cout << "Template: " << divide<float, float>(3, 2) << endl;
    cout << "Inference: " << divide(3, 3) << endl;

    return 0;
}