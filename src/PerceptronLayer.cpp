#include "stdafx.h"
#include "PerceptronLayer.h"


PerceptronLayer::PerceptronLayer(int inputCount, int outputCount)
	:
	nIn(inputCount), nOut(outputCount)
{
	weights.resize(nIn, nOut);
	std::uniform_real_distribution<float> distribution{ -1.f, 1.f };
	std::default_random_engine engine(std::chrono::system_clock::now());

	for (int i = 0; i < nIn; i++)
	{
		for (int j = 0; j < nOut; j++)
			weights(i, j) = distribution(engine);
	}
}

PerceptronLayer::~PerceptronLayer()
{
}
