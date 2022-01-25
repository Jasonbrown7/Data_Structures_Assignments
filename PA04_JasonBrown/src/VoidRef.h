/////////////////////////////////////////////////////////////////////////////
//
//	File: VoidRef.h
//
//	$Header: $
//
//
//	This defines the key-value pair structure used by all of the balanced
//	tree algorithms tested.
//
/////////////////////////////////////////////////////////////////////////////

#include <stdint.h>
#include <iostream>
#pragma once
using namespace std;

struct VoidRef_t
{
	uint32_t   Key;
	void* pContext;
};

