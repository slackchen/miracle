#pragma once

#include <vector>
#include <stack>
#include <string>

namespace Miracle
{
	enum class CodeType
	{
		Mov,
		Add
	};

	class Code
	{
	public:
		CodeType type;
		int n;

		Code(CodeType type)
		{
			this->type = type;
		}
	};

	class Assembler
	{
		std::vector<Code> codes;
		std::stack<int> intStack;

	public:
		Assembler(std::vector<Code> codes);

		std::string Run();
	};
}
