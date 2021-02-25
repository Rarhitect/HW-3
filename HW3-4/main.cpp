#include <iostream>
#include <chrono>
#include <random>
#include <set>
#include <string>

#include <boost/functional/hash.hpp>

std::set < std::string > make_random_words(std::size_t N, std::size_t length = 10)
{
    std::uniform_int_distribution <> letter(97, 122);
    std::default_random_engine e(static_cast < std::size_t > (
        std::chrono::system_clock::now().time_since_epoch().count()));

    std::set < std::string > words;

    for (std::string s(length, '_'); std::size(words) < N; words.insert(s))
        for (auto & c : s)
            c = letter(e);

    return words;
}

unsigned int RSHash(const char* str, unsigned int length);
unsigned int JSHash(const char* str, unsigned int length);
unsigned int PJWHash(const char* str, unsigned int length);
unsigned int ELFHash(const char* str, unsigned int length);
unsigned int BKDRHash(const char* str, unsigned int length);
unsigned int SDBMHash(const char* str, unsigned int length);
unsigned int DJBHash(const char* str, unsigned int length);
unsigned int DEKHash(const char* str, unsigned int length);
unsigned int APHash(const char* str, unsigned int length);

constexpr unsigned int N = 1000000;

void RS_collision_test(std::set<std::string> words);
void JS_collision_test(std::set<std::string> words);
void PJW_collision_test(std::set<std::string> words);
void BKDR_collision_test(std::set<std::string> words);
void SDBM_collision_test(std::set<std::string> words);
void DJB_collision_test(std::set<std::string> words);
void AP_collision_test(std::set<std::string> words);
void ELF_collision_test(std::set<std::string> words);
void DEK_collision_test(std::set<std::string> words);

int main()
{
    std::set<std::string> words = make_random_words(N);
    
    RS_collision_test(words);
    JS_collision_test(words);
    PJW_collision_test(words);
    BKDR_collision_test(words);
    SDBM_collision_test(words);
    DJB_collision_test(words);
    AP_collision_test(words);
    ELF_collision_test(words);
    DEK_collision_test(words);
    
    return 0;
}

void RS_collision_test(std::set<std::string> words)
{
    unsigned int collision_counter = 0;
    std::set < std::size_t > word_hashes;
    for (auto &i: words)
    {
        if ( word_hashes.count( RSHash(i.c_str(), 10) ) == 0 )
        {
            word_hashes.insert( RSHash(i.c_str(), 10) );
        }
        else
        {
            ++collision_counter;
        }
    }

    std::cout << "RS method; " << collision_counter << " collisions" << std::endl;
}

void JS_collision_test(std::set<std::string> words)
{
    unsigned int collision_counter = 0;
    std::set < std::size_t > word_hashes;
    for (auto &i: words)
    {
        if ( word_hashes.count( JSHash(i.c_str(), 10) ) == 0 )
        {
            word_hashes.insert( JSHash(i.c_str(), 10) );
        }
        else
        {
            ++collision_counter;
        }
    }

    std::cout << "JS method; " << collision_counter << " collisions" << std::endl;
}

void PJW_collision_test(std::set<std::string> words)
{
    unsigned int collision_counter = 0;
    std::set < std::size_t > word_hashes;
    for (auto &i: words)
    {
        if ( word_hashes.count( PJWHash(i.c_str(), 10) ) == 0 )
        {
            word_hashes.insert( PJWHash(i.c_str(), 10) );
        }
        else
        {
            ++collision_counter;
        }
    }

    std::cout << "PJW method; " << collision_counter << " collisions" << std::endl;
}

void ELF_collision_test(std::set<std::string> words)
{
    unsigned int collision_counter = 0;
    std::set < std::size_t > word_hashes;
    for (auto &i: words)
    {
        if ( word_hashes.count( ELFHash(i.c_str(), 10) ) == 0 )
        {
            word_hashes.insert( ELFHash(i.c_str(), 10) );
        }
        else
        {
            ++collision_counter;
        }
    }

    std::cout << "ELF method; " << collision_counter << " collisions" << std::endl;
}

void BKDR_collision_test(std::set<std::string> words)
{
    unsigned int collision_counter = 0;
    std::set < std::size_t > word_hashes;
    for (auto &i: words)
    {
        if ( word_hashes.count( BKDRHash(i.c_str(), 10) ) == 0 )
        {
            word_hashes.insert( BKDRHash(i.c_str(), 10) );
        }
        else
        {
            ++collision_counter;
        }
    }

    std::cout << "BKDR method; " << collision_counter << " collisions" << std::endl;
}

void SDBM_collision_test(std::set<std::string> words)
{
    unsigned int collision_counter = 0;
    std::set < std::size_t > word_hashes;
    for (auto &i: words)
    {
        if ( word_hashes.count( SDBMHash(i.c_str(), 10) ) == 0 )
        {
            word_hashes.insert( SDBMHash(i.c_str(), 10) );
        }
        else
        {
            ++collision_counter;
        }
    }

    std::cout << "SDBM method; " << collision_counter << " collisions" << std::endl;
}

