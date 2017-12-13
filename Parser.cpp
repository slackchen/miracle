#include "Parser.h"

namespace Miracle
{
	Parser::Parser(std::string code): lexer(code)
	{
	}

	SyntaxTree Parser::Parse()
	{
		bracketPair = 0;
		ParseExp();
		if (bracketPair != 0)
			ParseError();

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
			if (tokenCurrent.type == TokenType::RightBracket)
			{
				bracketPair--;
				return;
			}
			else if (tokenCurrent.type == TokenType::Number)
			{
				auto n = syntaxTree.CreateNode<SyntaxNodeNumber>();
				n->token = tokenCurrent;
				stack.emplace(n);

				Token nextPeek = lexer.PeekToken(); 
				if (nextPeek.type == TokenType::Number)
					ParseError();
			}
			else if (tokenCurrent.type == TokenType::SymbolAdd
				|| tokenCurrent.type == TokenType::SymbolSub
				|| tokenCurrent.type == TokenType::SymbolMul
				|| tokenCurrent.type == TokenType::SymbolDiv)
			{
				Token op = tokenCurrent;
				Token arg2 = lexer.Read();
				Token nextPeek = lexer.PeekToken();
				SyntaxNodePtr parentNode;

				if (arg2.type == TokenType::LeftBracket)
				{
					bracketPair++;
					if (lexer.PeekToken().type != TokenType::Number)
						ParseError();

					ParseExp();
					parentNode = syntaxTree.currentNode;
				}
				else if (arg2.type != TokenType::Number)
				{
					ParseError();
					return;
				}

				if (
					(tokenCurrent.type == TokenType::SymbolAdd || tokenCurrent.type == TokenType::SymbolSub)
					&& ( nextPeek.type == TokenType::SymbolMul || nextPeek.type == TokenType::SymbolDiv)
					)
				{
					lexer.Unread();
					ParseExp();
					parentNode = syntaxTree.currentNode;

				}


				auto top = stack.top();
				SyntaxNodePtr childNode = stack.size() > 0 ? stack.pop() , top : std::make_shared<SyntaxNode>();

				SyntaxNodePtr opNode;
				switch (op.type)
				{
				case TokenType::SymbolAdd:
					opNode = syntaxTree.CreateNode<SyntaxNodeBinaryOperator>();
					break;
				case TokenType::SymbolSub:
					opNode = syntaxTree.CreateNode<SyntaxNodeBinaryOperator>();
					break;
				case TokenType::SymbolMul:
					opNode = syntaxTree.CreateNode<SyntaxNodeBinaryOperator>();
					break;
				case TokenType::SymbolDiv:
					opNode = syntaxTree.CreateNode<SyntaxNodeBinaryOperator>();
					break;
				}
				
				auto n1 = childNode->token.type != TokenType::None ? opNode->AddChild(childNode) : opNode->CreateNode<SyntaxNodeNumber>();
				auto n2 = parentNode != nullptr ? opNode->AddChild(parentNode) : opNode->CreateNode<SyntaxNodeNumber>();
				opNode->token = op;				
				if (parentNode == nullptr)
					n2->token = arg2;

				stack.emplace(opNode);
			}
			else
			{
				ParseError();
			}

			tokenCurrent = lexer.Read();
		}
	}

	void Parser::ParseError()
	{
		throw std::exception("Parse error");
	}
}
