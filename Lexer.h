#pragma once

#include <string>

namespace Miracle
{
	enum class TokenType
	{
		None,
		Number,
		SymbolAdd,
		EndSymbol
	};

	struct Token
	{		
		TokenType type = TokenType::None;
		std::string content;
	};


	class Lexer
	{
		std::string strData;
		size_t pos;

	public:
		Lexer(std::string str);

		Token Read();

		Token PeekToken();

		char PeekChar();

		Token ReadNumber();

		Token ReadSymbol();

		bool IsSymbol(char ch);

		bool IsEnd();

		void SkipBlanks();

		bool IsNumber(char ch);

		bool IsAlpha(char ch);

		bool IsBlanks(char ch);
	};
}
