import java.time.LocalDate;
import java.time.LocalTime;
import java.util.Scanner;
class Clock {
    private int hours, minutes, seconds;

    public Clock() {
        this(12, 0, 0); // Set default time to 12:00:00
    }

    public Clock(int hours, int minutes, int seconds) {
        setClock(hours, minutes, seconds);
    }

    public Clock(int secondsSinceMidnight) {
        this(secondsSinceMidnight / 3600, (secondsSinceMidnight % 3600) / 60, secondsSinceMidnight % 60);
    }

    // Set time values while checking for validity
    public void setClock(int hours, int minutes, int seconds) {
        if (hours >= 0 && hours < 24 && minutes >= 0 && minutes < 60 && seconds >= 0 && seconds < 60) {
            this.hours = hours;
            this.minutes = minutes;
            this.seconds = seconds;
        } else throw new IllegalArgumentException("Invalid time values.");
    }

    // Get and set methods for hours, minutes, and seconds
    public int getHours() { return hours; }
    public int getMinutes() { return minutes; }
    public int getSeconds() { return seconds; }
    public void setHours(int hours) { if (hours >= 0 && hours < 24) this.hours = hours; else throw new IllegalArgumentException("Invalid hours value."); }
    public void setMinutes(int minutes) { if (minutes >= 0 && minutes < 60) this.minutes = minutes; else throw new IllegalArgumentException("Invalid minutes value."); }
    public void setSeconds(int seconds) { if (seconds >= 0 && seconds < 60) this.seconds = seconds; else throw new IllegalArgumentException("Invalid seconds value."); }

    // Increment time by one second
    public void tick() { seconds++; if (seconds >= 60) { seconds = 0; minutes++; if (minutes >= 60) { minutes = 0; hours = (hours + 1) % 24; } } }

    // Decrement time by one second
    public void tickDown() { seconds--; if (seconds < 0) { seconds = 59; minutes--; if (minutes < 0) { minutes = 59; hours = (hours + 23) % 24; } } }

    // Add time from another Clock instance
    public void addClock(Clock other) { seconds += other.seconds; minutes += other.minutes; hours += other.hours; normalizeTime(); }

    // Subtract time from another Clock instance and return the difference as a new Clock
    public Clock subtractClock(Clock other) {
        int totalThis = hours * 3600 + minutes * 60 + seconds, totalOther = other.hours * 3600 + other.minutes * 60 + other.seconds;
        return new Clock(Math.abs(totalThis - totalOther));
    }

    // Normalize the time to ensure valid values
    private void normalizeTime() { minutes += seconds / 60; seconds %= 60; hours = (hours + minutes / 60) % 24; minutes %= 60; }

    // String representation of the time in HH:MM:SS format
    public String toString() { return String.format("%02d:%02d:%02d", hours, minutes, seconds); }
}

// Demonstrate the Clock class with user input
public class Clock3524 {
    public static void main(String[] args) {
        System.out.println("2021503524 - Mugundh J B");
        System.out.println("Date: " + LocalDate.now() + " Time: " + LocalTime.now());
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter seconds since midnight for first Clock: ");
        int sec1 = scanner.nextInt();
        Clock c1 = new Clock(sec1);
        System.out.println("First Clock: " + c1);

        // Create a second Clock instance
        Clock c2 = new Clock(15, 30, 45);
        System.out.println("Second Clock: " + c2);

        // Calculate and display the difference between the two Clock instances
        System.out.println("Difference Clock (Third Clock): " + c1.subtractClock(c2));

        scanner.close();
    }
}
