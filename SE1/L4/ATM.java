package L4;

public class ATM {
    private int balance;

    public ATM(int balance) {
        this.balance = balance;
    }

    public void deposit(int amount) {
        if (amount > 0 && amount <= 100000) this.balance += amount;
        else System.out.println("Deposit amount out of range");
    }

    public void withdrawal(int amount) {
        if (amount < this.balance) this.balance -= amount;
        else System.out.println("Withdrawal amount exceeds balance");
    }

    public void transfer(int amount, ATM b) {
        if (amount > 0 && amount <= 100000) {
            this.balance -= amount;
            b.balance += amount;
        }
        else System.out.println("Transfer amount out of range");
    }

    public int balanceCheck() {
        return this.balance;
    }
}