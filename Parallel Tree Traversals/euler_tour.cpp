#include <iostream>
#include <unordered_map>
#include <vector>
#include <omp.h>
#include <cmath>
#include "euler_tour.h"

using namespace std;

EulerTour::EulerTour(){
    n=11;
    num_edges=20;
    adj.resize(n,vector<int> ());
    edges.resize(num_edges,{-1,-1});
    successor.resize(num_edges,-1);
    predecessor.resize(num_edges,-1);
    dist.resize(num_edges,-1);

    /*
    * the input should be such that
    * root node must be pushed first
    * followed by nodes from left to right
    * into the adj list
    */
    adj[0].push_back(7);
    edges[0]={0,7};
    reverse_map[7]=0;
    adj[0].push_back(1);
    edges[1]={0,1};
    reverse_map[1]=1;
    adj[0].push_back(9);
    edges[2]={0,9};
    reverse_map[9]=2;
    adj[0].push_back(10);
    edges[3]={0,10};
    reverse_map[10]=3;

    adj[1].push_back(0);
    edges[4]={1,0};
    reverse_map[1000]=4;
    
    adj[2].push_back(3);
    edges[5]={2,3};
    reverse_map[2003]=5;
    
    adj[3].push_back(7);
    edges[6]={3,7};
    reverse_map[3007]=6;
    adj[3].push_back(6);
    edges[7]={3,6};
    reverse_map[3006]=7;
    adj[3].push_back(2);
    edges[8]={3,2};
    reverse_map[3002]=8;
    
    adj[4].push_back(7);
    edges[9]={4,7};
    reverse_map[4007]=9;
    adj[4].push_back(5);
    edges[10]={4,5};
    reverse_map[4005]=10;
    adj[4].push_back(8);
    edges[11]={4,8};
    reverse_map[4008]=11;
    
    adj[5].push_back(4);
    edges[12]={5,4};
    reverse_map[5004]=12;
    
    adj[6].push_back(3);
    edges[13]={6,3};
    reverse_map[6003]=13;
    
    adj[7].push_back(3);
    edges[14]={7,3};
    reverse_map[7003]=14;
    adj[7].push_back(0);
    edges[15]={7,0};
    reverse_map[7000]=15;
    adj[7].push_back(4);
    edges[16]={7,4};
    reverse_map[7004]=16;
    
    adj[8].push_back(4);
    edges[17]={8,4};
    reverse_map[8004]=17;
    
    adj[9].push_back(0);
    edges[18]={9,0};
    reverse_map[9000]=18;
    
    adj[10].push_back(0);
    edges[19]={10,0};
    reverse_map[10000]=19;
    root=7;
}

void EulerTour::find_successors(){
    omp_set_num_threads(n);

    #pragma omp parallel for
    for(int i=0;i<n;i++){
        int u,v;
        int hashed_lhs,hashed_rhs;
        for(int j=0;j<adj[i].size();j++){
            if(i==root && j==adj[i].size()-1){
                // set the last edge to point to NULL
                continue;
            }
            v=i;
            u=adj[i][j];
            
            /*
            * Hashing is performed as follows:
            * 
            * <u,v> is represented as 1000*u+v, where
            * 1000 is a constant that can be changed
            * depending on the user inputs
            * 
            * Another way of hashing without dependencies 
            * is storing the edges as strings - 
            * <u,v> is represented as "u|v"
            * this method is safer than the above
            * which is not followed here because it
            * introduces additional parsing logic
            * but can be accomplished in O(1) time
            */
            hashed_lhs=u*MAX_FACTOR+v;
            hashed_rhs=v*MAX_FACTOR+adj[i][(j+1)%adj[i].size()];
            
            successor[reverse_map[hashed_lhs]]=reverse_map[hashed_rhs];
            predecessor[reverse_map[hashed_rhs]]=reverse_map[hashed_lhs];
            if(adj[u].size()==1){
                successor[reverse_map[v*MAX_FACTOR+u]]=reverse_map[hashed_lhs];
                predecessor[reverse_map[hashed_lhs]]=reverse_map[v*MAX_FACTOR+u];
            }
            if(i==root && j==0){
                // set predecessor to point to itself for the first edge
                first_edge={i,adj[i][j]};
                predecessor[reverse_map[i*MAX_FACTOR+adj[i][j]]]=reverse_map[i*MAX_FACTOR+adj[i][j]];
            }
        }
    }

#ifndef _DEBUG_
    print_successors();
#endif
}

void EulerTour::list_ranking(){
    int limit=(int) (log2(num_edges)+1);
    omp_set_num_threads(num_edges);
    
    #pragma omp parallel for
    // initialization of dist[]
    for(int i=0;i<num_edges;i++){
        if(edges[i]==first_edge){
            dist[i]=0;
        }
        else{
            dist[i]=1;
        }
    }

    for(int j=0;j<limit;j++){
        vector<int> dist2(num_edges,-1);
        vector<int> predecessor2(num_edges,-1);

        #pragma omp parallel shared(dist2,predecessor2)
        {
            #pragma omp for
            for(int i=0;i<num_edges;i++){
                if(edges[i]!=first_edge){
                    dist2[i]=dist[i]+dist[predecessor[i]];
                    predecessor2[i]=predecessor[predecessor[i]];
                }
            }

            #pragma omp for
            for(int i=0;i<num_edges;i++){
                if(edges[i]!=first_edge){
                    predecessor[i]=predecessor2[i];
                    dist[i]=dist2[i];
                }
            }
        }
    }
}

void EulerTour::print_tour(){
    /*
    * printing need not be done in parallel
    * as this does not count towards the
    * time complexity of the solution
    */
    cout<<"Euler tour:\n";
    for(int i=0;i<num_edges;i++){
        int u=edges[tour_order[i]].first+1;
        int v=edges[tour_order[i]].second+1;
        cout<<u<<"->"<<v<<": "<<(dist[tour_order[i]]+1)<<endl;
    }
    cout<<endl;
}

#ifndef _DEBUG_
void EulerTour::print_successors(){
    /*
    * printing need not be done in parallel
    * as this does not count towards the
    * time complexity of the solution
    */
    for(int i=0;i<successor.size();i++){
        if(successor[i]==-1){
            continue;
        }
        int u=edges[i].first+1;
        int v=edges[i].second+1;
        cout<<u<<" "<<v<<" -> ";
        u=edges[successor[i]].first+1;
        v=edges[successor[i]].second+1;
        cout<<u<<" "<<v<<endl;
    }
    cout<<successor.size()<<" "<<predecessor.size()<<endl;
}
#endif

void EulerTour::store_order(){
    tour_order.resize(num_edges,-1);

    #pragma omp parallel for
    /*
    * storing the edges in the order
    * of Euler tour in tour_order
    */
    for(int i=0;i<num_edges;i++){
        tour_order[dist[i]]=i;
    }

    print_tour();
}
