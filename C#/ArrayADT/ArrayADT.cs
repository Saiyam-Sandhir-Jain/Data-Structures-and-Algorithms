using System;
using System.Runtime.InteropServices.Marshalling;

namespace ArrayADT
{
    public class ArrayADT
    {
        private int[] _items;
        private uint _size;
        private uint _length;

        // ########## Properties ##########

        public uint Size
        {
            get { return _size; }
        }

        public uint Length
        {
            get { return _length; }
        }

        // ########### Consturctors ##########endregion

        public ArrayADT()
        {
            _items = [];    // initialize items to empty array
            _size = 0;      // initialize size to 0
            _length = 0;    // initialize length to 0
        }

        // Initialize ArrayADT using size parameter
        public ArrayADT(uint size)
        {
            _items = [];    // initialize items to empty array
            _size = size;   // initialize '_size' to size
            _length = 0;    // initialize length to 0
        }

        // Initialize ArrayADT by copying contents from array
        public ArrayADT(int[] array, uint length)
        {
            if (array.Length < length)
                throw new Exception("Error: 'length' cannot be greater that than 'array' size.");

            _items = new int[array.Length];
            Array.Copy(array, _items, length);      // Copy elements from array into ArrayADT

            _size = (uint)array.Length;             // Initialize size to array's length
            _length = length;                       // Initialize '_length' to length
        }

        // Copy Constructor for ArrayADT
        public ArrayADT(ArrayADT arrayADT, uint length)
        {
            if (arrayADT.Size < length)
                throw new Exception("Error: 'length' cannot be greater than 'arrayADT.Size'.");

            _items = new int[arrayADT.Size];
            Array.Copy(arrayADT._items, _items, length);    // Copy elements from arrayADT to ArrayADT

            _size = arrayADT.Size;                          // Initialize size to arrayADT's size
            _length = length;                               // Initialize '_length' to length
        }

        // ########## Operations ##########

        public int GetArrayElement(uint index)
        {
            if (index >= _length)
                throw new IndexOutOfRangeException("Error: Index parameter is out of array bounds.");

            return _items[index];
        }

        public void SetArrayElement(uint index, int value)
        {
            if (index >= _length)
                throw new IndexOutOfRangeException("Error: Index parameter is out of array bounds.");

            _items[index] = value;
        }

        public void DisplayArray()
        {
            if (_length == 0)
            {
                Console.WriteLine("ArrayADT is empty.");
            }

            for (uint i = 0; i < _length; ++i)
            {
                Console.WriteLine($"|{_items[i]}| ");
            }
        }

        // Check if ArrayADT is full
        public bool IsFull()
        {
            if (_length == _size)
                return true;

            return false;
        }

        // Check if ArrayADT is empty
        public bool IsEmpty()
        {
            if (_length == 0)
                return true;

            return false;
        }

        // Append an element at the end of the array
        public void AppendArray(int value)
        {
            if (IsFull())
                throw new IndexOutOfRangeException("Error: Cannot append to full ArrayADT.");

            _items[_length] = value;
            _length++;
        }

        // Extend the ArrayADT by appending elements from some arrayADT
        public void ExtendArray(ArrayADT arrayADT)
        {
            if (IsFull())
                throw new IndexOutOfRangeException("Error: Cannot extend a full ArrayADT.");

            // Append elements of arrayADT untill the ArrayADT is filled or 
            // all the elements from the arrayADT are appended
            for (uint i = _length; i < _size && i - _length < arrayADT.Length; ++i)
            {
                _items[i] = arrayADT.GetArrayElement(i - _length);
                _length++;
            }
        }

        // Insert an element at a given index of the ArrayADT
        public void InsertArray(uint index, int value)
        {
            if (index > _length)
                throw new IndexOutOfRangeException("Error: Index parameter is out of array bounds.");

            if (IsFull())
                throw new IndexOutOfRangeException("Error: Cannot inset to a full ArrayADT.");

            // Right shifting the elements
            for (uint i = index; i < _length; ++i)
            {
                _items[i + 1] = _items[i];
            }
            _length++;

            _items[index] = value;
        }

        // Popping an element at the end of the ArrayADT
        public int PopArray()
        {
            if (IsEmpty())
                throw new IndexOutOfRangeException("Error: Cannot pop from an empty ArrayADT.");

            int poppedElement = _items[_length - 1];
            _items[_length - 1] = 0;
            --_length;

            return poppedElement;
        }

        // Remove element at the given index of the ArrayADT
        public int RemoveArray(uint index)
        {
            if (index >= _length)
                throw new IndexOutOfRangeException("Error: Cannot remove an element at a given index.");

            if (IsEmpty())
                throw new IndexOutOfRangeException("Error: Cannot remove an element from an empty ArrayADT.");

            int poppedElement = _items[index];

            // Left shifting elements
            for (uint i = index; i < _length - 1; ++i)
            {
                _items[i] = _items[i + 1];
            }
            --_length;

            return poppedElement;
        }

        // Remove first occurence of a value in the ArrayADT
        public uint RemoveArray(int value)
        {
            if (IsEmpty())
                throw new IndexOutOfRangeException("Error: Cannot remove from an empty ArrayADT.");

            uint removedIndex = LinearSearchArray(value);
            RemoveArray(removedIndex);

            return removedIndex;
        }

        public uint LinearSearchArray(int value)
        {
            for (uint i = 0; i < _length; ++i)
            {
                if (_items[i] == value)
                    return i;
            }

            throw new Exception("Error: No such element found in the ArrayADT");
        }

        public void ResizeArray(uint newSize)
        {
            Array.Resize<int>(ref _items, (int)newSize);
            _size = newSize;
        }
    }
}