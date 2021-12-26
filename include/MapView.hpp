#pragma once

#include <map>
#include <type_traits>

template<
    class TKey,
    class TBase
>
class MapView
{
public:

    [[nodiscard]]
    virtual
    const TBase&
    at(
        const TKey& key
    ) const = 0;

    [[nodiscard]]
    virtual
    TBase&
    at(
        const TKey& key
    ) = 0;

    [[nodiscard]]
    virtual
    size_t
    capacity(
        void
    ) const = 0;

    virtual
    void
    clear(
        void
    ) const = 0;

    [[nodiscard]]
    virtual
    bool
    empty(
        void
    ) const = 0;

    virtual
    bool
    erase(
        const TKey& key
    ) = 0;

    virtual
    bool
    insert(
        const TKey& key,
        const TBase& value
    ) = 0;

    virtual
    bool
    insert_or_assign(
        const TKey& key,
        TBase&& value
    ) = 0;

    [[nodiscard]]
    virtual
    size_t
    size(
        void
    ) const = 0;

    virtual
    TBase&
    operator [](
        const TKey& key
    ) = 0;

    virtual
    TBase&
    operator [](
        TKey&& key
    ) = 0;
};

template<class TKey, class TBase, class TDerived /*, typename = typename std::enable_if<std::is_base_of<TBase, TDerived>::value >::type */>
class MapViewImpl :
    public MapView<TKey, TBase>
{
private:
    std::map<TKey, TDerived>& view;

public:
    MapViewImpl(
        std::map<TKey, TDerived>& view
    ) :
        view(view)
    {
        // Nothing to do
    }

    [[nodiscard]]
    virtual
    const TBase&
    at(
        const TKey& key
    ) const {
        return view.at(key);
    }

    [[nodiscard]]
    virtual
    TBase&
    at(
        const TKey& key
    ) {
        return view.at(key);
    }

    [[nodiscard]]
    virtual
    size_t
    capacity(
        void
    ) const {
        return view.capacity();
    }

    virtual
    void
    clear(
        void
    ) const {
        view.clear();
    }

    [[nodiscard]]
    virtual
    bool
    empty(
        void
    ) const {
        return view.empty();
    }

    virtual
    bool
    erase(
        const TKey& key
    ) {
        return view.erase(key) != 0;
    }

    virtual
    bool
    insert(
        const TKey& key,
        const TBase& value
    ) {
        const auto& derived = dynamic_cast<const TDerived&>(value);
        return view.insert({key, derived}).second;
    }

    virtual
    bool
    insert_or_assign(
        const TKey& key,
        TBase&& value
    ) {
        return view.inser_or_assign(key, dynamic_cast<TDerived>(value)).second;
    }

    [[nodiscard]]
    virtual
    size_t
    size(
        void
    ) const {
        return view.size();
    }

    virtual
    TBase&
    operator [](
        const TKey& key
    ) {
        return view[key];
    }

    virtual
    TBase&
    operator [](
        TKey&& key
    ) {
        return view[key];
    }
};
