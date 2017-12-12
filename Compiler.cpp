#include "Compiler.h"

namespace Miracle
{
	Compiler::Compiler(SyntaxTree syntaxTree)
	{
		Build(syntaxTree.root);
	}

	void Compiler::Build(SyntaxNodePtr syntaxNode)
	{
		codes = std::vector<Code>();
		Visit(syntaxNode);
	}

	void Compiler::Visit(SyntaxNodePtr syntaxNode)
	{
		if (!syntaxNode->childs.empty())
		{
			for (auto& syntaxNodeChild : syntaxNode->childs)
			{
				Visit(syntaxNodeChild);
			}
		}

		switch (syntaxNode->token.type)
		{
		case TokenType::SymbolAdd:
			{
				Code code(CodeType::Add);
				codes.emplace_back(code);
				break;
			}
		case TokenType::Number:
			{
				Code code(CodeType::Mov);
				code.n = std::stoi(syntaxNode->token.content);
				codes.emplace_back(code);
				break;
			}
		}
	}
}
