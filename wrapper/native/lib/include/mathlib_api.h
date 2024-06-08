#ifndef CCSL_RSA_API
#define CCSL_RSA_API

#include "lib_export.h"
#include <cstdint>

#ifdef __cplusplus
extern "C"
{
#endif
	class MathLibrarySDK;

	typedef struct _ErrStatus
	{
		uint8_t Success;
		uint32_t Error;
		char ErrorMsg[512];
	} ErrStatus;

	SDK_SHARED MathLibrarySDK* createMathLibrary(int size, ErrStatus* opResult);
	SDK_SHARED void freeMathLibrary(MathLibrarySDK* lib);

	SDK_SHARED uint8_t putData_MathLib(MathLibrarySDK* lib, int parameter, ErrStatus* opResult);
	SDK_SHARED uint8_t processData_MathLib(MathLibrarySDK* lib, ErrStatus* opResult);

	SDK_SHARED uint8_t addResultCallback_MathLib(MathLibrarySDK* lib, void(*callback)(int), ErrStatus* opResult);
	SDK_SHARED uint8_t removeResultCallback_MathLib(MathLibrarySDK* lib, ErrStatus* opResult);
	SDK_SHARED uint8_t addErrorCallback_MathLib(MathLibrarySDK* lib, void(*callback)(ErrStatus), ErrStatus* opResult);
	SDK_SHARED uint8_t removeErrorCallback_MathLib(MathLibrarySDK* lib, ErrStatus* opResult);

#ifdef __cplusplus
}
#endif

#endif