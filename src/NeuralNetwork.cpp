#include <stdafx.h>
#include "NeuralNetwork.h"

NeuralNet::NeuralNet(int inputs, int outputs, std::initializer_list<int> hiddenInputSizes)
	:
	inputCount(inputs), outputCount(outputs)
{
	expectedOutput.resize(outputCount);
	
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
