#include "Parser.h"
#include "Compiler.h"

#include <iostream>

using namespace Miracle;

int main()
{
	std::string code = "1 + 3 + 8 + 10000000 + 142142124";

	try
	{
		Parser parser(code);

		SyntaxTree tree = parser.Parse();
		Compiler compiler(tree);
		Assembler assembler(compiler.codes);

		std::cout << code + " = " + assembler.Run() << std::endl;
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}