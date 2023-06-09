//
//  MSDKSynthesizeSingleton.h
//  MSDKCore
//
//  Created by Hillson Song on 5/14/18.
//  Copyright © company. All rights reserved.
//

#ifndef SYNTHESIZE_SINGLETON_FOR_CLASS_H
#define SYNTHESIZE_SINGLETON_FOR_CLASS_H

#import <objc/runtime.h>


#pragma mark -
#pragma mark Singleton

/* Synthesize Singleton For Class
 *
 * Creates a singleton interface for the specified class with the following methods:
 *
 * + (MyClass*) sharedInstance;
 * + (void) purgeSharedInstance;
 *
 * Calling sharedInstance will instantiate the class and swizzle some methods to ensure
 * that only a single instance ever exists.
 * Calling purgeSharedInstance will destroy the shared instance and return the swizzled
 * methods to their former selves.
 *
 *
 * Usage:
 *
 * MyClass.h:
 * ========================================
 *    #import "SynthesizeSingleton.h"
 *
 *    @interface MyClass: SomeSuperclass
 *    {
 *        ...
 *    }
 *    SYNTHESIZE_SINGLETON_FOR_CLASS_HEADER(MyClass);
 *
 *    @end
 * ========================================
 *
 *
 *    MyClass.m:
 * ========================================
 *    #import "MyClass.h"
 *
 *    @implementation MyClass
 *
 *    SYNTHESIZE_SINGLETON_FOR_CLASS(MyClass);
 *
 *    ...
 *
 *    @end
 * ========================================
 *
 *
 * Note: Calling alloc manually will also initialize the singleton, so you
 * can call a more complex init routine to initialize the singleton like so:
 *
 * [[MyClass alloc] initWithParam:firstParam secondParam:secondParam];
 *
 * Just be sure to make such a call BEFORE you call "sharedInstance" in
 * your program.
 */

#define SYNTHESIZE_SINGLETON_FOR_CLASS_HEADER(__CLASSNAME__)    \
\
+ (__CLASSNAME__*) sharedInstance;    \
+ (void) purgeSharedInstance;


#define SYNTHESIZE_SINGLETON_FOR_CLASS(__CLASSNAME__)    \
\
static __CLASSNAME__* volatile _##__CLASSNAME__##_sharedInstance = nil;    \
\
+ (__CLASSNAME__*) sharedInstanceNoSynch    \
{    \
return (__CLASSNAME__*) _##__CLASSNAME__##_sharedInstance;    \
}    \
\
+ (__CLASSNAME__*) sharedInstanceSynch    \
{    \
@synchronized(self)    \
{    \
if(nil == _##__CLASSNAME__##_sharedInstance)    \
{    \
_##__CLASSNAME__##_sharedInstance = [[self alloc] init];    \
}    \
else    \
{    \
NSAssert2(1==0, @"SynthesizeSingleton: %@ ERROR: +(%@ *)sharedInstance method did not get swizzled.", self, self);    \
}    \
}    \
return (__CLASSNAME__*) _##__CLASSNAME__##_sharedInstance;    \
}    \
\
+ (__CLASSNAME__*) sharedInstance    \
{    \
return [self sharedInstanceSynch]; \
}    \
\
+ (id)allocWithZone:(NSZone*) zone    \
{    \
@synchronized(self)    \
{    \
if (nil == _##__CLASSNAME__##_sharedInstance)    \
{    \
_##__CLASSNAME__##_sharedInstance = [super allocWithZone:zone];    \
if(nil != _##__CLASSNAME__##_sharedInstance)    \
{    \
Method newSharedInstanceMethod = class_getClassMethod(self, @selector(sharedInstanceNoSynch));    \
method_setImplementation(class_getClassMethod(self, @selector(sharedInstance)), method_getImplementation(newSharedInstanceMethod));    \
}    \
}    \
}    \
return _##__CLASSNAME__##_sharedInstance;    \
}    \
\
+ (void)purgeSharedInstance    \
{    \
@synchronized(self)    \
{    \
if(nil != _##__CLASSNAME__##_sharedInstance)    \
{    \
Method newSharedInstanceMethod = class_getClassMethod(self, @selector(sharedInstanceSynch));    \
method_setImplementation(class_getClassMethod(self, @selector(sharedInstance)), method_getImplementation(newSharedInstanceMethod));    \
_##__CLASSNAME__##_sharedInstance = nil;    \
}    \
}    \
}    \
\
- (id)copyWithZone:(NSZone *)zone    \
{    \
return self;    \
}    \
\

#endif
