/* Longest Palindromic Substring 
	ACTUALLY WORKS BUT LEETCODE GIVES TIME LIMIT EXCEEDED */



//              .___....._               _.....___.
//                  .": o :':         :': o :".
//                  '. '-' .'.       .'. '-' .'
//                    '---'             '---'
//
//          _...----...      ...   ...      ...----..._
//       .-'__..-""'----    '.  '"'  .'    ----'""-..__'-.
//      '.-'   _.--"""'       '-._.-'       '"""--._   '-.
//      '  .-"'                  :                  '"-.  '
//        '   '.              _.'"'._              .'   '
//              '.       ,.-'"       "'-.,       .'
//                '-                           .'
//                  '-._                   _.-'
//                      '"'--...___...--'"'
//
//
// 




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int someFunction(char* s, int l, int r){
    
    int left = l;
    int right = r;
    
    // continue comparing left and right while chars are the same
    while(left >=0 && right < strlen(s) && s[left] == s[right]){
        right++;
        left--;
    }
    return right-left-1;
}

char* longestPalindrome(char* s) {
     
    
    if (s == NULL || strlen(s) < 1)
        return "";
    int first = 0;
    int last = 0;
    //int indexMax = 0;
    int sizeMax = 0;
    int size1, size2;
    
    // try left/right method for individual chars
    for (int i = 0; i < strlen(s); i++){
        
        size1 = someFunction(s, i, i);
        size2 = someFunction(s, i, i+1);

        //printf("returned size: %d\n", size1);

        
        if (size1 > size2){
            sizeMax = size1;
        }
        else{
            sizeMax = size2;
        }
        
        if(sizeMax > last - first){
            first = i - (sizeMax-1)/2;
            last = i + sizeMax/2;
        }
        
    }
    
    //printf("first: %d,  last: %d\n", first, last);
        
    char *ans = malloc(last-first+1);
    int count = 0;
    for (int i = first; i <= last; i++){
        ans[count++] = s[i]; 
        printf("%c", s[i]);
    }
    ans[count] = '\0';
    
    //strcpy(mystring)
    
    return ans;
}



int main(){

	char s[1000] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	longestPalindrome(s);
	printf("\n");
	return 0;

}
