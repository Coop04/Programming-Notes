public class _51_fish implements _51_prey,_51_predator{
    
    @Override
    public void flee() {
        System.out.println("The fish is swimming away");
    }

    @Override
    public void hunt() {
        System.out.println("The fish is hunting");
    }
}
