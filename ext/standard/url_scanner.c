/* Generated by re2c 0.5 on Thu Oct 21 22:22:05 1999 */
#line 1 "url_scanner.re"
/*
   +----------------------------------------------------------------------+
   | PHP version 4.0                                                      |
   +----------------------------------------------------------------------+
   | Copyright (c) 1997, 1998, 1999 The PHP Group                         |
   +----------------------------------------------------------------------+
   | This source file is subject to version 2.0 of the PHP license,       |
   | that is bundled with this package in the file LICENSE, and is        |
   | available at through the world-wide-web at                           |
   | http://www.php.net/license/2_0.txt.                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Author: Sascha Schumann <sascha@schumann.cx>                         |
   +----------------------------------------------------------------------+
 */
/* $Id$ */

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#undef MIN
#define MIN(a,b) (a)<(b)?(a):(b)

#define YYCTYPE char
#define YYCURSOR state->crs
#define YYLIMIT state->end
#define YYMARKER state->ptr
#define YYFILL(n)

typedef enum {
	INITIAL,
	REF
} state;

typedef struct {
	state state;
	const char *crs;
	const char *end;
	const char *ptr;
	const char *start;
	char *target;
	size_t targetsize;
	const char *data;
} lexdata;

#define FINISH { catchup(state); goto finish; }

#define BEGIN(x) 						\
		switch(state->state) { 			\
			case INITIAL: 				\
				catchup(state); 		\
				break; 					\
			case REF: 					\
				screw_url(state); 		\
				break; 					\
		} 								\
		state->state = x; 				\
		state->start = state->crs; 		\
		goto nextiter

#define ATTACH(s, n) 										\
{ 															\
	size_t _newlen = state->targetsize + n; 				\
	state->target = realloc(state->target, _newlen + 1); 	\
	memcpy(state->target + state->targetsize, s, n); 		\
	state->targetsize = _newlen; 							\
	state->target[_newlen] = '\0'; 							\
}
	
#define URLLEN 512
	
static void screw_url(lexdata *state)
{
	int len;
	char buf[URLLEN];
	char url[URLLEN];
	const char *p, *q;
	char c;

	/* search outer limits for URI */
	for(p = state->start; p < state->crs && (c = *p); p++)
		if(c != '"' && c != ' ') break;

	/*  
	 *  we look at q-1, because q points to the character behind the last
	 *  character we are going to copy and the decision is based on that last
	 *  character 
	 */

	for(q = state->crs; q > state->start && (c = *(q-1)); q--)
		if(c != '"' && c != ' ') break;

	/* attach beginning */
	
	ATTACH(state->start, p-state->start);
	
	/* copy old URI */
	len = MIN(q - p, sizeof(buf) - 1);
	memcpy(url, p, len);
	url[len] = '\0';
	
	/* construct new URI */
	len = snprintf(buf, sizeof(buf), "%s%c%s", url,
			memchr(state->start, '?', len) ? '&' : '?',
			state->data);

	/* attach new URI */
	ATTACH(buf, len);
	
	/* attach rest */
	ATTACH(q, state->crs - q);
}

static void catchup(lexdata *state) 
{
	ATTACH(state->start, (state->crs - state->start));
}

#line 135


