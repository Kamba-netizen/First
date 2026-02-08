#include <iostream>
#include <string.h>
class Mystring {
    private:
    char* string_content;
    int str_len;
    int memory_capacity;

    public:
    Mystring(char c);
    Mystring(const char* str);
    Mystring(const Mystring& str);
    ~Mystring();

    int Length() const;
    int capacity() const;
    void reserve(int size);

    char at(int i) const;
    void Print() const;
    void Println() const;
    Mystring& assign(const Mystring& str);
    Mystring& assign(const char* str);
};

Mystring::Mystring(char c) {
    string_content = new char[1];
    string_content[0] = c;
    str_len = 1;
    memory_capacity = 1;
}
Mystring::Mystring(const char* str) {
    str_len = strlen(str);
    memory_capacity = str_len;
    string_content = new char[str_len];
    for (int i = 0; i != str_len; i++)
        string_content[i] = str[i];
    
}
Mystring::Mystring(const Mystring& str) {
    str_len = str.str_len;
    memory_capacity =str.str_len;
    string_content = new char[str_len];
    for (int i = 0; i != str_len; i++)
        string_content[i] = str.string_content[i];
}
Mystring::~Mystring() {
    delete[] string_content;
}
int Mystring::Length() const {
    return str_len;
}
int Mystring::capacity() const {
    return memory_capacity;
}
void Mystring::Print() const {
    for (int i = 0; i != str_len; i++)
        std::cout << string_content[i];
}
void Mystring::Println() const {
  for (int i = 0; i != str_len; i++) {
    std::cout << string_content[i];
  }
  std::cout << std::endl;
}
Mystring& Mystring::assign(const Mystring& str) {
    if(str.str_len > memory_capacity) {
        string_content = new char[str.str_len];
        memory_capacity = str.str_len;
    }
    for (int i = 0; i != str.str_len; i++)
        string_content[i] = str.string_content[i];
    str_len = str.str_len;

    return* this;
}
Mystring& Mystring::assign(const char* str) {
    int str_length = strlen(str);
    if (str_length > memory_capacity) {
        delete[] string_content;
        string_content = new char[str_length];
        memory_capacity = str_length;
    }
    for (int i = 0; i != str_length; i++)
        string_content[i] = str[i];
    str_len = str_length;

    return* this;
}
void Mystring::reserve(int size) {
    if (size > memory_capacity) {
        char* prev_string_content = string_content;
        
        string_content = new char[size];
        memory_capacity = size;

        for (int i = 0; i != str_len; i++)
            string_content[i] = prev_string_content[i];
        delete[] prev_string_content;
    }
}
char Mystring::at(int i) const {
    if (i > str_len || i < 0)
        return NULL;
    else
        return string_content[i];
}

int main() {
  Mystring str1("very very very long string");
  str1.reserve(30);

  std::cout << "Capacity : " << str1.capacity() << std::endl;
  std::cout << "String length : " << str1.Length() << std::endl;
  str1.Println();
  std::cout << str1.at(23) << std::endl;
  return 0;
}