//
//  PLVLiveChannel.h
//  PLVLiveSDK
//
//  Created by ftao on 24/10/2017.
//  Copyright © 2017 easefun. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 直播观看频道信息
 */
@interface PLVLiveChannel : NSObject

/// 直播频道 Id
@property (nonatomic, copy, readonly) NSNumber *channelId;
/// 直播用户 Id
@property (nonatomic, copy, readonly) NSString *userId;
/// 直播频道名称
@property (nonatomic, copy, readonly) NSString *name;
/// 直播 FLV 地址
@property (nonatomic, copy, readonly) NSString *flvUrl;
/// 直播 M3U8 地址
@property (nonatomic, copy, readonly) NSString *m3u8Url;
/// 直播流名称
@property (nonatomic, copy, readonly) NSString *stream;

/// NGB 是否开启
@property (nonatomic, readonly) BOOL isNgbEnabled;
/// 防盗链是否开启
@property (nonatomic, readonly) BOOL isUrlProtected;
/// NGB URL
@property (nonatomic, copy, readonly) NSString *ngbUrl;
/// bakUrl URL
@property (nonatomic, copy, readonly) NSString *bakUrl;

/// Qos 发送频率
@property (nonatomic, copy, readonly) NSNumber *reportFreq;


/**
 便利初始化方法
 */
+ (instancetype)liveChannelWithJsonDict:(NSDictionary *)jsonDict;

@end
