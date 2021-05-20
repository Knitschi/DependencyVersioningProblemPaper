#include "dvpLibCDependencyNamesPrivate.h"
#include CPF_VERSIONED_INCLUDE(dvpLibC, ComplexType.h)

#include <iostream>

CPF_VERSIONED_NAMESPACE(dvpLibC)
{

	ComplexType::ComplexType()
		: m_foo{5} 
	{

	}

	int ComplexType::getFoo() const
	{
		return m_foo;
	}

	void ComplexType::setFoo(int foo)
	{
		m_foo = foo;
	}

}
