abstract class Animal {

    public Animal() { //constructor
        System.out.println("Animal constructor called.");
    }
    @Override //destructor
    public void finalize() throws Throwable {
        System.out.println("Animal destructor called.");
    }
    public abstract void makeSound();//pure virtual function
    public void eat() {//virtual function
        System.out.println("This animal eats food.");
    }
    final void breathe() {//non virtual function
        System.out.println("(Breathing...)");
    }

}

class Dog extends Animal {
    public Dog() {
        System.out.println(">> Dog constructor called.");
    }
    @Override
    public void finalize() throws Throwable {
        System.out.println("<< Dog destructor called.");
    }
    @Override
    public void makeSound() {
        System.out.println("Woof!");
    }
    @Override
    public void eat() {
        System.out.println("The dog eats dog food.");
    }
}
class Cat extends Animal {
    public Cat() {
        System.out.println(">> Cat constructor called.");
    }

    @Override
    public void finalize() throws Throwable {
        System.out.println("<< Cat destructor called.");
    }

    @Override
    public void makeSound() {
        System.out.println("Meow!");
    }
}
class Labrador extends Dog {
    public Labrador() {
        System.out.println(">>> Labrador constructor called.");
    }

    @Override
    public void finalize() throws Throwable {
        System.out.println("<<< Labrador destructor called.");
    }
    @Override
    public void makeSound() {
        System.out.println("Labrador Woof!");
    }
}

class Main {
    public static void main(String[] args) {
        //Java has only heap(1-3)
        Dog dog = new Dog();
        System.out.println("dog(object) is created.");

        Labrador labrador = new Labrador();
        System.out.println("labrador(object) is created.");

        Animal cat = new Cat();
        System.out.println("cat(object) is created.");

        Animal a[] = new Animal[3];
        a[0]=dog;
        a[1]=labrador;
        a[2]=cat;

        for(int i=0;i<a.length;i++){
            System.out.println("--- Animal number ["+i+"] ---");
            a[i].makeSound();
            a[i].eat();
            a[i].breathe();
        }
        
        dog = null;
        labrador = null;
        cat = null;

        System.gc();//ขอให้ garbage collector ทำงาน
        //ก่อนถูกลบ JVM อาจเรียก เมธอด finalize() ของ object นั้น
        System.out.println("Heap memory deleted successfully.");
    }
}

