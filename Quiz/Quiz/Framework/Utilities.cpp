#include "Framework.h"


StringToArray* StringToArray::instance = nullptr;

StringToArray::~StringToArray()
{
	if (depthForth)
	{

	}
	else if (depthThird)
	{

	}
	else if (depthSecond)
	{

	}


	delete instance;
}

bool StringToArray::To_Array(string target)
{
	string aElem;
	int depth = 0, index = 0;
	
	// check max depth
	{
		while (state == State::OPEN)
		{
			char c = target[index];
			switch (c)
			{
				OPEN_SIGN
				{
					depth++;
				}
			default:
				{
					state = State::ELEM;
					break;
				}
			}
			index++;
		}
	}

	int maxDepth = depth;

	// def type
	{
		if (toINT(target[index]) < 0 || toINT(target[index]) > 9)
			type = Type::STRING;
		else
		{
			int i = index;
			while (state == State::ELEM && type == Type::INT)
			{
				switch (target[i])
				{
				case '.':
				{
					type = Type::FLOAT;
					break;
				}
				CLOSE_SIGN
				{
					state = State::CLOSE;
					break;
				}
				}
				i++;
			}
		}
	}

	state = State::ELEM;

	// make arr
	{
		while (depth != 0)
		{
			char c = target[index];

		switch (c)
		{
		OPEN_SIGN
		{
			depth++;
			state = State::OPEN;
			break;
		}

		CLOSE_SIGN
		{
			depth--;
			if (state != State::CLOSE)
				state = State::CLOSED;
			break;
		}
		case ',':
		{
			state = State::APPEND;
			break;
		}
		case ' ':
		{
			if (state == State::APPEND)
			{
				state = State::NONE;
				break;
			}
		}
		default:
			aElem += target[index];
			state = State::ELEM;
		}

		switch (state)
		{
		case StringToArray::State::NONE:
			break;
		case StringToArray::State::OPEN:
			break;
		case StringToArray::State::ELEM:
			break;
		case StringToArray::State::CLOSE:
			break;
		case StringToArray::State::APPEND:
			break;
		case StringToArray::State::CLOSED:
			break;

		default:
			break;
		}
		index++;

		}

	}
	return true;
}
