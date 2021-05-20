#include "dvpLibB1DependencyNamesPrivate.h"
#include CPF_VERSIONED_INCLUDE(dvpLibB1, libB1.h)

#include <iostream>


CPF_VERSIONED_NAMESPACE(dvpLibB1)
{

	void b1UseValueType(dvpLibC::ValueType value)
	{
		std::cout << "Called dpvLibB1::b1UseValueType() with argument " << value.foo << value.bar << "\n";
	}

	dvpLibC::ValueType b1ReturnValueType()
	{
		return dvpLibC::ValueType{ 3, 4 };
	}

	void b1UseComplexType(dvpLibC::ComplexType* value)
	{
		std::cout << "Called dpvLibB2::b2UseComplexType() with argument " << value->getFoo() << "\n";
	}

	std::unique_ptr<dvpLibC::ComplexType> globalComplexType = nullptr;

	dvpLibC::ComplexType* b1ReturnComplexType()
	{
		if (!globalComplexType)
		{
			globalComplexType = std::make_unique<dvpLibC::ComplexType>();
		}
		return globalComplexType.get();
	}

	void b1SetComplexType(std::unique_ptr<dvpLibC::ComplexType> value)
	{
		globalComplexType = std::move(value);
	}

	std::unique_ptr<dvpLibC::ComplexType> b1CreateComplexType()
	{
		return std::make_unique<dvpLibC::ComplexType>();
	}

}
