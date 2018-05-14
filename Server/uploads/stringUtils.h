#ifndef _STRINGUTILS_H_
#define _STRINGUTILS_H_

#include <string.h>

#define PARSE_DEBUG 0

// =====================================================================
//  string utils
// =====================================================================
inline bool isspacechar(char c)
{
    return ((c == ' ') || (c == '\r') || (c == '\n') || (c == '\t') || (c == 0));
}

// ----------------------------------------------
char *skipspace(char *str, int *idx = NULL)
{
    int i = 0;
    while (isspacechar(*str) && *str)
    {
        str++;
        i++;
    }
    if (idx)
        *idx = i;
    return str;
}

// ----------------------------------------------
bool atoi(char *str, int *value, char **endstr = NULL)
{

#if PARSE_DEBUG
    Serial.print("atoi: ");
    Serial.print(str);
#endif

    str = skipspace(str);
    int curval = 0;
    bool retval = false;
    int mulval = 1;
    while (*str && (!isspacechar(*str)))
    {
        if ((*str >= '0') && (*str <= '9'))
        {
            curval *= 10;
            curval += *str - '0';
            retval = true;
        }
        else if (*str == '-' && retval == false)
        {
            mulval = -1;
        }
        else if (*str == '+' && retval == false)
        {
            //nothing
        }
        else
        {
            if (endstr == NULL)
                retval = false;
            break;
        }
        str++;
    }

    if (value)
        *value = curval * mulval;
    if (endstr && retval)
        *endstr = str;

#if PARSE_DEBUG
    Serial.print(" ");
    Serial.println(retval);
#endif


    return retval;
}

// ----------------------------------------------
bool isToken(char** inStr, const char* token)
{
    char* str = *inStr;
    bool retVal = false;
    const int l = ::strlen(token);
    str = skipspace(str);
    if(*str)
    {
        int len = ::strlen(str);
        if(len > l) 
        {
            // we're enforcing white space between tokens
            // otherwise partil matches would happen
            retVal =  isspacechar(str[l]) && ::strncmp (str, token, l) == 0;
        }
        else if(len == l)
            retVal =  ::strncmp (str, token, l) == 0;
        else 
            retVal = false;
    }

    if(retVal)
    {
        *inStr = str + l;
    }
    
    return retVal;
}

#endif
