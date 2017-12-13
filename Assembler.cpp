#include "Assembler.h"

namespace Miracle
{
	Assembler::Assembler(std::vector<Code> codes)
	{
		this->codes = codes;
	}

	std::string Assembler::Run()
	{
		intStack = std::stack<int>();
		std::string strResult = "";

		for (auto& code : codes)
		{
			switch (code.type)
			{
			case CodeType::Mov:
			{
				intStack.emplace(code.n);
				break;
			}
			case CodeType::Add:
			{
				int n1 = intStack.top();
				intStack.pop();
				int n2 = intStack.top();
				intStack.pop();
				int result = n1 + n2;
				intStack.emplace(result);
				strResult = std::to_string(result);
				break;
			}
			case CodeType::Sub:
			{
				int n1 = intStack.top();
				intStack.pop();
				int n2 = intStack.top();
				intStack.pop();
				int result = n2 - n1;
				intStack.emplace(result);
				strResult = std::to_string(result);
				break;

			}
			case CodeType::Mul:
			{
				int n1 = intStack.top();
				intStack.pop();
				int n2 = intStack.top();
				intStack.pop();
				int result = n2 * n1;
				intStack.emplace(result);
				strResult = std::to_string(result);
				break;

			}
			case CodeType::Div:
			{
				int n1 = intStack.top();
				intStack.pop();
				int n2 = intStack.top();
				intStack.pop();
				int result = n2 / n1;
				intStack.emplace(result);
				strResult = std::to_string(result);
				break;

			}
			}
		}

		return strResult;
	}
}
