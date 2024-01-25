class Solution {
    long long base = 256; 
    long long prime = 101; 
public:
    int strStr(string haystack, string needle) {
        int needleLength = needle.length();
        int haystackLength = haystack.length();
        long long needleHash = 0; 
        long long windowHash = 0; 
        long long power = 1; 

        for (int i = 0; i < needleLength - 1; i++)
            power = (power * base) % prime;

        for (int i = 0; i < needleLength; i++) {
            needleHash = (base * needleHash + needle[i]) % prime;
            windowHash = (base * windowHash + haystack[i]) % prime;
        }

        for (int i = 0; i <= haystackLength - needleLength; i++) {
            if (needleHash == windowHash) {
                int j;
                for (j = 0; j < needleLength; j++) {
                    if (haystack[i + j] != needle[j])
                        break;
                }
                if (j == needleLength)
                    return i;
            }

            if (i < haystackLength - needleLength) {
                windowHash = (base * (windowHash - haystack[i] * power) + haystack[i + needleLength]) % prime;
                if (windowHash < 0)
                    windowHash = (windowHash + prime);
            }
        }
        return -1;
    }
};