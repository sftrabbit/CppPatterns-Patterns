// The rule of zero

#include <memory>

class shallow
{
	private:
		std::shared_ptr<int> p = std::make_shared<int>(5);
};

class deep
{
	public:
		deep() = default;

		deep(deep const& other)
			: p{std::make_unique<int>(*other.p)}
		{ }

	private:
		std::unique_ptr<int> p = std::make_unique<int>(5);
};

// Use existing RAII types to encapsulate and safely manage
// dynamically allocated resources.
// 
// The class `shallow` ([5-9]) manages a dynamically allocated `int`
// object. Rather than manage this object manually, we use a
// [`std::shared_ptr`](cpp/memory/shared_ptr) on [15] to take
// ownership of the object. The lifetime of this object is now
// tied to the lifetime of the `foo` object that contains it
// without having to implement any constructors or destructors. If
// a `shallow` object is copied, the copy will share ownership of
// this resource.
// 
// If we want to perform a deep copy, we can instead use a
// [`std::unique_ptr`](cpp/memory/unique_ptr) and implement a
// copy constructor to copy the resource, as shown with the `deep`
// class on [11-22].

int main()
{
	shallow s1;
	shallow s2 = s1;

	deep d1;
	deep d2 = d1;
}
