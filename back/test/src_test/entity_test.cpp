#include "gtest/gtest.h"
#include "entity_test.h"

#include <iostream>

/*
UNIT TEST for Entity class

Functions tested :
getXPosition, getYPosition, getScore, getSpeed,
getDirection, getFraction, setXPosition
setYPosition, addScore, entityCollision,
updateFraction, updateDirection, distanceTo,
pushInput, move, virtualMove

Missing : getGrid

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

TEST_F(EntityTest, distanceTo_null) {
	EXPECT_EQ(0, _entity->distanceTo(_entity2->getXPosition(), _entity2->getYPosition()));
}

TEST_F(EntityTest, distanceTo_int) {
	EXPECT_EQ(42, _entity->distanceTo(_entity3->getXPosition(), _entity3->getYPosition()));
}

TEST_F(EntityTest, move) {
	_entity->move(1);
	EXPECT_EQ(17, _entity->getXPosition());
	EXPECT_EQ(29, _entity->getYPosition());
}

TEST_F(EntityTest, move_none) {
	_entity->move(0);
	EXPECT_EQ(18, _entity->getXPosition());
	EXPECT_EQ(29, _entity->getYPosition());
}

TEST_F(EntityTest, move_good_event) {
	_entity3->pushInput(RIGHT);
	_entity3->move(1);
	EXPECT_EQ(2, _entity3->getXPosition());
	EXPECT_EQ(4, _entity3->getYPosition());
	EXPECT_EQ(RIGHT, _entity3->getDirection());
}

TEST_F(EntityTest, move_bad_event) {
	_entity3->pushInput(UP);
	_entity3->move(1);
	EXPECT_EQ(UP, _entity3->getDirection());
	std::cout << "Entity position" << _entity3->getXPosition() << "/n";
	std::cout << "Entity position" << _entity3->getYPosition() << "/n";
	EXPECT_EQ(1, _entity3->getXPosition());
	EXPECT_EQ(4, _entity3->getYPosition());
}

TEST_F(EntityTest, virtualMove) {
	_entity->virtualMove();
	EXPECT_EQ(17, _entity->getXPosition());
	EXPECT_EQ(29, _entity->getYPosition());
}

TEST_F(EntityTest, updateFraction) {
	_entity->updateFraction(2/5);
	EXPECT_EQ(2/5, _entity->getFraction());
}

TEST_F(EntityTest, updateDirection) {
	_entity->updateDirection(UP);
	EXPECT_EQ(UP, _entity->getDirection());
}
