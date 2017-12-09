// Overload operator<<

#include <iostream>

class foo
{
  public:
    friend std::ostream& operator<<(std::ostream& stream,
                                    foo const& f);

  private:
    int x = 10;
};

std::ostream& operator<<(std::ostream& stream,
                         foo const& f)
{
  return stream << "A foo with x = " << f.x;
}

// Write your class type objects to an output stream.
//
// We implement `operator<<` on [15-19], which takes a reference to an
// [`std::ostream`](cpp/io/basic_ostream) (the base class for all
// output streams) and the `foo` object we wish to write to the stream.
// On [18], we simply write a string representing the `foo` object to
// the steam and return a reference to the stream itself, allowing
// this call to be chained.
//
// Note that we declare this `operator<<` as a `friend` of `foo` on
// [8-9]. This gives it access to `foo`'s private member, `x`.

int main()
{
  foo f;
  std::cout << f << std::endl;
}
