#include "stdafx.h"
#include "NeuralNetwork.h"
#include <Eigen/Dense>
#include <iostream>
#include <string>

#include "NeuralNetwork.h"

int main(int arc, char** argv)
{
	NeuralNet test(1, 5, { 3 });
	std::cout << test.to_string();

	
	char c = 95;
	short out;
	/*
	test.think(&c, &out);
	std::cout << std::to_string(c) << "\n" << std::to_string(out) << "\n";
	*/
	scanf_s("%d", &out);
	return 0;
}
