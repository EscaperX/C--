#pragma once

#include <iterator>
#include <functional>
#include <iostream>

template <typename Map, bool isConstant = true>
class HashMap_Iterator {

public:

    using value_type = std::conditional_t<IsConstant, const typename Map::value_type, typename Map::value_type>;

    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using pointer = value_type*;
    using reference = value_type&;

    friend Map;
    friend HashMap_Iterator<Map, true>;
    friend HashMap_Iterator<Map, false>;

    // implict cast to const_iterator
    operator HashMap_Iterator<Map, true>() const {
        return HashMap_Iterator<Map, true>(m_bucket_array, m_node, m_bucket);
    }

private:
    using node = typename Map::node;
    using bucket_array_type = typename Map::bucket_array_type;

    bucket_array_type* m_bucket_array;
    node* m_node;
    size_t m_bucket;


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
