#ifndef H_LINGO_STRLEN
#define H_LINGO_STRLEN

#include <lingo/constexpr.hpp>

#include <cstddef>

namespace lingo
{
	template <typename UnitT>
	LINGO_CONSTEXPR14 std::size_t strlen(const UnitT* string) noexcept
	{
		const UnitT* null_character = string;
		while (*null_character)
		{
			++null_character;
		}

		return null_character - string;
	}

	template <typename UnitT>
	LINGO_CONSTEXPR14 std::size_t strlen_s(const UnitT* string, std::size_t maximum_size) noexcept
	{
		if (string == nullptr)
		{
			return 0;
		}

		for (size_t i = 0; i < maximum_size; ++i)
		{
			if (string[i] == 0)
			{
				return i;
			}
		}

		return maximum_size;
	}
}

#endif