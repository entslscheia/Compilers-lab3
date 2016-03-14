#include <stdlib.h>
#include <stdio.h>
#include "node.h"
#include "intercode.h"

extern FILE* yyin;
node *root = NULL;
InterCodes* ics;
int main(int argc, char** argv)
{
	if ( argc <= 2 ) return 1;
	FILE* f = fopen(argv[1], "r");
	if ( !f )
	{
		perror(argv[1]);
		return 1;
	}
	yyrestart(f);
	yyparse();
	print_intercode(ics, argv[2]);
	return 0;
}


