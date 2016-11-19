#include "stdafx.h"
#include "NeuralNetwork.h"
#include <Eigen/Dense>
#include <iostream>
#include <string>

#include "NeuralNetwork.h"

int main(int arc, char** argv)
{
<<<<<<< HEAD
	NeuralNet n{ 32, 32, Eigen::VectorXi{} };
	int f = -384864;
	int out;
	n.think(&f, &out);
	printf("%d\n", out);
	scanf_s("%d", &f);
=======
	Eigen::VectorXi x;
	x.resize(2);
	x[0] = 32;
	x[1] = 16;

	NeuralNet* n = new NeuralNet(64, 3, x);

	std::string waitForInputString;
	std::cin >> waitForInputString;
>>>>>>> origin/master
	return 0;
}
