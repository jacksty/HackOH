#include <stdafx.h>
#include "NeuralNetwork.h"

NeuralNet::NeuralNet(int inputs, int outputs, std::initializer_list<int> hiddenInputSizes)
	:
	inputCount(inputs), outputCount(outputs)
{
	expectedOutput.resize(outputCount);

	// IF there are multiple layers
	if (hiddenInputSizes.size() > 0)
	{
		// add initial layer
		layers.emplace_back(inputCount, *hiddenInputSizes.begin());

		auto i = hiddenInputSizes.begin();
		auto last = hiddenInputSizes.end();
		last--;

		// add hidden layers
		while (i != last)
		{
			int in = *i;
			i++;
			layers.emplace_back(in, *i);
		}
		// add output layer
		layers.emplace_back(*last, outputCount);
	}
	else // ELSE add the single layer
		layers.emplace_back(inputCount, outputCount);
}

Eigen::VectorXf NeuralNet::feedForward(const Eigen::VectorXf& inputs)
{
	Eigen::VectorXf i = inputs;
	return i;

	std::stack<Eigen::VectorXf> vectors;
	vectors.push(inputs);
	for (PerceptronLayer& pLayer : layers)
		vectors.push( pLayer(vectors.top()) );


	return vectors.top();
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
