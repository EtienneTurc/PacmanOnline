#include "entity_test.h"
#include "gtest/gtest.h"

/*
UNIT TEST for Entity class

Functions tested :
getXPosition, getYPosition, getScore, getSpeed,
getDirection, getFraction, setXPosition
setYPosition, addScore, entityCollision

Missing :
getGrid
*/

TEST_F(EntityTest, getXPosition) {
	EXPECT_EQ(18, _entity->getXPosition());
}

TEST_F(EntityTest, getYPosition) {
	EXPECT_EQ(29, _entity->getYPosition());
}

TEST_F(EntityTest, getDirection) {
	EXPECT_EQ(LEFT, _entity->getDirection());
}

TEST_F(EntityTest, getSpeed) {
	EXPECT_EQ(1, _entity->getSpeed());
}

TEST_F(EntityTest, getScore) {
	EXPECT_EQ(20, _entity->getScore());
}

TEST_F(EntityTest, getFraction) {
	EXPECT_EQ(1/2, _entity->getFraction());
}

TEST_F(EntityTest, setXPosition) {
	_entity->setXPosition(1);
	EXPECT_EQ(1, _entity->getXPosition());
}

TEST_F(EntityTest, setYPosition) {
	_entity->setYPosition(4);
	EXPECT_EQ(4, _entity->getYPosition());
}

TEST_F(EntityTest, addScore) {
	_entity->addScore(5);
	EXPECT_EQ(25, _entity->getScore());
}

TEST_F(EntityTest, entityCollision_true) {
	EXPECT_TRUE( _entity->entityCollision(*_entity2));
}

TEST_F(EntityTest, entityCollision_false) {
	EXPECT_FALSE( _entity->entityCollision(*_entity3));
}
