#include "Lexer.h"

namespace Miracle
{
	Lexer::Lexer(std::string str)
	{
		strData = str;
		pos = 0;
		readCount = 0;
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
		else if (IsBracket(ch))
		{
			return ReadBracket();
		}

		return Token();
	}

	void Lexer::Unread()
	{
		pos -= readCount;
		readCount = 0;
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

		readCount = pos - start;

		Token token;
		token.type = TokenType::Number;
		token.content = strData.substr(start, readCount);
		return token;
	}

	Token Lexer::ReadSymbol()
	{
		char ch = strData[pos];
		int start = pos;
		pos++;

		readCount = pos - start;

		Token token;
		switch (ch)
		{
		case '+':
			token.type = TokenType::SymbolAdd;
			break;
		case '-':
			token.type = TokenType::SymbolSub;
			break;
		case '*':
			token.type = TokenType::SymbolMul;
			break;
		case '/':
			token.type = TokenType::SymbolDiv;
			break;
		}
		token.content = strData.substr(start, readCount);
		return token;
	}

	Token Lexer::ReadBracket()
	{
		char ch = strData[pos];
		int start = pos;
		pos++;

		readCount = pos - start;

		Token token;
		switch (ch)
		{
		case '(':
			token.type = TokenType::LeftBracket;
			break;
		case ')':
			token.type = TokenType::RightBracket;
			break;
		}
		token.content = strData.substr(start, readCount);
		return token;
	}

	bool Lexer::IsSymbol(char ch)
	{
		return ch == '+' || ch == '-' || ch == '*' || ch == '/';
	}

	bool Lexer::IsBracket(char ch)
	{
		return ch == '(' || ch == ')';
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
