#pragma once

#include "dvpLibCDependencyNames.h"
#include CPF_VERSIONED_INCLUDE(dvpLibC, dvplibc_export.h)

CPF_VERSIONED_NAMESPACE(dvpLibC)
{
	class DVPLIBC_EXPORT ComplexType
	{
	public:

		ComplexType();

		int getFoo() const;
		void setFoo(int foo);

	private:

		int m_foo;

	};
}
