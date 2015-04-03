// Non-member non-friend interfaces 

namespace ns
{
	class foo
	{
		public:
			void member()
			{
				// Uses private data
			}

		private:
			// Private data
	};

	void non_member(foo obj)
	{
		obj.member();
	}
}

int main()
{
	ns::foo obj;
	non_member(obj);
}

// Reduce dependencies on internal class details and improve
// encapsulation.
// 
// The `foo` class, defined on [5-15], has a single member function,
// `member` ([8-11]), that requires access to `foo`'s private data.
// 
// The function `non_member` on [17-20] is also logically part of
// `foo`'s interface, yet has been defined as a non-member because it
// can be implemented in terms of `member`. This approach
// [improves encapsulation](http://www.drdobbs.com/cpp/how-non-member-functions-improve-encapsu/184401197)
// by reducing the number of functions that are dependent on the
// private members of a class.
// 
// On [26], argument-dependent lookup (ADL) allows us to call
// `non_member` without qualifying it with the `ns` namespace. The ADL
// rule specifies that the name of a function will be looked up
// in the namespaces of its arguments. As we are passing an
// `ns::foo` to `non_member`, the function is found in the `ns`
// namespace.
