// common.h
#ifndef common_h
#define common_h

#include <iostream>
#include <vector>

//Love this macro functions, found in secp256k1:
//https://github.com/bitcoin-core/secp256k1/blob/master/src/util.h
#define TEST_FAILURE(msg)                                        \
    do                                                           \
    {                                                            \
        fprintf(stderr, "%s:%d: %s\n", __FILE__, __LINE__, msg); \
        abort();                                                 \
    } while (0)
#define EXPECT(x, c) __builtin_expect((x), (c))
#define CHECK(cond)                                        \
    do                                                     \
    {                                                      \
        if (EXPECT(!(cond), 0))                            \
        {                                                  \
            TEST_FAILURE("test condition failed: " #cond); \
        }                                                  \
    } while (0)
//////////////////////////////////////////////////////////////////

//basic class used in the examples:
class CommonFct
{
public:
    std::vector<char> ReadAllBytes(char const *filename);
    bool WriteAllBytes(char const *filename, std::string data);

private:
};

#endif /* common_h */
