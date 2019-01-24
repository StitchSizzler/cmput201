   /*  Problem approach:
    "+/-" before "." which is before "e"
    "+/-" must preceed all digits.
    These symbols can only appear once, except "+/-" after "e".
    "e" must be preceded by digits (doesn't have to be immediately before)
    and must be followed by digits. 
    Start with boolean digits found as false.
    Continue to scan for white space.
    Check if the first element immediately after is a "+/-".
    If the next is a digit set digits found to true and 
    continue scanning while digit. 
    Check if the next one is ".", and coninue scanning.
    The "." must be followed by numbers and not symblos so 
    check if the next is a digit. Set digits found to true (because
    it is possible that we only encountered +/-/. so far and no digits)
    and continue scanning while digits. If "e" is found check if digits
    have been found by that point. If so, check for "+/-" right after. If "e"
    is found, we must have digits after e so set digits found 
    to false. If digits found, set to true and continue scanning. 
    The number must be complete by this point and we have to make
    sure that it is not followed by anymore symbols or letters.
    Continue scanning for white space until a symbol is `found.
    If that symbol is a new like character, then we're gucci. If digits found
    is also true, then our answer is true. 
    
    NOTE: Use single quotations for char!   >_<

*/

bool isNumber(char* s) {
    
    /* 0 for false, 1 for true */
    int digits_found = 0;
    
    /* scan and ignore leading white space */
    while (*s == ' '){
        ++s;
    }
    
    /* check for leading "+/-" */
    if (*s == '+' || *s == '-'){
        ++s;
    }
    
    /* scan for digits */
    while (isdigit(*s)){
        ++s;
        digits_found = 1;
    }
    
    /* check for "." */
    if (*s == '.'){
        ++s;
    }
    
    /* check for digit */
    while (isdigit(*s)){
        ++s;
        digits_found = 1;
    }
    
    /* check for "e" and if digits found so far */
    if (*s == 'e'){   
        if (digits_found == 1){
            ++s;
            
            /* check for "+/-" */
            if (*s == '+' || *s == '-'){
                ++s;
            }
            
            /* "e" must be followed by digits */
            digits_found = 0;
            while(isdigit(*s)){
                ++s;
                digits_found = 1;
            }
        }
        
    }
    
    /* nothing other than white space and null should be after this point */
    
    /* scan for white space */
    while (*s == ' '){
        ++s;
    }
    
    bool is_num = (digits_found == 1) && (*s == '\0');
    
    return is_num;
    
}
