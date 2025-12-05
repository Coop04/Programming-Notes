public class _48_fish extends _48_animal{
    
    @Override // good practice to add annotation, so that other developers can also know this method is being overrided
    void move() {
        System.out.println("This animal is swimming");
    }
}
