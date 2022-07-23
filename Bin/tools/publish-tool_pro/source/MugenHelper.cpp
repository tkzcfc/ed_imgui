#include "MugenHelper.h"

#include "json.hpp"
#include "mugen/act/frame/GCollisionFrame.h"
#include "mugen/act/frame/GAudioFrame.h"
#include "mugen/act/frame/GEventFrame.h"
#include "mugen/act/frame/GPhysicalForceFrame.h"

#include "mugen/collision/GShapeAABB.h"
#include "mugen/collision/GShapePolygon.h"
#include "mugen/collision/GShapeCircle.h"

#include "mugen/act/condition/GScriptCondition.h"

#include "core/shape/CRect.h"
#include "fmt/format.h"



using namespace nlohmann;
USING_NS_G;


std::vector<std::string> MugenHelper::s_errLog;
std::vector<std::string> MugenHelper::s_waring;
std::string MugenHelper::s_errsActName;
std::string MugenHelper::s_errskillName;


static GFrame* createFrameByType(json& track, int32_t index, GFrameType type, int32_t startFrame, int32_t frameLen)
{
	auto frame = track["frames"][index];
	GFrame* pFrame = NULL;

	switch (type)
	{
	case ng::ATT_COLLISION_FRAME:
	case ng::DEF_COLLISION_FRAME:
	{
		auto curFramePtr = new GCollisionFrame();
		pFrame = curFramePtr;

		int32_t shapeType = track["shape"];
		auto shapeData = frame["shapeData"];

		shapeType--;

		if (shapeType == (int32_t)ECollisionType::RECT_AABB)
		{
			CRect rect;
			rect.setAnchorPoint(shapeData["anchorPoint"]["x"], shapeData["anchorPoint"]["y"]);
			rect.setContentSize(shapeData["contentSize"]["x"], shapeData["contentSize"]["y"]);
			rect.setPoint(shapeData["point"]["x"], shapeData["point"]["y"]);
			rect.setScale(shapeData["scale"]["x"], shapeData["scale"]["y"]);
			rect.setRotation(shapeData["rotation"]);
			rect.setSkewX(shapeData["skew"]["x"]);
			rect.setSkewY(shapeData["skew"]["y"]);
			rect.apply();

			if (rect.isAABBBox())
			{
				auto minV = rect.getVertexMin();
				auto maxV = rect.getVertexMax();

				auto w = maxV.x - minV.x;
				auto h = maxV.y - minV.y;

				auto shape = new GShapeAABB();
				shape->setRect(GFixedVec2(minV.x, minV.y), GFixedVec2(w, h));
				curFramePtr->setShape(shape);
			}
			else
			{
				GFixedVec2 vs[4];
				for (auto i = 0; i < 4; ++i)
				{
					auto vertex = rect.getVertexByIndex(i);
					vs[i].x = vertex.x;
					vs[i].y = vertex.y;
				}

				auto shape = new GShapePolygon();
				shape->set(vs, 4);
				curFramePtr->setShape(shape);
			}
		}
		else if (shapeType == (int32_t)ECollisionType::POLYGON)
		{
			auto vertex = shapeData["vertex"];

			GFixedVec2 vs[MAX_POLY_VERTEX_COUNT];
			for (auto i = 0; i < vertex.size(); ++i)
			{
				float x = vertex[i]["x"];
				float y = vertex[i]["y"];
				vs[i].x = x;
				vs[i].y = y;
			}

			auto shape = new GShapePolygon();
			shape->set(vs, vertex.size());
			curFramePtr->setShape(shape);
		}
		else if (shapeType == (int32_t)ECollisionType::CIRCLE)
		{
			float x = shapeData["center"]["x"];
			float y = shapeData["center"]["y"];
			float radius = shapeData["radius"];

			auto shape = new GShapeCircle();
			shape->set(GFixedVec2(x, y), radius);
			curFramePtr->setShape(shape);
		}
		else
		{
			G_ASSERT(false);
		}
	}
	break;
	case ng::PHYSICAL_FORCE_FRAME:
	{
		auto curFramePtr = new GPhysicalForceFrame();
		pFrame = curFramePtr;
		curFramePtr->setTriggerMaxCount(frame["triggerMaxCount"]);
		curFramePtr->setTriggerInterval(frame["triggerInterval"]);
		curFramePtr->setStartFrame(frame["time"]);
		curFramePtr->setFrameLen(frame["len"]);

		auto x = deal_float(frame["force"]["x"]);
		auto y = deal_float(frame["force"]["y"]);
		auto z = deal_float(frame["force"]["z"]);
		curFramePtr->setValue(GFixedVec3(x, y, z));
		curFramePtr->setValueType((GValueType)frame["valueType"].get<int>());
		curFramePtr->setForceOrientation((GForceOrientation)frame["forceOrientation"].get<int>());
		curFramePtr->setForceType((GPhysicalForceType)frame["forceType"].get<int>());
	}
	break;
	case ng::EVENT_FRAME:
	{
		G_ASSERT(0);
	}
	break;
	case ng::AUDIO_FRAME:
	{
		auto curFramePtr = new GAudioFrame();
		pFrame = curFramePtr;
		curFramePtr->setTriggerMaxCount(frame["triggerMaxCount"]);
		curFramePtr->setTriggerInterval(frame["triggerInterval"]);
		curFramePtr->setStartFrame(frame["time"]);
		curFramePtr->setFrameLen(frame["len"]);

		curFramePtr->setAudio(frame["audioName"].get<std::string>());
	}
	break;
	case ng::SCRIPT_FRAME:
	{
		auto curFramePtr = new GScriptFrame();
		pFrame = curFramePtr;
		curFramePtr->setTriggerMaxCount(frame["triggerMaxCount"]);
		curFramePtr->setTriggerInterval(frame["triggerInterval"]);
		curFramePtr->setStartFrame(frame["time"]);
		curFramePtr->setFrameLen(frame["len"]);

		curFramePtr->setScriptFile(frame["scriptFile"].get<std::string>());
		curFramePtr->setArgStr(frame["argStr"].get<std::string>());
		curFramePtr->setScriptCode(frame["isScriptCode"]);
	}
	break;
	case ng::UNKNOWN_FRAME:
		break;
	default:
		break;
	}

	if (pFrame)
	{
		int32_t time = frame["time"];
		int32_t len = frame["len"];

		if (len < 0) len = frameLen;

		pFrame->setStartFrame(startFrame + time);
		pFrame->setFrameLen(len);
		pFrame->setType(type);
	}
	else
	{
		MugenHelper::addWaring(fmt::format("Frame type {0} export is not supported", type));
	}

	return pFrame;
}

