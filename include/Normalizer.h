#pragma once
#include <stdexcept>
#include <format>

namespace AudioMix
{
	class Normalizer
	{
	private:
		size_t _leftBorder;
		size_t _rightBorder;
	public:
		Normalizer(size_t leftBorder, size_t rightBorder);
		float Normalize(size_t value);
	};
}