//
//  Node.hpp
//  BridgeSolver

#ifndef Node_hpp
#define Node_hpp

#include <vector>
#include <string>

class Node {
public:
    
    std::vector<Node> connectedNodes;
    
    friend bool operator==(const Node &node, const Node &node2) {
        if(node.connectedNodes == node2.connectedNodes) {
            return true;
        }
        return false;
    }
    
    friend bool operator!=(const Node &node, const Node &node2) {
        if(node.connectedNodes == node2.connectedNodes) {
            return false;
        }
        return true;
    }
    std::string name = "";
    
};

#endif /* Node_hpp */
