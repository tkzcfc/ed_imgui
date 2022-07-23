//
//#include "MugenTest.h"
//#include <string>
//#include "mugen/mugen.h"
//
//#include "mugen/act/frame/GCollisionFrame.h"
//#include "mugen/act/frame/GAudioFrame.h"
//#include "mugen/act/frame/GEventFrame.h"
//#include "mugen/act/frame/GForceFrame.h"
//#include "mugen/act/frame/GImpulseFrame.h"
//
//#include "mugen/collision/GShapeAABB.h"
//#include "mugen/collision/GShapePolygon.h"
//#include "mugen/collision/GShapeCircle.h"
//
//USING_NS_G;
//
//class ActionSimulator : public GAction
//{
//public:
//	virtual void onEnter() override
//	{
//		GAction::onEnter();
//		printf("enter action:%s, play:%d\n", this->getName().c_str(), m_curFrame);
//	}
//
//	virtual void onUpdate() override
//	{
//		GAction::onUpdate();
//		printf("playing action:%s, frame:%d\n", this->getName().c_str(), m_curFrame - 1);
//	}
//
//	virtual void onExit() override
//	{
//		GAction::onExit();
//		printf("exit action:%s, frame:%d\n", this->getName().c_str(), m_curFrame);
//	}
//};
//
//class EventSimulator : public GFrame
//{
//public:
//
//	std::string eventName;
//
//	virtual void onEnter(int32_t currentFrameIndex) override
//	{
//		//GFrame::onEnter(currentFrameIndex);
//		printf("event(%s) onEnter: %d\n", eventName.c_str(), currentFrameIndex);
//	}
//
//	virtual void onUpdate(int32_t currentFrameIndex) override
//	{
//		printf("event(%s) onUpdate: %d\n", eventName.c_str(), currentFrameIndex);
//		GFrame::onUpdate(currentFrameIndex);
//	}
//
//	virtual void onExit(int32_t currentFrameIndex) override
//	{
//		printf("event(%s) onExit: %d\n", eventName.c_str(), currentFrameIndex);
//		GFrame::onExit(currentFrameIndex);
//	}
//};
//
//void MugenTest::testMain()
//{
//	GSkill* skill = new GSkill();
//
//	int32_t length1 = 1;
//	{
//		int32_t startFrame = 2;
//		auto act = new ActionSimulator();
//		act->setName("run_ready");
//		act->setStartFrame(startFrame);
//		act->setEndFrame(startFrame + length1 - 1);
//
//		skill->addAction(act);
//	}
//
//	int32_t length2 = 5;
//	{
//		int32_t startFrame = 2;
//		auto act = new ActionSimulator();
//		act->setName("running");
//		act->setStartFrame(startFrame);
//		act->setEndFrame(startFrame + length2 - 1);
//
//		skill->addAction(act);
//	}
//
//	int32_t length3 = 3;
//	{
//		int32_t startFrame = 0;
//		auto act = new ActionSimulator();
//		act->setName("runn_end");
//		act->setStartFrame(startFrame);
//		act->setEndFrame(startFrame + length3 - 1);
//
//		skill->addAction(act);
//	}
//
//
//	{
//		auto timeline = new GTimeline();
//
//		{
//			auto pEvent = new EventSimulator();
//			pEvent->eventName = "event_ready";
//			pEvent->setStartFrame(0);
//			pEvent->setFrameLen(length1);
//
//			timeline->addFrame(pEvent, GFrameType::EVENT_FRAME);
//		}
//
//
//		{
//			auto pEvent = new EventSimulator();
//			pEvent->eventName = "event_loop";
//			pEvent->setStartFrame(length1);
//			pEvent->setFrameLen(length2 + length3);
//
//			timeline->addFrame(pEvent, GFrameType::EVENT_FRAME);
//		}
//
//
//		{
//			auto pEvent = new EventSimulator();
//			pEvent->eventName = "event_end";
//			pEvent->setStartFrame(length1 + length2);
//			pEvent->setFrameLen(length3);
//
//			timeline->addFrame(pEvent, GFrameType::EVENT_FRAME);
//		}
//
//
//		skill->getTrack()->addTimeline(timeline);
//
//
//		{
//			auto timeline = new GTimeline();
//			auto pEvent = new EventSimulator();
//			pEvent->eventName = "event_anytime";
//			pEvent->setStartFrame(0);
//			pEvent->setFrameLen(length1 + length2 + length3);
//
//			timeline->addFrame(pEvent, GFrameType::EVENT_FRAME);
//			skill->getTrack()->addTimeline(timeline);
//		}
//
//
//		skill->setTotalFrame(length1 + length2 + length3);
//		skill->setTotalLoopCount(2);
//		skill->setLoopActionIndex(2);
//	}
//
//	int32_t frameCount = 0;
//
//	while (true)
//	{
//		printf("\n\n\n[%d]--------------------------------------\n", frameCount);
//		frameCount++;
//		skill->onUpdate();
//		if (skill->getPlayFinish())
//		{
//			break;
//		}
//	}
//}
//
//
//
//
