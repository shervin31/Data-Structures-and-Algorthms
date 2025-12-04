/**
 * Count the number words of given simple string. A word starts with an English charactor end with a charactor of space, tab, comma, or period.  
 *
 * @param s - char pointer to a string
 * @return - return the number of words. 
 */


int str_words(char *s){
    if (*s == '\0'){
        return -1;
    }
    int count = 0;
    char *p = s; 

    if ((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z')) {
        count++;
    }
   
    while (*p != '\0'){
        if (*p == '\t' || *p == '\n' || *p == ' ' || *p == ',' || *p == '.'){ 
            if (*(p + 1) != '\0' && ((*(p + 1) >= 'a' && *(p + 1) <= 'z') || (*(p + 1) >= 'A' && *(p + 1) <= 'Z'))){ 
                count ++;
            }
        }
        p ++;
        
    }

    return count;

}

/**
 * Change every upper case English letter to its lower case of string passed by s.
 *
 * @param s - char pointer to a string
 * @return - return the number of actual flips.   
 */
int str_lower(char *s){
    int count = 0;
    char *p = s;

    while(*p != '\0'){
        if (*p >= 'A' && *p <= 'Z'){
            *p = *p + 32;
            count ++;
        }
        p ++;
    }

    return count;
}





