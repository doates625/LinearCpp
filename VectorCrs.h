/**
 * @file VectorCrs.h
 * @brief Class for vector cross product expressions
 * @author Dan Oates (WPI Class of 2020)
 */
#pragma once
#include "LinearCpp.h"

/**
 * Class Declaration
 */
class VectorCrs : public VectorExp<3>
{
public:
	VectorCrs(const VectorExp<3>& lhs, const VectorExp<3>& rhs);
	float get(uint8_t i) const override;
protected:
	const VectorExp<3>* lhs_ptr;
	const VectorExp<3>* rhs_ptr;
	Vector<3> lhs_copy;
	Vector<3> rhs_copy;
};

/**
 * Function Declaration
 */
VectorCrs crs(const VectorExp<3>& lhs, const VectorExp<3>& rhs);
