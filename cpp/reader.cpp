#include "std.h"
#include <ctype.h>

#include "expression.h"
#include "list.h"
#include "reader.h"

namespace Interpreter {

    extern List emptyList;
    const char *prompt;
    const char *primaryPrompt = "-> ";
    const char *secondaryPrompt = "> ";

Expression * error(const char *a, const char *b)
{
    fprintf(stderr,"Error: %s%s\n", a, b);
    return 0;
}

void ReaderClass::printPrimaryPrompt()
{
    prompt = primaryPrompt; 
}

void ReaderClass::printSecondaryPrompt()
{
    prompt = secondaryPrompt;
}

//http://www.delorie.com/gnu/docs/readline/rlman_24.html
/* A static variable for holding the line. */
static char *line_read = (char *)NULL;

void ReaderClass::fillInputBuffer()
{
    /* If the buffer has already been allocated,
       return the memory to the free pool. */
    if (line_read)
    {
        free (line_read);
        line_read = (char *)NULL;

    }
    /* Get a line from the user. */
    line_read = readline(prompt);

    /* If the line has any text in it,
       save it on the history. */
    if (line_read && *line_read) {
        add_history (line_read);
    }
    else if (line_read == NULL) {
        strcpy(line_read,"quit");
    }

    // initialize the current pointer
    p = line_read;
    skipSpaces();
}

int ReaderClass::isSeparator(int c)
{
	switch(c) {
	case ' ': case '\t': case '\n':
	case EOF: case '\0': case '\'':
	case ';': case ')': case '(':

		return 1;
	}
	return 0;
}

void ReaderClass::skipSpaces()
{
	while ((*p == ' ') || (*p == '\t')) p++;
	if (*p == ';')	// comment
		while (*p) p++;	// read until end of line
}

void ReaderClass::skipNewlines()
{
	skipSpaces();
	while (*p == '\0') {	// end of line
		printSecondaryPrompt();
		fillInputBuffer();
		}
}

Expression * ReaderClass::promptAndRead()
{
	// loop until the user types something
	do {
		printPrimaryPrompt();
		fillInputBuffer();
		} while (! *p);

	// now that we have something, break it apart
	Expression * val = readExpression();

	// make sure we are at and of line
	skipSpaces();
	if (*p) {
		error("unexpected characters at end of line:", p);
		}
	return val;
}

Expression * ReaderClass::readExpression()
{
	// see if it's an integer
	if (isdigit(*p))
		return new IntegerExpression(readInteger());

	// might be a signed integer
	if ((*p == '-') && isdigit(*(p+1))) {
		p++;
		return new IntegerExpression(- readInteger());
		}

	// or it might be a list
	if (*p == '(') {
		p++;
		return readList();
		}
	
	// otherwise it must be a symbol
	return readSymbol();
}

int ReaderClass::readInteger()
{
	int val = 0;
	while (isdigit(*p)) {
		val = val * 10 + (*p - '0');
		p++;
		}
	return val;
}

ListNode * ReaderClass::readList()
{
	// skipNewlines will issue secondary prompt
	// until a valid character is typed
	skipNewlines();

	// if end of list, return empty list
	if (*p == ')') {
		p++;
		return emptyList;
		}

	// now we have a non-empty character
	Expression * val = readExpression();
	return new ListNode(val, readList());
}

Symbol * ReaderClass::readSymbol()
{	char token[80], *q;

	for (q = token; ! isSeparator(*p); )
		*q++ = *p++;
	*q = '\0';
	return new Symbol(token);
}

}
