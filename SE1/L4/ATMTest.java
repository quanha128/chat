package L4;

public class ATMTest {
    public static void main(String[] args) {
        ATM bob = new ATM(1000);
        ATM alice = new ATM(2000);

        System.out.println(bob.balanceCheck());
        System.out.println(alice.balanceCheck());

        bob.deposit(3000);
        alice.withdrawal(500);

        System.out.println(bob.balanceCheck());
        System.out.println(alice.balanceCheck());

        bob.transfer(2000, alice);

        System.out.println(bob.balanceCheck());
        System.out.println(alice.balanceCheck());

        bob.deposit(100001);
        alice.withdrawal(100000);
    }
}
