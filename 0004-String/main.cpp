#include<iostream>
#include<cstring>

class Str
{
  private:
  char *res;
  unsigned int len;

  public:
  // default ctor
  // RAII (Resource Acquisition In Initialization)
  // initializer list (when must be used): member that can be created but not changed.
  // - like const member,
  // - reference member (int& var),
  // - obj from another class need to initialize, but there is only parameterized ctor defined, and
  // not default ctor is defined in its class.
  Str(): res(nullptr), len(0) {}

  // parameterized ctor
  Str(const char *chs)
  {
    len = std::strlen(chs);
    res  = new char [len+1];
    std::strcpy(res, chs);
  }

  // copy ctor
  // if not pass through ref, it will call copy ctor,
  // which is undefined
  Str(const Str &ipstring)
  {
    len = ipstring.len;
    res = new char[len+1];
    std::strcpy(res, ipstring.res);
  }

  // move-copy ctor
  // && rvalue reference, i.e., passing as temp object
  // & normal reference
  // Can not take lvalue reference from rvalue
  // // int& a = 10;  // will not work
  // const int& b = 10; // will work  // int temp = 10; const int& = temp;
  Str(Str&& ipstring)
  {
    if (this != &ipstring)
    {
      len = ipstring.len;
      res = ipstring.res;   // not copy, just pointing to existing ipstring.res
      ipstring.len = 0;
      ipstring.res = nullptr;
    }
  }

  // copy assignment operator
  // var3 = var2
  // var3 calls the operator= func with var2 as parameter
  /*
  Str& operator=(const Str &ipstring)
  {
    // to avoid var3=var3 condition;
    if(this!=&ipstring)
    {
      // delete already assigned resource
      delete []res;
      len = ipstring.len;
      res = new char[len+1];
      strcpy(res, ipstring.res);
    }
    return *this;
  }
  */

  /* copy And Swap (CAS) idiom */
  // ipstr will use copy constructor
  Str& operator=(Str ipstr) noexcept
  {
    std::swap(this->res, ipstr.res);
    std::swap(this->len, ipstr.len);
    return *this;
  }

  // move-copy assignment operator
  /*
  Str& operator=(Str &&ipstring)
  {
    if (this != &ipstring)
    {
      len = ipstring.len;
      res = ipstring.res;
      ipstring.len = 0;
      ipstring.res = nullptr;
    }
    return *this;
  }
  */

  Str& operator()(Str &&ipstring)
  {
    if (this != &ipstring)
    {
      len = ipstring.len;
      res = ipstring.res;
      ipstring.len = 0;
      ipstring.res = nullptr;
    }
    return *this;
  }

  unsigned int length()
  {
    return len;
  }

  // cin >> str2; cout << str2;
  // operator>> will call with cin and str2 as parameter
  // need to overload these operators, outside class
  // else cin will call the operator>>, in that case operator>> need to overload
  // inside cin class, which is not permitted
  // to access Str.res private variable, friend function is declared to
  // provide access to private variables of Str class
  friend std::istream& operator>> (std::istream& in, const Str& ipstr);
  friend std::ostream& operator<< (std::ostream& out, const Str& ipstr);

  ~Str()
  {
    if (res)
    {
      delete []res;
      res = nullptr;
      len = 0;
    }
  }
};

std::istream& operator>> (std::istream& in, const Str& ipstr)
{
  in >> ipstr.res;
  return in;
}

std::ostream& operator<< (std::ostream& out, const Str& ipstr)
{
  out << ipstr.res;
  // need to return ostream as cout can be chained.
  // cout << str2 << str1;
  return out;
}

int main(int argc, char** argv)
{
  Str var1;                     // default ctor

  Str var2 = "hello ";           // parameterized ctor
  Str var3("world ");

  Str var4(var3);               // copy ctor
  Str var5 = var4;

  Str var6 = std::move(var5);   // move-copy ctor
  Str var7 (std::move(var6));
  Str var8 = (Str&&) var7;

  var1 = var8;                  // copy assignment operator
  var1 = var1;

  var1 = std::move(var4);       // move-copy assignment operator

  var1(std::move(var3));        // () operator

  std::cout << var1;            // << operator

  std::cin >> var1;            // >> operator

  int len = var1.length();

  // std::cout << var1 << var2 << var3 << var4 << var5 << var6 << var7 << var8 << std::endl;
  std::cout << var1 << var2 << var8 << std::endl;

  //dtor

  return 0;
}