static void addTracksToSkill(GSkill* skill, json& tracks, int32_t startFrame, int32_t frameLen)
{

	for (auto i = 0; i < tracks.size(); ++i)
	{
		auto timeline = new GTimeline();

		auto track = tracks[i];

		int32_t type = track["type"];
		auto frames = track["frames"];

		for (auto j = 0; j < frames.size(); ++j)
		{
			auto frame = createFrameByType(track, j, (GFrameType)type, startFrame, frameLen);
			if (frame)
			{
				timeline->addFrame(frame, (GFrameType)type);
			}
		}

		skill->getTrack()->addTimeline(timeline);
	}
}


static GCondition* exportCondition(json& data)
{
	GCondition* pCondition = NULL;

	int type = data["type"].get<int>();
	if (type == (int)GConditionType::SCRIPT_CONDITION)
	{
		auto pCur = new GScriptCondition();
		pCur->setScriptFile(data["scriptFile"].get<std::string>());
		pCur->setArgStr(data["argStr"].get<std::string>());
		pCur->setScriptCode(data["isScriptCode"]);

		pCondition = pCur;
	}

	if (pCondition)
	{
		pCondition->setBeginFrame(data["beginFrame"]);
		pCondition->setFrameLen(data["frameLen"]);
		pCondition->setType((GConditionType)type);
	}
	else
	{
		MugenHelper::addWaring(fmt::format("Conditional type {0} export is not supported", type));
	}

	return pCondition;
}

