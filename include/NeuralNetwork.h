#pragma once
#include <stdafx.h>
#include "PerceptronLayer.h"

class NeuralNet
{
	// PROPERTIES
protected:
	/// The number of bits accepted as input.
	const int inputCount;
	/// The number of bits provided as output.
	const int outputCount;
	std::vector<PerceptronLayer> layers;

	/// Error correction multiplier for adjusting weights.
	float learningRate;
	Eigen::VectorXf expectedOutput;

	// CONSTRUCTOR
public:
	/// Creates a new NN.
	///		inputs: The number of bits accepted as input.
	///		outputs: The number of bits to be output.
	///		hiddenLayersArray: A list containing the size for each hidden layer. Can be empty.
	NeuralNet(int inputs, int outputs, std::initializer_list<int> hiddenInputSizes = {});

	// METHODS
protected:
	Eigen::VectorXf feedForward(const Eigen::VectorXf& inputs);
	void process(const char* input, char* output);

public:
	template<typename _In, typename _Out>
	inline void think(const _In* input, _Out* output)
	{
		process(reinterpret_cast<const char*>(input), reinterpret_cast<char*>(output));
	}
	std::string to_string() const;


	// SETTERS
public:
	inline void setLearningRate(float rate) { learningRate = rate; }

	template<typename T>
	void setExpectedOutput(const T* expected)
	{
		const char* expectedChar = reinterpret_cast<char*>(expected);

		for (int i = 0; i < outputCount; i++)
			expectedOutput[i] = static_cast<float>((expectedChar[i / 8] >> (i % 8)) & 0x1);
	}
};
