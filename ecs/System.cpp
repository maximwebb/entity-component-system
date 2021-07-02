#include "Manager.h"
#include "System.h"


System::System(Manager& m) : id(getNextId()), m(m) { }

void System::SubscribeInner(std::type_index type_id, EventHandler f) {
	m.RegisterEventListener(type_id, f);
}