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

<<<<<<< HEAD
	Eigen::VectorXf feedForward(const Eigen::VectorXf& inputs);

	char* process(const char* input, char* output);

public:
	template<typename T>
	void think(const T* input, T* output)
	{
		process(reinterpret_cast<const char*>(input), reinterpret_cast<char*>(output));
	}
};
=======
	Eigen::VectorXf feedForward(const Eigen::VectorXi& inputs);
};


>>>>>>> origin/master
