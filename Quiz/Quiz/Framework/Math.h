#pragma once

namespace Math
{
	void Clamp(int min, int max, int& value)
	{
		if (value < min) value = min;
		if (value > max) value = max;
	}
}