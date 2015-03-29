// Define class interfaces with non-member functions 

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

// Improve encapsulation with non-member non-friend functions.
// 
// On [17-20], we define a function, `non_member`, which is logically
// part of the interface of `foo`. However, as this function can
// simply be implemented in terms of the member function, `member`, 
// we define it as a non-member function.
// 
// This approach [improves encapsulation](http://www.drdobbs.com/cpp/how-non-member-functions-improve-encapsu/184401197)
// by reducing the number of functions that are dependent on the
// private members of a class.
// 
// On [26], argument-dependent lookup (ADL) allows us to call
// `non_member` without qualifying it with the `ns` namespace. The ADL
// rule specifies that the name of a function will be looked up
// in the namespaces of its arguments. As we are passing an
// `ns::foo` to `non_member`, the function is found in the `ns`
// namespace.
