﻿#include "cell.h"

void Cell::setupPixel(const int& x, const int& y)
{
	pixelSize_ = calculatePixelSize();
	setStyle();
	collider_ = { pixelSize_.x * x, pixelSize_.y * y, pixelSize_.x, pixelSize_.y};
	collider_.drawRect();
}

void Cell::drawNeighbours()
{
	ofSetColor(ofColor::red);
	ofDrawBitmapString(count_, collider_.x, collider_.addYH());
}

bool Cell::wasClickInside(int x, int y)
{
	return collider_.checkBounds(static_cast<float>(x),static_cast<float>(y));
}

void Cell::setStyle() const
{
	ofFill();
	switch (isLive_) {
	case true:
		ofSetColor(active);
		break;
	default:
		ofNoFill();
		ofSetColor(inactive);
		break;
	}

	if (testing_) ofSetColor(ofColor::red, 50);
	
}



Point<float> Cell::calculatePixelSize()
{
	Point <float> output{
		static_cast <float> (ofGetWidth()) / GRID_SIZE.x,
		static_cast <float> (ofGetHeight()) / GRID_SIZE.y
	};

	return output;
}
