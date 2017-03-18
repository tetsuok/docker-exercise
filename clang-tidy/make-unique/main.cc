#include <memory>

class A {};

class B {
 public:
  B() : a_(new A) {}

  void reset() {
    a_.reset(new A);
  }

 private:
  std::unique_ptr<A> a_;
};

int main() {
  {
    auto b_ptr = std::unique_ptr<B>(new B);
  }
  return 0;
}
