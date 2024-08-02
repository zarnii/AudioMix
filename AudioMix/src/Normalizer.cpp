#include "Normalizer.h"

namespace AudioMix
{
	Normalizer::Normalizer(size_t leftBorder, size_t rightBorder)
	{
		if (leftBorder > rightBorder)
		{
			throw std::range_error("Left border > right border");
		}

		_leftBorder = leftBorder;
		_rightBorder = rightBorder;
	}

	float Normalizer::Normalize(size_t value)
	{
		if (value < _leftBorder)
		{
			throw std::range_error(std::format("Value < left border ({})", _leftBorder));
		}

		if (value > _rightBorder)
		{
			throw std::range_error(std::format("Value > right border ({})", _rightBorder));
		}

		return (float)(value - _leftBorder) / (_rightBorder - _leftBorder);
	}
}