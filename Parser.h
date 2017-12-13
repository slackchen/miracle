#pragma once

#include <stack>
#include <string>
#include <exception>

#include "Lexer.h"
#include "SyntaxTree.h"

namespace Miracle
{
	class Parser
	{
		Lexer lexer;
		SyntaxTree syntaxTree;
		Token tokenCurrent;

	public:
		Parser(std::string code);

		SyntaxTree Parse();

		void ParseExp();

		static void ParseError();
	};
}
