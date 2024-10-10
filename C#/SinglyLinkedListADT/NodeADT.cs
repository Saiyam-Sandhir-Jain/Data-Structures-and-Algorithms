using System;

namespace SinglyLinkedList.NodeADT
{
    public class NodeADT 
    {
        // Attributes/Properties
        public int Value { get; set; }
        public  NodeADT? Next { get; set; }

        // Constructors
        public NodeADT() {}                             // Default Constructor
        public NodeADT(int value) {}                    // Parametrized Constructor: value
        public NodeADT(int vlaue, NodeADT next) {}      // Parametrized Constructor: value, next
        public NodeADT(NodeADT node) {}                 // Copy Constructor

        // Operations
        public void Display() {}
    }
}