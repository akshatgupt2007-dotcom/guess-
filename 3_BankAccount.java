import java.util.Scanner;

/** Simple bank account simulator: deposit, withdraw, check balance. */
public class BankAccount {
    private final String owner;
    private double balance;

    public BankAccount(String owner, double initialBalance) {
        this.owner = owner;
        this.balance = initialBalance;
    }

    public void deposit(double amount) {
        if (amount <= 0) {
            System.out.println("Deposit must be positive.");
            return;
        }
        balance += amount;
        System.out.printf("Deposited %.2f. New balance: %.2f%n", amount, balance);
    }

    public void withdraw(double amount) {
        if (amount <= 0) {
            System.out.println("Withdrawal must be positive.");
        } else if (amount > balance) {
            System.out.println("Insufficient funds.");
        } else {
            balance -= amount;
            System.out.printf("Withdrew %.2f. New balance: %.2f%n", amount, balance);
        }
    }

    public void showBalance() {
        System.out.printf("%s's balance: %.2f%n", owner, balance);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter account holder name: ");
        BankAccount acc = new BankAccount(sc.nextLine(), 0);

        int choice;
        do {
            System.out.println("\n1. Deposit  2. Withdraw  3. Balance  4. Exit");
            System.out.print("Choose: ");
            choice = sc.hasNextInt() ? sc.nextInt() : 4;
            switch (choice) {
                case 1 -> { System.out.print("Amount: "); acc.deposit(sc.nextDouble()); }
                case 2 -> { System.out.print("Amount: "); acc.withdraw(sc.nextDouble()); }
                case 3 -> acc.showBalance();
                case 4 -> System.out.println("Goodbye!");
                default -> System.out.println("Invalid option.");
            }
        } while (choice != 4);
        sc.close();
    }
}
