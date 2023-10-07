// 146. LRU Cache

// Design a data structure that follows the constraints of a Least Recently 
// Used (LRU) cache.

// Implement the LRUCache class:

// LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
// int get(int key) Return the value of the key if the key exists, otherwise 
// return -1.
// void put(int key, int value) Update the value of the key if the key exists.
// Otherwise, add the key-value pair to the cache. If the number of keys exceeds
// the capacity from this operation, evict the least recently used key.
// The functions get and put must each run in O(1) average time complexity.

#include <iostream>

//solution with O(n) avg time complexity
// #include <unordered_map>
// #include <vector>
// #include <algorithm> //find

// class LRUCache
// {
// public:
//     LRUCache(int capacity): m_capacity(capacity)
//     {}
    
//     int get(int key)
//     {
//         if (m_map.end() == m_map.find(key))
//         {
//             return -1;
//         }

//         MoveToBack(key);
//         return m_map[key];
//     }
    
//     void put(int key, int value)
//     {
//         //in case the key is already exist
//         if (m_map.end() != m_map.find(key))
//         {
//             m_map[key] = value;
//             MoveToBack(key);
//             return;
//         }
//         //in case the map is full
//         if (m_map.size() == m_capacity)
//         {
//             int keyToRemove = m_usage.front();
//             m_map.erase(keyToRemove);
//             m_usage.erase(m_usage.begin());
//         }

//         m_map[key] = value;
//         m_usage.push_back(key);
//     }

// private:
//     size_t m_capacity;
//     std::unordered_map<int ,int> m_map;
//     std::vector<int> m_usage; //the first is the least recently used key

//     void MoveToBack(int key)
//     {
//         auto it = std::find(m_usage.begin(), m_usage.end(), key);
//         if (it != m_usage.end())
//         {
//             m_usage.erase(it);
//         }

//         m_usage.push_back(key);
//     }
// };

////////////////////////////////////////////////////////////////////////////////

//solution with O(1) avg time complexity
#include <unordered_map>

class LRUCache
{
private:
    struct Node
    {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int m_capacity;
    std::unordered_map<int, Node*> m_map;
    Node* head; // Dummy head node
    Node* tail; // Dummy tail node

    void moveToHead(Node* node)
    {
        if (node == head->next)
            return;

        if (node->prev)
            node->prev->next = node->next;
        if (node->next)
            node->next->prev = node->prev;

        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void evictLRU()
    {
        Node* nodeToRemove = tail->prev;
        m_map.erase(nodeToRemove->key);
        nodeToRemove->prev->next = tail;
        tail->prev = nodeToRemove->prev;
        delete nodeToRemove;
    }

public:
    LRUCache(int capacity) : m_capacity(capacity)
    {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (m_map.find(key) != m_map.end())
        {
            Node* node = m_map[key];
            moveToHead(m_map[key]);
            return node->value;
        }

        return -1;
    }

    void put(int key, int value)
    {
        if (m_map.find(key) != m_map.end())
        {
            Node* node = m_map[key];
            node->value = value;
            moveToHead(node);
        }
        else
        {
            if (static_cast<int>(m_map.size()) == m_capacity)
            {
                evictLRU();
            }

            Node* newNode = new Node(key, value);
            m_map[key] = newNode;
            moveToHead(newNode);
        }
    }
};


////////////////////////////////////////////////////////////////////////////////
int main ()
{
    // LRUCache lru(5);

    // lru.put(1,1);
    // std::cout << lru.get(1) << std::endl;
    return 0;
}
