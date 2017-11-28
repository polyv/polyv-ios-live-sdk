//
//  PLVSocketObject.h
//  PLVLiveSDK
//
//  Created by ftao on 24/10/2017.
//  Copyright © 2017 easefun. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *const PLVSocketObjectDefaultUserNick; // 默认用户昵称
extern NSString *const PLVSocketObjectDefaultUserPic;  // 默认用户头像

/// socketIO 事件对象类型
typedef NS_ENUM(NSUInteger, PLVSocketObjectType) {
    PLVSocketObjectTypeChatRoom = 0,        // 聊天室对象
    PLVSocketObjectTypeLinkMic,             // 连麦对象
    PLVSocketObjectTypePPT                  // PPT 对象
};

/// SocketIO 对象用户类型
typedef NS_ENUM(NSUInteger, PLVSocketObjectUserType) {
    PLVSocketObjectUserTypeStudent,         // 学生（普通直播观看下用户类型）
    PLVSocketObjectUserTypeSlice,           // 云课堂学员（PPT模式下用户类型）
    PLVSocketObjectUserTypeTeacher,         // 教师（推流端用户类型）
};

/// 返回 SocketIO 对象用户类型对应的字符串符号
NSString *NameStringWithSocketObjectUserType(PLVSocketObjectUserType userType);

/**
 SocketObject 对象的基类，业务中使用其子类
 */
@interface PLVSocketObject : NSObject

/// socket 对象类型
@property (nonatomic, assign) PLVSocketObjectType objectType;

/// 消息/事件名
@property (nonatomic, strong) NSString *event;

/// 消息/事件内容
@property (nonatomic, strong) NSDictionary *jsonDict;

/**
 便利初始化方法，使用子类调用

 @param jsonDict 消息/事件内容
 @return PLVSocketObject 子类对象
 */
+ (instancetype)socketObjectWithJsonDict:(NSDictionary *)jsonDict;

@end
