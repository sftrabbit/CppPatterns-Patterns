// Write class type objects to a stream

#include <iostream>

class foo
{
	public:
		foo(int x)
			: x(x)
		{ }

		friend std::ostream& operator<<(std::ostream& stream, 
		                                foo const& f);

	private:
		int x;
};

std::ostream& operator<<(std::ostream& stream, 
                         foo const& f)
{
	return stream << "A foo with x = " << f.x;
}

int main()
{
	foo f(10);
	std::cout << f << std::endl;
}


// Write your class type objects to an output stream by implementing
// `operator<<`.
// 
// We implement `operator<<` on [19-23], which takes a reference to an
// [`std::ostream`](cpp/io/basic_ostream) (the base class for all
// output streams) and the `foo` object we wish to write to the stream.
// On [22], we simply write a string representing the `foo` object to
// the steam and return a reference to the stream itself, allowing
// this call to be chained.
// 
// Note that we declare this `operator<<` as a `friend` of `foo` on
// [12-13]. This gives it access to `foo`'s private member, `x`.
// 
// On [27-28], we stream a `foo` object to [`std::cout`](cpp/io/cout).
