/*
 * tess.h
 */
#ifndef TESS_H
#define TESS_H

#include <math.h>
#include <stdlib.h>
#include "Algebra.h"

/* assumes sphere is centered at origin */
inline double transverseSliceRadiusSphere(double radius, double y) {
	return sqrt(SQR(radius) - SQR(y));
}

inline double transverseSliceRadiusCone(double radius, double height,
										double y) {
	return radius * (height - y) / height;
}

inline double ithSliceXComponent(double radius, int i, int segmentsX) {
	return radius * cos((2*((double)i)*PI)/segmentsX);
} 

inline double ithSliceZComponent(double radius, int i, int segmentsX) {
	return radius * sin((2*((double)i)*PI)/segmentsX);
}

#endif

