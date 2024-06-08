#ifndef MATHLIBRARY_H
#define MATHLIBRARY_H

#include "Types.h"

namespace Math
{
    class MathLibrary
    {
    public:
        MathLibrary(int size);
        ~MathLibrary();

        void PutData(int p);
        void Process();
        int GetResult() { return _result; }

        void AddResultCallback(int* callback);
        void RemoveResultCallback();

        void AddErrorCallback(int* callback);
        void RemoveErrorCallback();

    private:
        int* _mass;
        int _size;
        int _index = 0;

        int _result = 0;

        int* _resultCallback = nullptr;
        int* _errorCallback = nullptr;

        void Print();
        void Error(Types::OpStatus status);
    };
}

#endif