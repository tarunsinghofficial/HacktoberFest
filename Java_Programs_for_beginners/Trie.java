
import java.util.HashMap;

public class Trie
{
    node root;

    public Trie() {
        root = new node('.');
    }

    public void insert(String word)
    {
        insert(word, this.root, 0);
    }

    public void insert(String word, node node, int si)
    {
        if(si==word.length()){
            node.endsHere = true;  // mark this node as ending point
            return;
        }

        char c = word.charAt(si);

        if(!node.children.containsKey(c))  // if no such child exists
            node.children.put(c, new node(c)); // add child node


        insert(word, node.children.get(c), si+1); // insert next char in trie
    }

    public boolean search(String word) {
        return search(word, this.root, 0);
    }

    public boolean search(String word, node node, int si)
    {
        if(si==word.length()){
            // if this node is an ending point
            return node.endsHere;
        }

        char c = word.charAt(si);

        if(!node.children.containsKey(c))  // if no such child exists
            return false;


        return search(word, node.children.get(c), si+1); // search next char in trie
    }


    public boolean startsWith(String prefix) {
        return startsWith(prefix, this.root, 0);
    }

    public boolean startsWith(String word, node node, int si)
    {
        if(si>=word.length()) return true;

        char c = word.charAt(si);

        if(!node.children.containsKey(c))  // if no such child exists
            return false;

        return startsWith(word, node.children.get(c), si+1); // search next char in trie
    }


    static class node{
        Character val;
        HashMap<Character, node> children;  // child value - its node pointer
        boolean endsHere = false;

        public node(Character c){
            this.val = c;
            this.children = new HashMap<>();
        }
    }

}
