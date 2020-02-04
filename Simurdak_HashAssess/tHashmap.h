#pragma once
#include "hash.h"

template<typename K, typename V>
class tHashmap
{
	V * data;				// Buffer holding all potential pairs in hashmap.
	size_t dataCapacity;	// Size of the above buffers.

public:
	// Constructs the hashmap with a specific size.
	tHashmap()
	{
		dataCapacity = 10;
		data = new V[dataCapacity];
	}

	// Copy constructor.
	tHashmap(const tHashmap& original)
	{
		for (int i = 0; i < dataCapacity; ++i)
		{
			data[i] = original.data[i];
		}
	}

	// Copy assignment.
	tHashmap& operator=(const tHashmap &rhs)
	{
		for (int i = 0; i < dataCapacity; ++i)
		{
			this.data[i] = rhs.data[i];
		}
		return *this;
	}

	// Cleans-up any underlying data.
	~tHashmap()
	{
		delete[] data;
	}

	// Returns the object at the given key.
	V& operator[] (const K& _key)
	{
		auto keyVal = hash(_key) % dataCapacity;
		return data[keyVal];
	}
};