static void exportChannels(GSkill* skill, json& curSkillInfo)
{
	auto channels = curSkillInfo["channels"];

	for (auto i = 0; i < channels.size(); ++i)
	{
		auto data = channels[i];

		auto channel = new GChannel();
		channel->setNextSkillId(data["nextSkillId"]);
		channel->setCheckType((GChannel::CheckType)data["checkType"].get<int>());
		channel->setInterruptType((GInterruptType)data["interruptType"].get<int>());

		auto conditions = data["conditions"];

		for (auto j = 0; j < conditions.size(); ++j)
		{
			auto pCondition = exportCondition(conditions[j]);
			if (pCondition)
			{
				channel->addCondition(pCondition);
			}
			else
			{
				MugenHelper::addError(fmt::format("Skill: {0}, channel {1} condition {2} export failed", skill->getName(), i, j));
			}
		}

		skill->addChannel(channel);
	}
}


NS_G::GEntity* MugenHelper::serializeRole(const char* content)
{
	auto pEntity = GEntityManager::getInstance()->newEntity();

	try
	{
		auto data = json::parse(content);

		// 技能信息
		auto skillInfo = data["skillInfo"];
		// 动作信息
		auto actInfo = data["actInfo"];

		auto actorCom = new GActorComponent();
		pEntity->addComponent(actorCom);

		int defaultSkillIndex = data["defaultSkillIndex"];
		defaultSkillIndex--;
		if (defaultSkillIndex < skillInfo.size())
		{
			actorCom->setDefaultSkillId(skillInfo[defaultSkillIndex]["id"]);
		}
		else
		{
			addError(fmt::format("Default skill index: {0} not found", defaultSkillIndex + 1));
		}

		for (auto i = 0; i < skillInfo.size(); ++i)
		{
			auto curSkillInfo = skillInfo[i];

			s_errskillName = curSkillInfo["name"].get<std::string>();

			auto skill = new GSkill();
			skill->setName(curSkillInfo["name"]);
			skill->setId(curSkillInfo["id"]);
			skill->setTotalLoopCount(curSkillInfo["loopCount"]);
			actorCom->addSkill(skill);

			int32_t curFrame = 0;
			// 通过动作id填充技能
			auto arrActInfo = curSkillInfo["arrActInfo"];
			for (auto j = 0; j < arrActInfo.size(); ++j)
			{
				auto curAct = arrActInfo[j];

				int32_t actId = curAct["id"];
				int32_t loopCount = curAct["loopCount"];

				bool ok = false;
				for (auto k = 0; k < actInfo.size(); ++k)
				{
					if (actInfo[k]["id"] == actId)
					{
						ok = true;
						auto curActInfo = actInfo[k];

						int32_t max = curActInfo["max"];
						int32_t min = curActInfo["min"];
						int32_t len = max - min + 1;

						auto action = new GAction();
						action->setStartFrame(min);
						action->setEndFrame(max);
						action->setMaxLoopCount(loopCount);
						action->setId(curActInfo["id"]);
						action->setName(curActInfo["name"]);
						action->setPlayName(curActInfo["playName"]);
						skill->addAction(action);
						
						s_errsActName = action->getName();
						// 将动作中的事件帧添加到技能中
						addTracksToSkill(skill, curActInfo["tracks"], curFrame, len);

						curFrame += len;
						break;
					}
				}

				if (!ok)
				{
					addError(fmt::format("Skill \"{0}\" cannot find action ID: {1}", skill->getName(), actId));
				}

				skill->setTotalFrame(curFrame);
			}

			addTracksToSkill(skill, curSkillInfo["tracks"], 0, curFrame);

			// 技能通道
			auto cnit = curSkillInfo.find("channels");
			if (curSkillInfo.end() != cnit)
			{
				exportChannels(skill, curSkillInfo);
			}
		}


		s_errsActName = "";
		s_errskillName = "";

		auto staticCom = new GStaticDataComponent();
		actorCom->addComponent(staticCom);

		float tmp = 0.0f;

		// 动画资源路径
		staticCom->armatureFile = data["resFile"].get<std::string>();

		// directionLeft
		staticCom->directionLeft = data["directionLeft"].get<bool>();

		// offset
		tmp = data["offset"]["x"];
		staticCom->offset.x = tmp;
		tmp = data["offset"]["y"];
		staticCom->offset.y = tmp;

		// radius
		tmp = data["radius"];
		staticCom->radius = tmp;

		// mass
		tmp = data["mass"];
		staticCom->mass = tmp;

		// size
		tmp = data["roleSize"]["x"];
		staticCom->size.x = tmp;
		tmp = data["roleSize"]["y"];
		staticCom->size.y = tmp;
		tmp = data["roleSize"]["z"];
		staticCom->size.z = tmp;

		// 线性速度
		tmp = data["moveSpeed"]["x"];
		staticCom->moveSpeed.x = tmp;
		tmp = data["moveSpeed"]["y"];
		staticCom->moveSpeed.y = tmp;

		// force
		tmp = data["force"]["x"];
		staticCom->force.x = tmp;
		tmp = data["force"]["y"];
		staticCom->force.y = tmp;
		tmp = data["force"]["z"];
		staticCom->force.z = tmp;


		// 跳跃冲力
		tmp = data["impulsion"]["x"];
		staticCom->impulse.x = tmp;
		tmp = data["impulsion"]["y"];
		staticCom->impulse.y = tmp;
		tmp = data["impulsion"]["z"];
		staticCom->impulse.z = tmp;

		return pEntity;
	}
	catch (const json::parse_error& err)
	{
		addError(fmt::format("json parse_error: {0}", err.what()));
		// parse errors are ok, because input may be random bytes
		return NULL;
	}
	catch (const json::out_of_range& err)
	{
		addError(fmt::format("json out_of_range: {0}", err.what()));
		// out of range errors may happen if provided sizes are excessive
		return NULL;
	}
	catch (const json::other_error& err)
	{
		addError(fmt::format("json other_error: {0}", err.what()));
		return false;
	}
	catch (const json::type_error& err)
	{
		addError(fmt::format("json type_error: {0}", err.what()));
		return NULL;
	}
	catch (const json::invalid_iterator& err)
	{
		addError(fmt::format("json invalid_iterator: {0}", err.what()));
		return NULL;
	}
	catch (const json::exception& err)
	{
		addError(fmt::format("json exception: {0}", err.what()));
		return NULL;
	}
	catch (...)
	{
		addError("json unknown error");
		return NULL;
	}
	

	return NULL;
}


