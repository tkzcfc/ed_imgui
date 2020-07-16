#include "ScissorLayer.h"


ScissorLayer::ScissorLayer()
	: _scissorRestored(false)
{}

ScissorLayer::~ScissorLayer()
{}

void ScissorLayer::visit(Renderer *renderer, const Mat4& parentTransform, uint32_t parentFlags)
{    
	// quick return if not visible
	if (!isVisible())
	{
		return;
	}

	uint32_t flags = processParentFlags(parentTransform, parentFlags);

	// IMPORTANT:
	// To ease the migration to v3.0, we still support the Mat4 stack,
	// but it is deprecated and your code should not rely on it
	Director* director = Director::getInstance();
	CCASSERT(nullptr != director, "Director is null when setting matrix stack");
	director->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
	director->loadMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW, _modelViewTransform);

	this->beforeDraw();
	bool visibleByCamera = isVisitableByVisitingCamera();

	if (!_children.empty())
	{
		int i = 0;

		// draw children zOrder < 0
		for (; i < _children.size(); i++)
		{
			Node *child = _children.at(i);
			if (child->getLocalZOrder() < 0)
			{
				child->visit(renderer, _modelViewTransform, flags);
			}
			else
			{
				break;
			}
		}

		// this draw
		if (visibleByCamera)
			this->draw(renderer, _modelViewTransform, flags);

		// draw children zOrder >= 0
		for (; i < _children.size(); i++)
		{
			Node *child = _children.at(i);
			child->visit(renderer, _modelViewTransform, flags);
		}
	}
	else if (visibleByCamera)
	{
		this->draw(renderer, _modelViewTransform, flags);
	}

	this->afterDraw();

	director->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_MODELVIEW);
}

void ScissorLayer::beforeDraw()
{
	_beforeDrawCommand.init(_globalZOrder);
	_beforeDrawCommand.func = CC_CALLBACK_0(ScissorLayer::onBeforeDraw, this);
	Director::getInstance()->getRenderer()->addCommand(&_beforeDrawCommand);
}

void ScissorLayer::onBeforeDraw()
{
	_scissorRestored = false;
	Rect frame = getViewRect();
	auto glview = Director::getInstance()->getOpenGLView();

	if (glview->isScissorEnabled()) {
		_scissorRestored = true;
		_parentScissorRect = glview->getScissorRect();
		//set the intersection of _parentScissorRect and frame as the new scissor rect
		if (frame.intersectsRect(_parentScissorRect)) {
			float x = MAX(frame.origin.x, _parentScissorRect.origin.x);
			float y = MAX(frame.origin.y, _parentScissorRect.origin.y);
			float xx = MIN(frame.origin.x + frame.size.width, _parentScissorRect.origin.x + _parentScissorRect.size.width);
			float yy = MIN(frame.origin.y + frame.size.height, _parentScissorRect.origin.y + _parentScissorRect.size.height);
			glview->setScissorInPoints(x, y, xx - x, yy - y);
		}
	}
	else {
		glEnable(GL_SCISSOR_TEST);
		glview->setScissorInPoints(frame.origin.x, frame.origin.y, frame.size.width, frame.size.height);
	}
}

void ScissorLayer::afterDraw()
{
	_afterDrawCommand.init(_globalZOrder);
	_afterDrawCommand.func = CC_CALLBACK_0(ScissorLayer::onAfterDraw, this);
	Director::getInstance()->getRenderer()->addCommand(&_afterDrawCommand);
}

void ScissorLayer::onAfterDraw()
{
	if (_scissorRestored) {//restore the parent's scissor rect
		auto glview = Director::getInstance()->getOpenGLView();

		glview->setScissorInPoints(_parentScissorRect.origin.x, _parentScissorRect.origin.y, _parentScissorRect.size.width, _parentScissorRect.size.height);
	}
	else {
		glDisable(GL_SCISSOR_TEST);
	}
}

Rect ScissorLayer::getViewRect()
{
	Vec2 screenPos = this->convertToWorldSpace(Vec2::ZERO);

	float scaleX = this->getScaleX();
	float scaleY = this->getScaleY();

	for (Node *p = _parent; p != nullptr; p = p->getParent()) {
		scaleX *= p->getScaleX();
		scaleY *= p->getScaleY();
	}
	const auto& _viewSize = this->getContentSize();

	if (scaleX < 0.f) {
		screenPos.x += _viewSize.width*scaleX;
		scaleX = -scaleX;
	}
	if (scaleY < 0.f) {
		screenPos.y += _viewSize.height*scaleY;
		scaleY = -scaleY;
	}

	return Rect(screenPos.x, screenPos.y, _viewSize.width*scaleX, _viewSize.height*scaleY);
}

