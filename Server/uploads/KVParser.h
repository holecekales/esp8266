// I think this is sort of working


#ifndef _KVPARSER_H_
#define _KVPARSER_H_

#pragma once

#define KVCOUNT		2

class KVStore
{
protected:

	typedef struct {
		int start;
		int len;
	} Token;

	typedef struct {
		Token key;
		Token value;
	} KV;


	// buffer, that holds the string that contains
	// the which has all of the key/values
	// these key/values are white space seprated
	char* buf;	

	// indecies into the buffer. 
	KV	config[KVCOUNT];

	// protected methods for doing all of the parsing
	void findToken(int* start, int* end);
	bool parseKeyValue(int idx, int* start);

public:
	KVStore()	{ buf = NULL; }
	~KVStore() { delete[] buf; buf = NULL; }

	// allocate the string buffer to a given size
	// this needs to be alloacted, since we will modify it
	bool allocBuffer(int size);

	// access the raw buffer!! 
	// if allocBuffer() was not called - bad things will happen
	char* bufferPtr() { return buf; }

	// parse() - main method - must be called before 
	// values can be access and queired
	bool parse();

	// getting config values; parse() needs to be called 
	// before these things work
	char*	getStr(const char* key);
	int		getInt(const char* key);

};


#endif // _KVPARSER_H_