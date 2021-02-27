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

void RS_collision_test(std::set<std::string> words, std::size_t size);
void JS_collision_test(std::set<std::string> words, std::size_t size);
void PJW_collision_test(std::set<std::string> words, std::size_t size);
void BKDR_collision_test(std::set<std::string> words, std::size_t size);
void SDBM_collision_test(std::set<std::string> words, std::size_t size);
void DJB_collision_test(std::set<std::string> words, std::size_t size);
void AP_collision_test(std::set<std::string> words, std::size_t size);
void ELF_collision_test(std::set<std::string> words, std::size_t size);
void DEK_collision_test(std::set<std::string> words, std::size_t size);

std::size_t N1 = 1000;
std::size_t N2 = 1000;
std::size_t N3 = 1000;
std::size_t N4 = 1000;
std::size_t N5 = 1000;
std::size_t N6 = 1000;
std::size_t N7 = 1000;
std::size_t N8 = 1000;
std::size_t N9 = 1000;

int main()
{
    std::cout << "RS method" << std::endl;
    for (auto i = 0; i < 20; ++i)
    {
        std::set<std::string> words = make_random_words(N1);
        RS_collision_test(words, N1);
        N1 += 50000;
    }
    std::cout << "JS method" << std::endl;
    for (auto i = 0; i < 20; ++i)
    {
        std::set<std::string> words = make_random_words(N2);
        JS_collision_test(words, N2);
        N2 += 50000;
    }
    std::cout << "PJW method" << std::endl;
    for (auto i = 0; i < 20; ++i)
    {
        std::set<std::string> words = make_random_words(N3);
        PJW_collision_test(words, N3);
        N3 += 50000;
    }
    std::cout << "BKDR method" << std::endl;
    for (auto i = 0; i < 20; ++i)
    {
        std::set<std::string> words = make_random_words(N4);
        BKDR_collision_test(words, N4);
        N4 += 50000;
    }
    std::cout << "SDBM method" << std::endl;
    for (auto i = 0; i < 20; ++i)
    {
        std::set<std::string> words = make_random_words(N5);
        SDBM_collision_test(words, N5);
        N5 += 50000;
    }
    std::cout << "DJB method" << std::endl;
    for (auto i = 0; i < 20; ++i)
    {
        std::set<std::string> words = make_random_words(N6);
        DJB_collision_test(words, N6);
        N6 += 50000;
    }
    std::cout << "AP method" << std::endl;
    for (auto i = 0; i < 20; ++i)
    {
        std::set<std::string> words = make_random_words(N7);
        AP_collision_test(words, N7);
        N7 += 50000;
    }
    std::cout << "ELF method" << std::endl;
    for (auto i = 0; i < 20; ++i)
    {
        std::set<std::string> words = make_random_words(N8);
        ELF_collision_test(words, N8);
        N8 += 50000;
    }
    std::cout << "DEK method" << std::endl;
    for (auto i = 0; i < 20; ++i)
    {
        std::set<std::string> words = make_random_words(N9);
        DEK_collision_test(words, N9);
        N9 += 50000;
    }
    return 0;
}

void RS_collision_test(std::set<std::string> words, std::size_t size)
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
    std::cout << "Size = " << size << "; " << collision_counter << " collisions" << std::endl;
}

void JS_collision_test(std::set<std::string> words, std::size_t size)
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

    std::cout << "Size = " << size << "; " << collision_counter << " collisions" << std::endl;
}

void PJW_collision_test(std::set<std::string> words, std::size_t size)
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

    std::cout << "Size = " << size << "; " << collision_counter << " collisions" << std::endl;
}

void ELF_collision_test(std::set<std::string> words, std::size_t size)
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

    std::cout << "Size = " << size << "; " << collision_counter << " collisions" << std::endl;
}

void BKDR_collision_test(std::set<std::string> words, std::size_t size)
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

    std::cout << "Size = " << size << "; " << collision_counter << " collisions" << std::endl;
}

void SDBM_collision_test(std::set<std::string> words, std::size_t size)
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

    std::cout << "Size = " << size << "; " << collision_counter << " collisions" << std::endl;
}

void DJB_collision_test(std::set<std::string> words, std::size_t size)
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

    std::cout << "Size = " << size << "; " << collision_counter << " collisions" << std::endl;
}

void AP_collision_test(std::set<std::string> words, std::size_t size)
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

    std::cout << "Size = " << size << "; " << collision_counter << " collisions" << std::endl;
}

void DEK_collision_test(std::set<std::string> words, std::size_t size)
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

    std::cout << "Size = " << size << "; " << collision_counter << " collisions" << std::endl;
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
