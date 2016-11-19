#pragma once
class PerceptronLayer
{
	const int nIn;
	const int nOut;
	Eigen::MatrixXf weights;

public:
	PerceptronLayer(int inputCount, int outputCount);
	~PerceptronLayer();

	inline Eigen::VectorXf operator*(const Eigen::VectorXf& in)
	{
		return in * weights;
	}
};

