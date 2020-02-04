#pragma once

template<typename K, typename V>
class tHashmap
{
	V * data;				// Buffer holding all potential pairs in hashmap.
	size_t dataCapacity;	// Size of the above buffers.

public:
	tHashmap();		// Constructs the hashmap with a specific size.
	tHashmap();		// Cleans-up any underlying data.

	V& operator[] (const K& key);	// Returns the object at the given key.
};