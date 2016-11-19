#include "stdafx.h"
#include "NeuralNetwork.h"
#include <Eigen/Dense>
#include <iostream>
#include <string>

#include "NeuralNetwork.h"

int main(int arc, char** argv)
{
	NeuralNet n{ 32, 32, Eigen::VectorXi{} };
	int f = -384864;
	int out;
	n.think(&f, &out);
	printf("%d\n", out);
	scanf_s("%d", &f);

	return 0;
}
