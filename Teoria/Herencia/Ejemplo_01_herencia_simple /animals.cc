// En el siguiente ejemplos se crean la clase Animal y Dog, donde Dog hereda de Animal
// sus métodos y añade el método bark
// Para compilar realizar make y para ejecutar realizar ./animals

#include <iostream>

class Animal {
 public:
  void eat() {
    std::cout << "I can eat!" << std::endl;
  }

  void sleep() {
    std::cout << "I can sleep!" << std::endl;
  }
};

// La herencia se consigue de la siguiente forma:
// class "Subclase" : "tipo_de_herencia" "Clase_base"
class Dog : public Animal {
 public:
  void bark() {
    std::cout << "I can bark! Woof woof!!" << std::endl;
  }
};

int main() {
  Dog dog1;
  dog1.eat();
  dog1.sleep();
  dog1.bark();
  return 0;
}