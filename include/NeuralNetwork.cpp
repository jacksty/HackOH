##include <stdafx.h>
#include "NeuralNetwork.h"

NeuralNet::NeuralNet(int inputs, int outputs, Eigen::VectorXi hiddenLayersArray)
	:
	hiddenLayerSizes(hiddenLayersArray),
	inputCount(inputs), outputCount(outputs),
	//weightLayers(std::vector<Eigen::VectorXf*>()),
	hiddenLayerCount(hiddenLayersArray.size())
{
	//Creating inital wieght layer
	if (hiddenLayerCount == 0)
	{
		weightLayers.push_back(new Eigen::MatrixXf(outputs, inputs + 1));
	}
	else
	{
		weightLayers.push_back(new Eigen::MatrixXf(hiddenLayersArray[0], inputs + 1));
	}


	//Createing the weight layers
	for (int i = 0; i < hiddenLayerCount + 1; i++)
	{
		if (i + 1 == hiddenLayerCount)
		{
			weightLayers.push_back(new Eigen::MatrixXf(outputs, hiddenLayersArray[i] + 1));
			break;
		}
		weightLayers.push_back(new Eigen::MatrixXf(hiddenLayersArray[i + 1], hiddenLayersArray[i] + 1));
	}



	for (int i = 0; i < weightLayers.size(); i++)
	{
		printf("Layer: %d, row: %d, col: %d\n", i, weightLayers[i]->rows(), weightLayers[i]->cols());
	}
}

Eigen::VectorXf NeuralNet::feedForward(const Eigen::VectorXi& inputs)
{
	Eigen::VectorXf x = Eigen::VectorXf(0);
	return x;
}