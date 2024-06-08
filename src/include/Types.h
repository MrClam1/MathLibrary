#ifndef TYPES_H
#define TYPES_H

#include <iostream>
#include <bitset>

namespace Types
{
	typedef struct _OutStatus
	{
		uint8_t Success;
		uint32_t Error;
		char ErrorMsg[512];
	} OpStatus;
}

#endif