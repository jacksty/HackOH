#include "stdafx.h"
#include "NeuralNetwork.h"
#include <Eigen/Dense>
#include <iostream>
#include <string>

int main(int arc, char** argv)
{
	Eigen::VectorXi x;
	x.resize(2);
	x[0] = 32;
	x[1] = 16;

	NeuralNet* n = new NeuralNet(64, 3, x);

	std::string waitForInputString;
	std::cin >> waitForInputString;
	return 0;
}
