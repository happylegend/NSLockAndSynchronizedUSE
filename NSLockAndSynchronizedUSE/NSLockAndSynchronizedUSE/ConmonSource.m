//
//  ConmonSource.m
//  NSLockAndSynchronizedUSE
//
//  Created by 紫冬 on 13-8-29.
//  Copyright (c) 2013年 qsji. All rights reserved.
//

#import "ConmonSource.h"

@implementation ConmonSource
@synthesize i = _i;
@synthesize lock = _lock;
@synthesize arraySource = _arraySource;

-(id)init
{
    self = [super init];
    if (self)
    {
        NSLock *aLock = [[NSLock alloc] init];
        self.lock = aLock;
        [aLock release];
        aLock = nil;
        
        NSMutableArray *aArraySource = [[NSMutableArray alloc] init];
        self.arraySource = aArraySource;
        [aArraySource release];
        aArraySource = nil;
        
        self.i = 0;
    }
    
    return self;
}

-(void)produceBread:(Bread *)bread  //生产面包
{
    //使用NSLock
    [self.lock lock];        
    [self.arraySource addObject:bread];
    
    [self.lock unlock];
    (self.i)++;
    NSLog(@"生产的第%d个面包", self.i);
    
    /*
    
    //也可以使用@Synchronized
    @synchronized(self)
    {
        [self.arraySource addObject:bread];

    }
    
    //使用@Synchronized的另外一个写法是：
    @synchronized(self.arraySource)
    {
        [self.arraySource addObject:bread];
    }
     
     */
/*
 总结，当我们使用@Synchronized的时候，括号中的数据，既可以是self，也可以使用self.arraySource，当然这两种方式达到的效果是相同的，但是含义却有点区别：
 当使用self的时候，表示执行这个代码块的时候，表示只能有一个线程有权使用这个对象
 当使用self.arraySource的时候，表示执行这个代码块的时候，只能有一个线程有权使用这个数组
 
 其实这两者的差别在于：
 如果用self，表示整个对象，其他线程无法操作这个对象，以及对象的任何数据和方法
 如果用self.arraySource仅仅表示无法其他线程无法使用这个对象中的这个数组共享资源
 */
    
}

-(void)consumeBread  //消费面包
{
    //同理，消费面包也是一样也可以使用上面的几种思路。如果有面包，就从最后一个开始消费
    //使用NSLock
    [self.lock lock];
    if (self.arraySource.count > 0)
    {
        NSLog(@"消费的第%d个面包", self.i);
        [self.arraySource removeObjectAtIndex:self.arraySource.count - 1];
                
    }
    [self.lock unlock];
    
    
    /*
    //使用@Synchronized
    @synchronized(self)
    {
        if (self.arraySource.count > 0)
        {
            [self.arraySource removeObjectAtIndex:self.arraySource.count - 1];
        }
    }
    
    //使用@synchronized的另一种方法
    @synchronized(self.arraySource)
    {
        if (self.arraySource.count > 0)
        {
            [self.arraySource removeObjectAtIndex:self.arraySource.count - 1];
        }
    }
     
     */
}

-(void)dealloc
{
    self.arraySource = nil;
    [super dealloc];
}

@end
