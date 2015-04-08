// Visitor

#include <functional> // for std::reference_wrapper
#include <iostream> // for std::cout
#include <vector>

// Forward define this
class shape_visitor;

class shape
{
	public:
		virtual void accept(shape_visitor& visitor) = 0;
};

// We need to forward define these here so that the visitor interface knows about them
class circle;
class square;

class shape_visitor
{
	public:
		virtual void visit(circle& shape) = 0;
		virtual void visit(square& shape) = 0;
};

class circle : public shape
{
	public:
		virtual void accept(shape_visitor& visitor)
		{
			visitor.visit(*this);
		}
};

class square : public shape
{
	public:
		virtual void accept(shape_visitor& visitor)
		{
			visitor.visit(*this);
		}
};

class print_visitor : public shape_visitor
{
	public:
		virtual void visit(circle& shape)
		{
			std::cout << "Visited a circle" << std::endl;
		};
		
		virtual void visit(square& shape)
		{
			std::cout << "Visited a square" << std::endl;
		};
};

// Visit different types of shapes and print their types.
// 
// The visitor pattern allows generic algorithms to be implemented 
// without adding to the underlying objects and allows different actions
// for each type of object being visited without the need for dynamic casting.
// 
// The `shape` class, defined on [10-14], defines
// an interface that allows it to accept a shape visitor. Each specialization 
// a shape implements this method to call the appropriate
// visit function on the visitor. This is know as 'double dispatch'
// because there are 2 concrete function calls.
// Visitors, in this case, are objects that
// implement the `shape_visitor` interface ([34-39]). The
// visitor interface defines visit functions for each type of shape.
// This way, the compiler helps to detect
// 
// In this example, a `print_visitor` ([41-53]) is used to print the type
// of shape that each item in the shapes vector is. Other simple examples
// could include calculating the area of a given shape.
int main()
{
	std::vector<std::reference_wrapper<shape>> shapes;
	
	circle myCircle;
	shapes.push_back(myCircle);
	
	square mySquare;
	shapes.push_back(mySquare);
	
	print_visitor v;
	for (shape& s : shapes)
	{
		s.accept(v);
	}
};