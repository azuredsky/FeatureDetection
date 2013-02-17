/*
 * RbfKernel.hpp
 *
 *  Created on: 16.02.2013
 *      Author: Patrik Huber
 */

#pragma once

#ifndef RBFKERNEL_HPP_
#define RBFKERNEL_HPP_

#include "opencv2/core/core.hpp"

using cv::Mat;

namespace classification {

/**
 * A radial basis function kernel.
 */
class RbfKernel {
public:

	explicit RbfKernel();
	~RbfKernel();

	/**
	 * Computes the radial basis function kernel of ...
	 *
	 * @param[in] input The ...
	 * @return The result of the kernel computation
	 */
	inline double compute(const Mat& value);	// Write the implementation in the header to allow inlining?
	// float kernel(unsigned char*, unsigned char*, int, float, float, int, int); // from DetSVM.h

	/*
float DetectorSVM::kernel(unsigned char* data, unsigned char* support, int nonLinType, float basisParam, float divisor, int polyPower, int nDim)
{
	int dot = 0;
	int val2;
	float out;
	float val;
	int i;
	switch (nonLinType) {
	case 1: // polynomial
		for (i = 0; i != nDim; ++i)
			dot += data[i] * support[i];
		out = (dot+basisParam)/divisor;
		val = out;
		for (i = 1; i < polyPower; i++)
			out *= val;
		return out;
	case 2: // RBF
		for (i = 0; i != nDim; ++i) {
			val2 = data[i] - support[i];
			dot += val2 * val2;
		}
		return (float)exp(-basisParam*dot);
	default: assert(0);
	}
	return 0;

}


	*/

private:
	double gamma; ///< Parameter of the radial basis function exp(-gamma*|u-v|^2). TODO CHECK WITH MR IMPLEMENTATION! REALLY? What about a) 0-255 / 0-1 scaling? And 1/gamma or gamma?
};

} /* namespace classification */
#endif /* RBFKERNEL_HPP_ */