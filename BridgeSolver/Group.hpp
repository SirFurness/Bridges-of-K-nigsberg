//
//  Group.hpp
//  BridgeSolver
//
//  Created by Eric on 6/14/16.
//  Copyright © 2016 Eric. All rights reserved.
//

#ifndef Group_hpp
#define Group_hpp

#include <vector>
#include <string>
#include "Node.hpp"

using namespace std;

class Group {
public:
    
    std::vector<Node> nodesInPool;
     
    bool isNodeInGroup(Node node) {
        for(int i = 0; i < nodesInPool.size(); i++) {
            if(node.name == nodesInPool[i].name) {
                return true;
            }
        }
        
        return false;
    }
    
    friend bool operator==(const Group &group, const Group &group2) {
        if(group.nodesInPool == group2.nodesInPool) {
            return true;
        }
        
        return false;
    }
    
    friend bool operator!=(const Group &group, const Group &group2) {
        if(group.nodesInPool == group2.nodesInPool) {
            return false;
        }
        
        return false;
    }
    
    std::string name = "";

    
};

#endif /* Group_hpp */
