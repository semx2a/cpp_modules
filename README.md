# CPP MODULES

## Summary

This repository contains the modules of the C++ piscine from 42 School.

Each module is in a folder named `cppXX` where `XX` is the number of the module.

The higher the number, the more advanced the module is.

In all of these exercises, I have adhered to good coding practices, ensuring that my code is clean, readable, and efficient. All my code has been compiled using the `c++` compiler with the flags `-Wall -Wextra -Werror`, and it has been confirmed to compile with the `-std=c++98` flag as well.

## Module 00 - Basics

This module served as a solid introduction to Object-Oriented Programming (OOP) using C++, focusing on namespaces, classes, member functions, initialization lists, stdio streams, static and const among others.

The goal of the project was to get familiarized with the basics of C++ and OOP, by creating a series of exercises (Mégaphone, My Awesome PhoneBook) designed to test the understanding of the various concepts.

The exercises covered a wide range of topics, including but not limited to:

- **Creation of Classes and Member Functions**: Developed classes with public and private attributes, along with associated member functions. This helped in understanding the concept of Encapsulation in OOP.
- **Understanding of `this` pointer**: Utilized `this` pointer to refer to the current instance of a class, aiding in distinguishing between local and member variables.
- **Utilization of Initialization Lists**: Implemented initialization lists in constructors for efficient initialization of data members.
- **Static and Const**: Made use of static and const for respective constant and single copy class members.
- **Accessors (getters and setters)**: Implemented accessors (getters and setters) which are functions that read and write the private attributes of a class, providing a controlled access to the private data members of a class.
- **Understanding of Visibility**: Differentiated between public and private visibility specifiers, and their implications on encapsulation in classes.
- **Comparison between Instances**: Wrote comparison functions to compare the values between two instances of the same class.
- **Pointers to Members**: Gained a good understanding of pointers to members of classes, which are somewhat different from normal pointers.
- **Non-member Attributes and Functions**: Worked with non-member attributes and functions, understanding how they can be used in a class context.


## Module 01 - Memory Allocation and References

The objective of this module was to gain a deep understanding of memory allocation, pointers to members, references, and the switch instruction in C++.

The exercises allowed me to enhance my skills in the following areas:

- **Memory Allocation:** Learned how to dynamically allocate memory for program variables during runtime using the new operator for initialization and the delete operator for de-allocation.
- **Pointers on members:** Learned how to declare and assign pointers to class members and understood how to operate them.
- **References:** Understood the use of references in C++ and how they can be used as an alternative to pointers, especially in function argument lists and function return values.
- **Switch Instruction:** Gained experience in employing the switch case control structure to execute one code block among many alternatives.
- **Using C++ libraries:** Had the opportunity to explore the C++ standard library and learned to prefer C++ versions of functions over their C counterparts.

## Module 02 - Ad-hoc Polymorphism, Operators Overloading, and Canonical Form

This training module introduced key aspects of the C++ language including ad-hoc polymorphism, operator overloading, and the canonical form. Exercises were provided to enhance understanding and proficiency in these areas:

- **Ad-hoc Polymorphism:** Ad-hoc polymorphism was covered through function overloading, which allows multiple functions with the same name but different parameters. This allows the same function name to be used for different types.
- **Operator Overloading:** Operator overloading was also explored, providing a way to redefine C++ built-in operators. This allows those operators to work with user-defined classes, improving code readability and efficiency.
- **Canonical Form:** The module also discussed the canonical form in C++. This includes a default constructor, a copy constructor, an assignment operator, and a virtual destructor, which are crucial in managing memory and ensuring proper functionality of user-defined types.

## Module 03 - Inheritance

Key learning outcomes of this module include understanding and applying the principle of inheritance to derive classes from other classes, the exercises are based on game design principles and include:

