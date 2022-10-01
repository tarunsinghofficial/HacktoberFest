#include <iostream>
#include <unordered_map>
#include <vector>
#include <omp.h>
#include <cmath>
#include "euler_tour.h"

using namespace std;

vector<pair<int,int>> edges2;

void preorder(vector<int>& weight, EulerTour et){
    vector<int> pre(et.n,0);
    
    #pragma omp parallel for
    // populating pre[v] for all v
    for(int i=0;i<et.num_edges;i++){
        int u,v;
        u=edges2[i].first;
        v=edges2[i].second;
        int j=et.reverse_map[v*MAX_FACTOR+u];
        // parent of v is u
        if(et.dist[et.tour_order[i]]<et.dist[j]){
            pre[v]=weight[i]+1;
        }
    }
    pre[et.root]=1;

    // printing preorder traversal
    cout<<"Preorder traversal:\n";
    #pragma omp parallel for
    for(int i=0;i<et.n;i++){
        #pragma omp critical
        {
            cout<<(i+1)<<" => "<<(pre[i])<<endl;
        }
    }
}

void prefix_sum(vector<int>& weight, EulerTour et){
    int limit=(int) (log2(et.num_edges)+1);
    omp_set_num_threads(et.num_edges);

    vector<int> weight2(et.num_edges,-1);

    #pragma omp parallel for
    // initialization of weight2
    for(int i=0;i<et.num_edges;i++){
        weight2[i]=weight[i];
    }

    for(int i=0;i<limit;i++){
        #pragma omp parallel for
        for(int j=0;j<et.num_edges;j++){
            if(j<(int) pow(2,i)){
                weight2[j]=weight[j];
            }
            else{
                weight2[j]=weight[j]+weight[j-(int) pow(2,i)];
            }
        }

        #pragma omp parallel for
        for(int j=0;j<et.num_edges;j++){
            weight[j]=weight2[j];
        }
    }
}

void assign_weights(vector<int>& weight, EulerTour et){
    weight.resize(et.num_edges,-1);
    edges2.resize(et.num_edges,{-1,-1});
    
    omp_set_num_threads(et.num_edges);

    #pragma omp parallel for
    /*
    * changing the original order of et.edges
    * according to the order of Euler tour
    */
    for(int i=0;i<et.num_edges;i++){
        edges2[i]=et.edges[et.tour_order[i]];
    }

    #pragma omp parallel for
    // assigning weights to edges
    for(int i=0;i<et.num_edges;i++){
        int u,v;
        u=edges2[i].first;
        v=edges2[i].second;
        int j=et.reverse_map[v*MAX_FACTOR+u];
        // parent of v is u
        if(et.dist[et.tour_order[i]]<et.dist[j]){
            weight[i]=1;
        }
        // parent of u is v
        else{
            weight[i]=0;
        }
    }
}

int main(){
    // performing Euler tour
    EulerTour et;
    et.find_successors();
    et.list_ranking();
    et.store_order();
    
    // performing preorder traversal
    vector<int> weight;
    assign_weights(weight,et);
    prefix_sum(weight,et);
    preorder(weight,et);
}