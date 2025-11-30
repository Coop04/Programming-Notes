public class _25_break_continue {
    public static void main(String[] args) {
        
        for(int i=0;i<10;i++) {
            System.out.println(i);
            if(i==4) {
                break;
            }
        }
        System.out.println();

        for(int i=0;i<10;i++) {
            System.out.println(i);
            if(i==4) {
                continue;
            }
        }
    }
}
