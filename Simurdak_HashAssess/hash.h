#pragma once
#include <limits>
#include <string>
#include <cstring>
#include <iostream>

// Template declaration for hash.
template<typename T>
size_t hash(const T& val)
{
	// Unelegant way of telling user to specialize this template.
	T::specialize_this_template_for_type;
}

// Template specialization for int.
template<>
size_t hash<int>(const int& val)
{
	// Knuth's hash function.
	return val * 2654435761 % std::numeric_limits<size_t>::max();
}

template<>
size_t hash<char>(const char& val)
{
	return (int)val * 2654435761 % std::numeric_limits<size_t>::max();
}

template<>
size_t hash<char*>(char * const& val)
{
	int hashVal = 0;
	for (int i = 0; i != '\0'; ++i)
	{
		hashVal += val[i];
	}
	return hashVal;
}

template<>
size_t hash<std::string>(const std::string& val)
{
	return hash<char*>(val.c_str);
}