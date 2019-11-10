# Chapter 15: Polymorphism and Virtual Functions

### 15.1 Type Compatibility in Inheritance Hierarchies

Objects of a derived class can be used wherever objects of a base class object are expected.

- **A derived class pointer can always be assigned to a base class pointer**. This means that base class pointers can point to derived class objects.
- **A type cast is required to perform the opposite assignment of a base class pointer to a derived class pointer.** An error may result at run time if the base class pointer does not actually point to a derived class object.

Review:

- Shared pointers handle `new` and `delete` (dynamic memory allocation) for you and should be used when you want to share pointers between objects.
- Unique pointers should be used when you only need an instance of that pointer within scope because it will only exist within the scope where it is defined. Once the scope is exited, the pointer is destroyed.

```c++
#include <memory>
// shared pointer
//			template parameter		  equivalent to calling 'new'
std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();

// unique pointer
std::unique_ptr<Entity> entity = std::make_unique<Entity>();
```

```c++
class Base
{
public:
    int i;
    Base(int k) { i = k; }
};

class Derived : public Base
{
public:
    double d;
    Derived(int k, double g) : Base(k) { d = g; }
};

// Raw pointers
Base  *raw_pb = new Base(5);
Derived *raw_pd = new Derived(6, 10.5);

// Smart pointers
shared_ptr<Base> pb = make_shared<Base>(5);
shared_ptr<Derived> pd = make_shared<Derived>(6, 10.5);

// Rule #1: A derived class pointer can always be assigned to a base class pointer.

// Raw pointers
Base *raw_bp1 = raw_pd;
Base *raw_bp2 = new Derived(7, 11.5);

// Smart pointers
shared_ptr<Base> pb1 = pd;
shared_ptr<Base> pb2 = make_shared<Derived>(7, 11.5);

// Rule #2: A type cast is required to perform the opposite assignment of a base class pointer to a derived class pointer.

Derived *raw_pd1 = static_cast<Derived *>(raw_pb1);
shared_ptr<Derived> pd1 = static_pointer_cast<Derived>(pb1);	// smart pointer

```

These compatibility rules hold true even for deep inheritance hierarchies, such as `Person` -> `Faculty` -> `TFaculty`. 

```c++
TFaculty *tF = new TFaculty(name, disc);
Person *p;
p - tF;

// An assignment in the reverse direction, however, requires a type cast:
tF = static_cast<TFaculty *>(p);
// using shared pointers
shared_ptr<Person> ptp;
shared_ptr<TFaculty> ptf;
ptf = static_pointer_cast<TFaculty>(ptp);
```

- A function parameter that is declared as a pointer to a base class will accept a pointer to a derived class object.
- A function that declares a return type of a pointer to a particular class *C* may return a pointer to an object of a class derived from _C_.

When a base class pointer is pointing to an object of a derived class, any attempt to access class members not derived from the base class will cause an error. We need to coax the compiler to accept the statement by using type casts, such as `static_cast` and `static_pointer_cast`.

```c++
static_pointer_cast<Faculty> (pPerson)->setDepartment(Discipline::BIOLOGY);
// OR
shared_ptr<Faculty> pFaculty = static_pointer_cast<Faculty>(pPerson);
pFaculty−>setDepartment(Discipline::BIOLOGY);
```

- When a pointer to a base class is being used to access a member function that has been overridden by the derived class, the default C++ behavior is to use the version of the function that is defined in the class of the pointer rather than in the class of the object.



### 15.2 Polymorphism and Virtual Member Functions

**Virtual functions** allow the most specific version of a member function in an inheritance hierarchy to be selected for execution. Virtual functions make polymorphism possible.

A piece of code is said to be ***polymorphic*** if the executing code with different types of data produces different behavior. For example, a function would be called polymorphic if it executes differently when it is passed different types of parameters.

- The virtual characteristic is inherited. If a member function of a derived class overrides a virtual function in the base class, then that member function is automatically virtual itself.
- Although it is not necessary, many programmers still tag derived virtual functions with the key word `virtual` to identify them.

```c++
class B
{
public:
   virtual void mfun()
   {
      cout << "Base class version";
   }
};

class D : public B
{
public:
   virtual void mfun()
   {
      cout << "Derived class version";
   }
};
```

- If a virtual member  function is defined outside of the class declaration, the virtual keyword goes on its declaration inside the class but not on the function.



#### Dynamic and Static Binding

The compiler is said to **bind** the name of a function when it selects the code that should be executed when the function name is invoked. In other words, the compiler binds the name to a function definition when the function is called.

-  **Static binding** happens at compile time and binds the name to a fixed function definition, which is then executed each time the name is invoked.
  - The compiler uses type information available at compile time. If the code is operating on objects of different classes within an inheritance hierarchy, the only type information available to the compiler will be the base class pointer type used to access all the objects.
  - Static binding will always use the base class version of a member function.
- **Dynamic binding** occurs at run-time. It only works if the compiler can determine at runtime the exact class that a subclass object belongs to. The compiler stores runtime type information in every object of a class with a virtual function.
  - Dynamic binding always uses the version of the member function in the actual class of the object, regardless of the class of the pointer used to access the object.



`override` tells the compiler that the function is supposed to override a function in the base class. It will cause a compiler error if the function does not actually override any functions.

`final` tells the compiler that a virtual member function cannot be overridden any further down the class hierarchy.



### 15.3 Abstract Base Classes and Pure Virtual Functions

Abstract classes and pure virtual functions can be used to define an interface that must be implemented by derived classes.

**Pure virtual function** - a member function for which the class provides no implementation. The C++ way of declaring a pure virtual function is to put the expression `= 0` in the class declaration where the body of the function would otherwise have gone.

**Abstract class** - a class with at least one pure virtual function. The C++ compiler will not allow you to instantiate an abstract class. Abstract classes can only be subclassed, meaning you can only use them as base classes from which to derive other classes. They are essentially templates.

- A class derived from an abstract class inherits all functions in the base class and will itself be an abstract class unless it overrides all the abstract functions it inherits.

Remember the following points about abstract base classes and pure virtual functions:

- When a class contains a pure virtual function, it is an abstract base class.
- Abstract base classes cannot be instantiated.
- Pure virtual functions are declared with the = 0 notation and have no body or definition.
- Pure virtual functions must be overridden in derived classes that need to be instantiated.



### 15.4 Composition versus Inheritance

Inheritance shold model an “is-a” relation, rather than a “has-a” relation, between the derived and base classes. Composition occurs whenever a class contains an object of another class as one of its member variables.

- It is a good design practice to prefer composition to inheritance whenever possible.

Ways to decide whether to use inheritance or composition:

- Is it natural to think of a C2 object as a special type of C1 object? If so, then you should use inheritance.
- Will objects of class C2 need to be used in places where objects of class C1 are used? For example, will they need to be passed to functions that take reference parameters of type C1, or pointers to C1? If so, then you should make C2 a derived class of C1.