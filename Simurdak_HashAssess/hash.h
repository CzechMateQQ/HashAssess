#pragma once
#include <limits>
#include <cstring>
#include <iostream>

// Template declaration for hash.
template<typename T>
size_t hash(const T& _val)
{
	// Unelegant way of telling user to specialize this template.
	T::specialize_this_template_for_type;
}

// Template specialization for int.
template<>
size_t hash<int>(const int& _val)
{
	// Knuth's hash function.
	return _val * 2654435761 % std::numeric_limits<size_t>::max();
}

// Template specialization for char.
template<>
size_t hash<char>(const char& _val)
{
	return (int)_val * 2654435761 % std::numeric_limits<size_t>::max();
}

// Template specialization for C-string.
// Extremely basic method.
template<>
size_t hash<char*>(char * const& _val)
{
	unsigned int hashVal = 0;
	for (int i = 0; _val[i] != '\0'; ++i)
	{
		hashVal += _val[i];
	}
	return hashVal;
}

// Template specialization for std::string.
template<>
size_t hash<std::string>(const std::string& _val)
{
	return hash<char*>((char*)_val.c_str());
}