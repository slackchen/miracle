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

		static bool IsSymbol(char ch);

		bool IsEnd() const;

		void SkipBlanks();

		static bool IsNumber(char ch);

		static bool IsAlpha(char ch);

		static bool IsBlanks(char ch);
	};
}
