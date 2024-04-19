#include<bits/stdc++.h>
using namespace std;
class disjoint_set_union{
  protected:
    map<int, int> parent;
  public:
    virtual void make(int v){
      parent[v] = v;
    }
    virtual int find_set(int v){
      if(v == parent[v]) return v;
      return find_set(parent[v]);
    }
    virtual void union_sets(int a, int b){
      a = find_set(a);
      b = find_set(b);
      if(a != b)
        parent[b] = a;
    }
    void display(){
    	for(pair<int ,int> i: parent){
    		cout << i.first << " = " << i.second << endl;
    	}
    	cout << endl;
    }
};
// more optimised dsu with path compression (O (log(n)))
class disjoint_set_union_pc : public disjoint_set_union{
  public:
    int find_set(int v) override{
      if(v == parent[v]) return v;
      return parent[v] = find_set(parent[v]);
    }
};
// more optimised implementation using size by rank (O (lamda(n)))
class disjoint_set_union_sr : public disjoint_set_union_pc{
  private:
    map<int, int> size;
  public:
    void make(int v) override{
      parent[v] = v;
      size[v] = 1;
    }
    void union_sets(int a, int b) override{
      a = find_set(a);
      b = find_set(b);
      if(a != b){
        if(size[a] < size[b])
          swap(a, b);
        parent[b] = a;
        size[a] += size[b];
      }
    }
};

int main(){
  disjoint_set_union dsu;
  for(int i =1;i<=5;i++){
		dsu.make(i);
	}
	dsu.union_sets(1,2);
	dsu.display();
	dsu.union_sets(2,3);
	dsu.display();
	dsu.union_sets(4,5);
	dsu.display();
	dsu.union_sets(3,4);
	dsu.display();

  disjoint_set_union_pc dsupc;
  for(int i =1;i<=5;i++){
		dsupc.make(i);
	}
	dsupc.union_sets(1,2);
	dsupc.display();
	dsupc.union_sets(2,3);
	dsupc.display();
	dsupc.union_sets(4,5);
	dsupc.display();
	dsupc.union_sets(3,4);
	dsupc.display();

  disjoint_set_union_sr dsusr;
  for(int i =1;i<=5;i++){
    dsusr.make(i);
  }
  dsusr.union_sets(1,2);
  dsusr.display();
  dsusr.union_sets(2,3);
  dsusr.display();
  dsusr.union_sets(4,5);
  dsusr.display();
  dsusr.union_sets(3,4);
  dsusr.display();
}
