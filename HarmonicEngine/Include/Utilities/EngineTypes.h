#pragma once
#ifndef _ENGINETYPES_H
#define _ENGINETYPES_H

using ubyte = unsigned __int8;

enum class ELogTypes : ubyte {
	LT_General,
	LT_Warning,
	LT_Error
};

#endif // !_ENGINETYPES_H
