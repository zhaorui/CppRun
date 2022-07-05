#include <iostream>
using namespace std;

struct B {
  virtual void bar() { std::cout << "B::bar\n"; }
  virtual ~B() = default;
};

struct D : B
{
    D() { std::cout << "D::D\n";  }
    ~D() { std::cout << "D::~D\n";  }
    void bar() override { std::cout << "D::bar\n";  }
};

// 消费 unique_ptr 的函数能以值或以右值引用接收它
std::unique_ptr<D> pass_through(std::unique_ptr<D> p)
{
    p->bar();
    return p;
}

void close_file(std::FILE* fp) { std::fclose(fp); }

void unique_ptr_demo() {
  std::cout << "unique ownership semantics demo\n";
  {
      auto p = std::make_unique<D>(); // p 是占有 D 的 unique_ptr
      auto q = pass_through(std::move(p)); 
      assert(!p); // 现在 p 不占有任何内容并保有空指针
      q->bar();   // 而 q 占有 D 对象
  } // ~D 调用于此
}