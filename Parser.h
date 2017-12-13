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
		int bracketPair;

	public:
		Parser(std::string code);

		SyntaxTree Parse();

		void ParseExp();

		static void ParseError();

		template <class T>
		inline SyntaxNodePtr CreateNode(SyntaxNodePtr node)
		{
			if (node != nullptr)
				return node->childs[0]->CreateNode<T>();

			return syntaxTree.CreateNode<T>();
		}
	};
}
