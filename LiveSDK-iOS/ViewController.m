//
//  ViewController.m
//  LiveSDK-iOS
//
//  Created by ftao on 28/11/2017.
//  Copyright © 2017 easefun. All rights reserved.
//

#import "ViewController.h"
#import <PLVLiveSDK/PLVLiveSDK.h>

@interface ViewController () <PLVSocketIODelegate>

@property (nonatomic, strong) PLVSocketIO *socketIO;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    [PLVLiveConfig liveConfigWithAppId:@"666" appSecret:@"dasdasdasdasdasd"];
    NSLog(@"appId:%@, appSecret:%@",[PLVLiveConfig sharedInstance].appId,[PLVLiveConfig sharedInstance].appSecret);
    
    //[PLVLiveAPI loadChannelInfoWithUserId:@"asd" channelId:103117 completion:^(PLVLiveChannel *channel) {
    //    NSLog(@"listUsers:%@",channel);
    //} failure:^(PLVLiveErrorCode errorCode, NSString *description) {
    //    NSLog(@"errorCode:%ld, descripption:%@",errorCode,description);
    //}];
    
    self.socketIO = [[PLVSocketIO alloc] initSocketIOWithConnectToken:@"" enableLog:NO];
    self.socketIO.delegate = self;
    [self.socketIO connect];
}

#pragma mark - <PLVSocketIODelegate>

- (void)socketIO:(PLVSocketIO *)socketIO didConnectWithInfo:(NSString *)info {
    NSLog(@"socketIO:didConnectWithInfo: %@",info);
}

- (void)socketIO:(PLVSocketIO *)socketIO didReceiveChatMessage:(PLVSocketChatRoomObject *)chatRoomObject {
    NSLog(@"socketIO:didReceiveChatMessage: type:%lu, event:%@",chatRoomObject.eventType,chatRoomObject.event);
    NSDictionary *dict = chatRoomObject.jsonDict;
    NSLog(@"%@",dict);
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
