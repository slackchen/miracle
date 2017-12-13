#pragma once

#include "Assembler.h"
#include "SyntaxTree.h"

namespace Miracle
{
	class Compiler
	{
	public:
		std::vector<Code> codes;

		Compiler(SyntaxTree syntaxTree);

		void Build(SyntaxNodePtr syntaxNode);

		void Visit(SyntaxNodePtr syntaxNode);
	};
}
