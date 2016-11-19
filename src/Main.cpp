#include "stdafx.h"
#include "NeuralNetwork.h"
#include <Eigen/Dense>
#include <iostream>
#include <string>

#include "NeuralNetwork.h"

int main(int arc, char** argv)
{
	Eigen::VectorXi x;
	x.resize(2);
	x[0] = 32;
	x[1] = 16;
	NeuralNet n{ 64, 3, x };
	int f = -384864;
	int out;
	n.think(&f, &out);
	printf("%d\n", out);
	scanf_s("%d", &f);

	return 0;
}
