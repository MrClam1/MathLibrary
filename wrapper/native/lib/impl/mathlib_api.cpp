#include "mathlib_api.h"

#include "MathLibrary.h"

uint8_t fillOpStatusAndGetStatus(Types::OpStatus src, ErrStatus* dst)
{
	dst->Success = src.Success;
	dst->Error = src.Error;
	memcpy(&dst->ErrorMsg, &src.ErrorMsg, sizeof(src.ErrorMsg));
	return src.Success;
};

SDK_SHARED MathLibrarySDK* createMathLibrary(int size, ErrStatus* opResult)
{
	MathLibrarySDK* lib = nullptr;
	try
	{
		lib = reinterpret_cast<MathLibrarySDK*>(new Math::MathLibrary(size));
	}
	catch (std::exception error)
	{
		Types::OpStatus err;
		err.Success = 0;
		err.Error = 1002;

		auto msg = error.what();
		int size = std::strlen(msg) + 1;
		memcpy_s(
			err.ErrorMsg,
			size,
			msg,
			size
		);
		fillOpStatusAndGetStatus(err, opResult);
		return nullptr;
	}
	catch (...)
	{
		Types::OpStatus err;
		err.Success = 0;
		err.Error = 1003;
		memcpy_s(err.ErrorMsg, 14, "Invalid data!", 14);
		fillOpStatusAndGetStatus(err, opResult);
		return nullptr;
	}
	Types::OpStatus err;
	err.Success = 1;
	err.Error = 0;
	fillOpStatusAndGetStatus(err, opResult);
	return lib;
}

SDK_SHARED void freeMathLibrary(MathLibrarySDK* lib)
{
	const auto mathLib = reinterpret_cast<Math::MathLibrary*>(lib);
	delete mathLib;
}

SDK_SHARED uint8_t putData_MathLib(MathLibrarySDK* lib, int parameter, ErrStatus* opResult)
{
	try
	{
		if (lib == nullptr)
			throw std::invalid_argument("Lib is null!");

		Math::MathLibrary* mathLib = reinterpret_cast<Math::MathLibrary*>(lib);

		mathLib->PutData(parameter);
	}
	catch (std::exception error)
	{
		Types::OpStatus err;
		err.Success = 0;
		err.Error = 1002;

		auto msg = error.what();
		int size = std::strlen(msg) + 1;
		memcpy_s(
			err.ErrorMsg,
			size,
			msg,
			size
		);
		return fillOpStatusAndGetStatus(err, opResult);
	}
	catch (...)
	{
		Types::OpStatus err;
		err.Success = 0;
		err.Error = 1003;
		memcpy_s(err.ErrorMsg, 14, "Invalid data!", 14);
		return fillOpStatusAndGetStatus(err, opResult);
	}
	Types::OpStatus err;
	err.Success = 1;
	err.Error = 0;
	return fillOpStatusAndGetStatus(err, opResult);
}

SDK_SHARED uint8_t processData_MathLib(MathLibrarySDK* lib, ErrStatus* opResult)
{
	try
	{
		if (lib == nullptr)
			throw std::invalid_argument("Lib is null!");

		Math::MathLibrary* mathLib = reinterpret_cast<Math::MathLibrary*>(lib);

		mathLib->Process();
	}
	catch (std::exception error)
	{
		Types::OpStatus err;
		err.Success = 0;
		err.Error = 1002;

		auto msg = error.what();
		int size = std::strlen(msg) + 1;
		memcpy_s(
			err.ErrorMsg,
			size,
			msg,
			size
		);
		return fillOpStatusAndGetStatus(err, opResult);
	}
	catch (...)
	{
		Types::OpStatus err;
		err.Success = 0;
		err.Error = 1003;
		memcpy_s(err.ErrorMsg, 14, "Invalid data!", 14);
		return fillOpStatusAndGetStatus(err, opResult);
	}
	Types::OpStatus err;
	err.Success = 1;
	err.Error = 0;
	return fillOpStatusAndGetStatus(err, opResult);
}

