//
//  AppDelegate.h
//  NSLockAndSynchronizedUSE
//
//  Created by 紫冬 on 13-8-29.
//  Copyright (c) 2013年 qsji. All rights reserved.
//

/*
 这个例子我们只是验证的是原子操作，并没有涉及到线程的调度，因此生产和消费是乱序的，输出来的数据也是很不规律的
 另外，我们的线程操作共享数据，是通过了ConmonSource对象，是通过调用conmonSource对象来生产和消费的
 并不是通过线程直接操作的数组这个共享数据
 在另外一个例子中，我们将使用线程直接操作共享数据
 */

#import <UIKit/UIKit.h>
#import "ConmonSource.h"

@interface AppDelegate : UIResponder <UIApplicationDelegate>
{
    
}

@property (strong, nonatomic) UIWindow *window;

@end
