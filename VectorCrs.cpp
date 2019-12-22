/**
 * @file VectorCrs.cpp
 * @author Dan Oates (WPI Class of 2020)
 */
#include "VectorCrs.h"

/**
 * @brief Friend constructor (lhs x rhs)
 */
VectorCrs::VectorCrs(const VectorExp<3>& lhs, const VectorExp<3>& rhs) :
	lhs_ptr(&lhs),
	rhs_ptr(&rhs)
{
	// Conditionally copy lhs
	if (!lhs.evaluated())
	{
		lhs_copy = lhs;
		lhs_ptr = &lhs_copy;
	}

	// Conditionally copy rhs
	if (!rhs.evaluated())
	{
		rhs_copy = rhs;
		rhs_ptr = &rhs_copy;
	}
}

/**
 * @brief Returns element of expression
 * @param i Vector index [0...n-1]
 */
float VectorCrs::get(uint8_t i) const
{
	switch(i)
	{
		case 0: return
			lhs_ptr->get(1) * rhs_ptr->get(2) -
			lhs_ptr->get(2) * rhs_ptr->get(1);
		case 1: return
			lhs_ptr->get(2) * rhs_ptr->get(0) -
			lhs_ptr->get(0) * rhs_ptr->get(2);
		case 2: return
			lhs_ptr->get(0) * rhs_ptr->get(1) -
			lhs_ptr->get(1) * rhs_ptr->get(0);
	}
	return 0.0f;
}

/**
 * @brief Vector cross product (lhs x rhs)
 */
VectorCrs crs(const VectorExp<3>& lhs, const VectorExp<3>& rhs)
{
	return VectorCrs(lhs, rhs);
}
