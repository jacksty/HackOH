#pragma once
class PerceptronLayer
{
	const int nIn;
	const int nOut;
	const float kValue;
	Eigen::MatrixXf weights;

	// CONSTRUCTOR / DESTRUCTOR
public:
	PerceptronLayer(int inputCount, int outputCount, float kPower = 15.f);
	~PerceptronLayer();


	// METHODS
protected:
	Eigen::VectorXf sigmoidVectorRounded(const Eigen::VectorXf& summedVector);

public:
	inline Eigen::VectorXf operator()(const Eigen::VectorXf& in) { return sigmoidVectorRounded(in * weights); }

	// GETTERS
public:
	inline int getSizeIn() const { return nIn; }
	inline int getSizeOut() const { return nOut; }
	std::string to_string() const;
};

