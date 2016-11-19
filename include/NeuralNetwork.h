#pragma once
#include <stdafx.h>

class NeuralNet
{
public:
	const int inputCount;
	const int hiddenLayerCount;
	const int outputCount;
	const Eigen::VectorXi hiddenLayerSizes;

	std::vector<Eigen::MatrixXf*> weightLayers = std::vector<Eigen::MatrixXf*>();

	NeuralNet(int inputs, int outputs, Eigen::VectorXi hiddenLayersArray);

	Eigen::VectorXf feedForward(const Eigen::VectorXi& inputs);
};


