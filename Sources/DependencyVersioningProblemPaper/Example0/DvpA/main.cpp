
#define dvpLibAVer dvpLibA_1_0_0
#include CPF_VERSIONED_INCLUDE(dvpLibAVer, libA.h)

int main()
{
	dvpLibAVer::workWithValueType();
	dvpLibAVer::workWithComplexType();
	dvpLibAVer::workWithdvpLibD();

	return 0;
}