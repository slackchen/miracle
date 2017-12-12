#include "Parser.h"

namespace Miracle
{
	Parser::Parser(std::string code): lexer(code)
	{
	}

	SyntaxTree Parser::Parse()
	{
		ParseExp();

		return syntaxTree;
	}

	void Parser::ParseExp()
	{
		tokenCurrent = lexer.Read();
		if (tokenCurrent.type == TokenType::None)
		{
			ParseError();
			return;
		}

		std::stack<SyntaxNodePtr> stack;

		while (tokenCurrent.type != TokenType::None)
		{
			if (tokenCurrent.type == TokenType::Number)
			{
				auto n = syntaxTree.CreateNode<SyntaxNodeNumber>();
				n->token = tokenCurrent;
				stack.emplace(n);
			}
			else if (tokenCurrent.type == TokenType::SymbolAdd)
			{
				Token op = tokenCurrent;
				Token arg2 = lexer.Read();

				if (arg2.type == TokenType::None)
				{
					ParseError();
					return;
				}

				auto top = stack.top();
				SyntaxNodePtr childNode = stack.size() > 0 ? stack.pop() , top : std::make_shared<SyntaxNode>();

				auto add = syntaxTree.CreateNode<SyntaxNodeAddOperator>();
				auto n1 = childNode->token.type != TokenType::None ? add->AddChild(childNode) : add->CreateNode<SyntaxNodeNumber>();
				auto n2 = add->CreateNode<SyntaxNodeNumber>();
				add->token = op;
				n2->token = arg2;

				stack.emplace(add);
			}

			tokenCurrent = lexer.Read();
		}
	}

	void Parser::ParseError()
	{
		throw std::exception("Parse error");
	}
}
