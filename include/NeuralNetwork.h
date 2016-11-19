#pragma once
#include <stdafx.h>

class NeuralNet
{
	// PROPERTIES
	/// The number of bits accepted as input.
	const int inputCount;
	/// The number of bits provided as output.
	const int outputCount;
	const int hiddenLayerCount;
	const Eigen::VectorXi hiddenLayerSizes;

	/// Error correction multiplier for adjusting weights.
	float learningRate;
	std::vector<Eigen::MatrixXf*> weightLayers;
	Eigen::VectorXf expectedOutput;

	// CONSTRUCTOR
	/// Creates a new NN.
	///		inputs: The number of bits accepted as input.
	///		outputs: The number of bits to be output.
	///		hiddenLayersArray: A list containing the size for each hidden layer. Can be empty.
	NeuralNet(int inputs, int outputs, Eigen::VectorXi hiddenLayersArray);

	// METHODS
	Eigen::VectorXf feedForward(const Eigen::VectorXf& inputs);
	void process(const char* input, char* output);
	//void learn(const Eigen::VectorXf& inputs, const Eigen::VectorXf& outputs);
	

public:
	template<typename T>
	inline void think(const T* input, T* output)
	{
		process(reinterpret_cast<const char*>(input), reinterpret_cast<char*>(output));
	}


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
