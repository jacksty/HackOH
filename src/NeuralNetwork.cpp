#include <stdafx.h>
#include "NeuralNetwork.h"

NeuralNet::NeuralNet(int inputs, int outputs, Eigen::VectorXi hiddenLayersArray)
	:
	hiddenLayerSizes(hiddenLayersArray),
	inputCount(inputs), outputCount(outputs),
	weightLayers(std::vector<Eigen::MatrixXf*>())
	//hiddenLayerCount(hiddenLayersArray.size())
{

	//Creating inital wieght layer
	if (hiddenLayerSizes.size() == 0)
	{
		weightLayers.push_back(new Eigen::MatrixXf(outputs, inputs + 1));
	}
	else
	{
		weightLayers.push_back(new Eigen::MatrixXf(hiddenLayersArray[0], inputs + 1));

		//Createing the rest of the weight layers
		for (int i = 0; i < hiddenLayerSizes.size(); i++)
		{
			if (i + 1 == hiddenLayerSizes.size())
			{
				weightLayers.push_back(new Eigen::MatrixXf(outputs, hiddenLayersArray[i] + 1));
			}
			else
			{
				weightLayers.push_back(new Eigen::MatrixXf(hiddenLayersArray[i + 1], hiddenLayersArray[i] + 1));
			}
		}
	}

	for (int i = 0; i < weightLayers.size(); i++)
	{
		printf("Layer: %d, row: %d, col: %d\n", i, weightLayers[i]->rows(), weightLayers[i]->cols());
	}
}

Eigen::VectorXf NeuralNet::feedForward(const Eigen::VectorXf& inputs)
{
	Eigen::VectorXf i = inputs;
	return i;



	i.conservativeResize(i.size() + 1);
	i[i.size() - 1] = 1.0f;

	Eigen::VectorXf x = (*weightLayers[0]) * i;

	//Sigmoid datalayer
	if (hiddenLayerSizes.size() == 0)
	{
		return i;
	}


	for (int i = 0; i < hiddenLayerSizes.size(); i++)
	{
		x.conservativeResize(x.size() + 1);
		x[x.size() - 1] = 1.0f;
		
		if (i == hiddenLayerSizes.size() - 1)
		{
			x = (*weightLayers[0] * x);
			//Sigmoid
			break;
		}

		//Sigmoid
	}

	return i;
}


void NeuralNet::process(const char * input, char* output)
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
}
