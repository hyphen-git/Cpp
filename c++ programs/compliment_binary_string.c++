// a simple program to convert a binary string of 0 and 1 to 1 and 0 with the use of class , methods , properties and nesting of methods how to access the private method

// updated
#include <iostream>
#include <string>
using namespace std;

class binary
{
private:
   string str;

   void compliment_string(void);
   void display_string();

public:
   void input_string(void);
   void check_string(void);
};

void binary ::input_string()
{
   cout << "Enter the number string in binary : ";
   cin >> str;
}

void binary ::check_string()
{
   for (int i = 0; i < str.length(); i++)
   {
      if (str.at(i) != '0' && str.at(i) != '1')
      {
         cout << "Incorrect string format " << endl;
         exit(0);
      }
   }
   compliment_string();
}

void binary ::compliment_string()
{
   for (int i = 0; i < str.length(); i++)
   {
      if (str.at(i) == '1')
      {
         str.at(i) = '0';
      }
      else
      {
         str.at(i) = '1';
      }
   }

   display_string();
}

void binary ::display_string()
{

   cout << "The compliment of the given binary string is : ";
   for (int i = 0; i < str.length(); i++)
   {
      cout << str.at(i);
   }
}

int main()
{
   binary obj;

   obj.input_string();
   obj.check_string();

   return 0;
}
