#ifndef UMLCOMPONENTDIAGRAM_H
#define UMLCOMPONENTDIAGRAM_H

#include "UmlBaseComponentDiagram.h"
//Added by qt3to4:
#include "misc/mystr.h"

// This class manages 'ccomponent diagrams', notes that the class 'UmlDiagram'
// is a mother class of all the diagrams, allowing to generalize their
// management
// You can modify it as you want (except the constructor)

class UmlComponentDiagram : public UmlBaseComponentDiagram
{
public:
    UmlComponentDiagram(void * id, const WrapperStr & n)
        : UmlBaseComponentDiagram(id, n) {};
};

#endif