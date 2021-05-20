
#include "dvpLibADependencyNamesPrivate.h"
#include CPF_VERSIONED_INCLUDE(dvpLibA, libA.h)

#include <iostream>

#include CPF_VERSIONED_INCLUDE(dvpLibB1, libB1.h)
#include CPF_VERSIONED_INCLUDE(dvpLibB2, libB2.h)
#include CPF_VERSIONED_INCLUDE(dvpLibD, MyFunction.h)

namespace dvpLibA
{
	dvpLibC_from_dvpLibB2::ValueType to_2_2_0ValueType(dvpLibC_from_dvpLibB1::ValueType value)
	{
		dvpLibC_from_dvpLibB2::ValueType oldVersion;

		oldVersion.foo = value.foo;
		oldVersion.bar = value.bar;

		return oldVersion;
	}

	dvpLibC_from_dvpLibB1::ValueType to_2_3_0ValueType(dvpLibC_from_dvpLibB2::ValueType value)
	{
		dvpLibC_from_dvpLibB1::ValueType newVersion;

		newVersion.foo = value.foo;
		newVersion.bar = value.bar;

		return newVersion;
	}

	void workWithValueType()
	{
		auto foo1 = dvpLibB1::b1ReturnValueType();
		dvpLibB2::b2UseValueType(to_2_2_0ValueType(foo1));

		auto foo2 = dvpLibB2::b2ReturnValueType();
		dvpLibB1::b1UseValueType(to_2_3_0ValueType(foo2));
	}

	dvpLibC_from_dvpLibB2::ComplexType* to_2_2_0ComplexType(dvpLibC_from_dvpLibB1::ComplexType* ct)
	{
		return reinterpret_cast<dvpLibC_from_dvpLibB2::ComplexType*>(ct);
	}

	dvpLibC_from_dvpLibB1::ComplexType* to_2_3_0ComplexType(dvpLibC_from_dvpLibB2::ComplexType* ct)
	{
		return reinterpret_cast<dvpLibC_from_dvpLibB1::ComplexType*>(ct);
	}

	std::unique_ptr<dvpLibC_from_dvpLibB2::ComplexType> to_2_2_0UniqueComplexType(std::unique_ptr<dvpLibC_from_dvpLibB1::ComplexType> ct)
	{
		return std::unique_ptr<dvpLibC_from_dvpLibB2::ComplexType>(to_2_2_0ComplexType(ct.release()));
	}

	std::unique_ptr<dvpLibC_from_dvpLibB1::ComplexType> to_2_3_0UniqueComplexType(std::unique_ptr<dvpLibC_from_dvpLibB2::ComplexType> ct)
	{
		return std::unique_ptr<dvpLibC_from_dvpLibB1::ComplexType>(to_2_3_0ComplexType(ct.release()));
	}

	void workWithComplexType()
	{
		auto foo1 = dvpLibB1::b1ReturnComplexType();
		dvpLibB2::b2UseComplexType(to_2_2_0ComplexType(foo1));

		auto foo2 = dvpLibB2::b2ReturnComplexType();
		dvpLibB1::b1UseComplexType(to_2_3_0ComplexType(foo2));

		auto foo3 = dvpLibB1::b1CreateComplexType();
		dvpLibB2::b2SetComplexType(to_2_2_0UniqueComplexType(std::move(foo3)));

		auto foo4 = dvpLibB2::b2CreateComplexType();
		dvpLibB1::b1SetComplexType(to_2_3_0UniqueComplexType(std::move(foo4)));

		auto foo5 = std::make_unique<dvpLibC_from_dvpLibB2::ComplexType>();
		dvpLibB2::b2UseComplexType(foo5.get());
		dvpLibB1::b1UseComplexType(to_2_3_0ComplexType(foo5.get()));
	}

	void workWithdvpLibD()
	{
		auto isCool = dvpLibD::isCoolMan();
	}

}


