
#include "dvpLibB2DependencyNamesPrivate.h"
#include CPF_VERSIONED_INCLUDE(dvpLibB2, libB2.h)

#include <iostream>

CPF_VERSIONED_NAMESPACE(dvpLibB2)
{

	void b2UseValueType(dvpLibC::ValueType value)
	{
		std::cout << "Called dpvLibB2::b2UseValueType() with argument " << value.foo << value.bar << "\n";
	}

	dvpLibC::ValueType b2ReturnValueType()
	{
		return dvpLibC::ValueType{ 3, 4 };
	}

	void b2UseComplexType(dvpLibC::ComplexType* value)
	{
		std::cout << "Called dpvLibB2::b2UseComplexType() with argument " << value->getFoo() << "\n";
	}

	std::unique_ptr<dvpLibC::ComplexType> globalComplexType = nullptr;

	dvpLibC::ComplexType* b2ReturnComplexType()
	{
		if (!globalComplexType)
		{
			globalComplexType = std::make_unique<dvpLibC::ComplexType>();
		}
		return globalComplexType.get();
	}

	void b2SetComplexType(std::unique_ptr<dvpLibC::ComplexType> value)
	{
		globalComplexType = std::move(value);
	}

	std::unique_ptr<dvpLibC::ComplexType> b2CreateComplexType()
	{
		return std::make_unique<dvpLibC::ComplexType>();
	}

}
