#include <stdafx.h>
#include "NeuralNetwork.h"

NeuralNet::NeuralNet(int inputs, int outputs, Eigen::VectorXi hiddenLayersArray) : inputCount(inputs), outputCount(outputs), hiddenLayerSizes(hiddenLayersArray)
{
	hiddenLayerCount = hiddenLayersArray.size();


	//Creating inital wieght layer
	if (hiddenLayerCount == 0)
	{
		weightLayers.push_back(new Eigen::VectorXf(outputs, inputs + 1));
	}
	else
	{
		weightLayers.push_back(new Eigen::VectorXf(hiddenLayersArray[0], inputs + 1));
	}


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

Eigen::VectorXf NeuralNet::feedForward(const Eigen::VectorXi& inputs)
{
	Eigen::VectorXf x = Eigen::VectorXf(0);
	return x;
}