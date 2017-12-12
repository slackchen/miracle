#include "SyntaxTree.h"

namespace Miracle
{
	SyntaxNodePtr SyntaxNode::AddChild(SyntaxNodePtr child)
	{
		childs.emplace_back(child);
		return child;
	}
}
