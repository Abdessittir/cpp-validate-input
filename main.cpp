#include <iostream>
#include <limits>

void ignoreLine(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double getDouble(){
    while (true){
        std::cout << "Enter a number: ";
        double x{};
        std::cin >> x;

        if (!std::cin){
            std::cin.clear();
            ignoreLine();
            std::cerr << "Oops, that input is invalid.  Please try again.\n";
        }
        else {
            ignoreLine();
            return x;
        }
    }
}

char getOperator(){
    while(true){
        std::cout << "Enter an operator (+, *, -, /):";
        char ope{};
        std::cin >> ope;
        ignoreLine();

        switch(ope){
            case '+':
            case '*':
            case '/':
            case '-':
               return ope;
            default:
               std::cerr << "Oops, that input is invalid.  Please try again.\n";
        }
    }
}

void printResult(double x, char operation, double y){
    switch (operation)
    {
    case '+':
        std::cout << x << " + " << y << " is " << x + y << '\n';
        break;
    case '-':
        std::cout << x << " - " << y << " is " << x - y << '\n';
        break;
    case '*':
        std::cout << x << " * " << y << " is " << x * y << '\n';
        break;
    case '/':
        std::cout << x << " / " << y << " is " << x / y << '\n';
        break;
    default: // Being robust means handling unexpected parameters as well, even though getOperator() guarantees operation is valid in this particular program
        std::cerr << "Something went wrong: printResult() got an invalid operator.\n";
    }
}

int main(){

    double x{ getDouble() };
    char operation{ getOperator() };
    double y{ getDouble() };

    printResult(x, operation, y);
    
    return 0;
}