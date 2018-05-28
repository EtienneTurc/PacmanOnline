#ifndef ENTITY_TEST_H
#define ENTITY_TEST_H

#include "entity.h"
#include "grid.h"
#include "parameters.h"

class EntityTest : public ::testing::Test {
	protected:
		virtual void SetUp() {
			_grid = new Grid;
			_entity = new Entity(_grid, 18, 29, LEFT, 1, 20);
			_entity2 = new Entity(_grid, 18, 29, LEFT, 1, 20);
			_entity3 = new Entity(_grid, 1, 4, DOWN, 1, 20);
		};

		Grid* _grid;
		Entity* _entity;
		Entity* _entity2;
		Entity* _entity3;
};

#endif
