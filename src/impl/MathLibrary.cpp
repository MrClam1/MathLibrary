#include <iostream>
#include "MathLibrary.h"

using namespace Math;

MathLibrary::MathLibrary(int s)
{
	_size = s;
	_mass = new int[_size];
}

MathLibrary::~MathLibrary()
{
	delete[] _mass;
	std::cout << "Destructor called for Native MathLib!" << std::endl;
}

void MathLibrary::PutData(int p)
{
	if (_index == _size)
	{
		Types::OpStatus err;
		err.Success = 0;
		err.Error = 1002;
		memcpy_s(err.ErrorMsg, 18, "Massive is full!", 18);

		Error(err);
		return;
	}

	_mass[_index] = p;
	_index++;

	return;
}

void MathLibrary::Process()
{
	if (_index == 0)
	{
		Types::OpStatus err;
		err.Success = 0;
		err.Error = 1002;
		memcpy_s(err.ErrorMsg, 18, "Massive is empty!", 18);

		Error(err);
		return;
	}

	int res = 0;

	for (int i = 0; i < _index; i++)
	{
		res += _mass[i];
	}

	_result = res;

	Print();

	return;
}

void MathLibrary::AddResultCallback(int* callback)
{
	_resultCallback = callback;
}

void MathLibrary::RemoveResultCallback()
{
	_resultCallback = nullptr;
}

void MathLibrary::AddErrorCallback(int* callback)
{
	_errorCallback = callback;
}

void MathLibrary::RemoveErrorCallback()
{
	_errorCallback = nullptr;
}

void MathLibrary::Print()
{
	if (_resultCallback == nullptr)
		return;

	auto callback = reinterpret_cast<void(*)(int)>(_resultCallback);
	callback(_result);
}

void MathLibrary::Error(Types::OpStatus status)
{
	if (_errorCallback == nullptr)
		return;

	auto callback = reinterpret_cast<void(*)(Types::OpStatus)>(_errorCallback);
	callback(status);
}