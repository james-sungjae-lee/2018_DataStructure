#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  ofstream output("data5.txt", ios::out);
  string buffer = "A program that translates a high level languageto a machine language\n is called a compiler. A compiler is thus a somewhat peculiar sort\n of program and its output is yet another program. To avoid confusion,\n the input program is usually called the source program or\n source code, and the translated version produced by the compiler is called";
  output << buffer;
  output.close();

  ifstream input("data5.txt", ios::in);

  long c;
  long characters = 0;
  long havealpha;
  long words = 0;
  long counter;
  long sentences = 0;
  long newlines = 0;

  while ((c=input.get()) != EOF)
{
  long total = 0;
  long line = 0;
  long totaltemp = 0;
  long linetemp = 0;

  while (c!='\n')
  {
      ++total;
      ++line;
      if (total > totaltemp)
      {
          totaltemp = total;
          linetemp = line;
      }
      if (c=='\n')
      {
          total = 0;
          line = 0;
      }
  }
    ++characters;
    if(isalpha(c))
        havealpha=true;
    if (isspace(c) && havealpha)
    {
        ++words;
        havealpha=false;
    }

    if (c=='.')
        counter = 2;
    if (c==' ')
        --counter;
    if (c=='\n')
        counter = 0;
    if (counter <= 0)
    {
        ++sentences;
        counter = 0;
    }

    if (c=='\n')
        ++newlines;

        cout<<characters<<"Characters"<<words<<"Words"<<sentences<<"Sentences"                        <<newlines<<"New Lines"<<"The longest line is"<<linetemp<<"with"<<totaltemp<<"characters"   <<endl;

}
}
