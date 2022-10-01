//Jeff Blankenship
//CS-151
//Modular math example

public class AlarmClock {
  
  public static void main (String[] args){
    
    //Write a program which will 
    //Ask for the time you’re going to bed.
    int bedtime = 11;
    
    //Ask for the number of minutes you want to sleep.
    int sleepMinutes = 473;
    
    
    //Calculate the exact time (hours:minutes) to set your alarm.
    //(Note:  be sure to "roll over" the clock at 
    //the appropriate numbers)
    int alarmHour=0;
    int alarmMinute=0;
    
    int sleepHours = sleepMinutes / 60;
    int morningMinutes = sleepMinutes % 60;
    
    System.out.println("******************sleepHours: " + sleepHours);
    System.out.println("morningMinutes: " + morningMinutes);
    
    alarmHour = (bedtime + sleepHours)% 12;
    System.out.println("alarmHour: " + alarmHour);
    
    //display in time of day format
    System.out.print("\nSet your alarm for ");
    System.out.print(alarmHour);
    System.out.print(":" + morningMinutes);
    
  }
  
}