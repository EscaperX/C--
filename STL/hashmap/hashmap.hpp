#pragma once

#include <functional>
#include <iostream>
template <typename K, typename V>
class HashMap_Iterator {

};
/**
 * @brief template class for a hash map
 *
 * @tparam K key type
 * @tparam V mapped type
 * @tparam H hash function, return size_t
 */
template <typename K, typename V, typename H = std::hash<K>>
class HashMap {
public:
    using value_type = std::pair<const K, V>;

    HashMap();
    explicit HashMap(size_t, bucket_count, const H& hash = H);
    ~HashMap();
    // copy constructor
    HashMap(const HashMap& rhs);
    HashMap& operator = (const HashMap& rhs);
    // move constructor
    HashMap(HashMap && rhs);
    HashMap& operator = (HashMap&& rhs);

    inline size_t size() const noexcept;

    inline bool empty() const noexcept;

    inline float load_factor() const noexcept;

    inline size_t bucket_count() const noexcept;

    bool contains(const K& key) const noexcept;

    M& at(const K& key);

    const M& at(const K& key) const;

    void clear() noexcept;



private:
    struct node {
        value_type value;
        node* next;
        node(const value_type& value = value_type(), node* next = nullptr) : value(value), next(next) {}
    };


};
