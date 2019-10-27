# Chapter 11: More about Classes and Object-Oriented Programming



### 11.1 The `this` Pointer and Constant Member Functions

By default, the compiler provides each member function of a class with an implicit parameter that points to the object through which the member function is called. The implicit parameter is called `this`. A constant member function is one that does not modify the object through which it is called.

**The `this` Pointer**

```c++
void Example(int x)
{
	this->x = x;	// class memeber variable x = parameter x
}					// equivalent to (*this).x
```

**Constant Member Functions**: a function that cannot modify its object. Add the `const` keyword after the function’s parameter list to tell the compiler that the member function should not be allowed to modify its object.

```c++
int ConstExample::getValue() const	// must be in the declaration & definition
{
	return x;
}
```

- A function with a constant parameter  cannot turn around and pass it as a non-constant parameter to another function. The other function must also promise not to modify the parameter.



### 11.2 Static Members

If a member variable is declared `static`, all objects of that class have access to that variable. If a member function is declared `static`, it may be called before any instances of the class are defined.

##### Static Member Variables

To create a static member variable, place the keyword `static` in front of the variable declaration. Then, place a separate definition of the variable outside the class.

```c++
class StatDemo
{
    private:
    	static int x;
}

int StatDemo::x;
```

When one class object changes this static variable, it changes the value for all objects of this class.

![1571627924946](assets/1571627924946.png)

**declaration**: provides information about the existence and type of a variable or function.

**definition**: provides all the information contained in a declaration and, in addition, causes memory to be allocated for the variable or function being defined.

Static member variables must be **declared** inside the class and **defined** outside of it.

**instance members**: a member whose use must be associated with a particular instance of a class.

**static member**: a member that does not need to be associated with any instance. Only the class of the static member needs to be specified.  

- Member functions that do not access any non-static members of their class should be made static.

- The `this` pointer cannot be used in a static member function because static member functions are not called through any instance of their class.

```c++
class StatAccess
{
   private:
      int x; 
   public:
      static void print(StatAccess a)
      {
         cout << a.x;
      }
   StatAccess(int x) { this−>x = x; }
};
```



### 11.3 Friends of Classes

A `friend` is a function that is not a member of a class but has access to the private members of the class.

The class must grant access to the friend function.

```c++
class Aux
{
private:
   double auxBudget;
public:
   Aux() { auxBudget = 0; }
   void addBudget(double);
   double getDivBudget() { return auxBudget; }
};

void Aux::addBudget(double b)
{
   auxBudget += b;
   Budget::corpBudget += auxBudget;
}
```



### 11.4 Memberwise Assignment

The `=` operator may be used to assign one object to another, or to initialize one object with another object’s data. By default, each member of one object is copied to its counterpart in the other object.



### 11.5 Copy Constructors

A copy constructor is a special constructor that is called whenever a new object is created and initialized with the data of another object of the same class.

If the programmer does not specify a copy constructor for the class, then the compiler automatically calls the *default copy constructor*. This default copy constructor simply copies the data of the existing object to the new object using memberwise assignment.

Problems may occur when copying objects with pointers, as the value of the pointer in the first object is copied to the second object, leaving both pointers pointing to the same data.

![1571634087888](assets/1571634087888.png)

A programmer-defined copy constructor must have a single parameter that is a reference to the *same* class. This avoids the problems of the default copy constructor by allocating separate memory for the pointer of the new object before doing the copy. The parameter should be a const reference because the copy constructor should not modify the object being copied.

```c++
NumberArray::NumberArray(const NumberArray &obj)
```

The copy constructor is also automatically called by the compiler to create a copy of an object whenever an object is being passed by *value* in a function call. 

Class copy constructors are called when:

- A variable is being initialized from an object of the same class
- A function is called with a value parameter of the class
- A function is returning a value that is an object of the class



### 11.6 Operator Overloading

C++ allows you to redefine how standard operators work when used with class objects.

To address the problems that result from memberwise assignment of objects, we need to modify the behavior of the assignment operator so that it does something other than memberwise assignment when it is applied to objects of classes that have pointer members. In effect, we are supplying a different version of the assignment operator to be used for objects of that class. In so doing, we say that we are *overloating* the assignment operator.

![image-20191027100907264](assets/image-20191027100907264.png)