- **Exercise 00:** Understanding and applying the [open-closed principle](https://en.wikipedia.org/wiki/Open%E2%80%93closed_principle#:~:text=In%20object%2Doriented%20programming%2C%20the,without%20modifying%20its%20source%20code.) of OOP
- **Exercise 01:** Implementing and testing inheritance
- **Exercise 02:** Getting hands-on experience with repetitive tasks using inheritance

## Module 04 - Subtype Polymorphism, Abstract Classes, Interfaces

This module focused on learning and implementing principles related to Polymorphism, Abstract Classes, and Interfaces in C++. It was designed to deepen the understanding of Object-Oriented Programming (OOP) in a C++ environment.

- **Sub-Typing Polymorphism**: The `Animal` exercise where `Dog` and `Cat` classes inherit from `Animal` and override the `makeSound()` function. This demonstrates how different types of the same base class (`Animal`) can have distinct behaviors (`Dog` and `Cat` making different sounds).
- **Abstract Classes**: The `Animal` class in the second exercise is made abstract to ensure it can't be instantiated directly. This is achieved by defining at least one pure virtual function in the `Animal` class. The `Dog` and `Cat` classes, which inherit from `Animal`, provide their own implementation of this function.
- **Interfaces**: While not explicitly present in these exercises, the concept of interfaces is similar to that of pure abstract classes (classes where all functions are pure virtual). An example could be a hypothetical `ISoundMaker` interface with a pure virtual function `makeSound()`, which would then be implemented by any classes (like `Dog` or `Cat`) that 'implement' this interface.

## Module 05 - Repetitive Inheritance, Exceptions

- **Nested Classes**: The concept of nested classes was applied in the design of the bureaucratic machine where each Bureaucrat was treated as a class and each action or form they could fill was also a class nested within the Bureaucrat class.
- **Exception Handling**: Exception handling was extensively used in the bureaucratic machine to handle cases where a bureaucrat tries to perform an action for which they do not have the required grade. If the grade was too low, a `Form::GradeTooLowException` was thrown.
- **Memory Management**: The project required proper management of dynamically allocated memory to avoid memory leaks, especially when creating new forms or actions.

### Exercises

- **Exercise 00**: This exercise focused on creating a `Bureaucrat` class with attributes such as a constant name and a grade that ranges from 1 to 150.
- **Exercise 01**: This exercise expanded on the `Bureaucrat` class by adding a `Form` class that the bureaucrats could fill out. The `Form` class had attributes such as a constant name, a boolean indicating whether it was signed or not, and grades required to sign and execute it.
- **Exercise 02**: This exercise introduced more specific forms that the bureaucrats could fill out, such as `ShrubberyCreationForm`, `RobotomyRequestForm`, and `PresidentialPardonForm`. Each form had a specific action associated with it that the bureaucrats could execute.
- **Exercise 03**: This exercise introduced an `Intern` class that could create forms for the bureaucrats to fill out. The `Intern` class had a `makeForm` function that took in the name of a form and a target and returned a pointer to a `Form` object.


## Module 06 - C++ Casts

In this module, we dive deep into the concepts of type conversion, or 'casting', in C++. This concept is fundamental to understanding how different data types interact with one another in a C++ program.

The project consists of three main exercises:

- **Scalar Conversion:** In this exercise, I gained a solid understanding of how to convert scalar types in C++. I learned how to perform both implicit and explicit conversions, and got hands-on experience with promotion and demotion of types.

- **Serialization:** This exercise introduced me to the concept of serialization in C++. I learned how to convert complex data types to a serialized format that can be stored or transmitted and then converted back to its original form.

- **Real Type Identification:** The final exercise required me to identify the real type of a class instance at runtime. This helped me understand the concept of 'type identification' in C++, and also familiarize myself with the dynamic_cast operator.

## Module 07 - C++ Templates

The aim of this module was to explore and understand the concept of templates in C++. This module provided me with the essential knowledge to develop efficient and flexible code using templates, which is a powerful feature of C++.

The projects in this module ranged from simple function templates to more complex class templates. Through these projects, I gained a deep understanding of the power of templates in creating reusable code, which can work with different data types while ensuring type safety.

- **Function Templates:** In this exercise, I started with a few basic function templates to get a feel for the syntax and usage of templates in C++. I implemented function templates for common operations like min, max, and swap.
- **Iter:** Here, I created a function template named 'iter'. This function took three parameters: an array, the length of the array, and a function. The 'iter' function applied the passed function to each element of the array.
- **Array:** In this exercise, I implemented a class template named 'Array'. This class encapsulated an array of elements, where the type of the elements and the size of the array were template parameters. This class also implemented member functions for accessing and modifying array elements.

## Module 08 - Templated Containers, Iterators, Algorithms

This module focused on Container Templates, Iterators, and Algorithms. In the project, I was introduced to container templates, iterators, and algorithms in C++.

These exercises helped me understand the different types of containers available in C++, such as sequence containers, associative containers, and derived containers, and their use cases. Additionally, I worked with iterators to manipulate and traverse through these containers, and used various algorithms to perform operations on the container data.

### Skills Gained

- Deep understanding of container templates, iterators, and algorithms in C++
- Proficiency in programming with C++98 standards
- Practical experience with different types of containers such as sequence containers (vector, deque, list, forward_list, array), associative containers (set, map, multiset, multimap), and derived containers (stack, queue, priority_queue)
- Strong ability to design and implement efficient data structures and algorithms in C++
- Experience in writing clean, efficient, and maintainable code

### Exercises

The repository consists of the following exercises:

- **Exercise 00: Easy Find**
- **Exercise 01: Span**
- **Exercise 02: Mutant Stack**

Each exercise had specific instructions and requirements, pushing me to think critically about the best ways to use and manipulate containers in C++, and to solve problems in an efficient and effective manner.

## Module 09 - The STL

This module and focuses on the **Standard Template Library (STL)**.

## Skills Gained:

**Working with STL:** The project provided a practical understanding of the STL in C++, including containers and algorithms.
- **STL Containers:** The project provided hands-on experience with STL containers such as vector, list, map, and stack.
- **STL Algorithms:** The project provided hands-on experience with STL algorithms such as find, count, and sort.
- **STL Iterators:** The project provided hands-on experience with STL iterators such as input iterators, output iterators, forward iterators, and bidirectional iterators.

### Exercises

- **Exercise 00 - Bitcoin Exchange:** This exercise involved simulating a Bitcoin exchange and implementing various functionalities using the STL.
- **Exercise 01 - Reverse Polish Notation:** This task involved implementing a calculator that uses reverse polish notation. It provided hands-on experience with stack data structure in STL.
- **Exercise 02 - PmergeMe:** This exercise involved implementing the Ford-Johnson Merge-Insertion Sort Algorithm using STL. This task significantly improved understanding of complex sorting algorithms and their implementation using C++ STL.

## Takeaways

The project compelled me to explore C++ and its features in depth. It served as an excellent platform to strengthen the foundation in C++ and OOP, which are essential for software development roles.

This project has greatly improved my problem-solving skills and my ability to read and understand the technical documentation. It also made me comfortable working with a statically typed, compiled language which has broadened my skill set as a software engineer.