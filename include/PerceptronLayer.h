#pragma once
class PerceptronLayer
{
	const int nIn;
	const int nOut;
	const float kValue;
	Eigen::MatrixXf weights;

public:
	PerceptronLayer(int inputCount, int outputCount, float kPower = 15.f);
	~PerceptronLayer();

	Eigen::VectorXf sigmoidVectorRounded(const Eigen::VectorXf& summedVector);

	inline Eigen::VectorXf operator()(const Eigen::VectorXf& in)
	{
		return sigmoidVectorRounded(in * weights);
	}
};

