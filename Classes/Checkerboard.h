﻿#ifndef __CHECKERBOARD_H__
#define __CHECKERBOARD_H__

#include <array>
#include "LogicHandle.h"


class Checkerboard : public cocos2d::Layer
{
public:
	static const int kInterval = 5;					// 棋盘间距
	static const int kChessPieceWidth = 100;		// 棋子宽度
	static const int kChessPieceHeight = 100;		// 棋子高度

public:
	Checkerboard();

	~Checkerboard();

	virtual bool init() override;

	CREATE_FUNC(Checkerboard);

public:
	/**
	 * 刷新棋盘
	 */
	void refresh_checkerboard();

	/**
	 * 获取棋子开始位置
	 */
	cocos2d::Vec2 get_chesspiece_start_pos() const;

	/**
	 * 世界坐标转换棋盘坐标
	 */
	cocos2d::Vec2 convert_to_checkerboard_space(const cocos2d::Vec2 &pos) const;

public:
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event) override;

	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event) override;
	
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event) override;
	
	virtual void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *unused_event) override;

private:
	bool real_move_;
	bool touch_lock_;
	cocos2d::Vec2 touch_begin_pos_;
	std::array<cocos2d::LayerColor*, LogicHandle::kCheckerboardRowNum * LogicHandle::kCheckerboardColNum> pieces_;
};

#endif