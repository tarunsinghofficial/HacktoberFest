package LeaderBoardGame;

import java.util.*;

//Implement a leaderboard that maintains the best score player at the top and gets any player in O(1) time.
public class LeaderBoard {
    private Map<String,Integer> hm;
    private TreeMap<Integer, Set<String>> scoreTreeMap;

   public LeaderBoard(){
        hm = new HashMap<>();
       scoreTreeMap = new TreeMap<>(Collections.reverseOrder());
   }

   public void addOrUpdateScore(String player , int score){
       if(hm.containsKey(player)){
           int oldScore = hm.get(player);
           removePlayerFromTreeMap(player,oldScore);
       }
       //update it in hashmap
       hm.put(player,score);
   }

   public void  removePlayerFromTreeMap(String player, int score){
       Set<String> players = scoreTreeMap.get(score);
       players.remove(player);

       if(players.isEmpty()){
           scoreTreeMap.remove(score);
       }
   }

   public int getPlayerScore(String player){
       return hm.getOrDefault(player, -1);
   }

   public String getTopPlayer(){
       if(scoreTreeMap.isEmpty()){
           return null;
       }

       Map.Entry<Integer, Set<String>> entry = scoreTreeMap.firstEntry();
       return entry.getValue().iterator().next();
   }

   public void removePlayer(String player){
       if(!hm.containsKey(player)){
           return;
       }

       int score = hm.get(player);
       removePlayerFromTreeMap(player,score);
       hm.remove(player);
   }
}
