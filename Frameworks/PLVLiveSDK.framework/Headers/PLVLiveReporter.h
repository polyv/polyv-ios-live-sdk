//
//  PLVLiveReporter.h
//  PLVLiveSDK
//
//  Created by ftao on 24/10/2017.
//  Copyright © 2017 easefun. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 直播服务质量统计
 */
@interface PLVLiveReporter : NSObject

/**
 首次加载时长
 */
+ (void)reportLoading:(NSString*)pid uid:(NSString*)uid channelId:(NSString*)channelId time:(int)time session_id:(NSString *)session_id param1:(NSString*)param1 param2:(NSString*)param2 param3:(NSString*)param3 param4:(NSString*)param4 param5:(NSString*)param5;

/**
 二次缓冲时长
 */
+ (void)reportBuffer:(NSString*)pid uid:(NSString*)uid channelId:(NSString*)channelId time:(int)time session_id:(NSString *)session_id param1:(NSString*)param1 param2:(NSString*)param2 param3:(NSString*)param3 param4:(NSString*)param4 param5:(NSString*)param5;

/**
 播放出错
 */
+ (void)reportError:(NSString *)pid uid:(NSString *)uid channelId:(NSString *)channelId session_id:(NSString *)session_id param1:(NSString *)param1 param2:(NSString *)param2 param3:(NSString *)param3 param4:(NSString *)param4 param5:(NSString *)param5 uri:(NSString *)uri status:(NSString *)status errorcode:(NSString *)errorcode errormsg:(NSString *)errormsg;

/**
 播放中
 */
+ (void)stat:(NSString*)pid uid:(NSString*)uid cid:(NSString*)cid flow:(long)flow pd:(int)pd sd:(int)sd cts:(NSTimeInterval)cts duration:(int)duration;

@end
