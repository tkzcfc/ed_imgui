#pragma once


#include "cocos2d.h"

USING_NS_CC;

class ScissorLayer : Layer
{
public:

	ScissorLayer();

	virtual ~ScissorLayer();

	CREATE_FUNC(ScissorLayer);

	virtual void visit(Renderer *renderer, const Mat4& parentTransform, uint32_t parentFlags)override;

protected:

	/**
	* clip this view so that outside of the visible bounds can be hidden.
	*/
	void beforeDraw();
	void onBeforeDraw();
	/**
	 * retract what's done in beforeDraw so that there's no side effect to
	 * other nodes.
	 */
	void afterDraw();
	void onAfterDraw();

	Rect getViewRect();

private:
	CustomCommand _beforeDrawCommand;
	CustomCommand _afterDrawCommand;

	Rect _parentScissorRect;
	bool _scissorRestored;
};

