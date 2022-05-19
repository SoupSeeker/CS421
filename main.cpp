#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;

ifstream fin;  // global stream for reading from the input file
ofstream out;  // global stream for writing to file

/* INSTRUCTION:  copy your parser.cpp here
      cp ../ParserFiles/parser.cpp .
   Then, insert or append its contents into this file and edit.
   Complete all ** parts.
*/
//=====================================================
// File scanner.cpp written by: Group Number: 10
//=====================================================

// --------- Two DFAs ---------------------------------

// WORD DFA 
// Done by: Sophia
bool word(string s)
{
    int state = 0;
    int charpos = 0;
    // replace the following todo the word dfa  **
    while (s[charpos] != '\0')
    {
        //trs(q0,V) = q0q1
        if (state == 0 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' || s[charpos] == 'E'))
        {
            state = 1;
        }
        //trs(q0,'c') = qC
        else if (state == 0 && s[charpos] == 'c')
        {
            state = 2;
        }
        //trs(q0,'s') = qS
        else if (state == 0 && s[charpos] == 's')
        {
            state = 3;
        }
        //trs(q0,'t') = qT
        else if (state == 0 && s[charpos] == 't')
        {
            state = 4;
        }
        //trs(q0,'bghkmnpr') = qY
        else if (state == 0 && (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' || s[charpos] == 'k' || s[charpos] == 'm' || s[charpos] == 'n' || s[charpos] == 'p' || s[charpos] == 'r'))
        {
            state = 5;
        }
        //trs(q0,'dwzyj') = qSa
        else if (state == 0 && (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' || s[charpos] == 'y' || s[charpos] == 'j'))
        {
            state = 6;
        }
        //trs(qSa,V) = q0q1
        else if (state == 6 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' || s[charpos] == 'E'))
        {
            state = 1;
        }
        //trs(qY,V) = q0q1
        else if (state == 5 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' || s[charpos] == 'E'))
        {
            state = 1;
        }
        //trs(qY,'y') = qSa
        else if (state == 5 && s[charpos] == 'y')
        {
            state = 6;
        }
        //trs(qT,V) = q0q1
        else if (state == 4 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' || s[charpos] == 'E'))
        {
            state = 1;
        }
        //trs(qT,'s') = qSa
        else if (state == 4 && s[charpos] == 's')
        {
            state = 6;
        }
        //trs(qS,V) = q0q1
        else if (state == 3 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' || s[charpos] == 'E'))
        {
            state = 1;
        }
        //trs(qS,'h') = qSa
        else if (state == 3 && s[charpos] == 'h')
        {
            state = 6;
        }
        //trs(qC,'h') = qSa
        else if (state == 2 && s[charpos] == 'h')
        {
            state = 6;
        }
        //trs(q0q1,V) = q0q1
        else if (state == 1 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' || s[charpos] == 'E'))
        {
            state = 1;
        }
        //trs(q0q1,'c') = qC
        else if (state == 1 && s[charpos] == 'c')
        {
            state = 2;
        }
        //trs(q0q1,'s') = qS
        else if (state == 1 && s[charpos] == 's')
        {
            state = 3;
        }
        //trs(q0q1,'t') = qT
        else if (state == 1 && s[charpos] == 't')
        {
            state = 4;
        }
        //trs(q0q1,'bghkmpr') = qY
        else if (state == 1 && (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' || s[charpos] == 'k' || s[charpos] == 'm' || s[charpos] == 'p' || s[charpos] == 'r'))
        {
            state = 5;
        }
        //trs(q0q1,'dwzyj') = qSa
        else if (state == 1 && (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' || s[charpos] == 'y' || s[charpos] == 'j'))
        {
            state = 6;
        }
        //trs(q0q1,'n') = q0qY   **new state
        else if (state == 1 && s[charpos] == 'n')
        {
            state = 7;
        }
        //trs(q0qY,V) = q0q1
        else if (state == 7 && (s[charpos] == 'a' || s[charpos] == 'i' || s[charpos] == 'u' || s[charpos] == 'e' || s[charpos] == 'o' || s[charpos] == 'I' || s[charpos] == 'E'))
        {
            state = 1;
        }
        //trs(q0qY,'c') = qC
        else if (state == 7 && s[charpos] == 'c')
        {
            state = 2;
        }
        //trs(q0qY,'s') = qS
        else if (state == 7 && s[charpos] == 's')
        {
            state = 3;
        }
        //trs(q0qY,'t') = qT
        else if (state == 7 && s[charpos] == 't')
        {
            state = 4;
        }
        //trs(q0qY,'bghkmnpr') = qY
        else if (state == 7 && (s[charpos] == 'b' || s[charpos] == 'g' || s[charpos] == 'h' || s[charpos] == 'k' || s[charpos] == 'm' || s[charpos] == 'n' || s[charpos] == 'p' || s[charpos] == 'r'))
        {
            state = 5;
        }
        //trs(q0qY,'dwzyj') = qSa
        else if (state == 7 && (s[charpos] == 'd' || s[charpos] == 'w' || s[charpos] == 'z' || s[charpos] == 'y' || s[charpos] == 'j'))
        {
            state = 6;
        }
        //trs(q0qY,'y') = qSa
        else if (state == 7 && s[charpos] == 'y')
        {
            state = 6;
        }
        else
        {
            return(false);
        }

        charpos++;
    }//end of while

    // where did I end up????
    if (state == 1 || state == 7)
    {
        return(true);  // end in a final state
    }
    else
    {
        return(false);
    }
}

// PERIOD DFA 
// Done by: Sophia
bool period(string s)
{  // complete this **
    int state = 0;
    int charpos = 0;
    while (s[charpos] != '\0')
    {
        if (state == 0 && s[charpos] == '.')
        {
            state = 1;
        }
        else
        {
            return(false);
        }
        charpos++;
    } //end of while

    // where did I end up????
    if (state == 1)
    {
        return(true);  // end in a final state
    }
    else
    {
        return(false);
    }
}
// ------ Three  Tables : tokentype, tokenName, reservedWords--------------------

// TABLES Done by: Sophia
// ** Update the tokentype to be WORD1, WORD2, PERIOD, ERROR, EOFM, etc.
enum tokentype {
    ERROR, WORD1, WORD2, PERIOD, VERB, VERBNEG,
    VERBPAST, VERBPASTNEG, IS, WAS, OBJECT, SUBJECT, DESTINATION,
    PRONOUN, CONNECTOR, EOFM
};

// ** For the display names of tokens - must be in the same order as the tokentype.
string tokenName[30] = { "ERROR", "WORD1", "WORD2", "PERIOD", "VERB", "VERBNEG",
                        "VERBPAST", "VERBPASTNEG", "IS", "WAS", "OBJECT", "SUBJECT", "DESTINATION",
                        "PRONOUN", "CONNECTOR", "EOFM" };

// ** Need the reservedwords table to be set up here. 
// ** Do not require any file input for this. Hard code the table.
// ** a.out should work without any additional files.
string reservedWords[20][2] =
{
  "masu", "VERB",
  "masen", "VERBNEG",
  "mashita", "VERBPAST",
  "masendeshita", "VERBPASTNEG",
  "desu", "IS",
  "deshita", "WAS",
  "o", "OBJECT",
  "wa", "SUBJECT",
  "ni", "DESTINATION",
  "watashi", "PRONOUN",
  "anata", "PRONOUN",
  "kare", "PRONOUN",
  "kanojo", "PRONOUN",
  "sore", "PRONOUN",
  "mata", "CONNECTOR",
  "soshite", "CONNECTOR",
  "shikashi", "CONNECTOR",
  "dakara", "CONNECTOR",
  "eofm", "EOFM"
};


// ------------ Scanner and Driver ----------------------- 

// Scanner processes only one word each time it is called
// Gives back the token type and the word itself
// ** Done by: Jake 
int scanner(tokentype& tt, string& w)
{
    fin >> w;                               // ** Grab the next word from the file via fin
    cout << "Scanner called using word: " << w << endl;
    if (w == "eofm") {
        tt = EOFM;
        return 0;              // 1. If it is eofm, return right now.   
    }


    //2. Call the token functions (word and period) one after another (if-then-else).
    //   Generate a lexical error message if both DFAs failed. Let the tokentype be ERROR in that case.

    if (word(w)) {  
        bool reserved = false;
        //w is a recognized word, do step 3 check against reserved
        int resSize = sizeof(reservedWords) / sizeof(reservedWords[0][0]);
        for (int i = 0; i < resSize / 2; i++) {
            if (w == reservedWords[i][0]) {
                string tokenType = reservedWords[i][1];         //if we find a match in the reservedWords list
                int numOfEle = sizeof(tokenName) / sizeof(tokenName[0]);

                for (int j = 0; j < numOfEle; j++) {            //go through until we find the correct token type then break
                    if (tokenType == tokenName[j]) {
                        tt = (tokentype)j;
                        reserved = true;                        //allows us to shortcut out of the scanner
                        break;
                    }
                }
                break;
            }
        }

        if (reserved) return 0;             //if the word was found to be a reserved word our work is done

        char back = *w.rbegin();
        if (back == 'I' || back == 'E') {       //if the word wasn't reserved, it becomes a WORD1 if it does not have a capital I or E
            tt = WORD2;
        }
        else {
            tt = WORD1;
        }
    }
    else if (period(w)) {                    //if it wasn't a word, it must be a period
        //s is a period
        tt = PERIOD;
    }
    else {                                  //otherwise it is an error
        //lexical error
        tt = ERROR;
        cout << "LEXICAL ERROR" << endl;
    }

    return 0;

}//the end of scanner

// The temporary test driver to just call the scanner repeatedly  
// This will go away after this assignment
// DO NOT CHANGE THIS!!!!!! 
// Done by:  Louis
/*
int main()
{
    tokentype thetype;
    string theword;
    string filename;

    cout << "Enter the input file name: ";
    cin >> filename;

    fin.open(filename.c_str());

    // the loop continues until eofm is returned.
    while (true)
    {
        scanner(thetype, theword);  // call the scanner which sets
                                    // the arguments
        if (theword == "eofm") break;  // stop now

        cout << "Type is:" << tokenName[thetype] << endl;
        cout << "Word is:" << theword << endl << endl;
    }

    cout << "End of file is encountered." << endl;
    fin.close();

}
*/
// end of scanner section


//=========================================================================
/* INSTRUCTION:  Complete all ** parts.
   You may use any method to connect this file to scanner.cpp
   that you had written.
  e.g. You can copy scanner.cpp here by: cp ../ScannerFiles/scanner.cpp .
       and then append the two files into one: cat scanner.cpp parser.cpp > myparser.cpp
*/

//=================================================
// File parser.cpp written by Group Number: 10
//=================================================

// ----- Four Utility Functions and Globals -----------------------------------
enum parserToken { STORY, S, AFTERSUBJECT, AFTERNOUN, AFTEROBJECT, VERBP, TENSE, NOUN, BE };

// ** For the display names of tokens - must be in the same order as the tokentype.
string parserName[30] = { "story", "s", "afterSubject", "afterNoun", "afterObject", "verb",
                        "tense", "noun", "be" };

// ** Need syntaxerror1 and syntaxerror2 functions (each takes 2 args)
//    to display syntax error messages as specified by me.  
// ** Need the updated match and next_token with 2 global vars
// saved_token and saved_lexeme
string saved_lexeme;
tokentype saved_token;
bool available = false;         //necessary to control how fast our tokens are getting read

// Type of error:  Expected .. but found .. 
// Done by: Jake
void syntaxError1(tokentype expected) {
    cout << "SYNTAX ERROR: expected argument doesn't match provided argument" << endl;
    cout << "Expected:  " << tokenName[expected] << "  received:  " << saved_lexeme << endl;
    exit(1);
}

// Type of error: Unexpected token found in ...
// Done by: Sophia
void syntaxError2(parserToken ptoken)
{
    cout << endl << "SYNTAX ERROR: unexpected " << saved_lexeme << " found in " << parserName[ptoken] << endl;
    exit(1);
}

// Purpose: call scanner to get new token
// Done by: Sophia
tokentype next_token()
{
    if (available == false)             //this boolean helps us control when we actually grab a new token from scanner
    {
        scanner(saved_token, saved_lexeme);     //within scanner we jump forward each time, but we need to take it 1 token at a time :)
        available = true;
    }

    return saved_token;
}

// Purpose: If the next token is the expected type we can pop the stack (or something like that)
// Done by: Jake
bool match(tokentype expected)
{
    if (next_token() != expected)
    {
        cout << "Mismatch" << endl;
        available = false;
        syntaxError1(expected);
        return false;
    }
    else
    {
        cout << "Matched:  " << tokenName[expected] << endl;
        available = false;
        return true;
    }
    return false;
}

//----------- Driver ---------------------------

// The new test driver to start the parser
// Done by: Josh / Jake / L. Krell
/*
int main()
{
    string filename;

    cout << "Enter the input file name: ";
    cin >> filename;
    fin.open(filename.c_str());

    //** calls the <story> to start parsing
    story();
    //** closes the input file 
    fin.close();

}
*/
// end
//** require no other input files!
//** syntax error EC requires producing errors.txt of error messages
//** tracing On/Off EC requires sending a flag to trace message output functions


//=================================================
// File translator.cpp written by Group Number: 10
//=================================================

// ----- Additions to the parser.cpp ---------------------

// ** Declare Lexicon (i.e. dictionary) that will hold the content of lexicon.txt
// Make sure it is easy and fast to look up the translation.
// Do not change the format or content of lexicon.txt 
//  Done by: Jake
string lexicon[50][2] = { " " };
string saved_E_word;

// Only called one time by the driver, just loads the contentes from text file
void makeLexicon() {
    fin.open("lexicon.txt");        //file open
    int i = 0;

    while (fin.good()) {
        string japanese, english;
        fin >> japanese;
        fin >> english;
        lexicon[i][0] = japanese;   //take the japanese word into left column
        lexicon[i][1] = english;    //take the english word into right column
        i++;
    }
    fin.close();                    //file closed
}

// ** Additions to parser.cpp here:
//    getEword() - using the current saved_lexeme, look up the English word
//                 in Lexicon if it is there -- save the result   
//                 in saved_E_word
//  In our lexicon 2d array, the words go straight down in ~50 rows
//  therfore we need to use the rows as our index to check for word
//  worst case time complexity --> O(n), average O(n), best O(1)
//  Done by: Jake

void getEword() {
    int rows = sizeof(lexicon) / sizeof(lexicon[0]);
    for (int i = 0; i < rows; i++) {                //step through lexicon and see if saved item is found
        if (lexicon[i][0] == saved_lexeme) {
            saved_E_word = lexicon[i][1];
            return;
        }
    }

    //if no word is found, then use the saved item instead
    saved_E_word = saved_lexeme;
}


//    gen(line_type) - using the line type,
//                     sends a line of an IR to translated.txt
//                     (saved_E_word or saved_token is used)
//  Done by: Jake

void gen(string line_type) {
    
    if (line_type == "TENSE") {     //if tense gets passed, we need to use saved_token as given in comments
        string tense = tokenName[saved_token];          //from test1result.txt, notice that all the TENSE: are followed by saved_token
        out << line_type << "  " << tense << endl;
        return;
    }
    out << line_type << "  " << saved_E_word << endl;   //the one's without TENSE have translations
    
}

// ----- Changes to the parser.cpp content ---------------------

// ** Comment update: Be sure to put the corresponding grammar 
//    rule with semantic routine calls
//    above each non-terminal function 

// ** Each non-terminal function should be calling
//    getEword and/or gen now.

// ** Make each non-terminal into a function here
// ** Be sure to put the corresponding grammar rule above each function
// ** Be sure to put the name of the programmer above each function

//<tense> := VERBPAST | VERBPASTNEG | VERB | VERBNEG
// Done by: Sophia / Josh
void tense()
{
    cout << "Process <tense>" << endl;
    tokentype r = next_token();

    if (r == VERBPAST)
    {
        match(VERBPAST);
    }
    else if (r == VERBPASTNEG)
    {
        match(VERBPASTNEG);
    }
    else if (r == VERB)
    {
        match(VERB);
    }
    else if (r == VERBNEG)
    {
        match(VERBNEG);
    }
    else {
        syntaxError2(TENSE);
    }
}

//<be> ::= IS | WAS
// Done by: Sophia / Josh
void be()
{
    cout << "Process <be>" << endl;
    tokentype r = next_token();

    if (r == IS)
    {
        match(IS);
    }
    else if (r == WAS)
    {
        match(WAS);
    }
    else {
        syntaxError2(BE);
    }
}

//<verb> ::= WORD2
void verb()
{
    cout << "Process <verb>" << endl;
    match(WORD2);
}

//<noun> ::= WORD1 | PRONOUN
// Done by: Sophia / Josh
void noun()
{
    cout << "Process <noun>" << endl;
    tokentype r = next_token();

    if (r == WORD1)
    {
        match(WORD1);
    }
    else if (r == PRONOUN)
    {
        match(PRONOUN);
    }
    else {
        syntaxError2(NOUN);
    }
}

//***Altered for translator, added gen and getEword calls***
//<after object> ::= <verb> #getEword# #gen(“ACTION”)# <tense> #gen(“TENSE”)# PERIOD | <noun> #getEword# DESTINATION #gen(“TO”)# 
// <verb> #getEword# #gen(“ACTION”)# <tense> #gen(“TENSE”)# PERIOD
// 
// Done by: Sophia / Josh / Jake
void afterObject()
{
    cout << "Process <afterObject>" << endl;
    tokentype r = next_token();

    if (r == WORD1 || r == PRONOUN)
    {
        noun();
        getEword();
        match(DESTINATION);
        gen("TO");
        verb();
        getEword();
        gen("ACTION");
        tense();
        gen("TENSE");
        match(PERIOD);
    }
    else if (r == WORD2)
    {
        verb();
        getEword();
        gen("ACTION");
        tense();
        gen("TENSE");
        match(PERIOD);
    }
    else {
        syntaxError2(AFTEROBJECT);
    }
}

//***Altered for translator, added gen and getEword calls***
//<after noun> ::= <be> #gen(“DESCRIPTION”)# #gen(“TENSE”)# PERIOD | DESTINATION #gen("TO")# <verb> #getEword# #gen(“ACTION”)# 
// <tense> #gen(“TENSE”)# PERIOD | OBJECT #gen(“OBJECT”)# <after object>
// 
// Done by: Sophia / Josh / Jake
void afterNoun()
{
    cout << "Process <afterNoun>" << endl;
    tokentype r = next_token();

    if (r == IS || r == WAS)
    {
        be();
        gen("DESCRIPTION");
        gen("TENSE");
        match(PERIOD);
    }
    else if (r == DESTINATION)
    {
        match(DESTINATION);
        gen("TO");
        verb();
        getEword();
        gen("ACTION");
        tense();
        gen("TENSE");
        match(PERIOD);
    }
    else if (r == OBJECT)
    {
        match(OBJECT);
        gen("OBJECT");
        afterObject();
    }
    else {
        syntaxError2(AFTERNOUN);
    }
}

//***Altered for translator, added gen and getEword calls***
//<after subject> ::= <verb> #getEword# #gen(“ACTION”)# <tense> #gen(“TENSE”)# PERIOD | <noun> #getEword# <after noun>
// 
// Done by: Sophia / Josh / Jake
void afterSubject()
{
    cout << "Process <afterSubject>" << endl;

    tokentype r = next_token();

    if (r == WORD2)
    {
        verb();
        getEword();
        gen("ACTION");
        tense();
        gen("TENSE");
        match(PERIOD);
    }
    else if (r == WORD1 || r == PRONOUN)
    {
        noun();
        getEword();
        afterNoun();
    }
    else {
        syntaxError2(AFTERSUBJECT);
    }
}

//***Altered for translator, added gen and getEword calls***
//<s> ::= [CONNECTOR #getEword# #gen(“CONNECTOR”)#] <noun> #getEword# SUBJECT#gen(“ACTOR”)# <after subject>
// 
// Done by: Sophia / Josh / Jake 
void s()
{
    cout << "Process <s>" << endl;

    tokentype r = next_token();

    if (r == CONNECTOR)
    {
        match(CONNECTOR);
        getEword();         
        gen("CONNETOR");
        noun();
        match(SUBJECT);
        afterSubject();
    }
    else {
        noun();
        getEword();
        match(SUBJECT);
        gen("ACTOR");
        afterSubject();
    }
}

//Grammar: <story> ::= <s> { <s> }
// Done by: Sophia / Josh
void story()
{
    cout << "Process <story>" << endl;
    s();

    while (true)
    {
        if (next_token() == EOFM)
        {
            cout << "Success" << endl;
            break;
        }
        s();
    }
}

// ---------------- Driver ---------------------------


// The final test driver to start the translator
// Done by:  Jake
int main()
{   
    makeLexicon();
    out.open("translated.txt");
    string filename;
    cout << "Enter the input file name: ";
    cin >> filename;
    fin.open(filename.c_str());

    //** calls the <story> to start parsing
    story();
    //** closes the input file 
    //** closes traslated.txt
    fin.close();
    out.close();

}// end
//** require no other input files!
//** syntax error EC requires producing errors.txt of error messages
//** tracing On/Off EC requires sending a flag to trace message output functions