static void url_scanner(lexdata *state)
{
	while(state->crs < state->end) {
	
	switch(state->state) {
		case INITIAL: 
{
	YYCTYPE yych;
	unsigned int yyaccept;
	goto yy0;
yy1:	++YYCURSOR;
yy0:
	if((YYLIMIT - YYCURSOR) < 7) YYFILL(7);
	yych = *YYCURSOR;
	switch(yych){
	case '\000':	goto yy7;
	case '<':	goto yy2;
	default:	goto yy4;
	}
yy2:	yych = *++YYCURSOR;
	switch(yych){
	case 'A':	case 'a':	goto yy9;
	case 'F':	case 'f':	goto yy10;
	default:	goto yy3;
	}
yy3:yy4:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy5:	switch(yych){
	case '\000':	case '<':	goto yy6;
	default:	goto yy4;
	}
yy6:
#line 147
	{ BEGIN(INITIAL); }
yy7:	yych = *++YYCURSOR;
yy8:
#line 148
	{ FINISH; }
yy9:	yych = *++YYCURSOR;
	switch(yych){
	case 'H':	case 'h':	goto yy3;
	case 'R':	case 'r':	goto yy26;
	default:	goto yy25;
	}
yy10:	yych = *++YYCURSOR;
	switch(yych){
	case 'R':	case 'r':	goto yy11;
	default:	goto yy3;
	}
yy11:	yych = *++YYCURSOR;
	switch(yych){
	case 'A':	case 'a':	goto yy12;
	default:	goto yy3;
	}
yy12:	yych = *++YYCURSOR;
	switch(yych){
	case 'M':	case 'm':	goto yy13;
	default:	goto yy3;
	}
yy13:	yych = *++YYCURSOR;
	switch(yych){
	case 'E':	case 'e':	goto yy14;
	default:	goto yy3;
	}
yy14:	yych = *++YYCURSOR;
	switch(yych){
	case 'S':	case 's':	goto yy3;
	default:	goto yy16;
	}
yy15:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy16:	switch(yych){
	case '\t':	case '\v':
	case '\f':	case ' ':	goto yy15;
	case 'S':	case 's':	goto yy17;
	default:	goto yy3;
	}
yy17:	yych = *++YYCURSOR;
	switch(yych){
	case 'R':	case 'r':	goto yy18;
	default:	goto yy3;
	}
yy18:	yych = *++YYCURSOR;
	switch(yych){
	case 'C':	case 'c':	goto yy19;
	default:	goto yy3;
	}
yy19:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy20:	switch(yych){
	case '\t':	case '\v':
	case '\f':	case ' ':	goto yy19;
	case '=':	goto yy21;
	default:	goto yy3;
	}
yy21:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy22:	switch(yych){
	case '\t':	case '\v':
	case '\f':	case ' ':	goto yy21;
	default:	goto yy23;
	}
yy23:
#line 144
	{ BEGIN(REF); }
yy24:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy25:	switch(yych){
	case '\t':	case '\v':
	case '\f':	case ' ':	goto yy24;
	case 'H':	case 'h':	goto yy39;
	default:	goto yy3;
	}
yy26:	yych = *++YYCURSOR;
	switch(yych){
	case 'E':	case 'e':	goto yy27;
	default:	goto yy3;
	}
yy27:	yych = *++YYCURSOR;
	switch(yych){
	case 'A':	case 'a':	goto yy28;
	default:	goto yy3;
	}
yy28:	yych = *++YYCURSOR;
	switch(yych){
	case 'H':	case 'h':	goto yy3;
	default:	goto yy30;
	}
yy29:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy30:	switch(yych){
	case '\t':	case '\v':
	case '\f':	case ' ':	goto yy29;
	case 'H':	case 'h':	goto yy31;
	default:	goto yy3;
	}
yy31:	yych = *++YYCURSOR;
	switch(yych){
	case 'R':	case 'r':	goto yy32;
	default:	goto yy3;
	}
yy32:	yych = *++YYCURSOR;
	switch(yych){
	case 'E':	case 'e':	goto yy33;
	default:	goto yy3;
	}
yy33:	yych = *++YYCURSOR;
	switch(yych){
	case 'F':	case 'f':	goto yy34;
	default:	goto yy3;
	}
yy34:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy35:	switch(yych){
	case '\t':	case '\v':
	case '\f':	case ' ':	goto yy34;
	case '=':	goto yy36;
	default:	goto yy3;
	}
yy36:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy37:	switch(yych){
	case '\t':	case '\v':
	case '\f':	case ' ':	goto yy36;
	default:	goto yy38;
	}
yy38:
#line 146
	{ BEGIN(REF); }
yy39:	yych = *++YYCURSOR;
	switch(yych){
	case 'R':	case 'r':	goto yy40;
	default:	goto yy3;
	}
yy40:	yych = *++YYCURSOR;
	switch(yych){
	case 'E':	case 'e':	goto yy41;
	default:	goto yy3;
	}
yy41:	yych = *++YYCURSOR;
	switch(yych){
	case 'F':	case 'f':	goto yy42;
	default:	goto yy3;
	}
yy42:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy43:	switch(yych){
	case '\t':	case '\v':
	case '\f':	case ' ':	goto yy42;
	case '=':	goto yy44;
	default:	goto yy3;
	}
yy44:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy45:	switch(yych){
	case '\t':	case '\v':
	case '\f':	case ' ':	goto yy44;
	default:	goto yy46;
	}
yy46:
#line 145
	{ BEGIN(REF); }
}
#line 149

			break;
		case REF: 
{
	YYCTYPE yych;
	unsigned int yyaccept;
	goto yy47;
yy48:	++YYCURSOR;
yy47:
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	switch(yych){
	case '\000':	case '#':	case '>':	goto yy49;
	case '\t':	case '\v':
	case '\f':	case ' ':	case '"':	goto yy50;
	case ':':	goto yy55;
	default:	goto yy52;
	}
yy49:yy50:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy51:	switch(yych){
	case '\000':	case '"':
	case '#':	case '>':	goto yy49;
	case '\t':	case '\v':
	case '\f':	case ' ':	goto yy50;
	case ':':	goto yy55;
	default:	goto yy52;
	}
yy52:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy53:	switch(yych){
	case '\000':	case '>':	goto yy54;
	case '\t':	case '\v':
	case '\f':	case ' ':	goto yy61;
	case '"':	goto yy63;
	case '#':	goto yy64;
	case ':':	goto yy55;
	default:	goto yy52;
	}
yy54:
#line 153
	{ BEGIN(INITIAL); }
yy55:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy56:	switch(yych){
	case '\000':	case '#':	case '>':	goto yy57;
	case '\t':	case '\v':
	case '\f':	case ' ':	goto yy58;
	case '"':	goto yy60;
	default:	goto yy55;
	}
yy57:
#line 155
	{ 
			/* don't modify absolute links */
			state->state = INITIAL; BEGIN(INITIAL); 
	}
yy58:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy59:	switch(yych){
	case '\t':	case '\v':
	case '\f':	case ' ':	goto yy58;
	case '"':	goto yy60;
	default:	goto yy57;
	}
yy60:	yych = *++YYCURSOR;
	goto yy57;
yy61:	++YYCURSOR;
	if(YYLIMIT == YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
yy62:	switch(yych){
	case '\t':	case '\v':
	case '\f':	case ' ':	goto yy61;
	case '"':	goto yy63;
	default:	goto yy54;
	}
yy63:	yych = *++YYCURSOR;
	goto yy54;
yy64:	yych = *++YYCURSOR;
yy65:	YYCURSOR -= 1;
#line 154
	{ BEGIN(INITIAL); }
}
#line 159

  			break;
	}
nextiter:
	;
	}
finish:
	;
}

char *url_adapt(const char *src, size_t srclen, const char *data, size_t *newlen)
{
	lexdata state;

	state.state = INITIAL;
	state.start = state.crs = src;
	state.end = src + srclen;
	state.ptr = NULL;
	state.target = NULL;
	state.targetsize = 0;
	state.data = data;

	url_scanner(&state);

	if(newlen) *newlen = state.targetsize;

	return state.target;
}
