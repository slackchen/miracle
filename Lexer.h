#pragma once

#include <string>

namespace Miracle
{
	enum class TokenType
	{
		None,
		Number,
		SymbolAdd,
		SymbolSub,
		SymbolMul,
		SymbolDiv,
		LeftBracket,
		RightBracket,
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
		int readCount;

	public:
		Lexer(std::string str);

		Token Read();

		void Unread();

		Token PeekToken();

		char PeekChar();

		Token ReadNumber();

		Token ReadSymbol();

		Token ReadBracket();

		static bool IsSymbol(char ch);

		bool IsEnd() const;

		void SkipBlanks();

		static bool IsNumber(char ch);

		static bool IsAlpha(char ch);

		static bool IsBlanks(char ch);

		static bool IsBracket(char ch);
	};
}
