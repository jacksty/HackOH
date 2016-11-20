#include "stdafx.h"
#include "NeuralNetwork.h"
#include <Eigen/Dense>
#include <iostream>
#include <string>

#include "NeuralNetwork.h"

int main(int arc, char** argv)
{
	NeuralNet test(8, 15, { 9, 12, 14 });
	char c = 95;
	short out;
	test.think(&c, &out);
	std::cout << std::to_string(c) << "\n" << std::to_string(out) << "\n";
	scanf_s("%d", &out);
	return 0;
}
