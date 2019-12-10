#pragma once

template<typename Container>
bool contains(Container& container, typename Container::value_type &value) {
    return container.find(value) != container.end();
}