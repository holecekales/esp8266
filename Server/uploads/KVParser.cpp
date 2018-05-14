// KVParser.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
// #include "string.h"
// #include <memory>

#include <Arduino.h>

#include "stringUtils.h"
#include "KVParser.h"

// allocate the string buffer to a given size
bool KVStore::allocBuffer(int size)
{
	buf = new char[size + 1];
	if (buf == NULL)
		return false;
	buf[size] = 0;
	return true;
}

void KVStore::findToken(int* start, int* end)
{
	int i;
	skipspace(buf + *start, &i);

	i = i + *start;
	*start = i;

	while (!isspacechar(*(buf + i)))
	{
		i++;
	}

	*end = i;
}

bool KVStore::parseKeyValue(int idx, int* start)
{
	int s = *start;
	int e;

	// cache the config element-for simplicity and speed
	KV* t = config + idx;

	// find the first token (white space separated)
	// in this case this is the name of the key
	findToken(&s, &e);

	// store the index which marks the begining of the key
	// in the source string and also the length of the name
	t->key.start = s;
	t->key.len = e - s;

	// pick up where we left off
	s = e;

	// now find the token that represents the value
	findToken(&s, &e);

	// again store the start and length of the value
	t->value.start = s;
	t->value.len = e - s;

	// store where we left off
	*start = e;

	// if length of both the key and the value is bigger than zero
	// then we have valid key/value pair
	return t->key.len && t->value.len;
}

// call parse 
bool KVStore::parse()
{
	// index which keeps track of the position in the source string
	// between key/value pairs
	int start = 0;

	int idx;

	bool parseResult = false;

	for (idx = 0; idx < KVCOUNT; idx++)
	{
		parseResult = parseKeyValue(idx, &start);
		if (parseResult == false)
			break;
	}

	// stampt the source array with null terminators
	// this way we can pull the values as c-strings
	// we have to do it in second pass since parseKeyValue
	// is called iteratively
	for (idx = 0; idx < KVCOUNT; idx++)
	{
		int pos = config[idx].value.start + config[idx].value.len;
		buf[pos] = 0;
	}

	// if all of the key/value pairs were valid
	// we have valid k/v store
	return parseResult;
}


char* KVStore::getStr(const char* key)
{
	int keyLen = ::strlen(key);
	int storeCount = KVCOUNT;

	for (int i = 0; i < storeCount; i++)
	{
		if (keyLen == config[i].key.len && ::strncmp(key, (buf + config[i].key.start), keyLen) == 0)
		{
			return buf + config[i].value.start;
		}
	}

	return NULL;
}

int KVStore::getInt(const char* key)
{
	char* str = getStr(key);
	int value = 0;
	if (str)
		atoi(str, &value);
	return value;
}





