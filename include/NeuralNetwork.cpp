#include <stdafx.h>
#include "NeuralNetwork.h"

NeuralNet::NeuralNet(int inputs, int outputs, Eigen::VectorXi hiddenLayersArray)
	:
	hiddenLayerSizes(hiddenLayersArray),
	inputCount(inputs), outputCount(outputs),
	weightLayers(std::vector<Eigen::VectorXf*>()),
	hiddenLayerCount(hiddenLayersArray.size())
{
	/*
	//Creating inital wieght layer
	if (hiddenLayerCount == 0)
	{
		weightLayers.push_back(new Eigen::VectorXf(outputs, inputs + 1));
	}
	else
	{
		weightLayers.push_back(new Eigen::VectorXf(hiddenLayersArray[0], inputs + 1));
	}
	*/
	
	//Createing the weight layers
	/*for (int i = 0; i < hiddenLayerCount + 1; i++)
	{
	if (i == 0)
	{
	if (i+1 == hiddenLayerCount)
	//weightLayers.push_back(Eigen::VectorXf)
	}
	}*/
}

Eigen::VectorXf NeuralNet::feedForward(const Eigen::VectorXf& inputs)
{
	Eigen::VectorXf x = Eigen::VectorXf{ inputs };
	return x;
}

char * NeuralNet::process(const char * input, char* output)
{
	Eigen::VectorXf inputVector;
	inputVector.resize(inputCount);

	for (int i = 0; i < inputCount; i++)
		inputVector[i] = static_cast<float>((input[i / 8] >> (i % 8)) & 0x1);

	inputVector = feedForward(inputVector);

	for (int i = 0; i < inputCount / 8; i++)
		output[i] = 0;

	for (int i = 0; i < inputCount; i++)
		output[i / 8] |= (static_cast<char>(inputVector[i]) & 0x1) << (i % 8);
	
	return output;
}
