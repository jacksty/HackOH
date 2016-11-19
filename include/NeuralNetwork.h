#pragma once
#include <stdafx.h>
#include <vector>
#include <Eigen/Dense>

class NeuralNet
{
public:
	int inputCount = 0;

	int hiddenLayerCount = 0;

	int outputCount = 0;

	Eigen::VectorXi hiddenLayerSizes;

	std::vector<Eigen::VectorXf*> weightLayers = std::vector<Eigen::VectorXf*>();

	NeuralNet(int inputs, int outputs, Eigen::VectorXi hiddenLayersArray);

	Eigen::VectorXf feedForward(const Eigen::VectorXi& inputs);
};