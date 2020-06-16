#include <iostream>
#include <string>

int hf ( std::string s )
{
  unsigned int h, i;

  h = 0;
  for( i = 0; i < s.length( ); i++ )
    h = 2 * h + 1 - ( s [ i ] & 1 );
  return h % 10;
}

int main()
{
    for (auto slowo : {"piesek","bla","quick","brown","fox","iwan","kara"})
    {
        std::cout << slowo << ":" <<hf(slowo) << "\n";
    }
    
    return 0;
}