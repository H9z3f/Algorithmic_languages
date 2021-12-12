#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

double Calculation(double First_operand, double Second_operand, string Operator) {
	if (Operator == "+") return (First_operand + Second_operand);
	else if (Operator == "-") return (First_operand - Second_operand);
	else if (Operator == "*") return (First_operand * Second_operand);
	else if (Operator == "/") return (First_operand / Second_operand);
	else if (Operator == "^") return (pow(First_operand, Second_operand));
	else if (Operator == "&") return (pow(First_operand, 1 / Second_operand));
}

int main() {
	cout << "Enter an example: ";

	string Input, Element;
	getline(cin, Input);
	stringstream Input_element(Input);

	vector<string> Stack;
	while (getline(Input_element, Element, ' ')) Stack.emplace_back(Element);

	int Difference = 0, Stack_size = Stack.size();

	for (unsigned int Index = 0; Index < Stack_size; ++Index) {
		if ((Stack[Index - Difference] == "+") || (Stack[Index - Difference] == "-") || (Stack[Index - Difference] == "*") || (Stack[Index - Difference] == "/") || (Stack[Index - Difference] == "^") || (Stack[Index - Difference] == "&")) {
			Stack[Index - Difference] = to_string(Calculation(stod(Stack[Index - 2 - Difference]), stod(Stack[Index - 1 - Difference]), Stack[Index - Difference]));
			Stack.erase(Stack.begin() + Index - 2 - Difference, Stack.begin() + Index - Difference);
			Difference += 2;
		} else if (Stack[Index - Difference] == "=") cout << "Result: " << Stack[Index - 1 - Difference] << "\n";
	}

	system("PAUSE");

	return (0);
}