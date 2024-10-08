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
    }
}