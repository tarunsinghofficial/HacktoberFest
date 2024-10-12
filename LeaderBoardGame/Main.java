package LeaderBoardGame;

public class Main {

    public static void main(String[] args){
        LeaderBoard leaderBoard = new LeaderBoard();
        leaderBoard.addOrUpdateScore("Fatema" , 88);
        leaderBoard.addOrUpdateScore("Mary", 74);
        leaderBoard.addOrUpdateScore("John",91);
        leaderBoard.addOrUpdateScore("Jemy",91);


        System.out.println("Top Player "+leaderBoard.getTopPlayer());
        System.out.println("Fatema's Score "+leaderBoard.getPlayerScore("Fatema"));

        leaderBoard.addOrUpdateScore("Fatema" ,92);
        System.out.println("Top Player after Fatema's update "+leaderBoard.getTopPlayer());

        leaderBoard.removePlayer("John");
        System.out.println("Top Player after removing John "+leaderBoard.getTopPlayer());

    }
}
