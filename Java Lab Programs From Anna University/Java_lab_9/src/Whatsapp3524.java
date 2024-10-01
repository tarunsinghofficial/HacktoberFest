import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

// Base class User representing a user
class User {
    String name;
    String phoneNumber;
    String status;

    // Constructor to initialize user attributes
    public User(String name, String phoneNumber, String status) {
        this.name = name;
        this.phoneNumber = phoneNumber;
        this.status = status;
    }
}

// Subclass Contact, extending User to store contacts
class Contact extends User {
    protected User[] contacts;
    protected int contactCount;
    private static final int MAX_CONTACTS = 10; // Default maximum contacts

    // Constructor to initialize contact attributes with default maximum contacts
    public Contact(String name, String phoneNumber, String status) {
        super(name, phoneNumber, status);
        contacts = new User[MAX_CONTACTS];
        contactCount = 0;
    }

    // Constructor to initialize contact attributes with a custom maximum contacts value
    public Contact(String name, String phoneNumber, String status, int maxContacts) {
        super(name, phoneNumber, status);
        contacts = new User[maxContacts];
        contactCount = 0;
    }

    // Method to add a contact to the contact list
    public void addContact(User user) {
        if (contactCount < contacts.length) {
            contacts[contactCount] = user;
            contactCount++;
            System.out.println(user.name + " is added to your contacts.");
        } else {
            System.out.println("Your contact list is full.");
        }
    }
}

// Class Message to store message information
class Message {
    User sender;
    User receiver;
    String messageContent;

    // Constructor to initialize message attributes
    public Message(User sender, User receiver, String messageContent) {
        this.sender = sender;
        this.receiver = receiver;
        this.messageContent = messageContent;
    }
}

// Class Chat to represent a chat between two users
class Chat {
    private User[] participants;
    private Message[] messages;
    private int messageCount;
    private static final int MAX_MESSAGES = 100; // Default maximum messages

    // Constructor to initialize chat participants with default maximum messages
    public Chat(User user1, User user2) {
        participants = new User[2];
        participants[0] = user1;
        participants[1] = user2;
        messages = new Message[MAX_MESSAGES];
        messageCount = 0;
    }

    // Constructor to initialize chat participants with a custom maximum messages value
    public Chat(User user1, User user2, int maxMessages) {
        participants = new User[2];
        participants[0] = user1;
        participants[1] = user2;
        messages = new Message[maxMessages];
        messageCount = 0;
    }

    // Method to add a message to the chat
    public void addMessage(Message message) {
        if (messageCount < messages.length) {
            messages[messageCount] = message;
            messageCount++;
        } else {
            System.out.println("Chat history is full.");
        }
    }

    // Method to display the chat history
    public void displayChatHistory() {
        System.out.println("\nChat History:");
        for (Message message : messages) {
            if (message != null) {
                System.out.println(message.sender.name + " ==> " + message.receiver.name + " : " + message.messageContent);
            }
        }
    }
}

public class Whatsapp3524 {
    public static void main(String[] args) {
        // Code for getting the current date and time
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");
        LocalDateTime now = LocalDateTime.now();
        System.out.println("2021503524  " + "Mugundh J B  " + dtf.format(now));

        // Create user objects
        User alice = new User("Alice", "+1234567890", "Available");
        User bob = new User("Bob", "+9876543210", "Away");

        // Create a contact list for Alice with default maximum contacts
        Contact aliceContacts = new Contact("Alice", "+1234567890", "Available");
        aliceContacts.addContact(bob);

        // Create messages between Alice and Bob
        Message message1 = new Message(alice, bob, "Hi, Bob!");
        Message message2 = new Message(bob, alice, "Hello, Alice!");
        Message message3 = new Message(alice, bob, "...");
        Message message4 = new Message(bob, alice, "...");
        Message message5 = new Message(alice, bob, "Bye, Bob!");
        Message message6 = new Message(bob, alice, "Bye, Alice!");

        // Create a chat between Alice and Bob with default maximum messages
        Chat chat = new Chat(alice, bob);
        chat.addMessage(message1);
        chat.addMessage(message2);
        chat.addMessage(message3);
        chat.addMessage(message4);
        chat.addMessage(message5);
        chat.addMessage(message6);

        // Display the chat history
        chat.displayChatHistory();
    }
}
