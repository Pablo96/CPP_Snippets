#include "EJ17_RuntimeDatatypes.hpp"

uint32 ComponentManager::componentsCounts = 0;

template<class T>
uint32 BaseComponentMetadata<T>::ID = ComponentManager::componentsCounts++;
template<class T>
size_t BaseComponentMetadata<T>::SIZE = sizeof(T);