SDK_SHARED uint8_t addResultCallback_MathLib(MathLibrarySDK* lib, void(*callback)(int), ErrStatus* opResult)
{
	try
	{
		if (lib == nullptr)
			throw std::invalid_argument("Lib is null!");

		Math::MathLibrary* mathLib = reinterpret_cast<Math::MathLibrary*>(lib);

		auto call = reinterpret_cast<int*>(callback);

		mathLib->AddResultCallback(call);
	}
	catch (std::exception error)
	{
		Types::OpStatus err;
		err.Success = 0;
		err.Error = 1002;

		auto msg = error.what();
		int size = std::strlen(msg) + 1;
		memcpy_s(
			err.ErrorMsg,
			size,
			msg,
			size
		);
		return fillOpStatusAndGetStatus(err, opResult);
	}
	catch (...)
	{
		Types::OpStatus err;
		err.Success = 0;
		err.Error = 1003;
		memcpy_s(err.ErrorMsg, 14, "Invalid data!", 14);
		return fillOpStatusAndGetStatus(err, opResult);
	}
	Types::OpStatus err;
	err.Success = 1;
	err.Error = 0;
	return fillOpStatusAndGetStatus(err, opResult);
}

SDK_SHARED uint8_t removeResultCallback_MathLib(MathLibrarySDK* lib, ErrStatus* opResult)
{
	try
	{
		if (lib == nullptr)
			throw std::invalid_argument("Lib is null!");

		Math::MathLibrary* mathLib = reinterpret_cast<Math::MathLibrary*>(lib);

		mathLib->RemoveResultCallback();
	}
	catch (std::exception error)
	{
		Types::OpStatus err;
		err.Success = 0;
		err.Error = 1002;

		auto msg = error.what();
		int size = std::strlen(msg) + 1;
		memcpy_s(
			err.ErrorMsg,
			size,
			msg,
			size
		);
		return fillOpStatusAndGetStatus(err, opResult);
	}
	catch (...)
	{
		Types::OpStatus err;
		err.Success = 0;
		err.Error = 1003;
		memcpy_s(err.ErrorMsg, 14, "Invalid data!", 14);
		return fillOpStatusAndGetStatus(err, opResult);
	}
	Types::OpStatus err;
	err.Success = 1;
	err.Error = 0;
	return fillOpStatusAndGetStatus(err, opResult);
}

SDK_SHARED uint8_t addErrorCallback_MathLib(MathLibrarySDK* lib, void(*callback)(ErrStatus), ErrStatus* opResult)
{
	try
	{
		if (lib == nullptr)
			throw std::invalid_argument("Lib is null!");

		Math::MathLibrary* mathLib = reinterpret_cast<Math::MathLibrary*>(lib);

		auto call = reinterpret_cast<int*>(callback);

		mathLib->AddErrorCallback(call);
	}
	catch (std::exception error)
	{
		Types::OpStatus err;
		err.Success = 0;
		err.Error = 1002;

		auto msg = error.what();
		int size = std::strlen(msg) + 1;
		memcpy_s(
			err.ErrorMsg,
			size,
			msg,
			size
		);
		return fillOpStatusAndGetStatus(err, opResult);
	}
	catch (...)
	{
		Types::OpStatus err;
		err.Success = 0;
		err.Error = 1003;
		memcpy_s(err.ErrorMsg, 14, "Invalid data!", 14);
		return fillOpStatusAndGetStatus(err, opResult);
	}
	Types::OpStatus err;
	err.Success = 1;
	err.Error = 0;
	return fillOpStatusAndGetStatus(err, opResult);
}

SDK_SHARED uint8_t removeErrorCallback_MathLib(MathLibrarySDK* lib, ErrStatus* opResult)
{
	try
	{
		if (lib == nullptr)
			throw std::invalid_argument("Lib is null!");

		Math::MathLibrary* mathLib = reinterpret_cast<Math::MathLibrary*>(lib);

		mathLib->RemoveErrorCallback();
	}
	catch (std::exception error)
	{
		Types::OpStatus err;
		err.Success = 0;
		err.Error = 1002;

		auto msg = error.what();
		int size = std::strlen(msg) + 1;
		memcpy_s(
			err.ErrorMsg,
			size,
			msg,
			size
		);
		return fillOpStatusAndGetStatus(err, opResult);
	}
	catch (...)
	{
		Types::OpStatus err;
		err.Success = 0;
		err.Error = 1003;
		memcpy_s(err.ErrorMsg, 14, "Invalid data!", 14);
		return fillOpStatusAndGetStatus(err, opResult);
	}
	Types::OpStatus err;
	err.Success = 1;
	err.Error = 0;
	return fillOpStatusAndGetStatus(err, opResult);
}