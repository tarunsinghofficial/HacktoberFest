public class Main {

    public static final String INVALID_VALUE_MESSAGE = "Invalid value";
    /// This is a constant
    public static void main(String[] args) {
        System.out.println(getDurationString(100,68));
        System.out.println(getDurationString(1));

    }

    public static String getDurationString(long minutes, long seconds){
        if (minutes >= 0 && ((seconds >= 0)&&(seconds <= 59))){
            long hour = minutes / 60;
            long remainingMinutes = minutes % 60;

            String hoursString = hour + "h ";
            if (hour < 10){
                hoursString = "0" + hoursString;
            }

            String minutesString = remainingMinutes + "m ";
            if (remainingMinutes < 10){
                minutesString = "0" + minutesString;
            }

            String secondsString = seconds + "s ";
            if (seconds < 10){
                secondsString = "0" + secondsString;
            }
            return hoursString + "" + minutesString + "" + secondsString +  "";
        }
        return INVALID_VALUE_MESSAGE;
    }

    public static String getDurationString(long seconds){
        if (seconds >= 0){
            long minutes = seconds / 60 ;
            long remainingSeconds = seconds % 60 ;

            return getDurationString(minutes,remainingSeconds);
        }
        return INVALID_VALUE_MESSAGE;
    }
}