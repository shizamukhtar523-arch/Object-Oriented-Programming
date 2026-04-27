 #include <iostream>
using namespace std;
class File
{
public:
    File()
    {
        cout << "File opened" << endl;
    }
    ~File()
    {
        cout << "File closed" << endl;
    }
};
class TextFile : public File
{
public:
    TextFile()
    {
        cout << "TextFile opened" << endl;
    }
    ~TextFile()
    {
        cout << "TextFile closed" << endl;
    }
};
int main()
{
    TextFile t;
}
