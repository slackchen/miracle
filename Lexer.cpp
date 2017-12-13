#include "Lexer.h"

namespace Miracle
{
	Lexer::Lexer(std::string str)
	{
		strData = str;
		pos = 0;
	}

	Token Lexer::Read()
	{
		SkipBlanks();

		if (IsEnd())
			return Token();

		char ch = strData[pos];
		if (IsNumber(ch))
		{
			return ReadNumber();
		}
		else if (IsSymbol(ch))
		{
			return ReadSymbol();
		}

		return Token();
	}

	Token Lexer::PeekToken()
	{
		int savePos = pos;

		Token token = Read();

		pos = savePos;

		return token;
	}

	char Lexer::PeekChar()
	{
		return strData[pos];
	}

	Token Lexer::ReadNumber()
	{
		int start = pos;

		while (!IsEnd() && IsNumber(PeekChar()))
			pos++;

		Token token;
		token.type = TokenType::Number;
		token.content = strData.substr(start, pos - start);
		return token;
	}

	Token Lexer::ReadSymbol()
	{
		int start = pos;
		pos++;

		Token token;
		token.type = TokenType::SymbolAdd;
		token.content = strData.substr(start, pos - start);
		return token;
	}

	bool Lexer::IsSymbol(char ch)
	{
		return ch == '+';
	}

	bool Lexer::IsEnd() const
	{
		return pos >= strData.length();
	}

	void Lexer::SkipBlanks()
	{
		while (!IsEnd() && IsBlanks(strData[pos]))
			pos++;
	}

	bool Lexer::IsNumber(char ch)
	{
		return ch >= '0' && ch <= '9';
	}

	bool Lexer::IsAlpha(char ch)
	{
		return ch >= 'a' && ch <= 'z' || (ch >= 'A' && ch <= 'Z');
	}

	bool Lexer::IsBlanks(char ch)
	{
		return ch == ' ' || ch == '\r' || ch == '\n';
	}
}
