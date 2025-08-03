#pragma once

#define toINT(c) static_cast<int>(c - '0')
#define OPEN_SIGN case '[':\
	case '{':\
	case '(':
#define CLOSE_SIGN case ']':\
	case '}':\
	case ')':

// Has limited Dimension  until Depth 4
class StringToArray
{
	enum class Type : char{
		NONE,
		INT,
		FLOAT,
		STRING
	} type = Type::NONE;

	enum class State : char {
		NONE,
		OPEN,
		ELEM,
		CLOSE,
		APPEND,
		CLOSED
	} state = State::NONE;

private:
	StringToArray() {}
	~StringToArray();

	static StringToArray* instance;

public:
	static StringToArray* Get()
	{
		if (instance == nullptr)
			instance = new StringToArray();
		return instance;
	}

public:
	bool To_Array(string target);

private:
	void* depthFirst = nullptr;
	void** depthSecond = nullptr;
	void*** depthThird = nullptr;
	void**** depthForth = nullptr;
};