void DJB_collision_test(std::set<std::string> words)
{
    unsigned int collision_counter = 0;
    std::set < std::size_t > word_hashes;
    for (auto &i: words)
    {
        if ( word_hashes.count( DJBHash(i.c_str(), 10) ) == 0 )
        {
            word_hashes.insert( DJBHash(i.c_str(), 10) );
        }
        else
        {
            ++collision_counter;
        }
    }

    std::cout << "DJB method; " << collision_counter << " collisions" << std::endl;
}

void AP_collision_test(std::set<std::string> words)
{
    unsigned int collision_counter = 0;
    std::set < std::size_t > word_hashes;
    for (auto &i: words)
    {
        if ( word_hashes.count( APHash(i.c_str(), 10) ) == 0 )
        {
            word_hashes.insert( APHash(i.c_str(), 10) );
        }
        else
        {
            ++collision_counter;
        }
    }

    std::cout << "AP method; " << collision_counter << " collisions" << std::endl;
}

void DEK_collision_test(std::set<std::string> words)
{
    unsigned int collision_counter = 0;
    std::set < std::size_t > word_hashes;
    for (auto &i: words)
    {
        if ( word_hashes.count( DEKHash(i.c_str(), 10) ) == 0 )
        {
            word_hashes.insert( DEKHash(i.c_str(), 10) );
        }
        else
        {
            ++collision_counter;
        }
    }

    std::cout << "DEK method; " << collision_counter << " collisions" << std::endl;
}

unsigned int RSHash(const char* str, unsigned int length = 10)
{
   unsigned int b    = 378551;
   unsigned int a    = 63689;
   unsigned int hash = 0;
   unsigned int i    = 0;

   for (i = 0; i < length; ++str, ++i)
   {
      hash = hash * a + (*str);
      a    = a * b;
   }

   return hash;
}

unsigned int JSHash(const char* str, unsigned int length = 10)
{
   unsigned int hash = 1315423911;
   unsigned int i    = 0;

   for (i = 0; i < length; ++str, ++i)
   {
      hash ^= ((hash << 5) + (*str) + (hash >> 2));
   }

   return hash;
}

unsigned int PJWHash(const char* str, unsigned int length = 10)
{
   const unsigned int BitsInUnsignedInt = (unsigned int)(sizeof(unsigned int) * 8);
   const unsigned int ThreeQuarters     = (unsigned int)((BitsInUnsignedInt  * 3) / 4);
   const unsigned int OneEighth         = (unsigned int)(BitsInUnsignedInt / 8);
   const unsigned int HighBits          =
                      (unsigned int)(0xFFFFFFFF) << (BitsInUnsignedInt - OneEighth);
   unsigned int hash = 0;
   unsigned int test = 0;
   unsigned int i    = 0;

   for (i = 0; i < length; ++str, ++i)
   {
      hash = (hash << OneEighth) + (*str);

      if ((test = hash & HighBits) != 0)
      {
         hash = (( hash ^ (test >> ThreeQuarters)) & (~HighBits));
      }
   }

   return hash;
}

unsigned int ELFHash(const char* str, unsigned int length = 10)
{
   unsigned int hash = 0;
   unsigned int x    = 0;
   unsigned int i    = 0;

   for (i = 0; i < length; ++str, ++i)
   {
      hash = (hash << 4) + (*str);

      if ((x = hash & 0xF0000000L) != 0)
      {
         hash ^= (x >> 24);
      }

      hash &= ~x;
   }

   return hash;
}

unsigned int BKDRHash(const char* str, unsigned int length = 10)
{
   unsigned int seed = 131; /* 31 131 1313 13131 131313 etc.. */
   unsigned int hash = 0;
   unsigned int i    = 0;

   for (i = 0; i < length; ++str, ++i)
   {
      hash = (hash * seed) + (*str);
   }

   return hash;
}

unsigned int SDBMHash(const char* str, unsigned int length = 10)
{
   unsigned int hash = 0;
   unsigned int i    = 0;

   for (i = 0; i < length; ++str, ++i)
   {
      hash = (*str) + (hash << 6) + (hash << 16) - hash;
   }

   return hash;
}

unsigned int DJBHash(const char* str, unsigned int length = 10)
{
   unsigned int hash = 5381;
   unsigned int i    = 0;

   for (i = 0; i < length; ++str, ++i)
   {
      hash = ((hash << 5) + hash) + (*str);
   }

   return hash;
}

unsigned int DEKHash(const char* str, unsigned int length = 10)
{
   unsigned int hash = length;
   unsigned int i    = 0;

   for (i = 0; i < length; ++str, ++i)
   {
      hash = ((hash << 5) ^ (hash >> 27)) ^ (*str);
   }

   return hash;
}

unsigned int APHash(const char* str, unsigned int length = 10)
{
   unsigned int hash = 0xAAAAAAAA;
   unsigned int i    = 0;

   for (i = 0; i < length; ++str, ++i)
   {
      hash ^= ((i & 1) == 0) ? (  (hash <<  7) ^ (*str) * (hash >> 3)) :
                               (~((hash << 11) + ((*str) ^ (hash >> 5))));
   }

   return hash;
}
