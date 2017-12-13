#pragma once

#include <vector>
#include <memory>

#include "Lexer.h"


namespace Miracle
{	
	typedef std::shared_ptr<class SyntaxNode> SyntaxNodePtr;

	class SyntaxNode
	{
	public:
		std::vector<SyntaxNodePtr> childs;
		Token token;

		template <class T>
		SyntaxNodePtr CreateNode()
		{
			SyntaxNodePtr node = std::make_shared<T>();
			childs.emplace_back(node);

		return node;
		}

		SyntaxNodePtr AddChild(SyntaxNodePtr child);
	};

	class SyntaxNodeNumber : public SyntaxNode
	{
	public:
		SyntaxNodeNumber()
		{
		}
	};

	class SyntaxNodeBinaryOperator : public SyntaxNode
	{
	public:
		SyntaxNodeBinaryOperator()
		{
		}
	};

	class SyntaxNodeAddOperator : public SyntaxNodeBinaryOperator
	{
	public:
		SyntaxNodeAddOperator()
		{
		}
	};

	class SyntaxNodeSubOperator : public SyntaxNodeBinaryOperator
	{
	public:
		SyntaxNodeSubOperator()
		{
		}
	};

	class SyntaxTree
	{
	public:
		SyntaxNodePtr root;
		SyntaxNodePtr currentNode;

		template <class T>
		SyntaxNodePtr CreateNode()
		{
			currentNode = std::make_shared<T>();
			root = currentNode;

		return currentNode;
		}
	};
}
