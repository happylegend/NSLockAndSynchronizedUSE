//
//  ConmonSource.h
//  NSLockAndSynchronizedUSE
//
//  Created by 紫冬 on 13-8-29.
//  Copyright (c) 2013年 qsji. All rights reserved.
//

/*
 NSLock和@Synchronized主要是用来保证原子操作的，多个线程共用一把锁，只有得到锁的线程，才能开始执行它的代码，直到代码块执行完以后，才释放锁。从而保证了线程的互斥和同步。
 因为只有一把锁，因此每次只能一个线程执行。
 又因为往往多个线程会共享同一资源，而用NSLock和@Synchronized括起来的代码块是一个原子操作，代码块执行过程中，不会被其他线程所中断，这样就保证了函数代码快完整的执行了，保证了
 对共享资源数据该流程阶段的完整操作。
 一定要保证每一个阶段的流程的完整操作，不可被中间打断，否则就会造成逻辑混乱。
 用生产者和消费者的思想的话，那么就是生产产品的完整过程和消费产品的完整过程都是原子操作。
 
 因此使用NSLock和@Synchronized的目的在于保证了保证操作共享资源(数据)线程代码块是原子操作，该代码块的执行不会被别的线程中断，从而保证了共享资源数据的完整性
 
 但是NSLock和@Synchronized不能同步线程的执行顺序，也就是说他们只保证了线程的代码块执行的完整性，但是却不能对线程的执行顺序进行调度
 如果我们要对线程的执行顺序进行调度，那么我们就要使用NSCondition、NSConditionLock等等
 
 本质上我们只需要记住NSLock和@synchronized仅仅保证保证的是操作共享资源代码块的原子操作和数据完整性，进而实现的线程互斥和同步。
 
 下面介绍两种实现线程同步的写法：
 我们以生产者和消费者为例子：
 下面介绍第一种：
 将生产和消费都写在共享资源对象中
 
 一般加锁有三种方式：
 lock，trylock，lockuntilDate:
 一般用法:
 [myLock  lock];
 //......
 //......
 [myLock unlock];
 
 if ([theLock tryLock]) 
 {
    //dosomething
    //......
    [theLock unlock];
 }
 
 [self.lock lockBeforeDate:[NSDate dateWithTimeIntervalSinceNow:10]];
 //......
 //......
 [self.lock unlock];

 */

#import <Foundation/Foundation.h>
#import "Bread.h"

@interface ConmonSource : NSObject
{
    NSMutableArray *_arraySource;
    NSLock *_lock;
    int _i;
}
@property(nonatomic, retain)NSLock *lock;
@property(nonatomic, retain)NSMutableArray *arraySource;
@property(nonatomic, assign)int i;

-(void)produceBread:(Bread *)bread;  //生产面包
-(void)consumeBread;                 //消费面包

@end
