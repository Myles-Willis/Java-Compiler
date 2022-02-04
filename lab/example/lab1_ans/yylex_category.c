/*
    Author: Bill Luo
*/

#include <stdio.h>
#include <stdlib.h>
#define VOWELS 1
#define CONSONANTS 2
#define DIGITS 3
#define PUNCTUATION 4
#define WHITESPACE 5

static char vowels[] = "aeiouAEIOU";
static char consonants[] = "bcdfghjklmnpqrstuvwxyzBCDFGHJKLMNPQRSTUVWXYZ";
static char digits[] = "0123456789";
static char punc[] = "~!<>?/@#$%^&*()-+={}[]|,.:;'\"\\`";
static char whitespace[] = " \t\n";

struct Pattern {
    int category;
    char *pattern;
};

// initialize array of patterns 
struct Pattern patterns[5] = {
    {VOWELS, vowels},
    {CONSONANTS, consonants},
    {DIGITS, digits},
    {PUNCTUATION, punc},
    {WHITESPACE, whitespace},
};

FILE *yyin;
// a flag indicating whether the last characters is EOF or not.
int eof_reached = 0;

int find_category(struct Pattern p, FILE *ifp) {
    int c;
    // a flag indicating any match for adjacent characters
    int matched_once = 0;
    // pre-check eof_reached flag, return EOF if is 1
    if (eof_reached) {
        return EOF;
    }
    while ((c=getc(ifp)) != EOF) {
        // flag indicating any match for the current characters
        int current_matched = 0;
        for (int i=0; p.pattern[i]!=0; i++) {
            if (p.pattern[i] == c) {
                current_matched = 1;
                matched_once = 1;
                continue;
            }
        }
        if (current_matched == 0) {
            ungetc(c,ifp);
            break;
        }
    }
    // If the last character is EOF, then we step up eof_reached flag to 1.
    if (c == EOF) {
        eof_reached = 1;
    }
    if (matched_once)
        return p.category;
    
    return 0;
}

int yylex()
{
    for (int i = 0; i < sizeof(patterns)/sizeof(patterns[0]); i++) {
        int ret_val = find_category(patterns[i], yyin);
        if (ret_val == 0)
            continue;
        return ret_val;
    }

    return EOF;
}