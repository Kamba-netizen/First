#include <iostream>

class string {
    char* str;
    int len;
    
    public:
    string(char c, int n); // 문자 c가 n 개 있는 문자열
    string(const char* s);
    string(const string& s);
    ~string();

    void show_stringlen();
    void add_string(const string& s);
    void copy_string(const string& s);
    int strlen();
    void show_string();
};

string::string(char c, int n) {
    len = n;
    str = new char[len + 1];
    for (int i=0; i<len; i++) 
        str[i] = c;
    str[len] = '\0';
}
string::string(const char* s) {
    int cnt = 0;
    while (s[cnt] != '\0')
        cnt++;
    str = new char[cnt + 1];
    for (int i=0; i<cnt; i++)
        str[i] = s[i];
    len = cnt;
    str[len] = '\0';
}
string::string(const string& s) {
    str = new char[s.len + 1];
    len = s.len;
    string::copy_string(s);
}
string::~string() {
    if (str)
        delete[] str;
}
void string::add_string(const string& s) {
    char* new_str = new char[len + s.len + 1];

    for (int i=0; i<len; i++) 
        new_str[i] = str[i];
    
    for (int i=0; i<s.len; i++) 
        new_str[len + i] = s.str[i];
    
    len += s.len;
    new_str[len] = '\0';
    delete[] str;
    str = new_str;
}
void string::copy_string(const string& s) {
    for (int i=0; i<s.len; i++) {
        str[i] = s.str[i];
    }
    str[s.len] = '\0';
}
int string::strlen() {
    return len;
}
void string::show_string() {
    std::cout << str << std::endl;
}
void string::show_stringlen() {
    std::cout << "문자열 길이: " << len << std::endl;
}
int main(void) {
    string s1('J', 5);
    string s2("Hello");
    string s3(s2);

    s1.add_string(s2);
    s1.show_string();
    s3.show_string();
    s1.show_stringlen();
    s1.copy_string(s3);
    s1.show_string();
    return 0;
    
}