bool MugenHelper::serializeRoleToFile(const char* content, const char* filename)
{
	GEntityManager::getInstance()->clear();

	s_errsActName = "";
	s_errskillName = "";

	int32_t oldCount = GObject::getObjectCount();

	s_waring.clear();
	s_errLog.clear();

	auto entity = serializeRole(content);
	if (entity == NULL)
		return false;

	if (s_errLog.empty() == false)
	{
		return false;
	}

	GByteBuffer buffer;

	// 序列化到buffer中
	G_GetComponent(entity, GActorComponent)->serialize(buffer);
	G_GetComponent(entity, GStaticDataComponent)->serialize(buffer);
	
	// 清理
	GEntityManager::getInstance()->clear();

	// 写入完毕
	buffer.writeFinish();

	FILE* fp = ::fopen(filename, "wb");
	if (fp == NULL)
	{
		addError(fmt::format("fail to open file: {0}", filename));
		return false;
	}

	if (0 == ::fwrite(buffer.data(), buffer.len(), 1, fp))
	{
		::fclose(fp);
		addError(fmt::format("fail to write file: {0}", filename));
		return false;
	}

	::fflush(fp);
	::fclose(fp);


	//printf("diff object: %d\n", GObject::getObjectCount() - oldCount);

	return true;
}


std::vector<std::string> MugenHelper::errors()
{
	return s_errLog;
}

std::vector<std::string> MugenHelper::warings()
{
	return s_waring;
}

void MugenHelper::addError(const std::string& err)
{
	s_errLog.push_back(fmt::format("actName: {0}", s_errsActName));
	s_errLog.push_back(fmt::format("skillName: {0}", s_errskillName));
	s_errLog.push_back(err);
}

void MugenHelper::addWaring(const std::string& str)
{
	s_waring.push_back(str);
}

