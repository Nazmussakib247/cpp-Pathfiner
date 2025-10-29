# include <iostream>
using namespace std;

int main() {
    // Declaring more than one variable of the same type
    int x = 10, y = 20, z = 30 ;
    cout << x + y + z << endl;

    //One value to multiple variables
    int a, b, c;
    a = b = c = 100;
    cout << a + b + c; 
    return 0;
}