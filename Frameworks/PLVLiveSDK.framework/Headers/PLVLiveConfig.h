//
//  PLVLiveConfig.h
//  PLVLiveSDK
//
//  Created by ftao on 24/10/2017.
//  Copyright © 2017 easefun. All rights reserved.
//

#import <Foundation/Foundation.h>

/// 日志等级
typedef NS_ENUM(NSUInteger, PLVLiveLogLevel) {
    k_PLV_LIVE_LOG_NULL         = 0,        // 无 LOG 输出
    k_PLV_LIVE_LOG_ERROR        = 1,        // ERROR 等级
    k_PLV_LIVE_LOG_INFO         = 2,        // INFO 等级
    k_PLV_LIVE_LOG_DEBUG        = 3,        // DEBUG 等级
};

/**
 直播 SDK 配置文件
 */
@interface PLVLiveConfig : NSObject

@property (nonatomic, strong, readonly) NSString *appId;
@property (nonatomic, strong, readonly) NSString *appSecret;

@property (nonatomic, strong, readonly) NSString *playerId;

/**
 LIVE SDK 版本信息
 */
+ (NSString *)sdkVersion;

/**
 LIVE SDK CONFIG 单例类
 */
+ (instancetype)sharedInstance;

/**
 初始化配置 appId 和 appSecret
 */
+ (instancetype)liveConfigWithAppId:(NSString *)appId appSecret:(NSString *)appSecret;

/**
 重置播放器 Id
 */
- (void)resetPlayerId;

#pragma mark - SDK 日志等级设置

/**
 设置Polyv Live SDK LOG等级
 
 @param logLevel 默认 k_PLV_LIVE_LOG_INFO
 */
+ (void)setLogLevel:(PLVLiveLogLevel)logLevel;

/**
 SDK 日志等级
 */
+ (PLVLiveLogLevel)logLevel;

@end
