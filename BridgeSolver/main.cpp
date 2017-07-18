//
//  main.cpp
//  BridgeSolver

#include <iostream>
#include "Node.hpp"
#include <vector>
#include <string>
#include "Group.hpp"
#include <algorithm>
#include <iterator>
#include <map>

std::vector<Node> passedNodes;

std::vector<std::vector<Node>> solutions;

Group w, x, y, z;

std::map<string, Group> groups;

Group startIsland;

std::vector<string> alphabet = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l"};

bool notOver = true;

int nodeAmt = 0;

void loopThroughConnectedNodes(Node node, Group group) {
    
    //std::cout << "I'm in group " << group.name << " and node " << node.name << std::endl;
    
    int same = 0;
    for(int i = 0; i < group.nodesInPool.size(); i++) {
        for(int a = 0; a < passedNodes.size(); a++) {
            if(passedNodes[a].name == group.nodesInPool[i].name) {
                same++;
            }
        }
    }
    
    if(same == group.nodesInPool.size()) {
        notOver = false;
        //std::cout << "Finished because all the nodes in the pool have been passed!\n";
    }
    
    if(passedNodes.size() == nodeAmt) {
        bool newSolution = true;
        
        for(int i = 0; i < solutions.size(); i++) {
            if(passedNodes == solutions[i]) {
                newSolution = false;
            }
        }
        
        if(newSolution) {
            solutions.push_back(passedNodes);
            
            std::cout << "Path found: " << std::endl;
            
            
            std::cout << "Start in island " << startIsland.name << std::endl;
            
            for(int a = 0; a < passedNodes.size(); a++) {
                
                if(a > 0) {
                    std::cout << ", ";
                }
                std::cout << passedNodes[a].name;
            }
            
            std::cout << std::endl;
        }
    }
    
    bool exit = false;
    for(int a = 0; a < passedNodes.size(); a++) {
        if(passedNodes[a].name == node.name) {
            exit = true;
        }
    }
    
    if((!exit) && notOver) {
        passedNodes.push_back(node);
        
        for(int q = 0; q < groups.size(); q++) {
            if(groups[alphabet[q]].name != group.name) {
                if(groups[alphabet[q]].isNodeInGroup(node)) {
                    for (int a = 0; a < groups[alphabet[q]].nodesInPool.size(); a++) {
                        loopThroughConnectedNodes(groups[alphabet[q]].nodesInPool[a], groups[alphabet[q]]);
                    }
                }
            }
        }
        
        
    }
    
    
}

void startInGroup(Group group) {
    
    for(int i = 0; i < group.nodesInPool.size(); i ++) {
        
        notOver = true;
        passedNodes.clear();
        startIsland = group;
        loopThroughConnectedNodes(group.nodesInPool[i], group);
        
    }
}


int main() {
    
    Node a, b, c, d, e, f, g, /**/h/**/;
    
    std::map<string, Node> nodes;
    
    std::cout << "How many bridges are there?" << std::endl;
    
    string nodeAmtStr;
    getline(cin, nodeAmtStr);
    
    nodeAmt = stoi(nodeAmtStr);
    
    
    for(int i = 0; i < nodeAmt; i++) {
        
        Node node;
        
        nodes[alphabet[i]] = node;
        nodes[alphabet[i]].name = alphabet[i];
    }
    
    std::cout << "How many islands are there?" << std::endl;
    
    string groupAmtStr;
    getline(cin, groupAmtStr);
    
    int groupAmt = stoi(groupAmtStr);
    
    for(int i = 0; i < groupAmt; i++) {
        
        Group group;
        
        groups[alphabet[i]] = group;
        groups[alphabet[i]].name = alphabet[i];
        
    }
    
    for(int i = 0; i < groupAmt; i++) {
        
        std::cout << "What bridges are in island '" << groups[alphabet[i]].name << "' (put other letters)" << std::endl;
        
        string node;
        while(std::getline(std::cin, node) && !node.empty()) {
            groups[alphabet[i]].nodesInPool.push_back(nodes[node]);
        }
        
    }
    
    // for each node in each group add every other node in that group to it
    for(int i = 0; i < groups.size(); i++) {
        for(int a = 0; a < groups[alphabet[i]].nodesInPool.size(); a++) {
            
            for(int j = 0; j < groups[alphabet[i]].nodesInPool.size(); j++) {
                
                if(a != j) {
                    
                    groups[alphabet[i]].nodesInPool[a].connectedNodes.push_back(groups[alphabet[i]].nodesInPool[j]);
                    
                }
                
            }
            
        }
    }
    
    for(int i = 0; i < groups.size(); i++) {
        
        startInGroup(groups[alphabet[i]]);
    }
    
    std::cout << "Done!" << std::endl;
    
}

