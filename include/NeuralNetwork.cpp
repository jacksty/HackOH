#include <stdafx.h>
#include "NeuralNetwork.h"

NeuralNet::NeuralNet(int inputs, int outputs, Eigen::VectorXi hiddenLayersArray)
	:
	hiddenLayerSizes(hiddenLayersArray),
	inputCount(inputs), outputCount(outputs),
	hiddenLayerCount(hiddenLayersArray.size()),
	learningRate(1.f)
{
	expectedOutput.resize(outputCount);
	//Creating inital wieght layer
	if (hiddenLayerCount == 0)
	{
		weightLayers.push_back(new Eigen::MatrixXf(outputs, inputs + 1));
	}
	else
	{
		weightLayers.push_back(new Eigen::MatrixXf(hiddenLayersArray[0], inputs + 1));
		
		//Createing the rest of the weight layers
		for (int i = 0; i < hiddenLayerCount + 1; i++)
		{
			if (i + 1 == hiddenLayerCount)
			{
				weightLayers.push_back(new Eigen::MatrixXf(outputs, hiddenLayersArray[i] + 1));
				break;
			}
			weightLayers.push_back(new Eigen::MatrixXf(hiddenLayersArray[i + 1], hiddenLayersArray[i] + 1));
		}
	}


	for (int i = 0; i < weightLayers.size(); i++)
	{
		printf("Layer: %d, row: %d, col: %d\n", i, weightLayers[i]->rows(), weightLayers[i]->cols());
	}
}

Eigen::VectorXf NeuralNet::feedForward(const Eigen::VectorXf& inputs)
{
	Eigen::VectorXf x = Eigen::VectorXf{ inputs };
	return x;
}

void NeuralNet::process(const char * input, char* output)
{
	Eigen::VectorXf inputVector;
	Eigen::VectorXf outputVector;

	inputVector.resize(inputCount);

	for (int i = 0; i < inputCount; i++)
		inputVector[i] = static_cast<float>((input[i / 8] >> (i % 8)) & 0x1);

	outputVector = feedForward(inputVector);


	for (int i = 0; i < inputCount / 8; i++)
		output[i] = 0;

	for (int i = 0; i < inputCount; i++)
		output[i / 8] |= (static_cast<char>(outputVector[i]) & 0x1) << (i % 8);
}

/*
void NeuralNet::learn(const Eigen::VectorXf& inputs, const Eigen::VectorXf& outputs)
{
	if (outputs.size() > 1)
	{
		for()
	}

}
*/
