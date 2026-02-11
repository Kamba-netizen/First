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

    Mystring& insert(int loc, const Mystring& str);
    Mystring& insert(int loc, const char* str);
    Mystring& insert(int loc, char c);

    Mystring& erase(int loc, int num);

    int find(int find_from, const Mystring& str) const;
    int find(int find_from, const char* str) const;
    int find(int find_from, const char c) const;

    int compare(const Mystring& str) const;
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
        return 0;
    else
        return string_content[i];
}
Mystring& Mystring::insert(int loc, const Mystring& str) {
    if (loc < 0 || loc > str_len)
        return* this;

    if (str_len + str.str_len > memory_capacity) {
        if (memory_capacity * 2 > str_len + str.str_len) 
            memory_capacity *= 2;
        else
            memory_capacity = str_len + str.str_len;

        char* prev_string_content = string_content;
        string_content = new char[memory_capacity];

        int i;
        for (i = 0; i < loc; i++)
            string_content[i] = prev_string_content[i];
        
        for (int j = 0; j != str.str_len; j++) 
            string_content[i+j] = str.string_content[j];
        
        for (; i < str_len; i++) 
            string_content[str.str_len + i] = prev_string_content[i];
        
        delete[] prev_string_content;

        str_len = str_len + str.str_len;
        return* this;
    }

    for (int i = str_len - 1; i >= loc; i--) 
        string_content[i + str.str_len] = string_content[i]; 

    for (int i = 0; i < str.str_len; i++) 
        string_content[i + loc] = str.string_content[i];
    str_len = str_len + str.str_len;
    return* this;
}
Mystring& Mystring::insert(int loc, const char* str) {
    Mystring temp(str);
    return insert(loc, temp);
}
Mystring& Mystring::insert(int loc, char c) {
    Mystring temp(c);
    return insert(loc, temp);
}
Mystring& Mystring::erase(int loc, int num) {
    if (num < 0 || loc > str_len || loc < 0)
        return* this;
    if (loc + num >= str_len) {
        str_len = loc;
        return* this;
    }
    
    for (int i = loc + num; i < str_len; i++) {
        string_content[i - num] = string_content[i];
    }
    str_len -= num;
    return* this;
}
int Mystring::find(int find_from, const Mystring& str) const {
    int i, j;
    if (str.str_len == 0)
        return -1;
    for (i = find_from; i <= str_len - str.str_len; i++) {
        for (j = 0; j < str.str_len; j++) {
            if (string_content[i + j] != str.string_content[j])
                break;
        }
        if (j == str.str_len)
            return i;
    }
    return -1;
}
int Mystring::find(int find_from, const char* str) const {
    Mystring temp(str);
    return find(find_from, temp);
}
int Mystring::find(int find_from, char c) const {
    Mystring temp(c);
    return find(find_from, temp);
}
int Mystring::compare(const Mystring& str) const {
    for (int i = 0; i < std::min(str_len, str.str_len); i++) {
        if (string_content[i] > str.string_content[i])
            return 1;
        else if (string_content[i] < str.string_content[i])
            return -1;
    }
    
    if (str_len == str.str_len) return 0;

    else if (str_len > str.str_len)
        return 1;
    return -1;
}
int main() {
  Mystring str1("abcde");
  Mystring str2("abcde");

  std::cout << "str1 and str2 compare : " << str1.compare(str2) << std::endl;

  return 0;
}