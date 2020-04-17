#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


struct analizator
{
    ifstream fisier;
    vector<string> TabelSpecial;
    vector<pair<int, int>> eroriDinStari;
    
    struct transition
    {
        char From, To;
        vector<char> Via;
    };
    vector<transition> trans = vector<transition>({
            {0, 2, {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '_'} },
            {2, 2, {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '_'}},
            {0, 3, {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'}},
            {3, 3,{'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'}},
            {31, 32,{'\\'}},
            {31, 33, {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '-', '=', '{', '}', '[', ']', '|', ':', '"', ';', '<', '>', '?', ',', '.', '/', ' '}},
            {32,33,{'\'', '\\', '"', 'n', 't', 'r', '0'}},
            {33,5,{'\''}},
            {0, 34,{'\"'}},
            {34, 35,{'\\'}},
            {3, 30, {'.'}},
            {36,36, {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '-', '=', '{', '}', '[', ']', '|', ':', ';', '<', '>', '?', ',', '.', '/', '\'', ' '}},
            {36, 35,{'\\'}},
            {30, 4, {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'}},
            {4, 4, {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'}},
            {34, 36, {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '-', '=', '{', '}', '[', ']', '|', ':', ';', '<', '>', '?', ',', '.', '/', '\'', ' '}},
            {35,36,{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '-', '=', '{', '}', '[', ']', '|', '\\', ':', '"', ';', '<', '>', '?', ',', '.', '/', '\'', '\n', '\0', '\0', '	'}},
            {36,6,{'\"'}},
            {0, 31,{'\''}},
            {0,7,{';', '{', '}'}},
            {40,41,{'*'}},
            {40,40, {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '~', '!', '@', '#', '$', '%', '^', '&', '(', ')', '_', '+', '-', '=', '{', '}', '[', ']', '|', '\\', ':', '"', ';', '<', '>', '?', ',', '.', '/', '\'', ' ', '\n', '\0', '\t'}},
            {41,8,{'/'}},
            {41,41, {'*'}},
            {16,37,{'/'}},
            {16,39,{'*'}},
            {37,38,{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '-', '=', '{', '}', '[', ']', '|', '\\', ':', '"', ';', '<', '>', '?', ',', '.', '/', '\'', ' ', '\t'}},
            {38,8,{'\n' + '\0'}},
            {38,38,{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '-', '=', '{', '}', '[', ']', '|', '\\', ':', '"', ';', '<', '>', '?', ',', '.', '/', '\'', ' ', '\t'}},
            {39,40,{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '~', '!', '@', '#', '$', '%', '^', '&', '(', ')', '_', '+', '-', '=', '{', '}', '[', ']', '|', '\\', ':', '"', ';', '<', '>', '?', ',', '.', '/', '\'', ' ', '\n', '\0', '\t'}},
            {39,41,{'*'}},
            {41,40,{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '~', '!', '@', '#', '$', '%', '^', '&', '(', ')', '_', '+', '-', '=', '{', '}', '[', ']', '|', '\\', ':', '"', ';', '<', '>', '?', ',', '.', '\'', ' ', '\n', '\0', '\t'}},
            {0,9,{' ', '\n', '\0'}},
            {9,9,{' ', '\n', '\0'}},
            {0,42,{':'}},{0,12,{'+'}},{0,13,{'-'}},{0,10,{'.'}},{0,14,{'!'}},{0,15,{'*'}},{0,16,{'/'}},{0,17,{'%'}},{0,20,{'<'}},{0,21,{'>'}},{0,22,{'&'}},{0,23,{'^'}},{0,24,{'|'}},{0,25,{'='}},{0,26, {'~', ',', '(', ')', '[', ']'}},{42,26,{':'}},{12,26,{'+','='}},{13,26,{'-','='}},{13,11,{'>'}},{10,26,{'*'}},{14,26,{'='}},{15,26,{'='}},{16,26,{'='}},{17,26,{'='}},{20,18,{'<'}},{20,26,{'='}},{21,19,{'>'}},{21,26,{'='}},{22,26,{'=','&'}},{23,26,{'='}},{24,26,{'=', '&'}},{25,26,{'='}}, {11,26,{'*'}}, {18,26,{'='}}, {19,26,{'='}}
            });
    
    template<typename t> bool are(vector<t> v, t c)
    {
        for (typename vector<t>::iterator it = v.begin(); it != v.end(); ++it)
            if (*it == c)
                return true;
        return false;
    }
    vector<transition> StariUrmatareDupaSursa(int s)
    {
        vector<transition> derivates = vector<transition>();
        for (vector<transition>::iterator it = trans.begin(); it != trans.end(); ++it)
            if (it->From == s)
                derivates.push_back(*it);
        return derivates;
    }
    string& undeInTabel(vector<string> v, string s)
    {
        for (vector<string>::iterator it = v.begin(); it != v.end(); ++it)
            if (*it == s)
                return *it;
    }
    int EroareDinStare(int s)
    {
        for (vector<pair<int,int>>::iterator it = eroriDinStari.begin(); it != eroriDinStari.end(); ++it)
            if (it->first == s)
                return it->second;
    }
    string tokenFormat;
    int stare, ultima, tip, pozCitire = 0;
    char c;

    string partVal;
    int ultimaFinala;
    string dupaultimulfinal = string();
    bool avemInRollbackSaved = false;

    bool gasit = false;
    struct token
    {
        int tiptoken, pozitieeroare;
        const string& inTabel;
        string val;
        token(int t, const string& v) :inTabel(v)
        {
            tiptoken = t; pozitieeroare = -1;
        }
        string get_value()
        {
            if (pozitieeroare > -1)return to_string(pozitieeroare);
            if (tiptoken == 5 || tiptoken == 4 || tiptoken == 3 || tiptoken == 1)return val;
            return inTabel;
        }
    };
    analizator(string cale)
    {
        fisier = ifstream(cale);        
        eroriDinStari = vector<pair<int, int>>({ {0,10},{35,17}, {30,13},{31,11},{32,14},{33, 15},{34,16},{41, 19},{42,20},{36,18},{39,19} });
        TabelSpecial = vector<string>({ "+","-","!","~",".*","->*","*","/","%","&","^","|","&&","||","=","+=","-=","*=","/=","%=","::","++","--",".","->","<<",">>","<","<=",">",">=","==","!=","<<=",">>=","&=","^=","|=",",","(",")","[","]",  "throw",  "else",  "21", "break", "new", "class", "sizeof", "virtual","union","inline", "static", "void","delete", "int", "static_cast", "volatile","do", "long", "struct", "wchar_t","double", "mutable", "switch", "while","dynamic_cast", "name8","this", "auto", "enum","bool", "explicit", "private", "true","asm","export", "protected", "try", "case", "extern", "public", "typedef", "catch", "false", "register", "typeid", "char", "float", "reinterpret_cast", "const", "friend", "short", "unsigned","const_cast", "default", "typename", "template" "for", "return", "goto", "signed", "using","continue", "if"});
    }
    token gettoken()
    {
        stare = 0;
        tip = 9;
        partVal = string();
        ultimaFinala = 1;
        tokenFormat = string();
        do
        {
            if (fisier.eof() && dupaultimulfinal.length()==0) 
            {
                gasit = true;
                if ((gasit && tokenFormat.length() == 0) || (fisier.eof() && tokenFormat.length() == 1))//s-a terminat fisierul si nu a inceput inca citirea unui token.
                {
                    gasit = true;
                    return token(8, "");
                }
                if (ultimaFinala != 1)//daca a fost intalnita vreo stare finala pe parcurs
                {
                    tokenFormat = partVal;
                    stare = ultimaFinala;

                    //current_file_position -= after_last_final_state.length();
                    avemInRollbackSaved = true;
                    partVal = string();
                    ultimaFinala = 1;
                    switch (stare)
                    {
                    case 1:
                        tip = 9;
                        break;
                    case 0:
                        tip = 9;
                        break;
                    case 2:
                        if (are(TabelSpecial, tokenFormat))
                            tip = 6;
                        tip = 0;
                        break;
                    case 3:
                        tip = 1;
                        break;
                    case 4:
                        tip = 2;
                        break;
                    case 5:
                        tip = 3;
                        break;
                    case 6:
                        tip = 4;
                        break;
                    case 7:
                        tip = 5;
                        break;
                    case 8:
                        tip = 7;
                        break;
                    case 9:
                        tip = 8;
                        break;
                    default:
                        tip = 21;
                        break;
                    }
                    if (tip == 7 || tip == 8)
                        return gettoken();

                    switch (tip)
                    {
                    case 0:if (!are(TabelSpecial, tokenFormat))
                        TabelSpecial.push_back(tokenFormat);
                        token tok = token(tip, undeInTabel(TabelSpecial, tokenFormat)); if (tok.tiptoken == 5 || tok.tiptoken == 4 || tok.tiptoken == 3 || tok.tiptoken == 1)tok.val = tokenFormat;
                        return tok;
                        break;
                    case 6:
                        token tok = token(tip, undeInTabel(TabelSpecial, tokenFormat)); if (tok.tiptoken == 5 || tok.tiptoken == 4 || tok.tiptoken == 3 || tok.tiptoken == 1)tok.val = tokenFormat;
                        return tok;
                        break;
                    case 7:
                        token tok = token(tip, ""); if (tok.tiptoken == 5 || tok.tiptoken == 4 || tok.tiptoken == 3 || tok.tiptoken == 1)tok.val = tokenFormat;
                        return tok;
                        break;
                    case 8:
                        token tok = token(tip, string()); if (tok.tiptoken == 5 || tok.tiptoken == 4 || tok.tiptoken == 3 || tok.tiptoken == 1)tok.val = tokenFormat;
                        return tok;
                        break;
                    case 21:
                        token tok = token(tip, undeInTabel(TabelSpecial, tokenFormat)); if (tok.tiptoken == 5 || tok.tiptoken == 4 || tok.tiptoken == 3 || tok.tiptoken == 1)tok.val = tokenFormat;
                        return tok;
                        break;
                    default:
                        token tok = token(tip, tokenFormat); if (tok.tiptoken == 5 || tok.tiptoken == 4 || tok.tiptoken == 3 || tok.tiptoken == 1)tok.val = tokenFormat;
                        return tok;
                        break;
                    }
                }
                else
                {
                    token tok = token(EroareDinStare(ultima), to_string(pozCitire));
                    tok.pozitieeroare = pozCitire;
                    return tok;
                }
            }
            if (!avemInRollbackSaved)//daca nu avem caractere intoarse dupa ultimul rollback
                fisier >> noskipws >> c;
            else
            {
                c = dupaultimulfinal.at(0);
                dupaultimulfinal.erase(0, 1);
                if (dupaultimulfinal.length() == 0)
                    avemInRollbackSaved = false;
            }
            ultima = stare;
            int next= -2;
            vector<transition> succesri = StariUrmatareDupaSursa(stare);
            for (vector<transition>::iterator consec = succesri.begin(); consec != succesri.end(); ++consec)
            {
                if (are(consec->Via, c))
                    next = consec->To;
            }
             if(next==-2) next = 1;
            tokenFormat += c;
            pozCitire++;
            if (!avemInRollbackSaved) dupaultimulfinal += c;//Daca citirea nu s-a facut din buffer-ul pentru recitiri, inseamna ca citim din fisier, deci punem in buffer la final;
            else dupaultimulfinal = c + dupaultimulfinal;// Daca citirea s-a facut din buffer-ul pentru recitiri, punem caracterul citit la inceputul buffer-ului de refolosiri
            stare = next;
            if (stare < 30 && stare>1)//Daca starea este mai mica decat -1, este considerata prin conventie stare finala
            {
                dupaultimulfinal.erase(0, tokenFormat.length() - partVal.length());//scoatem caractere consumate din bufferul cu cele de recitit
                partVal = tokenFormat; ultimaFinala = stare;

            }
        } while (stare != 1);//Citim pana intalnim 1, apoi incercam rollback.
        
        if ((gasit && tokenFormat.length() == 0) || (fisier.eof() && tokenFormat.length() == 1))//s-a terminat fisierul si nu a inceput inca citirea unui token.
        {
            gasit = true;
            return token(8, "");
        }
        if (ultimaFinala != 1)//daca a fost intalnita vreo stare finala pe parcurs
        {
            tokenFormat = partVal;
            stare = ultimaFinala;

            //current_file_position -= after_last_final_state.length();
            avemInRollbackSaved = true;
            partVal = string();
            ultimaFinala = 1;
            switch (stare)
            {
            case 1:
                tip = 9;
                break;
            case 0:
                tip = 9;
                break;
            case 2:
                if (are(TabelSpecial, tokenFormat))
                    tip = 6;
                tip = 0;
                break;
            case 3:
                tip = 1;
                break;
            case 4:
                tip = 2;
                break;
            case 5:
                tip = 3;
                break;
            case 6:
                tip = 4;
                break;
            case 7:
                tip = 5;
                break;
            case 8:
                tip = 7;
                break;
            case 9:
                tip = 8;
                break;
            default:
                tip = 21;
                break;
            }
            if (tip == 7 || tip == 8)
                return gettoken();

            switch (tip)
            {
            case 0:if (!are(TabelSpecial, tokenFormat))
                TabelSpecial.push_back(tokenFormat);
                token tok = token(tip, undeInTabel(TabelSpecial, tokenFormat)); if (tok.tiptoken == 5 || tok.tiptoken == 4 || tok.tiptoken == 3 || tok.tiptoken == 1)tok.val = tokenFormat;
                return tok;
                break;
            case 6:
                token tok = token(tip, undeInTabel(TabelSpecial, tokenFormat)); if (tok.tiptoken == 5 || tok.tiptoken == 4 || tok.tiptoken == 3 || tok.tiptoken == 1)tok.val = tokenFormat;
                return tok;
                break;
            case 7:
                token tok = token(tip, ""); if (tok.tiptoken == 5 || tok.tiptoken == 4 || tok.tiptoken == 3 || tok.tiptoken == 1)tok.val = tokenFormat;
                return tok;
                break;
            case 8:
                token tok = token(tip, string()); if (tok.tiptoken == 5 || tok.tiptoken == 4 || tok.tiptoken == 3 || tok.tiptoken == 1)tok.val = tokenFormat;
                return tok;
                break;
            case 21:
                token tok = token(tip, undeInTabel(TabelSpecial, tokenFormat)); if (tok.tiptoken == 5 || tok.tiptoken == 4 || tok.tiptoken == 3 || tok.tiptoken == 1)tok.val = tokenFormat;
                return tok;
                break;
            default:
                token tok = token(tip, tokenFormat); if (tok.tiptoken == 5 || tok.tiptoken == 4 || tok.tiptoken == 3 || tok.tiptoken == 1)tok.val = tokenFormat;
                return tok;
                break;
            }
        }
        else
        {
            token tok = token(EroareDinStare(ultima), to_string(pozCitire));
            tok.pozitieeroare = pozCitire;
            return tok;
        }
    }
};
vector<string> tip = vector<string>{ "id" , "int" ,"float" ,"char" ,"string" ,"sep" , "keyword" ,"op" ,"","err caracter" ,"err characterliteral" ,"","err float" , "err character backslash problem" ,"err many charracters","err string","err string backslash problem" ,"err multiline string" ,"error bad comment" ,"err operator not exists" };
int main()
{
    string in;
    getline(cin, in, '\n');
    analizator an(in);
    int ttip;
    do
    {
        analizator::token tok = an.gettoken();
        ttip = tok.tiptoken;
        cout << tip[tok.tiptoken];
        cout <<"    " << tok.get_value()<<'\n';
    } while (!an.gasit && !(ttip >= 9 && ttip < 20));
}
