#pragma once
#include "dvpLibB1DependencyNames.h"

#include <memory>

#include CPF_VERSIONED_INCLUDE(dvpLibC, ValueType.h)
#include CPF_VERSIONED_INCLUDE(dvpLibC, ComplexType.h)

#include CPF_VERSIONED_INCLUDE(dvpLibB1, dvpLibB1_export.h)

CPF_VERSIONED_NAMESPACE(dvpLibB1)
{
	DVPLIBB1_EXPORT void b1UseValueType(dvpLibC::ValueType value);
	DVPLIBB1_EXPORT dvpLibC::ValueType b1ReturnValueType();

	DVPLIBB1_EXPORT void b1UseComplexType(dvpLibC::ComplexType * value);
	DVPLIBB1_EXPORT dvpLibC::ComplexType* b1ReturnComplexType();

	DVPLIBB1_EXPORT void b1SetComplexType(std::unique_ptr<dvpLibC::ComplexType> value);
	DVPLIBB1_EXPORT std::unique_ptr<dvpLibC::ComplexType> b1CreateComplexType();
}
