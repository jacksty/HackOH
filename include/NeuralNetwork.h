#pragma once
#include <stdafx.h>

class NeuralNet
{
public:
	const int inputCount;
	//const int hiddenLayerCount;
	const int outputCount;
	const Eigen::VectorXi hiddenLayerSizes;

	std::vector<Eigen::MatrixXf*> weightLayers;

	NeuralNet(int inputs, int outputs, Eigen::VectorXi hiddenLayersArray);

	Eigen::VectorXf feedForward(const Eigen::VectorXf& inputs);

	void process(const char* input, char* output);

	Eigen::VectorXf sigmoidVectorRounded(const Eigen::VectorXf& summedVector, float kValue = 15.0f);

public:
	template<typename T>
	void think(const T* input, T* output)
	{
		process(reinterpret_cast<const char*>(input), reinterpret_cast<char*>(output));
	}
};
