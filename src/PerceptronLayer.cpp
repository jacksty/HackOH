#include "stdafx.h"
#include "PerceptronLayer.h"
#include "..\include\PerceptronLayer.h"


PerceptronLayer::PerceptronLayer(int inputCount, int outputCount, float kPower)
	:
	nIn(inputCount), nOut(outputCount),
	kValue(kPower)
{
	weights.resize(nIn, nOut);
	std::uniform_real_distribution<float> distribution{ -1.f, 1.f };
	std::default_random_engine engine(std::chrono::system_clock::now().time_since_epoch().count());

	for (int i = 0; i < nIn; i++)
	{
		for (int j = 0; j < nOut; j++)
			weights(i, j) = distribution(engine);
	}
}

PerceptronLayer::~PerceptronLayer()
{
}

Eigen::VectorXf PerceptronLayer::sigmoidVectorRounded(const Eigen::VectorXf& summedVector)
{
	Eigen::VectorXf x;
	x.resize(summedVector.cols());

	for (int i = 0; i < summedVector.size(); i++)
	{
		x[i] = 1.0f / (1.0f + exp(-kValue*summedVector[i]));
	}

	return x;
}

std::string PerceptronLayer::to_string() const
{
	std::stringstream stringBuilder;

	for (int j = 0; j < nOut; j++)
	{
		stringBuilder << "\t";
		for (int i = 0; i < nIn; i++)
			stringBuilder << std::to_string(weights(i, j)) << (i < nIn - 1 ? ", " : "\n");
	}

	return stringBuilder.str();
}
