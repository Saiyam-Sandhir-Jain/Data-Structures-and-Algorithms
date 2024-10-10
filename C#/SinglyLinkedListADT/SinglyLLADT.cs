using System;
using SinglyLinkedList.NodeADT;

namespace SinglyLinkedList.SinglyLLADT
{
    public class SinglyLLADT
    {
        // Attributes
        private NodeADT.NodeADT? _head;
        private uint _length;

        // Properties
        public NodeADT.NodeADT? Head
        {
            get { return _head; }
        }

        public uint Length
        {
            get { return _length; }
        }

        // Constructors
        public SinglyLLADT() {}                     // default constructor
        public SinglyLLADT(int[] array) {}          // parameterized constructor: array
        public SinglyLLADT(SinglyLLADT list) {}     // copy constructor

        // Operations
        public int GetListElement(uint index) { return 0; }
        public void SetListElement(uint index, int vlaue) {}
        public void DisplayList() {}
        public void AppendList(int value) {}
        public void ExtendList(SinglyLLADT otherList) {}
        public void InsertList(uint index, int value) {}
        public int PopList() { return 0; }
        public int RemoveListElement(uint index) { return 0; }
        public uint RemoveValueFromList(int value) { return 0; }
        public uint LinearSearchList(int value) { return 0; }
        public bool IsEmpty() { return false; }
    }
}